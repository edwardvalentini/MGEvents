//
//  Created by matt on 24/09/12.
//

#import "MGBlockWrapper.h"

/**
* Provides lightweight, blocks based keypath observing and custom events.
*/

@interface NSObject (MGEvents)

/** @name Custom event observing */

@property (nonatomic, retain) NSMutableDictionary *MGEventHandlers;

/**
When a custom event is triggered with the given name, perform the given block.

    [earth on:@"ChangedShape" do:^{
        NSLog(@"the earth has changed shape");
    }];
*/
- (void)on:(NSString *)eventName do:(MGBlock)handler;

/**
* When a custom event is triggered with the given name, perform the given block
* once. The block will not be performed on future triggering of the same event.
*/
- (void)on:(NSString *)eventName doOnce:(MGBlock)handler;

/**
When a custom event is triggered with the given name, perform the given block.
The block may potentially be provided a context object.

    [earth on:@"ChangedShape" doWithContext:^(id context) {
        NSLog(@"the earth has changed shape.");
        NSLog(@"some details about the shape change: %@", context);
    }];
*/
- (void)on:(NSString *)eventName doWithContext:(MGBlockWithContext)handler;

- (void)when:(id)object does:(NSString *)eventName do:(MGBlock)handler;
- (void)when:(id)object does:(NSString *)eventName doWithContext:(MGBlockWithContext)handler;

/** @name Custom event triggering */

/**
Trigger a custom event.

    [earth trigger:@"ChangedShape"];
*/
- (void)trigger:(NSString *)eventName;

/**
Trigger a custom event, providing context.

    [earth trigger:@"ChangedShape" withContext:@{ @"newShape": @"flat" }];
*/
- (void)trigger:(NSString *)eventName withContext:(id)context;

/** @name Keypath observing */

@property (nonatomic, retain) NSMutableDictionary *MGObservers;

/**
On change of the given keypath, perform the given block.

    [box onChangeOf:@"selected" do:^{
        NSLog(@"my selected state changed to: %@", box.selected ? @"ON" : @"OFF");
    }];
*/
- (void)onChangeOf:(NSString *)keypath do:(MGBlock)block;

/**
On change of any of the given keypaths, perform the given block.

    [box onChangeOfAny:@[@"selected", @"highlighted"] do:^{
        NSLog(@"my selected state is: %@", box.selected ? @"ON" : @"OFF");
        NSLog(@"my highlighted state is: %@", box.highlighted ? @"ON" : @"OFF");
    }];
*/
- (void)onChangeOfAny:(NSArray *)keypaths do:(MGBlock)block;

@property (nonatomic, copy) MGBlock onDealloc;

@end
