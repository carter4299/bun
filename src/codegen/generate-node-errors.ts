import NodeErrors from "../bun.js/bindings/ErrorCode.ts";
const outputDir = process.argv[2];
import path from "node:path";

if (!outputDir) {
  throw new Error("Missing output directory");
}

let enumHeader = ``;
let listHeader = ``;
let zig = ``;

enumHeader = `
// clang-format off
// Generated by: src/codegen/generate-node-errors.ts
#pragma once

namespace Bun {
  static constexpr size_t NODE_ERROR_COUNT = ${NodeErrors.length};
  enum class ErrorCode : uint8_t {
`;

listHeader = `
// clang-format off
// Generated by: src/codegen/generate-node-errors.ts
#pragma once

struct ErrorCodeData {
    JSC::ErrorType type;
    WTF::ASCIILiteral name;
    WTF::ASCIILiteral code;
};
static constexpr ErrorCodeData errors[${NodeErrors.length}] = {
`;

zig = `
// Generated by: src/codegen/generate-node-errors.ts
const std = @import("std");
const bun = @import("root").bun;
const JSC = bun.JSC;

fn ErrorBuilder(comptime code_: Error, comptime fmt_: [:0]const u8, Args: type) type {
  return struct {
      const code = code_;
      const fmt = fmt_;
      globalThis: *JSC.JSGlobalObject,
      args: Args,

      // Throw this error as a JS exception
      pub inline fn throw(this: @This()) void {
        code.throw(this.globalThis, fmt, this.args);
      }

      /// Turn this into a JSValue
      pub inline fn toJS(this: @This()) JSC.JSValue {
        return code.fmt(this.globalThis, fmt, this.args);
      }

      /// Turn this into a JSPromise that is already rejected.
      pub inline fn reject(this: @This()) JSC.JSValue {
        return JSC.JSPromise.rejectedPromiseValue(this.globalThis, code.fmt(this.globalThis, fmt, this.args));
      }

  };
}

pub const Error = enum(u8) {

`;

let i = 0;
let listForUsingNamespace = "";
for (const [code, constructor, name] of NodeErrors) {
  enumHeader += `    ${code} = ${i},\n`;
  listHeader += `    { JSC::ErrorType::${constructor.name}, "${name}"_s, "${code}"_s },\n`;
  zig += `    ${code} = ${i},\n`;
  listForUsingNamespace += ` /// ${name}: ${code} (instanceof ${constructor.name})\n`;
  listForUsingNamespace += ` pub inline fn ${code}(globalThis: *JSC.JSGlobalObject, comptime fmt: [:0]const u8, args: anytype) ErrorBuilder(Error.${code}, fmt, @TypeOf(args)) {\n`;
  listForUsingNamespace += `     return .{ .globalThis = globalThis, .args = args };\n`;
  listForUsingNamespace += ` }\n`;
  i++;
}

enumHeader += `
};
} // namespace Bun
`;

listHeader += `
};
`;

zig += `
 

  extern fn Bun__createErrorWithCode(globalThis: *JSC.JSGlobalObject, code: Error, message: *bun.String) JSC.JSValue;
  
  /// Creates an Error object with the given error code.
  /// Derefs the message string.
  pub fn toJS(this: Error, globalThis: *JSC.JSGlobalObject, message: *bun.String) JSC.JSValue {
    defer message.deref();
    return Bun__createErrorWithCode(globalThis, this, message);
  }

  pub fn fmt(this: Error, globalThis: *JSC.JSGlobalObject, comptime fmt_str: [:0]const u8, args: anytype) JSC.JSValue {
    if (comptime std.meta.fieldNames(@TypeOf(args)).len == 0) {
      var message = bun.String.static(fmt_str);
      return toJS(this, globalThis, &message);
    }

    var message = bun.String.createFormat(fmt_str, args) catch bun.outOfMemory();
    return toJS(this, globalThis, &message);
  }

  pub fn throw(this: Error, globalThis: *JSC.JSGlobalObject, comptime fmt_str: [:0]const u8, args: anytype) void {
    globalThis.throwValue(fmt(this, globalThis, fmt_str, args)); 
  }

};

pub const JSGlobalObjectExtensions = struct {
${listForUsingNamespace}
};
`;

await Bun.write(path.join(outputDir, "ErrorCode+List.h"), enumHeader);
await Bun.write(path.join(outputDir, "ErrorCode+Data.h"), listHeader);
await Bun.write(path.join(outputDir, "ErrorCode.zig"), zig);
