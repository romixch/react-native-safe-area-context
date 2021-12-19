#include "SafeAreaViewState.h"

namespace facebook {
namespace react {

#ifdef ANDROID

folly::dynamic SafeAreaViewState::getDynamic() const {
  folly::dynamic insetsValue = folly::dynamic::object();
  insetsValue["top"] = insets.top;
  insetsValue["left"] = insets.left;
  insetsValue["bottom"] = insets.bottom;
  insetsValue["right"] = insets.right;

  folly::dynamic edgesValue = folly::dynamic::array();
  for (auto const &edge : edges) {
    edgesValue.push_back(edge);
  }

  folly::dynamic data = folly::dynamic::object();
  data["insets"] = insetsValue;
  data["edges"] = edgesValue;
  data["mode"] = toString(mode);

  return data;
}
#endif

} // namespace react
} // namespace facebook
