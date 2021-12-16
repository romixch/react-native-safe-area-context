#include <memory>
#include <string>

#include <ReactCommon/TurboModuleManagerDelegate.h>
#include <fbjni/fbjni.h>

namespace com {
namespace example {

using namespace facebook::react;

class ExampleTurboModuleManagerDelegate : public jni::HybridClass<ExampleTurboModuleManagerDelegate, TurboModuleManagerDelegate> {
public:
  static constexpr auto kJavaDescriptor =
      "Lcom/example/ExampleTurboModuleManagerDelegate;";

  static jni::local_ref<jhybriddata> initHybrid(jni::alias_ref<jhybridobject>);

  static void registerNatives();

  std::shared_ptr<TurboModule> getTurboModule(const std::string name, const std::shared_ptr<CallInvoker> jsInvoker) override;
  std::shared_ptr<TurboModule> getTurboModule(const std::string name, const JavaTurboModule::InitParams &params) override;

private:
  friend HybridBase;
  using HybridBase::HybridBase;

};

} // namespace example
} // namespace com
