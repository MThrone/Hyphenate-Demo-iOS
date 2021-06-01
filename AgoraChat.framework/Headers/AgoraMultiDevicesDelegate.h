/*!
 *  \~chinese
 *  @header AgoraMultiDevicesDelegate.h
 *  @abstract 多设备回调
 *  @author Hyphenate
 *  @version 3.00
 *
 *  \~english
 *  @header AgoraMultiDevicesDelegate.h
 *  @abstract This protocol defined the callbacks of Multi-device
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

/*!
 *  \~chinese
 *  多设备事件类型
 *  用户UserA，登录2台机子DeviceA1和DeviceA2，另有一个用户UserB
 *
 *  \~english
 *  Multi-device event type
 *  User UserA logged into two devices DeviceA1 and DeviceA2 with another user UserB
 */
typedef NS_ENUM(NSInteger, AgoraMultiDevicesEvent) {
    AgoraMultiDevicesEventUnknow = -1,         /*! \~chinese 默认 \~english Default */
    AgoraMultiDevicesEventContactRemove = 2,   /*! \~chinese UserB和UserA是好友，UserA在DeviceA1上删除了UserB，DeviceA2会收到该回调 \~english UserB and UserA are friends, UserA removed UserB on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventContactAccept = 3,   /*! \~chinese UserB向UserA发送加好友申请，UserA在DeviceA1上同意了该请求，DeviceA2会收到该回调 \~english UserB sent UserA a friend request, UserA accepted the request on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventContactDecline = 4,  /*! \~chinese UserB向UserA发送加好友申请，UserA在DeviceA1上拒绝了该请求，DeviceA2会收到该回调 \~english UserB sent UserA a friend request, UserA declined the request on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventContactBan = 5,      /*! \~chinese UserA在DeviceA1上将UserB加入黑名单，DeviceA2会收到该回调 \~english UserB and UserA are friends, UserA blocked UserB on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventContactAllow = 6,    /*! \~chinese UserA在DeviceA1上将UserB从黑名单中移除，DeviceA2会收到该回调 \~english UserB and UserA are friends, UserA unblocked UserB on DeviceA1, DeviceA2 will receive this callback */
    
    AgoraMultiDevicesEventGroupCreate = 10,    /*! \~chinese UserA在DeviceA1上创建了群组Group，DeviceA2会收到该回调 \~english UserA created a group on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventGroupDestroy = 11,   /*! \~chinese UserA在DeviceA1上销毁了群组Group，DeviceA2会收到该回调 \~english UserA destroyed a group on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventGroupJoin = 12,      /*! \~chinese UserA在DeviceA1上主动加入了群组Group，DeviceA2会收到该回调 \~english UserA joined a group on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventGroupLeave = 13,     /*! \~chinese UserA在DeviceA1上退出了群组Group，DeviceA2会收到该回调 \~english UserA left a group on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventGroupApply = 14,     /*! \~chinese UserA在DeviceA1上发送了申请进入Group，DeviceA2会收到该回调 \~english UserA requested to join a group on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventGroupApplyAccept = 15,   /*! \~chinese UserA收到UserB的入群申请，UserA在DeviceA1上同意了该申请，DeviceA2会收到该回调 \~english UserA received UserB's request to join the group, UserA accepted the request on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventGroupApplyDecline = 16,  /*! \~chinese UserA收到UserB的入群申请，UserA在DeviceA1上拒绝了该申请，DeviceA2会收到该回调 \~english UserA received UserB's request to join the group, but UserA declined the request on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventGroupInvite = 17,    /*! \~chinese UserA在DeviceA1上邀请了某些人进入GroupA，DeviceA2会收到该回调 \~english UserA invited UserB to join a Group on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventGroupInviteAccept = 18,  /*! \~chinese UserBUserA加入群组,UserA在DeviceA1上同意了UserB的邀请，DeviceA2会收到该回调 \~english UserB invited UserA to join a group, UserA accepted UserB's invitation on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventGroupInviteDecline = 19, /*! \~chinese UserB邀请UserA加入群组,UserA在DeviceA1上拒绝了UserB的邀请，DeviceA2会收到该回调 \~english UserB invited UserA to join a group, UserA declined UserB's invitation on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventGroupKick = 20,      /*! \~chinese UserA在DeviceA1上将某些成员从GroupA中踢出，DeviceA2会收到该回调 \~english UserA removed a user(s) from a group on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventGroupBan = 21,       /*! \~chinese UserA在DeviceA1上将某些成员加入GroupA黑名单，DeviceA2会收到该回调 \~english UserA blocked a user(s) on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventGroupAllow = 22,     /*! \~chinese UserA在DeviceA1上将某些成员从GroupA黑名单中移除，DeviceA2会收到该回调 \~english UserA unblocked a user(s) on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventGroupBlock = 23,     /*! \~chinese UserA在DeviceA1上屏蔽了GroupA的消息，DeviceA2会收到该回调 \~english UserA blocked message from GroupA on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventGroupUnBlock = 24,   /*! \~chinese UserA在DeviceA1上取消了屏蔽GroupA的消息，DeviceA2会收到该回调 \~english UserA unblocked message from GroupA on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventGroupAssignOwner = 25,   /*! \~chinese UserA在DeviceA1上更新了GroupA的群主，DeviceA2会收到该回调 \~english UserA updated GroupA owner on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventGroupAddAdmin = 26,  /*! \~chinese UserA在DeviceA1上添加了GroupA的管理员，DeviceA2会收到该回调 \~english UserA added an admin to GroupA on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventGroupRemoveAdmin = 27,   /*! \~chinese UserA在DeviceA1上移除了GroupA的管理员，DeviceA2会收到该回调 \~english UserA removed an admin from GroupA on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventGroupAddMute = 28,   /*! \~chinese UserA在DeviceA1上禁言了GroupA的某些成员，DeviceA2会收到该回调 \~english UserA silent a user(s) on GroupA on DeviceA1, DeviceA2 will receive this callback */
    AgoraMultiDevicesEventGroupRemoveMute = 29,    /*! \~chinese UserA在DeviceA1上移除了GroupA的某些禁言成员，DeviceA2会收到该回调 \~english UserA un-silent a user(s) on GroupA on DeviceA1, DeviceA2 will receive this callback */
};

@protocol AgoraMultiDevicesDelegate <NSObject>

@optional

/*!
 *  \~chinese
 *  好友多设备事件回调
 *
 *  @param aEvent       多设备事件类型
 *  @param aUsername    用户名
 *  @param aExt         扩展信息
 *
 *  \~english
 *  The multi-device event callback of contact
 *
 *  @param aEvent       Event type
 *  @param aUsername    Username
 *  @param aExt         Extended Information
 */
- (void)multiDevicesContactEventDidReceive:(AgoraMultiDevicesEvent)aEvent
                                  username:(NSString *)aUsername
                                       ext:(NSString *)aExt;

/*!
 *  \~chinese
 *  群组多设备事件回调
 *
 *  @param aEvent       多设备事件类型
 *  @param aGroupId     群组ID
 *  @param aExt         扩展信息
 *
 *  \~english
 *  The multi-device event callback of group
 *
 *  @param aEvent       Event type
 *  @param aGroupId     Group id
 *  @param aExt         Extended Information
 */
- (void)multiDevicesGroupEventDidReceive:(AgoraMultiDevicesEvent)aEvent
                                 groupId:(NSString *)aGroupId
                                     ext:(id)aExt;

@end
