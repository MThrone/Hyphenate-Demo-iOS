//
//  ACDMAXGroupNumberCell.m
//  ChatDemo-UI3.0
//
//  Created by liang on 2021/10/22.
//  Copyright © 2021 easemob. All rights reserved.
//

#import "ACDMAXGroupNumberCell.h"

@interface ACDMAXGroupNumberCell ()
@property (nonatomic, strong) UITextField* maxGroupMemberField;

@end

@implementation ACDMAXGroupNumberCell

- (CGFloat)height {
    return 30.0f;
}


- (void)prepare {
    self.selectionStyle = UITableViewCellSelectionStyleNone;
    [self.contentView addSubview:self.nameLabel];
    [self.contentView addSubview:self.maxGroupMemberField];
}


- (void)placeSubViews {
    [self.nameLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.contentView).offset(16.0f);
        make.bottom.equalTo(self.contentView).offset(-16.0f);
        make.left.equalTo(self.contentView).offset(16);
    }];
    
    [self.maxGroupMemberField mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.contentView).offset(5);
        make.bottom.equalTo(self.contentView);
        make.left.equalTo(self.nameLabel.mas_right).offset(kAgroaPadding * 0.5);
        make.right.equalTo(self.contentView).offset(-10);
    }];
    
}

- (UITextField *)maxGroupMemberField {
    if (!_maxGroupMemberField) {
        _maxGroupMemberField = UITextField.new;
        _maxGroupMemberField.font = BFont(16.0);
        _maxGroupMemberField.textColor = COLOR_HEX(0x000000);
        _maxGroupMemberField.placeholder = @"No More Than 2000";
        _maxGroupMemberField.textAlignment = NSTextAlignmentRight;
    }
    return _maxGroupMemberField;
}

@end