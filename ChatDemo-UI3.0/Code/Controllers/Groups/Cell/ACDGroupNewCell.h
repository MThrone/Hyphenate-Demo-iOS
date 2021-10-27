//
//  ACDGroupNewCell.h
//  ChatDemo-UI3.0
//
//  Created by liang on 2021/10/25.
//  Copyright © 2021 easemob. All rights reserved.
//

#import "ACDCustomCell.h"
#import "AgoraGroupUIProtocol.h"
@class AgoraGroupModel;

NS_ASSUME_NONNULL_BEGIN

@interface ACDGroupNewCell : ACDCustomCell
@property (nonatomic, strong) AgoraGroupModel *model;
@property (nonatomic, assign) id<AgoraGroupUIProtocol> delegate;

@end

NS_ASSUME_NONNULL_END
