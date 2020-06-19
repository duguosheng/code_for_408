/**
 * @author: GodSon
 * @date: 2020-06-19 14:38:48
 * @lasttime: 2020-06-19 14:38:48
 * @description: KMP算法
 */

#ifndef KMP_H
#define KMP_H
#include "../seq/sqstring.h"

void GetNext(const SqString& s, int next[]);         // 获取next数组
void GetNextval(const SqString& s, int nextval[]);   // 获取nextval叔祖
int IndexKMP(const SqString& s, const SqString& p);  // kmp算法

#endif