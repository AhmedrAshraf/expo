/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#import <ABI46_0_0React/ABI46_0_0RCTFileReaderModule.h>

#import <ABI46_0_0FBReactNativeSpec/ABI46_0_0FBReactNativeSpec.h>
#import <ABI46_0_0React/ABI46_0_0RCTBridge.h>
#import <ABI46_0_0React/ABI46_0_0RCTConvert.h>

#import <ABI46_0_0React/ABI46_0_0RCTBlobManager.h>

#import "ABI46_0_0RCTBlobPlugins.h"

@interface ABI46_0_0RCTFileReaderModule() <ABI46_0_0NativeFileReaderModuleSpec>
@end

@implementation ABI46_0_0RCTFileReaderModule

ABI46_0_0RCT_EXPORT_MODULE(FileReaderModule)

@synthesize moduleRegistry = _moduleRegistry;

ABI46_0_0RCT_EXPORT_METHOD(readAsText:(NSDictionary<NSString *, id> *)blob
                  encoding:(NSString *)encoding
                  resolve:(ABI46_0_0RCTPromiseResolveBlock)resolve
                  reject:(ABI46_0_0RCTPromiseRejectBlock)reject)
{
  ABI46_0_0RCTBlobManager *blobManager = [_moduleRegistry moduleForName:"BlobModule"];
  NSData *data = [blobManager resolve:blob];

  if (data == nil) {
    reject(ABI46_0_0RCTErrorUnspecified,
           [NSString stringWithFormat:@"Unable to resolve data for blob: %@", [ABI46_0_0RCTConvert NSString:blob[@"blobId"]]], nil);
  } else {
    NSStringEncoding stringEncoding;

    if (encoding == nil) {
      stringEncoding = NSUTF8StringEncoding;
    } else {
      stringEncoding = CFStringConvertEncodingToNSStringEncoding(CFStringConvertIANACharSetNameToEncoding((CFStringRef) encoding));
    }

    NSString *text = [[NSString alloc] initWithData:data encoding:stringEncoding];

    resolve(text);
  }
}

ABI46_0_0RCT_EXPORT_METHOD(readAsDataURL:(NSDictionary<NSString *, id> *)blob
                  resolve:(ABI46_0_0RCTPromiseResolveBlock)resolve
                  reject:(ABI46_0_0RCTPromiseRejectBlock)reject)
{
  ABI46_0_0RCTBlobManager *blobManager = [_moduleRegistry moduleForName:"BlobModule"];
  NSData *data = [blobManager resolve:blob];

  if (data == nil) {
    reject(ABI46_0_0RCTErrorUnspecified,
           [NSString stringWithFormat:@"Unable to resolve data for blob: %@", [ABI46_0_0RCTConvert NSString:blob[@"blobId"]]], nil);
  } else {
    NSString *type = [ABI46_0_0RCTConvert NSString:blob[@"type"]];
    NSString *text = [NSString stringWithFormat:@"data:%@;base64,%@",
                      type != nil && [type length] > 0 ? type : @"application/octet-stream",
                      [data base64EncodedStringWithOptions:0]];

    resolve(text);
  }
}

- (std::shared_ptr<ABI46_0_0facebook::ABI46_0_0React::TurboModule>)getTurboModule:(const ABI46_0_0facebook::ABI46_0_0React::ObjCTurboModule::InitParams &)params
{
  return std::make_shared<ABI46_0_0facebook::ABI46_0_0React::NativeFileReaderModuleSpecJSI>(params);
}

@end

Class ABI46_0_0RCTFileReaderModuleCls(void)
{
  return ABI46_0_0RCTFileReaderModule.class;
}
