//
//  XYZToDoItem.h
//  ToDoList
//
//  Created by Nandini  on 8/19/14.
//
//

#import <Foundation/Foundation.h>

@interface XYZToDoItem : NSObject

@property NSString *itemName;
@property BOOL completed;
@property (readonly) NSDate *creationDate;

@end
