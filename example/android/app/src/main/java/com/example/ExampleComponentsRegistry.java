package com.example;

import com.facebook.jni.HybridData;
import com.facebook.proguard.annotations.DoNotStrip;
import com.facebook.react.fabric.ComponentFactory;
import com.facebook.soloader.SoLoader;

@DoNotStrip
public class ExampleComponentsRegistry {
  static {
    SoLoader.loadLibrary("fabricjni");
  }

  @DoNotStrip private final HybridData mHybridData;

  @DoNotStrip
  private native HybridData initHybrid(ComponentFactory componentFactory);

  @DoNotStrip
  private ExampleComponentsRegistry(ComponentFactory componentFactory) {
    mHybridData = initHybrid(componentFactory);
  }

  @DoNotStrip
  public static ExampleComponentsRegistry register(ComponentFactory componentFactory) {
    return new ExampleComponentsRegistry(componentFactory);
  }
}
