/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSWorker.h"

#include "ActiveDOMObject.h"
#include "EventNames.h"
#include "ExtendedDOMClientIsoSubspaces.h"
#include "ExtendedDOMIsoSubspaces.h"
#include "IDLTypes.h"
#include "JSDOMAttribute.h"
#include "JSDOMBinding.h"
#include "JSDOMConstructor.h"
#include "JSDOMConvertAny.h"
#include "JSDOMConvertBase.h"
#include "JSDOMConvertDictionary.h"
#include "JSDOMConvertInterface.h"
#include "JSDOMConvertObject.h"
#include "JSDOMConvertSequences.h"
#include "JSDOMConvertStrings.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMGlobalObjectInlines.h"
#include "JSDOMOperation.h"
#include "JSDOMWrapperCache.h"
#include "JSEventListener.h"
#include "StructuredSerializeOptions.h"
#include "JSWorkerOptions.h"
#include "ScriptExecutionContext.h"
#include "WebCoreJSClientData.h"
#include <JavaScriptCore/HeapAnalyzer.h>
#include <JavaScriptCore/IteratorOperations.h>
#include <JavaScriptCore/JSArray.h>
#include <JavaScriptCore/JSCInlines.h>
#include <JavaScriptCore/JSDestructibleObjectHeapCellType.h>
#include <JavaScriptCore/SlotVisitorMacros.h>
#include <JavaScriptCore/SubspaceInlines.h>
#include <wtf/GetPtr.h>
#include <wtf/PointerPreparations.h>
#include <wtf/URL.h>
#include "SerializedScriptValue.h"

namespace WebCore {
using namespace JSC;

// Functions

static JSC_DECLARE_HOST_FUNCTION(jsWorkerPrototypeFunction_terminate);
static JSC_DECLARE_HOST_FUNCTION(jsWorkerPrototypeFunction_postMessage);
static JSC_DECLARE_HOST_FUNCTION(jsWorkerPrototypeFunction_unref);
static JSC_DECLARE_HOST_FUNCTION(jsWorkerPrototypeFunction_ref);

// Attributes

static JSC_DECLARE_CUSTOM_GETTER(jsWorkerConstructor);
static JSC_DECLARE_CUSTOM_GETTER(jsWorker_onmessage);
static JSC_DECLARE_CUSTOM_SETTER(setJSWorker_onmessage);
static JSC_DECLARE_CUSTOM_GETTER(jsWorker_onmessageerror);
static JSC_DECLARE_CUSTOM_SETTER(setJSWorker_onmessageerror);
static JSC_DECLARE_CUSTOM_GETTER(jsWorker_onerror);
static JSC_DECLARE_CUSTOM_SETTER(setJSWorker_onerror);

class JSWorkerPrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSWorkerPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSWorkerPrototype* ptr = new (NotNull, JSC::allocateCell<JSWorkerPrototype>(vm)) JSWorkerPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSWorkerPrototype, Base);
        return &vm.plainObjectSpace();
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSWorkerPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSWorkerPrototype, JSWorkerPrototype::Base);

using JSWorkerDOMConstructor = JSDOMConstructor<JSWorker>;

template<> JSC::EncodedJSValue JSC_HOST_CALL_ATTRIBUTES JSWorkerDOMConstructor::construct(JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame)
{
    VM& vm = lexicalGlobalObject->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* castedThis = jsCast<JSWorkerDOMConstructor*>(callFrame->jsCallee());
    ASSERT(castedThis);
    if (UNLIKELY(callFrame->argumentCount() < 1))
        return throwVMError(lexicalGlobalObject, throwScope, createNotEnoughArgumentsError(lexicalGlobalObject));
    auto* context = castedThis->scriptExecutionContext();
    if (UNLIKELY(!context))
        return throwConstructorScriptExecutionContextUnavailableError(*lexicalGlobalObject, throwScope, "Worker"_s);
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto scriptUrl = convert<IDLUSVString>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    EnsureStillAliveScope argument1 = callFrame->argument(1);

    auto options = WorkerOptions {};
    options.bun.unref = false;

    if (JSObject* optionsObject = JSC::jsDynamicCast<JSC::JSObject*>(argument1.value())) {
        if (auto nameValue = optionsObject->getIfPropertyExists(lexicalGlobalObject, vm.propertyNames->name)) {
            if (nameValue.isString()) {
                options.name = nameValue.toWTFString(lexicalGlobalObject);
                RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
            }
        }

        if (auto miniModeValue = optionsObject->getIfPropertyExists(lexicalGlobalObject, Identifier::fromString(vm, "smol"_s))) {
            options.bun.mini = miniModeValue.toBoolean(lexicalGlobalObject);
            RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
        }

        if (auto ref = optionsObject->getIfPropertyExists(lexicalGlobalObject, Identifier::fromString(vm, "ref"_s))) {
            options.bun.unref = !ref.toBoolean(lexicalGlobalObject);
            RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
        }

        auto workerData = optionsObject->getIfPropertyExists(lexicalGlobalObject, Identifier::fromString(vm, "workerData"_s));
        if (!workerData) {
            workerData = optionsObject->getIfPropertyExists(lexicalGlobalObject, Identifier::fromString(vm, "data"_s));
        }

        if (workerData) {
            Vector<RefPtr<MessagePort>> ports;
            Vector<JSC::Strong<JSC::JSObject>> transferList;

            if (JSValue transferListValue = optionsObject->getIfPropertyExists(lexicalGlobalObject, Identifier::fromString(vm, "transferList"_s))) {
                if (transferListValue.isObject()) {
                    JSC::JSObject* transferListObject = transferListValue.getObject();
                    if (auto* transferListArray = jsDynamicCast<JSC::JSArray*>(transferListObject)) {
                        for (unsigned i = 0; i < transferListArray->length(); i++) {
                            JSC::JSValue transferListValue = transferListArray->get(lexicalGlobalObject, i);
                            if (transferListValue.isObject()) {
                                JSC::JSObject* transferListObject = transferListValue.getObject();
                                transferList.append(JSC::Strong<JSC::JSObject>(vm, transferListObject));
                            }
                        }
                    }
                }
            }

            ExceptionOr<Ref<SerializedScriptValue>> serialized = SerializedScriptValue::create(*lexicalGlobalObject, workerData, WTFMove(transferList), ports, SerializationForStorage::No, SerializationContext::WorkerPostMessage);
            if (serialized.hasException()) {
                WebCore::propagateException(*lexicalGlobalObject, throwScope, serialized.releaseException());
                return encodedJSValue();
            }

            Vector<TransferredMessagePort> transferredPorts;

            if (!ports.isEmpty()) {
                auto disentangleResult = MessagePort::disentanglePorts(WTFMove(ports));
                if (disentangleResult.hasException()) {
                    WebCore::propagateException(*lexicalGlobalObject, throwScope, disentangleResult.releaseException());
                    return encodedJSValue();
                }
                transferredPorts = disentangleResult.releaseReturnValue();
            }

            options.bun.data = serialized.releaseReturnValue();
            options.bun.dataMessagePorts = WTFMove(transferredPorts);
        }

        auto* globalObject = jsCast<Zig::GlobalObject*>(lexicalGlobalObject);
        auto envValue = optionsObject->getIfPropertyExists(lexicalGlobalObject, Identifier::fromString(vm, "env"_s));
        RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
        JSObject* envObject = nullptr;

        if (envValue && envValue.isCell()) {
            envObject = jsDynamicCast<JSC::JSObject*>(envValue);
        } else if (globalObject->m_processEnvObject.isInitialized()) {
            envObject = globalObject->processEnvObject();
        }

        if (envObject) {
            if (!envObject->staticPropertiesReified()) {
                envObject->reifyAllStaticProperties(globalObject);
                RETURN_IF_EXCEPTION(throwScope, {});
            }

            JSC::PropertyNameArray keys(vm, JSC::PropertyNameMode::Strings, JSC::PrivateSymbolMode::Exclude);
            envObject->methodTable()->getOwnPropertyNames(envObject, lexicalGlobalObject, keys, JSC::DontEnumPropertiesMode::Exclude);
            RETURN_IF_EXCEPTION(throwScope, {});

            HashMap<String, String> env;

            for (const auto& key : keys) {
                JSValue value = envObject->get(lexicalGlobalObject, key);
                RETURN_IF_EXCEPTION(throwScope, {});
                String str = value.toWTFString(lexicalGlobalObject).isolatedCopy();
                RETURN_IF_EXCEPTION(throwScope, {});
                env.add(key.impl()->isolatedCopy(), str);
            }

            options.bun.env = std::make_unique<HashMap<String, String>>(WTFMove(env));
        }

        JSValue argvValue = optionsObject->getIfPropertyExists(lexicalGlobalObject, Identifier::fromString(vm, "argv"_s));
        RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
        if (argvValue && argvValue.isCell() && argvValue.asCell()->type() == JSC::JSType::ArrayType) {
            Vector<String> argv;
            forEachInIterable(lexicalGlobalObject, argvValue, [&argv](JSC::VM& vm, JSC::JSGlobalObject* lexicalGlobalObject, JSC::JSValue nextValue) {
                auto scope = DECLARE_THROW_SCOPE(vm);
                String str = nextValue.toWTFString(lexicalGlobalObject).isolatedCopy();
                if (UNLIKELY(scope.exception()))
                    return;
                argv.append(str);
            });
            options.bun.argv = std::make_unique<Vector<String>>(WTFMove(argv));
        }

        JSValue execArgvValue = optionsObject->getIfPropertyExists(lexicalGlobalObject, Identifier::fromString(vm, "execArgv"_s));
        RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
        if (execArgvValue && execArgvValue.isCell() && execArgvValue.asCell()->type() == JSC::JSType::ArrayType) {
            Vector<String> execArgv;
            forEachInIterable(lexicalGlobalObject, execArgvValue, [&execArgv](JSC::VM& vm, JSC::JSGlobalObject* lexicalGlobalObject, JSC::JSValue nextValue) {
                auto scope = DECLARE_THROW_SCOPE(vm);
                String str = nextValue.toWTFString(lexicalGlobalObject).isolatedCopy();
                if (UNLIKELY(scope.exception()))
                    return;
                execArgv.append(str);
            });
            options.bun.execArgv = std::make_unique<Vector<String>>(WTFMove(execArgv));
        }
    }

    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    auto object = Worker::create(*context, WTFMove(scriptUrl), WTFMove(options));
    if constexpr (IsExceptionOr<decltype(object)>)
        RETURN_IF_EXCEPTION(throwScope, {});
    static_assert(TypeOrExceptionOrUnderlyingType<decltype(object)>::isRef);
    auto jsValue = toJSNewlyCreated<IDLInterface<Worker>>(*lexicalGlobalObject, *castedThis->globalObject(), throwScope, WTFMove(object));
    if constexpr (IsExceptionOr<decltype(object)>)
        RETURN_IF_EXCEPTION(throwScope, {});

    auto& impl = jsCast<JSWorker*>(jsValue)->wrapped();
    if (!impl.updatePtr()) {
        throwVMError(lexicalGlobalObject, throwScope, "Failed to start Worker thread"_s);
        return encodedJSValue();
    }

    setSubclassStructureIfNeeded<Worker>(lexicalGlobalObject, callFrame, asObject(jsValue));
    RETURN_IF_EXCEPTION(throwScope, {});

    return JSValue::encode(jsValue);
}
JSC_ANNOTATE_HOST_FUNCTION(JSWorkerDOMConstructorConstruct, JSWorkerDOMConstructor::construct);

template<> const ClassInfo JSWorkerDOMConstructor::s_info = { "Worker"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSWorkerDOMConstructor) };

template<> JSValue JSWorkerDOMConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    return JSEventTarget::getConstructor(vm, &globalObject);
}

template<> void JSWorkerDOMConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->length, jsNumber(1), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    JSString* nameString = jsNontrivialString(vm, "Worker"_s);
    m_originalName.set(vm, this, nameString);
    putDirect(vm, vm.propertyNames->name, nameString, JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->prototype, JSWorker::prototype(vm, globalObject), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::DontDelete);
}

JSC_DEFINE_CUSTOM_GETTER(jsWorker_threadIdGetter, (JSGlobalObject * lexicalGlobalObject, JSC::EncodedJSValue thisValue, PropertyName))
{
    auto* castedThis = jsDynamicCast<JSWorker*>(JSValue::decode(thisValue));
    if (UNLIKELY(!castedThis))
        return JSValue::encode(jsUndefined());

    // Main thread starts at 1
    //
    // Note that we cannot use posix thread ids here because we don't know their thread id until the thread starts
    //
    return JSValue::encode(jsNumber(castedThis->wrapped().clientIdentifier() - 1));
}

/* Hash table for prototype */

static const HashTableValue JSWorkerPrototypeTableValues[] = {
    { "constructor"_s, static_cast<unsigned>(PropertyAttribute::DontEnum), NoIntrinsic, { HashTableValue::GetterSetterType, jsWorkerConstructor, 0 } },
    { "onerror"_s, JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute, NoIntrinsic, { HashTableValue::GetterSetterType, jsWorker_onerror, setJSWorker_onerror } },
    { "onmessage"_s, JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute, NoIntrinsic, { HashTableValue::GetterSetterType, jsWorker_onmessage, setJSWorker_onmessage } },
    { "onmessageerror"_s, JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute, NoIntrinsic, { HashTableValue::GetterSetterType, jsWorker_onmessageerror, setJSWorker_onmessageerror } },
    { "postMessage"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { HashTableValue::NativeFunctionType, jsWorkerPrototypeFunction_postMessage, 1 } },
    { "ref"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { HashTableValue::NativeFunctionType, jsWorkerPrototypeFunction_ref, 0 } },
    { "terminate"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { HashTableValue::NativeFunctionType, jsWorkerPrototypeFunction_terminate, 0 } },
    { "threadId"_s, JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontDelete, NoIntrinsic, { HashTableValue::GetterSetterType, jsWorker_threadIdGetter, nullptr } },
    { "unref"_s, static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { HashTableValue::NativeFunctionType, jsWorkerPrototypeFunction_unref, 0 } },
};

const ClassInfo JSWorkerPrototype::s_info = { "Worker"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSWorkerPrototype) };

void JSWorkerPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSWorker::info(), JSWorkerPrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSWorker::s_info = { "Worker"_s, &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSWorker) };

JSWorker::JSWorker(Structure* structure, JSDOMGlobalObject& globalObject, Ref<Worker>&& impl)
    : JSEventTarget(structure, globalObject, WTFMove(impl))
{
}

// static_assert(std::is_base_of<ActiveDOMObject, Worker>::value, "Interface is marked as [ActiveDOMObject] but implementation class does not subclass ActiveDOMObject.");

JSObject* JSWorker::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    auto* structure = JSWorkerPrototype::createStructure(vm, &globalObject, JSEventTarget::prototype(vm, globalObject));
    structure->setMayBePrototype(true);
    return JSWorkerPrototype::create(vm, &globalObject, structure);
}

JSObject* JSWorker::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSWorker>(vm, globalObject);
}

JSValue JSWorker::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSWorkerDOMConstructor, DOMConstructorID::Worker>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

JSC_DEFINE_CUSTOM_GETTER(jsWorkerConstructor, (JSGlobalObject * lexicalGlobalObject, JSC::EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSWorkerPrototype*>(JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSWorker::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

static inline JSValue jsWorker_onmessageGetter(JSGlobalObject& lexicalGlobalObject, JSWorker& thisObject)
{
    UNUSED_PARAM(lexicalGlobalObject);
    return eventHandlerAttribute(thisObject.wrapped(), eventNames().messageEvent, worldForDOMObject(thisObject));
}

JSC_DEFINE_CUSTOM_GETTER(jsWorker_onmessage, (JSGlobalObject * lexicalGlobalObject, JSC::EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSWorker>::get<jsWorker_onmessageGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

static inline bool setJSWorker_onmessageSetter(JSGlobalObject& lexicalGlobalObject, JSWorker& thisObject, JSValue value)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    UNUSED_PARAM(vm);
    setEventHandlerAttribute<JSEventListener>(thisObject.wrapped(), eventNames().messageEvent, value, thisObject);
    vm.writeBarrier(&thisObject, value);
    ensureStillAliveHere(value);

    return true;
}

JSC_DEFINE_CUSTOM_SETTER(setJSWorker_onmessage, (JSGlobalObject * lexicalGlobalObject, JSC::EncodedJSValue thisValue, JSC::EncodedJSValue encodedValue, PropertyName attributeName))
{
    return IDLAttribute<JSWorker>::set<setJSWorker_onmessageSetter>(*lexicalGlobalObject, thisValue, encodedValue, attributeName);
}

static inline JSValue jsWorker_onmessageerrorGetter(JSGlobalObject& lexicalGlobalObject, JSWorker& thisObject)
{
    UNUSED_PARAM(lexicalGlobalObject);
    return eventHandlerAttribute(thisObject.wrapped(), eventNames().messageerrorEvent, worldForDOMObject(thisObject));
}

JSC_DEFINE_CUSTOM_GETTER(jsWorker_onmessageerror, (JSGlobalObject * lexicalGlobalObject, JSC::EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSWorker>::get<jsWorker_onmessageerrorGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

static inline bool setJSWorker_onmessageerrorSetter(JSGlobalObject& lexicalGlobalObject, JSWorker& thisObject, JSValue value)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    UNUSED_PARAM(vm);
    setEventHandlerAttribute<JSEventListener>(thisObject.wrapped(), eventNames().messageerrorEvent, value, thisObject);
    vm.writeBarrier(&thisObject, value);
    ensureStillAliveHere(value);

    return true;
}

JSC_DEFINE_CUSTOM_SETTER(setJSWorker_onmessageerror, (JSGlobalObject * lexicalGlobalObject, JSC::EncodedJSValue thisValue, JSC::EncodedJSValue encodedValue, PropertyName attributeName))
{
    return IDLAttribute<JSWorker>::set<setJSWorker_onmessageerrorSetter>(*lexicalGlobalObject, thisValue, encodedValue, attributeName);
}

static inline JSValue jsWorker_onerrorGetter(JSGlobalObject& lexicalGlobalObject, JSWorker& thisObject)
{
    UNUSED_PARAM(lexicalGlobalObject);
    return eventHandlerAttribute(thisObject.wrapped(), eventNames().errorEvent, worldForDOMObject(thisObject));
}

JSC_DEFINE_CUSTOM_GETTER(jsWorker_onerror, (JSGlobalObject * lexicalGlobalObject, JSC::EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSWorker>::get<jsWorker_onerrorGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

static inline bool setJSWorker_onerrorSetter(JSGlobalObject& lexicalGlobalObject, JSWorker& thisObject, JSValue value)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    UNUSED_PARAM(vm);
    setEventHandlerAttribute<JSEventListener>(thisObject.wrapped(), eventNames().errorEvent, value, thisObject);
    vm.writeBarrier(&thisObject, value);
    ensureStillAliveHere(value);

    return true;
}

JSC_DEFINE_CUSTOM_SETTER(setJSWorker_onerror, (JSGlobalObject * lexicalGlobalObject, JSC::EncodedJSValue thisValue, JSC::EncodedJSValue encodedValue, PropertyName attributeName))
{
    return IDLAttribute<JSWorker>::set<setJSWorker_onerrorSetter>(*lexicalGlobalObject, thisValue, encodedValue, attributeName);
}

static inline JSC::EncodedJSValue jsWorkerPrototypeFunction_terminateBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSWorker>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.terminate(); })));
}

JSC_DEFINE_HOST_FUNCTION(jsWorkerPrototypeFunction_terminate, (JSGlobalObject * lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSWorker>::call<jsWorkerPrototypeFunction_terminateBody>(*lexicalGlobalObject, *callFrame, "terminate");
}

static inline JSC::EncodedJSValue jsWorkerPrototypeFunction_postMessage1Body(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSWorker>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto message = convert<IDLAny>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    EnsureStillAliveScope argument1 = callFrame->uncheckedArgument(1);
    auto transfer = convert<IDLSequence<IDLObject>>(*lexicalGlobalObject, argument1.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.postMessage(*jsCast<JSDOMGlobalObject*>(lexicalGlobalObject), WTFMove(message), WTFMove(transfer)); })));
}

static inline JSC::EncodedJSValue jsWorkerPrototypeFunction_postMessage2Body(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSWorker>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto message = convert<IDLAny>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    EnsureStillAliveScope argument1 = callFrame->argument(1);
    JSValue optionsValue = argument1.value();
    StructuredSerializeOptions options;
    if (optionsValue.isObject()) {
        JSObject* optionsObject = asObject(optionsValue);
        if (auto transferListValue = optionsObject->getIfPropertyExists(lexicalGlobalObject, Identifier::fromString(vm, "transfer"_s))) {
            auto transferList = convert<IDLSequence<IDLObject>>(*lexicalGlobalObject, transferListValue);
            RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
            options.transfer = WTFMove(transferList);
        }
    }

    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.postMessage(*jsCast<JSDOMGlobalObject*>(lexicalGlobalObject), WTFMove(message), WTFMove(options)); })));
}

static inline JSC::EncodedJSValue jsWorkerPrototypeFunction_postMessageOverloadDispatcher(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSWorker>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    size_t argsCount = std::min<size_t>(2, callFrame->argumentCount());
    if (argsCount == 1) {
        RELEASE_AND_RETURN(throwScope, (jsWorkerPrototypeFunction_postMessage2Body(lexicalGlobalObject, callFrame, castedThis)));
    }
    if (argsCount == 2) {
        JSValue distinguishingArg = callFrame->uncheckedArgument(1);
        if (distinguishingArg.isUndefined())
            RELEASE_AND_RETURN(throwScope, (jsWorkerPrototypeFunction_postMessage2Body(lexicalGlobalObject, callFrame, castedThis)));
        if (distinguishingArg.isUndefinedOrNull())
            RELEASE_AND_RETURN(throwScope, (jsWorkerPrototypeFunction_postMessage2Body(lexicalGlobalObject, callFrame, castedThis)));
        {
            bool success = hasIteratorMethod(lexicalGlobalObject, distinguishingArg);
            RETURN_IF_EXCEPTION(throwScope, {});
            if (success)
                RELEASE_AND_RETURN(throwScope, (jsWorkerPrototypeFunction_postMessage1Body(lexicalGlobalObject, callFrame, castedThis)));
        }
        if (distinguishingArg.isObject())
            RELEASE_AND_RETURN(throwScope, (jsWorkerPrototypeFunction_postMessage2Body(lexicalGlobalObject, callFrame, castedThis)));
    }
    return argsCount < 1 ? throwVMError(lexicalGlobalObject, throwScope, createNotEnoughArgumentsError(lexicalGlobalObject)) : throwVMTypeError(lexicalGlobalObject, throwScope);
}

JSC_DEFINE_HOST_FUNCTION(jsWorkerPrototypeFunction_postMessage, (JSGlobalObject * lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSWorker>::call<jsWorkerPrototypeFunction_postMessageOverloadDispatcher>(*lexicalGlobalObject, *callFrame, "postMessage");
}

static inline JSC::EncodedJSValue jsWorkerPrototypeFunction_refBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSWorker>::ClassParameter castedThis)
{
    castedThis->wrapped().setKeepAlive(true);
    return JSValue::encode(jsUndefined());
}

JSC_DEFINE_HOST_FUNCTION(jsWorkerPrototypeFunction_ref, (JSGlobalObject * lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSWorker>::call<jsWorkerPrototypeFunction_refBody>(*lexicalGlobalObject, *callFrame, "ref");
}

static inline JSC::EncodedJSValue jsWorkerPrototypeFunction_unrefBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSWorker>::ClassParameter castedThis)
{
    castedThis->wrapped().setKeepAlive(false);
    return JSValue::encode(jsUndefined());
}

JSC_DEFINE_HOST_FUNCTION(jsWorkerPrototypeFunction_unref, (JSGlobalObject * lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSWorker>::call<jsWorkerPrototypeFunction_unrefBody>(*lexicalGlobalObject, *callFrame, "unref");
}

JSC::GCClient::IsoSubspace* JSWorker::subspaceForImpl(JSC::VM& vm)
{
    return WebCore::subspaceForImpl<JSWorker, UseCustomHeapCellType::No>(
        vm,
        [](auto& spaces) { return spaces.m_clientSubspaceForWorker.get(); },
        [](auto& spaces, auto&& space) { spaces.m_clientSubspaceForWorker = std::forward<decltype(space)>(space); },
        [](auto& spaces) { return spaces.m_subspaceForWorker.get(); },
        [](auto& spaces, auto&& space) { spaces.m_subspaceForWorker = std::forward<decltype(space)>(space); });
}

void JSWorker::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSWorker*>(cell);
    analyzer.setWrappedObjectForCell(cell, &thisObject->wrapped());
    if (thisObject->scriptExecutionContext())
        analyzer.setLabelForCell(cell, makeString("url "_s, thisObject->scriptExecutionContext()->url().string()));
    Base::analyzeHeap(cell, analyzer);
}

bool JSWorkerOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, AbstractSlotVisitor& visitor, ASCIILiteral* reason)
{
    auto* jsWorker = jsCast<JSWorker*>(handle.slot()->asCell());
    auto& wrapped = jsWorker->wrapped();
    if (!wrapped.isContextStopped() && wrapped.hasPendingActivity()) {
        if (UNLIKELY(reason))
            *reason = "ActiveDOMObject with pending activity"_s;
        return true;
    }
    UNUSED_PARAM(visitor);
    UNUSED_PARAM(reason);
    return false;
}

void JSWorkerOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    auto* jsWorker = static_cast<JSWorker*>(handle.slot()->asCell());
    auto& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsWorker->wrapped(), jsWorker);
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable : 4483)
extern "C" {
extern void (*const __identifier("??_7Worker@WebCore@@6B@")[])();
}
#else
extern "C" {
extern void* _ZTVN7WebCore6WorkerE[];
}
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::JSGlobalObject*, JSDOMGlobalObject* globalObject, Ref<Worker>&& impl)
{

    if constexpr (std::is_polymorphic_v<Worker>) {
#if ENABLE(BINDING_INTEGRITY)
        // const void* actualVTablePointer = getVTablePointer(impl.ptr());
#if PLATFORM(WIN)
        void* expectedVTablePointer = __identifier("??_7Worker@WebCore@@6B@");
#else
        // void* expectedVTablePointer = &_ZTVN7WebCore6WorkerE[2];
#endif

        // If you hit this assertion you either have a use after free bug, or
        // Worker has subclasses. If Worker has subclasses that get passed
        // to toJS() we currently require Worker you to opt out of binding hardening
        // by adding the SkipVTableValidation attribute to the interface IDL definition
        // RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    }
    return createWrapper<Worker>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::JSGlobalObject* lexicalGlobalObject, JSDOMGlobalObject* globalObject, Worker& impl)
{
    return wrap(lexicalGlobalObject, globalObject, impl);
}

Worker* JSWorker::toWrapped(JSC::VM&, JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicCast<JSWorker*>(value))
        return &wrapper->wrapped();
    return nullptr;
}
}
