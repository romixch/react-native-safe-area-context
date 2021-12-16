#include "ExampleModuleProvider.h"

#include <rncore.h>
#include <safeareacontext.h>

namespace com {
namespace example {

using namespace facebook::react;

std::shared_ptr<TurboModule> ExampleModuleProvider(
    const std::string moduleName,
    const JavaTurboModule::InitParams &params) {
  auto module = safeareacontext_ModuleProvider(moduleName, params);
  if (module != nullptr) {
    return module;
  }

  return rncore_ModuleProvider(moduleName, params);
}

} // namespace example
} // namespace com
