#pragma once

#include <react/renderer/components/safeareacontext/Props.h>
#include <react/renderer/graphics/Geometry.h>
#include <vector>

#ifdef ANDROID
#include <folly/dynamic.h>
#include <react/renderer/mapbuffer/MapBuffer.h>
#include <react/renderer/mapbuffer/MapBufferBuilder.h>
#endif

namespace facebook {
namespace react {

#ifdef ANDROID
inline EdgeInsets edgeInsetsFromDynamic(const folly::dynamic &value) {
  return EdgeInsets{
      .left = (float)value["left"].getDouble(),
      .top = (float)value["top"].getDouble(),
      .right = (float)value["right"].getDouble(),
      .bottom = (float)value["bottom"].getDouble(),
  };
}

inline std::vector<std::string> vectorFromDynamic(const folly::dynamic &value) {
  std::vector<std::string> edges;
  for (const auto &edge : value) {
    edges.push_back(edge.getString());
  }
  return edges;
}

inline RNCSafeAreaViewMode modeFromDynamic(const folly::dynamic &value) {
  const std::string &mode = value.getString();
  if (mode == "margin") {
    return RNCSafeAreaViewMode::Margin;
  } else {
    return RNCSafeAreaViewMode::Padding;
  }
}
#endif

/*
 * State for <SafeAreaView> component.
 */
class SafeAreaViewState final {
 public:
  using Shared = std::shared_ptr<const SafeAreaViewState>;

  SafeAreaViewState(){};

#ifdef ANDROID
  SafeAreaViewState(SafeAreaViewState const &previousState, folly::dynamic data)
      : insets(edgeInsetsFromDynamic(data["insets"])),
        mode(modeFromDynamic(data["mode"])),
        edges(vectorFromDynamic(data["edges"])){};
#endif

  EdgeInsets insets{};
  RNCSafeAreaViewMode mode{RNCSafeAreaViewMode::Padding};
  // TODO: This could be a bitmask.
  std::vector<std::string> edges{};

#ifdef ANDROID
  folly::dynamic getDynamic() const;
  MapBuffer getMapBuffer() const {
    return MapBufferBuilder::EMPTY();
  };

#endif
};

} // namespace react
} // namespace facebook
