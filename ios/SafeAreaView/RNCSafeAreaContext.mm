#import "RNCSafeAreaContext.h"

#import <SafeAreaContextSpec/SafeAreaContextSpec.h>
#import <UIKit/UIKit.h>

using namespace facebook::react;

@interface RNCSafeAreaContext () <NativeSafeAreaContextSpec>
@end

@implementation RNCSafeAreaContext

RCT_EXPORT_MODULE()

+ (BOOL)requiresMainQueueSetup
{
  return YES;
}

- (NSDictionary *)constantsToExport
{
  return [self getConstants];
}

- (NSDictionary *)getConstants
{
  UIWindow *window = [[UIApplication sharedApplication] keyWindow];
  if (@available(iOS 11.0, *)) {
    UIEdgeInsets safeAreaInsets = window.safeAreaInsets;
    return @{
      @"initialWindowMetrics" : @{
        @"insets" : @{
          @"top" : @(safeAreaInsets.top),
          @"right" : @(safeAreaInsets.right),
          @"bottom" : @(safeAreaInsets.bottom),
          @"left" : @(safeAreaInsets.left),
        },
        @"frame" : @{
          @"x" : @(window.frame.origin.x),
          @"y" : @(window.frame.origin.y),
          @"width" : @(window.frame.size.width),
          @"height" : @(window.frame.size.height),
        },
      }
    };
  } else {
    return @{
      @"initialWindowMetrics" : @{
        @"insets" : @{
          @"top" : @(20),
          @"right" : @(0),
          @"bottom" : @(0),
          @"left" : @(0),
        },
        @"frame" : @{
          @"x" : @(window.frame.origin.x),
          @"y" : @(window.frame.origin.y),
          @"width" : @(window.frame.size.width),
          @"height" : @(window.frame.size.height),
        },
      }
    };
  }
}

- (std::shared_ptr<TurboModule>)getTurboModule:(const ObjCTurboModule::InitParams &)params
{
  return std::make_shared<NativeSafeAreaContextSpecJSI>(params);
}

@end

