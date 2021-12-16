#pragma once

#include <memory>
#include <string>

#include <ReactCommon/JavaTurboModule.h>

namespace com {
namespace example {

using namespace facebook::react;

std::shared_ptr<TurboModule> ExampleModuleProvider(const std::string moduleName, const JavaTurboModule::InitParams &params);

} // namespace example
} // namespace com
