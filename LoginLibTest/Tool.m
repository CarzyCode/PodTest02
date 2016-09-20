//
//  Tool.m
//  LoginVC
//
//  Created by yhj on 15/12/10.
//  Copyright © 2015年 QQ:1787354782. All rights reserved.
//

#import "Tool.h"

#define APPW [UIScreen mainScreen].bounds.size.width
#define APPH [UIScreen mainScreen].bounds.size.height

@implementation Tool

extern UIButton *Tool_Btn(void)
{
    UIButton *btn=[[UIButton alloc]initWithFrame:CGRectMake(0,0,APPW/2,40)];
    [btn setImage:[UIImage imageNamed:@"colorButton1@2x.png"] forState:UIControlStateNormal];
    [btn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [btn setFont:[UIFont systemFontOfSize:17]];
    return btn;
    
}
@end
