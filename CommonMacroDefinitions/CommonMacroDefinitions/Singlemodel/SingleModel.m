//
//  SingleModel.m
//  CommonMacroDefinitions
//
//  Created by yuedao on 2018/2/5.
//  Copyright © 2018年 Yuedao. All rights reserved.
//

#import "SingleModel.h"

@implementation SingleModel

GPL_M_SINGLETON(SingleModel);

- (instancetype)init{
    if (self = [super init]) {
        self.age = 100;
    }
    return self;
}

@end
