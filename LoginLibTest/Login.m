//
//  Login.m
//  LoginLibTest
//
//  Created by apple on 16/8/11.
//  Copyright © 2016年 apple. All rights reserved.
//

#import "Login.h"
#import "Tool.h"

#define APPW [UIScreen mainScreen].bounds.size.width
#define APPH [UIScreen mainScreen].bounds.size.height
@implementation Login

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        _phoneTF=[[UITextField alloc]initWithFrame:CGRectMake(30,120,APPW-30*2,40)];
        _phoneTF.borderStyle =UITextBorderStyleRoundedRect;
        _phoneTF.placeholder= @"请输入手机号";
        [self addSubview:_phoneTF];
        
        _codeBtn=[UIButton new];
        [_codeBtn setFrame:CGRectMake(0, 0,140, 40)];
        [_codeBtn setBackgroundImage:[UIImage imageNamed:@"colorButton1@2x.png"] forState:UIControlStateNormal];
        [_codeBtn setTitle:@"获取短信" forState:UIControlStateNormal];
        [_codeBtn addTarget:self action:@selector(sendCode) forControlEvents:UIControlEventTouchUpInside];
        _phoneTF.rightView =_codeBtn;
        _phoneTF.rightViewMode=UITextFieldViewModeAlways;
        
        _codeTF=[[UITextField alloc]initWithFrame:CGRectMake(30,120+50,APPW-30*2,40)];
        _codeTF.borderStyle =UITextBorderStyleRoundedRect;
        _codeTF.placeholder= @"请输入验证码";
        [self addSubview:_codeTF];
        
        
        NSString *bundlePath = [[NSBundle mainBundle] pathForResource:@"LoginBundle" ofType:@"bundle"];
        NSBundle *bundle = [NSBundle bundleWithPath:bundlePath];
        NSString *path = [bundle pathForResource:@"colorButton1@2x" ofType:@"png"];
        UIImage *image = [UIImage imageWithContentsOfFile:path];
        _loginBtn=[UIButton new];
        [_loginBtn setFrame:CGRectMake(10,_codeTF.frame.origin.y+40+30,APPW-10*2, 40)];
        [_loginBtn setBackgroundImage:image forState:UIControlStateNormal];
        [_loginBtn setTitle:@"注册" forState:UIControlStateNormal];
        [_loginBtn addTarget:self action:@selector(sendCode) forControlEvents:UIControlEventTouchUpInside];
        [self addSubview:_loginBtn];
    }
    return self;
}
-(void)sendCode
{
    NSString *msg;
    if ([self.phoneTF.text isEqualToString:@""]||(self.phoneTF.text==NULL)) {
        msg =@"手机号码不能为空";
    }
    if (msg.length !=0) {
        UIAlertView  *alert=[[UIAlertView alloc]initWithTitle:@"提示" message:msg delegate:nil cancelButtonTitle:@"确定" otherButtonTitles:nil,nil];
        [alert show];
        return;
    }
    [self performSelector:@selector(countClick) withObject:nil];
}

-(void)countClick
{
    _codeBtn.enabled =NO;
    _count = 60;
    [_codeBtn setTitle:@"60秒" forState:UIControlStateDisabled];
    [NSTimer scheduledTimerWithTimeInterval:1 target:self selector:@selector(timerFired:) userInfo:nil repeats:YES];
}

-(void)timerFired:(NSTimer *)timer
{
    if (_count !=1) {
        _count -=1;
        [_codeBtn setTitle:[NSString stringWithFormat:@"%ld秒",_count] forState:UIControlStateDisabled];
    }
    else
    {
        [timer invalidate];
        _codeBtn.enabled = YES;
        [_codeBtn setTitle:@"获取验证码" forState:UIControlStateNormal];
    }
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

@end
