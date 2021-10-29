//
//  ACDGroupMemberAllViewController.h
//  ChatDemo-UI3.0
//
//  Created by liang on 2021/10/29.
//  Copyright © 2021 easemob. All rights reserved.
//

#import "AgoraSearchTableViewController.h"
#import "ACDContainerSearchTableViewController.h"

NS_ASSUME_NONNULL_BEGIN
@class AgoraUserModel;

@interface ACDGroupMemberAllViewController : ACDContainerSearchTableViewController

- (instancetype)initWithGroupId:(NSString *)aGroupId;

@end

NS_ASSUME_NONNULL_END
