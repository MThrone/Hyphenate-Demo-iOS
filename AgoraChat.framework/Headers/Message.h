/*!
 *  \~chinese
 *  @header Message.h
 *  @abstract 聊天消息
 *  @author Hyphenate
 *  @version 3.00
 *
 *  \~english
 *  @header Message.h
 *  @abstract Chat message
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "MessageBody.h"

/*!
 *  \~chinese
 *  聊天类型
 *
 *  \~english
 *  Chat type
 */
typedef enum {
    AgoraChatTypeChat   = 0,   /*! \~chinese 单聊消息 \~english one to one chat type */
    AgoraChatTypeGroupChat,    /*! \~chinese 群聊消息 \~english Group chat type */
    AgoraChatTypeChatRoom,     /*! \~chinese 聊天室消息 \~english Chatroom chat type */
} AgoraChatType;

/*!
 *  \~chinese
 *  消息发送状态
 *
 *  \~english
 *   Message delivery status
 */
typedef enum {
    MessageStatusPending  = 0,    /*! \~chinese 发送未开始 \~english Pending */
    MessageStatusDelivering,      /*! \~chinese 正在发送 \~english Delivering */
    MessageStatusSucceed,       /*! \~chinese 发送成功 \~english Succeed */
    MessageStatusFailed,          /*! \~chinese 发送失败 \~english Failed */
} MessageStatus;

/*!
 *  \~chinese
 *  消息方向
 *
 *  \~english
 *  Message direction
 */
typedef enum {
    MessageDirectionSend = 0,    /*! \~chinese 发送的消息 \~english Send */
    MessageDirectionReceive,     /*! \~chinese 接收的消息 \~english Receive */
} MessageDirection;

/*!
 *  \~chinese
 *  聊天消息
 *
 *  \~english
 *  Chat message
 */
@interface Message : NSObject

/*!
 *  \~chinese
 *  消息的唯一标识符
 *
 *  \~english
 *  Unique identifier of the message
 */
@property (nonatomic, copy) NSString *messageId;

/*!
 *  \~chinese
 *  所属会话的唯一标识符
 *
 *  \~english
 *  Unique identifier of conversation, the message's container object
 */
@property (nonatomic, copy) NSString *conversationId;

/*!
 *  \~chinese
 *  消息的方向
 *
 *  \~english
 *  Message delivery direction
 */
@property (nonatomic) MessageDirection direction;

/*!
 *  \~chinese
 *  发送方
 *
 *  \~english
 *  Message sender
 */
@property (nonatomic, copy) NSString *from;

/*!
 *  \~chinese
 *  接收方
 *
 *  \~english
 *  Message receiver
 */
@property (nonatomic, copy) NSString *to;

/*!
 *  \~chinese
 *  时间戳，服务器收到此消息的时间
 *
 *  \~english
 *  Timestamp, the time of server received the message
 */
@property (nonatomic) long long timestamp;

/*!
 *  \~chinese
 *  客户端发送/收到此消息的时间
 *
 *  \~english
 *  The time of client sends/receives the message
 */
@property (nonatomic) long long localTime;

/*!
 *  \~chinese
 *  消息类型
 *
 *  \~english
 *  Chat type
 */
@property (nonatomic) AgoraChatType chatType;

/*!
 *  \~chinese
 *  消息状态
 *
 *  \~english
 *  Message delivery status
 */
@property (nonatomic) MessageStatus status;

/*!
 *  \~chinese
 *  已读回执是否已发送/收到, 对于发送方表示是否已经收到已读回执，对于接收方表示是否已经发送已读回执
 *
 *  \~english
 *  Acknowledge if the message is read by the receipient. It indicates whether the sender has received a message read acknowledgement; or whether the recipient has sent a message read acknowledgement
 */
@property (nonatomic) BOOL isReadAcked;

@property (nonatomic) BOOL isNeedGroupAck;

@property (nonatomic, readonly) int groupAckCount;

/*!
 *  \~chinese
 *  送达回执是否已发送/收到，对于发送方表示是否已经收到送达回执，对于接收方表示是否已经发送送达回执，如果AgoraOptions设置了enableDeliveryAck，SDK收到消息后会自动发送送达回执
 *
 *  \~english
 *  Acknowledge if the message is delivered. It indicates whether the sender has received a message deliver acknowledgement; or whether the recipient has sent a message deliver acknowledgement. SDK will automatically send delivery acknowledgement if AgoraOptions is set to enableDeliveryAck
 */
@property (nonatomic) BOOL isDeliverAcked;

/*!
 *  \~chinese
 *  是否已读
 *
 *  \~english
 *  Whether the message has been read
 */
@property (nonatomic) BOOL isRead;

/*!
 *  \~chinese
 *  语音消息是否已听
 *
 *  \~english
 *  Whether the message has been listen
 */
@property (nonatomic) BOOL isListened;

/*!
 *  \~chinese
 *  消息体
 *
 *  \~english
 *  Message body
 */
@property (nonatomic, strong) MessageBody *body;

/*!
 *  \~chinese
 *  消息扩展
 *
 *  Key值类型必须是NSString, Value值类型必须是NSString或者 NSNumber类型的 BOOL, int, unsigned in, long long, double.
 *
 *  \~english
 *  Message extension
 *
 *  Key type must be NSString. Value type must be NSString, or NSNumber object (including int, unsigned in, long long, double, use NSNumber (@YES/@NO) instead of BOOL).
 */
@property (nonatomic, copy) NSDictionary *ext;

/*!
 *  \~chinese
 *  初始化消息实例
 *
 *  @param aConversationId  会话ID
 *  @param aFrom            发送方
 *  @param aTo              接收方
 *  @param aBody            消息体实例
 *  @param aExt             扩展信息
 *
 *  @result 消息实例
 *
 *  \~english
 *  Initialize a message instance
 *
 *  @param aConversationId  Conversation id
 *  @param aFrom            Sender
 *  @param aTo              Receiver
 *  @param aBody            Message body
 *  @param aExt             Message extention
 *
 *  @result Message instance
 */
- (id)initWithConversationID:(NSString *)aConversationId
                        from:(NSString *)aFrom
                          to:(NSString *)aTo
                        body:(MessageBody *)aBody
                         ext:(NSDictionary *)aExt;


@end
