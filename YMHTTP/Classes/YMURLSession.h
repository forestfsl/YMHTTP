//
//  YMURLSession.h
//  YMHTTP
//
//  Created by zymxxxs on 2020/2/3.
//

#import <Foundation/Foundation.h>
#import "YMURLSessionDelegate.h"

@class YMURLSessionConfiguration;
@class YMURLSessionTaskBehaviour;
@class YMURLSessionTask;

NS_ASSUME_NONNULL_BEGIN

@interface YMURLSession : NSObject

/// The shared session uses the currently set global NSURLCache,
/// NSHTTPCookieStorage and NSURLCredentialStorage objects.
@property (class, readonly, strong) YMURLSession *sharedSession;

+ (YMURLSession *)sessionWithConfiguration:(YMURLSessionConfiguration *)configuration;

+ (YMURLSession *)sessionWithConfiguration:(YMURLSessionConfiguration *)configuration
                                  delegate:(nullable id<YMURLSessionDelegate>)delegate
                             delegateQueue:(nullable NSOperationQueue *)queue;

@property (readonly, strong) NSOperationQueue *delegateQueue;
@property (nullable, readonly, strong) id<YMURLSessionDelegate> delegate;
@property (readonly, copy) YMURLSessionConfiguration *configuration;
@property (nullable, copy) NSString *sessionDescription;
@property (readonly, nonatomic, strong) dispatch_queue_t workQueue;

- (YMURLSessionTask *)dataTaskWithRequest:(NSURLRequest *)request;

- (YMURLSessionTask *)dataTaskWithURL:(NSURL *)url;

// TODO: dataTask
//- (YMURLSessionTask *)dataTaskWithRequest:(NSURLRequest *)request
//                        completionHandler:(void (^)(NSData *_Nullable data,
//                                                    NSURLResponse *_Nullable response,
//                                                    NSError *_Nullable error))completionHandler;
//
//- (YMURLSessionTask *)dataTaskWithURL:(NSURL *)url
//                    completionHandler:(void (^)(NSData *_Nullable data,
//                                                NSURLResponse *_Nullable response,
//                                                NSError *_Nullable error))completionHandler;

- (YMURLSessionTaskBehaviour *)behaviourForTask:(YMURLSessionTask *)task;

- (instancetype)init __attribute__((unavailable(
    "Please use NSURLSessionConfiguration.defaultSessionConfiguration or other class methods to create instances")));
+ (instancetype)new __attribute__((unavailable(
    "Please use NSURLSessionConfiguration.defaultSessionConfiguration or other class methods to create instances")));

@end

NS_ASSUME_NONNULL_END