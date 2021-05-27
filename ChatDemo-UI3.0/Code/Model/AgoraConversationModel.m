/************************************************************
 *  * Hyphenate
 * __________________
 * Copyright (C) 2016 Hyphenate Inc. All rights reserved.
 *
 * NOTICE: All information contained herein is, and remains
 * the property of Hyphenate Inc.
 */

#import "AgoraConversationModel.h"


@implementation AgoraConversationModel

- (instancetype)initWithConversation:(AgoraConversation*)conversation
{
    self = [super init];
    if (self) {
        _conversation = conversation;
        
        NSString *subject = [conversation.ext objectForKey:@"subject"];
        if ([subject length] > 0) {
            _title = subject;
        }
        
        if (_conversation.type == AgoraConversationTypeGroupChat) {
            NSArray *groups = [[AgoraChatClient sharedClient].groupManager getJoinedGroups];
            for (AgoraGroup *group in groups) {
                if ([_conversation.conversationId isEqualToString:group.groupId]) {
                    _title = group.subject;
                    break;
                }
            }
        }
        
        if (_conversation.type == AgoraConversationTypeChat) {
            dispatch_async(dispatch_get_global_queue(0, 0), ^{
                [[AgoraChatClient sharedClient].userInfoManager fetchUserInfoById:@[_conversation.conversationId] completion:^(NSDictionary *aUserDatas, AgoraError *aError) {
                    dispatch_async(dispatch_get_main_queue(), ^{
                        AgoraUserInfo *userInfo = aUserDatas[_conversation.conversationId];
                        _title = userInfo.nickName;
                    });
                }];
            });
        }
        
        if ([_title length] == 0) {
            _title = _conversation.conversationId;
        }
    }
    return self;
}



@end
