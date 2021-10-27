//
//  AgoraChatNewContactsViewController.h
//  ChatDemo-UI3.0
//
//  Created by liang on 2021/10/19.
//  Copyright © 2021 easemob. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ACDNewContactsViewController : UIViewController

- (void)loadContactsFromServer;

- (void)reloadContacts;

- (void)reloadContactRequests;

- (void)reloadGroupNotifications;

@end

NS_ASSUME_NONNULL_END
