#include <fbjni/fbjni.h>
#include "ExampleTurboModuleManagerDelegate.h"
#include "ExampleComponentsRegistry.h"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *) {
  return facebook::jni::initialize(vm, [] {
    com::example::ExampleTurboModuleManagerDelegate::registerNatives();
    com::example::ExampleComponentsRegistry::registerNatives();
  });
}
