#pragma once

#include <react/renderer/components/safeareacontext/EventEmitters.h>
#include <react/renderer/components/safeareacontext/Props.h>
#include <react/renderer/components/safeareacontext/SafeAreaViewState.h>
#include <react/renderer/components/view/ConcreteViewShadowNode.h>

namespace facebook {
namespace react {

extern const char RNCSafeAreaViewComponentName[];

/*
 * `ShadowNode` for <SafeAreaView> component.
 */
class SafeAreaViewShadowNode final : public ConcreteViewShadowNode<
                                         RNCSafeAreaViewComponentName,
                                         RNCSafeAreaViewProps,
                                         ViewEventEmitter,
                                         SafeAreaViewState> {
  using ConcreteViewShadowNode::ConcreteViewShadowNode;

 public:
  static ShadowNodeTraits BaseTraits() {
    auto traits = ConcreteViewShadowNode::BaseTraits();
    traits.set(ShadowNodeTraits::Trait::DirtyYogaNode);
    return traits;
  }

  void adjustLayoutWithState();
};

} // namespace react
} // namespace facebook
