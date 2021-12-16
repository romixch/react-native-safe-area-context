#include "ExampleTurboModuleManagerDelegate.h"
#include "ExampleModuleProvider.h"

namespace com {
namespace example {

using namespace facebook::react;

jni::local_ref<ExampleTurboModuleManagerDelegate::jhybriddata> ExampleTurboModuleManagerDelegate::initHybrid(jni::alias_ref<jhybridobject>) {
  return makeCxxInstance();
}

void ExampleTurboModuleManagerDelegate::registerNatives() {
  registerHybrid({
    makeNativeMethod("initHybrid", ExampleTurboModuleManagerDelegate::initHybrid),
  });
}

std::shared_ptr<TurboModule> ExampleTurboModuleManagerDelegate::getTurboModule(const std::string name, const std::shared_ptr<CallInvoker> jsInvoker) {
  return nullptr;
}

std::shared_ptr<TurboModule> ExampleTurboModuleManagerDelegate::getTurboModule(const std::string name, const JavaTurboModule::InitParams &params) {
  return ExampleModuleProvider(name, params);
}

} // namespace example
} // namespace com
