//
//  ACDChatNavigationView.m
//  ChatDemo-UI3.0
//
//  Created by liang on 2021/11/4.
//  Copyright © 2021 easemob. All rights reserved.
//

#import "ACDChatNavigationView.h"

#define kRedPointViewHeight 8.0f

@interface ACDChatNavigationView ()
@property (nonatomic, strong) UIImageView* backImageView;
@property (nonatomic, strong) UIView* redPointView;
@property (nonatomic, strong) UIButton* leftButton;
@property (nonatomic, strong) UIButton* rightButton;
@property (nonatomic, strong) UIButton* chatButton;

@end

@implementation ACDChatNavigationView


- (void)prepare {
    
    [self addSubview:self.leftButton];
    [self addSubview:self.redPointView];
    [self addSubview:self.chatButton];
    [self addSubview:self.leftLabel];
    [self addSubview:self.rightButton];
}


- (void)placeSubViews {
    [self.leftButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self).offset(kAgroaPadding * 2.0);
        make.left.equalTo(self).offset(kAgroaPadding);
        make.width.equalTo(@30.0);
        make.bottom.equalTo(self).offset(-5.0);

    }];
    
    [self.redPointView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerY.equalTo(self.leftButton).offset(-kAgroaPadding);
        make.centerX.equalTo(self.leftButton.mas_right).offset(-kAgroaPadding);
        make.size.equalTo(@kRedPointViewHeight);
    }];

    [self.chatButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerY.equalTo(self.leftButton);
        make.left.equalTo(self.leftButton.mas_right).offset(kAgroaPadding*0.5);
        make.width.equalTo(@30.0);

    }];
    
    [self.leftLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerY.equalTo(self.leftButton);
        make.left.equalTo(self.chatButton.mas_right).offset(kAgroaPadding);
        make.right.equalTo(self.rightButton.mas_left);
    }];
        
    [self.rightButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerY.equalTo(self.leftButton);
        make.right.equalTo(self).offset(-kAgroaPadding);
    }];
    
}

#pragma mark action
- (void)rightButtonAction {
    if (self.rightButtonBlock) {
        self.rightButtonBlock();
    }
}

- (void)leftButtonAction {
    if (self.leftButtonBlock) {
        self.leftButtonBlock();
    }
}

- (void)chatButtonAction {
    if (self.chatButtonBlock) {
        self.chatButtonBlock();
    }
}

#pragma mark getter and setter
- (UIButton *)leftButton {
    if (_leftButton == nil) {
        _leftButton = [[UIButton alloc] initWithFrame:CGRectMake(0, 0, 8, 15)];
        _leftButton.contentMode = UIViewContentModeScaleAspectFill;
        [_leftButton setImage:ImageWithName(@"black_goBack") forState:UIControlStateNormal];
        [_leftButton addTarget:self action:@selector(leftButtonAction) forControlEvents:UIControlEventTouchUpInside];
    }
    return _leftButton;
}

- (UIView *)redPointView {
    if (_redPointView == nil) {
        _redPointView = UIView.new;
        _redPointView.backgroundColor = TextLabelPinkColor;
        _redPointView.layer.cornerRadius = kRedPointViewHeight * 0.5;
        _redPointView.hidden = YES;
    }
    return _redPointView;
}


- (UILabel *)leftLabel {
    if (_leftLabel == nil) {
        _leftLabel = UILabel.new;
        _leftLabel.textColor = TextLabelBlackColor;
        _leftLabel.textAlignment = NSTextAlignmentLeft;
        _leftLabel.font = BFont(18.0f);
        _leftLabel.text = @"leftLabel";

    }
    return _leftLabel;
}

- (UIButton *)chatButton {
    if (_chatButton == nil) {
        _chatButton = [[UIButton alloc] initWithFrame:CGRectMake(0, 0, 8, 15)];
        _chatButton.contentMode = UIViewContentModeScaleAspectFill;
        [_chatButton setImage:ImageWithName(@"contact_add_contacts") forState:UIControlStateNormal];
        [_chatButton addTarget:self action:@selector(chatButtonAction) forControlEvents:UIControlEventTouchUpInside];

    }
    return _chatButton;
}

- (UIButton *)rightButton {
    if (_rightButton == nil) {
        _rightButton = [[UIButton alloc] initWithFrame:CGRectMake(0, 0, 8, 15)];
        _rightButton.contentMode = UIViewContentModeScaleAspectFill;
        [_rightButton setImage:ImageWithName(@"nav_chat_right_bar") forState:UIControlStateNormal];
        [_rightButton addTarget:self action:@selector(rightButtonAction) forControlEvents:UIControlEventTouchUpInside];
        _rightButton.hidden = YES;
    }
    return _rightButton;
}

@end

#undef kRedPointViewHeight
