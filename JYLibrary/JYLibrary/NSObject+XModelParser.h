//
//  NSObject+XModelParser.h
//  JYLibrary
//
//  Created by XJY on 16/10/11.
//  Copyright © 2016年 XJY. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol XModelParser <NSObject>

@optional
/**
 属性名映射
 */
- (NSDictionary
   <NSString *,//属性名
   NSString *>//映射名
   *)XModelParserModelPropertyNameMapper;

/**
 数组、集合里的元素类名映射
 */
- (NSDictionary
   <NSString *,//属性名
   NSString *>//元素类名
   *)XModelParserModelPropertyContainerClassMapper;

/**
 自定义转换属性
 return: YES 手动转换， NO 自动转换
 */
- (BOOL)XModelParserModelPropertyCustomTransform:(NSString *)propertyName value:(id)value;

/**
 默认值
 */
- (NSDictionary
   <NSString *,//属性名
   id>//默认值
*)XModelParserModelPropertyDefaultValue;

@end

@interface NSObject (XModelParser)

/**
 传入字典返回model实例，失败返回nil.
 */
+ (id)modelFromDictionary:(NSDictionary *)dictionary;

/**
 传入json返回model实例，支持NSString、NSData，失败返回nil.
 */
+ (id)modelFromJson:(id)json;

/**
 传入集合返回model实例，支持NSArray、NSSet，失败返回nil.
 */
+ (id)modelsFromCollection:(id)collection;

/**
 从model1拷贝值到model2，仅拷贝相同名称相同类型的属性，忽略readonly
 返回：YES：成功；NO：失败
 */
+ (BOOL)copyValueFrom:(id)from to:(id)to;

/**
 传入字典，model自动赋值.
 返回：YES：成功；NO：失败
 */
- (BOOL)setValueFromDictionary:(NSDictionary *)dictionary;

/**
 传入json给model自动赋值，支持NSString、NSData.
 返回：YES：成功；NO：失败
 */
- (BOOL)setValueFromJson:(id)json;

/**
 清空值，如果有默认值则置为默认
 返回：YES：成功；NO：失败
 */
- (BOOL)clearValue;

/**
 拷贝值到指定model，仅拷贝相同名称相同类型的属性，忽略readonly
 返回：YES：成功；NO：失败
 */
- (BOOL)copyValueTo:(id)model;

@end
