#include "ExampleComponentsRegistry.h"

#include <CoreComponentsRegistry.h>
#include <fbjni/fbjni.h>
#include <react/renderer/componentregistry/ComponentDescriptorProviderRegistry.h>
#include <react/renderer/components/rncore/ComponentDescriptors.h>
#include <react/renderer/components/safeareacontext/ComponentDescriptors.h>

namespace com {
namespace example {

using namespace facebook::react;

ExampleComponentsRegistry::ExampleComponentsRegistry(ComponentFactory *delegate)
    : delegate_(delegate) {}

std::shared_ptr<ComponentDescriptorProviderRegistry const>
ExampleComponentsRegistry::sharedProviderRegistry() {
  auto providerRegistry = CoreComponentsRegistry::sharedProviderRegistry();

  providerRegistry->add(concreteComponentDescriptorProvider<
                        RNCSafeAreaProviderComponentDescriptor>());

  return providerRegistry;
}

jni::local_ref<ExampleComponentsRegistry::jhybriddata>
ExampleComponentsRegistry::initHybrid(
    jni::alias_ref<jclass>,
    ComponentFactory *delegate) {
  auto instance = makeCxxInstance(delegate);

  auto buildRegistryFunction =
      [](EventDispatcher::Weak const &eventDispatcher,
         ContextContainer::Shared const &contextContainer)
      -> ComponentDescriptorRegistry::Shared {
    auto registry = ExampleComponentsRegistry::sharedProviderRegistry()
                        ->createComponentDescriptorRegistry(
                            {eventDispatcher, contextContainer});

    auto mutableRegistry =
        std::const_pointer_cast<ComponentDescriptorRegistry>(registry);

    mutableRegistry->setFallbackComponentDescriptor(
        std::make_shared<UnimplementedNativeViewComponentDescriptor>(
            ComponentDescriptorParameters{
                eventDispatcher, contextContainer, nullptr}));

    return registry;
  };

  delegate->buildRegistryFunction = buildRegistryFunction;
  return instance;
}

void ExampleComponentsRegistry::registerNatives() {
  registerHybrid({
      makeNativeMethod("initHybrid", ExampleComponentsRegistry::initHybrid),
  });
}

} // namespace example
} // namespace com
