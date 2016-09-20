//
//  Login.h
//  LoginLibTest
//
//  Created by apple on 16/8/11.
//  Copyright © 2016年 apple. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface Login : UIView
@property(nonatomic,strong)UIButton *codeBtn;/**< 哈喽 */
@property(nonatomic,strong)UITextField *phoneTF;
@property(nonatomic,strong)UITextField *codeTF;
@property(nonatomic,strong)UIButton *loginBtn;
@property(nonatomic,assign)NSInteger count;
@end
