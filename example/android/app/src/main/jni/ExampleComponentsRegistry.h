#pragma once

#include <ComponentFactory.h>
#include <fbjni/fbjni.h>
#include <react/renderer/componentregistry/ComponentDescriptorProviderRegistry.h>
#include <react/renderer/componentregistry/ComponentDescriptorRegistry.h>

namespace com {
namespace example {

using namespace facebook::react;

class ExampleComponentsRegistry
    : public facebook::jni::HybridClass<ExampleComponentsRegistry> {
  public:
  constexpr static auto kJavaDescriptor =
      "Lcom/example/ExampleComponentsRegistry;";

  static void registerNatives();

  ExampleComponentsRegistry(ComponentFactory *delegate);

  private:
  friend HybridBase;

  static std::shared_ptr<ComponentDescriptorProviderRegistry const>
  sharedProviderRegistry();

  const ComponentFactory *delegate_;

  static jni::local_ref<jhybriddata> initHybrid(
      jni::alias_ref<jclass>,
      ComponentFactory *delegate);
};

} // namespace example
} // namespace com
