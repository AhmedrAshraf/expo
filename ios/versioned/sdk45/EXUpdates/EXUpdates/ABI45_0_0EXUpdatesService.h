// Copyright 2020-present 650 Industries. All rights reserved.

#import <ABI45_0_0EXUpdates/ABI45_0_0EXUpdatesConfig.h>
#import <ABI45_0_0EXUpdates/ABI45_0_0EXUpdatesDatabase.h>
#import <ABI45_0_0EXUpdates/ABI45_0_0EXUpdatesSelectionPolicy.h>
#import <ABI45_0_0EXUpdates/ABI45_0_0EXUpdatesUpdate.h>
#import <ABI45_0_0ExpoModulesCore/ABI45_0_0EXInternalModule.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^ABI45_0_0EXUpdatesAppRelaunchCompletionBlock)(BOOL success);

@protocol ABI45_0_0EXUpdatesModuleInterface

@property (nonatomic, readonly) ABI45_0_0EXUpdatesConfig *config;
@property (nonatomic, readonly) ABI45_0_0EXUpdatesDatabase *database;
@property (nonatomic, readonly) ABI45_0_0EXUpdatesSelectionPolicy *selectionPolicy;
@property (nonatomic, readonly) NSURL *directory;

@property (nullable, nonatomic, readonly, strong) ABI45_0_0EXUpdatesUpdate *embeddedUpdate;
@property (nullable, nonatomic, readonly, strong) ABI45_0_0EXUpdatesUpdate *launchedUpdate;
@property (nullable, nonatomic, readonly, strong) NSDictionary *assetFilesMap;
@property (nonatomic, readonly, assign) BOOL isUsingEmbeddedAssets;
@property (nonatomic, readonly, assign) BOOL isStarted;
@property (nonatomic, readonly, assign) BOOL isEmergencyLaunch;
@property (nonatomic, readonly, assign) BOOL canRelaunch;

- (void)requestRelaunchWithCompletion:(ABI45_0_0EXUpdatesAppRelaunchCompletionBlock)completion;
- (void)resetSelectionPolicy;

@end

@interface ABI45_0_0EXUpdatesService : NSObject <ABI45_0_0EXInternalModule, ABI45_0_0EXUpdatesModuleInterface>

@end

NS_ASSUME_NONNULL_END
