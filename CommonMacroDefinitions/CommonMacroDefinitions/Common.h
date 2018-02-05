//
//  Common.h
//  CommonMacroDefinitions
//
//  Created by yuedao on 2018/2/5.
//  Copyright © 2018年 Yuedao. All rights reserved.
//

#ifndef Common_h
#define Common_h


/**
 * 打印日志
 */
#ifdef DEBUG
# define DLog(FORMAT, ...) fprintf(stderr,"\n\t[文件名: %s]\n\t[函数名: %s]\n\t[行号:%d]\n\t[打印: %s]\n",[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __FUNCTION__,__LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);

//# define DLog(fmt, ...) NSLog((@"\n\t[文件名:%s]\n""\t[函数名:%s]\n""\t[行号:%d] \n""\t[打印:" fmt "]\n\n"), __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);

#else
# define DLog(...);
#endif

/**
 * 单例
 */

#undef    GPL_H_SINGLETON
#define GPL_H_SINGLETON( __class ) \
+ (__class *)sharedInstance;

#undef    GPL_M_SINGLETON
#define GPL_M_SINGLETON( __class ) \
+ (__class *)sharedInstance \
{ \
static dispatch_once_t once; \
static __class * __singleton__; \
dispatch_once( &once, ^{ __singleton__ = [[__class alloc] init]; } ); \
return __singleton__; \
}

/**
 * NSUserDefault 存 object
 */
#define kYD_USERDEFAULTS_SET_OBJ(obj,key) [[NSUserDefaults standardUserDefaults] setObject:obj forKey:key]

/**
 * NSUserDefault 获取 object
 */
#define kYD_USERDEFAULTS_READ_OBJ(key) [[NSUserDefaults standardUserDefaults] objectForKey:key]

/**
 * NSUserDefault 立即写入数据
 */
#define kYD_USERDEFAULTS_SYN [[NSUserDefaults standardUserDefaults] synchronize]

/**
 * 状态栏高度
 */
#define kStatusHeight [[UIApplication sharedApplication] statusBarFrame].size.height

/**
 * 导航栏高度
 */
#define kNaviHeight self.navigationController.navigationBar.frame.size.height

/**
 * 导航栏和状态栏高度和
 */
#define kNavAndStatusHeight (kStatusHeight + kNaviHeight)


/**
 * 6S宽高比例
 */
#define WIDTH_6S_SCALE 375.0 * [UIScreen mainScreen].bounds.size.width
#define HEIGHT_6S_SCALE 667.0 * [UIScreen mainScreen].bounds.size.height

/**
 * 屏幕尺寸size
 */
#define kScreenSize ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? CGSizeMake([UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale, [UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale) : [UIScreen mainScreen].bounds.size)

/**
 * 弱引用
 */
#define kWeakSelf(type) __weak typeof(type) weak##type = type;

/**
 * 强引用
 */
#define kStrongSelf(type) __strong typeof(type) type = weak##type;

#endif /* Common_h */
