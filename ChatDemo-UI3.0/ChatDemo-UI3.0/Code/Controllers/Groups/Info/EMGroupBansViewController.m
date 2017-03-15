//
//  EMGroupBansViewController.m
//  ChatDemo-UI3.0
//
//  Created by XieYajie on 06/01/2017.
//  Copyright © 2017 XieYajie. All rights reserved.
//

#import "EMGroupBansViewController.h"

#import "EMMemberCell.h"
#import "UIViewController+HUD.h"

@interface EMGroupBansViewController ()

@property (nonatomic, strong) EMGroup *group;

@end

@implementation EMGroupBansViewController

- (instancetype)initWithGroup:(EMGroup *)aGroup
{
    self = [super init];
    if (self) {
        self.group = aGroup;
//        [self.dataArray addObjectsFromArray:self.group.blacklist];
    }
    
    return self;
}


- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.title = NSLocalizedString(@"title.blacklist", @"Blacklist");
    
    UIButton *backButton = [[UIButton alloc] initWithFrame:CGRectMake(0, 0, 44, 44)];
    backButton.accessibilityIdentifier = @"back";
    [backButton setImage:[UIImage imageNamed:@"Icon_Back"] forState:UIControlStateNormal];
    [backButton addTarget:self.navigationController action:@selector(popViewControllerAnimated:) forControlEvents:UIControlEventTouchUpInside];
    UIBarButtonItem *backItem = [[UIBarButtonItem alloc] initWithCustomView:backButton];
    [self.navigationItem setLeftBarButtonItem:backItem];
    
    self.showRefreshHeader = YES;
    [self tableViewDidTriggerHeaderRefresh];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.dataArray count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    EMMemberCell *cell = (EMMemberCell *)[tableView dequeueReusableCellWithIdentifier:@"EMMemberCell"];
    if (cell == nil) {
        cell = [[[NSBundle mainBundle] loadNibNamed:@"EMMemberCell" owner:self options:nil] lastObject];
        
        cell.showAccessoryViewInDelete = YES;
    }
    
    cell.imgView.image = [UIImage imageNamed:@"default_avatar"];
    cell.leftLabel.text = [self.dataArray objectAtIndex:indexPath.row];
    
    return cell;
}

- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    return YES;
}

- (UITableViewCellEditingStyle)tableView:(UITableView *)tableView editingStyleForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return UITableViewCellEditingStyleDelete;
}

- (nullable NSString *)tableView:(UITableView *)tableView titleForDeleteConfirmationButtonForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return NSLocalizedString(@"button.remove", @"Remove");
}

- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
//    NSString *userName = [self.dataArray objectAtIndex:indexPath.row];
//
//    [self showHudInView:self.view hint:NSLocalizedString(@"hud.wait", @"Pleae wait...")];
//    
//    __weak typeof(self) weakSelf = self;
//    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
//        EMError *error = nil;
//        weakSelf.group = [[EMClient sharedClient].groupManager unblockOccupants:@[userName] forGroup:weakSelf.group.groupId error:&error];
//        
//        dispatch_async(dispatch_get_main_queue(), ^{
//            [weakSelf hideHud];
//            if (!error) {
//                [weakSelf.dataArray removeObject:userName];
//                [weakSelf.tableView reloadData];
//                
//                [[NSNotificationCenter defaultCenter] postNotificationName:@"UpdateGroupDetail" object:weakSelf.group];
//            }
//            else {
//                [weakSelf showHint:error.errorDescription];
//            }
//        });
//    });
}

#pragma mark - data

- (void)tableViewDidTriggerHeaderRefresh
{
    self.page = 1;
    [self fetchBansWithPage:self.page isHeader:YES];
}

- (void)tableViewDidTriggerFooterRefresh
{
    self.page += 1;
    [self fetchBansWithPage:self.page isHeader:NO];
}

- (void)fetchBansWithPage:(NSInteger)aPage
                 isHeader:(BOOL)aIsHeader
{
    NSInteger pageSize = 50;
    __weak typeof(self) weakSelf = self;
    [MBProgressHUD showHUDAddedTo:self.view animated:YES];
//    [[EMClient sharedClient].groupManager getGroupBlacklistFromServerWithId:self.group.groupId pageNumber:self.page pageSize:pageSize completion:^(NSArray *aMembers, EMError *aError) {
//        [weakSelf hideHud];
//        [weakSelf tableViewDidFinishTriggerHeader:aIsHeader reload:NO];
//        if (!aError) {
//            if (aIsHeader) {
//                [weakSelf.dataArray removeAllObjects];
//            }
//
//            [weakSelf.dataArray addObjectsFromArray:aMembers];
//            [weakSelf.tableView reloadData];
//        } else {
//            NSString *errorStr = [NSString stringWithFormat:NSLocalizedString(@"group.ban.fetchFail", @"Fail to get blacklist: %@"), aError.errorDescription];
//            [weakSelf showHint:errorStr];
//        }
//        
//        if ([aMembers count] < pageSize) {
//            self.showRefreshFooter = NO;
//        } else {
//            self.showRefreshFooter = YES;
//        }
//    }];
}

@end
