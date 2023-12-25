#include <node.h>
#include <v8.h>

extern "C" NODE_MODULE_EXPORT void
NODE_MODULE_INITIALIZER(v8::Local<v8::Object> exports,
                        v8::Local<v8::Value> module,
                        v8::Local<v8::Context> context) {
}

static void FakeInit(v8::Local<v8::Object> exports,
                     v8::Local<v8::Value> module,
                     v8::Local<v8::Context> context) {
  auto isolate = context->GetIsolate();
  auto exception = v8::Exception::Error(v8::String::NewFromUtf8(isolate,
      "FakeInit should never run!").ToLocalChecked());
  isolate->ThrowException(exception);
}

#undef NODE_MODULE_VERSION
#define NODE_MODULE_VERSION 3
NODE_MODULE(NODE_GYP_MODULE_NAME, FakeInit)