//
//  YMURLSessionTask.h
//  YMHTTP
//
//  Created by zymxxxs on 2020/2/5.
//

#import <Foundation/Foundation.h>

@class YMURLSession;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, YMURLSessionTaskState) {
    YMURLSessionTaskStateRunning = 0,
    YMURLSessionTaskStateSuspended = 1,
    YMURLSessionTaskStateCanceling = 2,
    YMURLSessionTaskStateCompleted = 3,
};

@interface YMURLSessionTask : NSObject

@property (readonly) NSUInteger taskIdentifier;
@property (nullable, readonly, copy) NSURLRequest *originalRequest;
@property (nullable, readonly, copy) NSURLRequest *currentRequest;
@property (nullable, readonly, copy) NSURLResponse *response;
@property (readonly) YMURLSessionTaskState state;

- (instancetype)initWithSession:(YMURLSession *)session
                        reqeust:(NSURLRequest *)request
                 taskIdentifier:(NSUInteger)taskIdentifier;

- (instancetype)initWithSession:(YMURLSession *)session
                        reqeust:(NSURLRequest *)request
                 taskIdentifier:(NSUInteger)taskIdentifier
                           body:(NSString *)body;

- (void)suspend;
- (void)resume;

- (instancetype)init __attribute__((unavailable(
    "Please use NSURLSessionConfiguration.defaultSessionConfiguration or other class methods to create instances")));
+ (instancetype)new __attribute__((unavailable(
    "Please use NSURLSessionConfiguration.defaultSessionConfiguration or other class methods to create instances")));

@end

NS_ASSUME_NONNULL_END
