//
//  SingleModel.h
//  CommonMacroDefinitions
//
//  Created by yuedao on 2018/2/5.
//  Copyright © 2018年 Yuedao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Common.h"

#define SINGLEMODEL ((SingleModel *)[SingleModel sharedInstance])
@interface SingleModel : NSObject

GPL_H_SINGLETON(SingleModel);

@property (nonatomic, assign) NSInteger age;

@end
