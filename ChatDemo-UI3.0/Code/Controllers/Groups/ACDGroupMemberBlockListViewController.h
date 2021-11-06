//
//  ACDGroupMemberBlockViewController.h
//  ChatDemo-UI3.0
//
//  Created by liang on 2021/10/29.
//  Copyright © 2021 easemob. All rights reserved.
//

#import "AgoraSearchTableViewController.h"
#import "ACDContainerSearchTableViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface ACDGroupMemberBlockListViewController : ACDContainerSearchTableViewController

- (instancetype)initWithGroup:(AgoraChatGroup *)aGroup;

@end

NS_ASSUME_NONNULL_END
