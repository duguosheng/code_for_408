/**
 * @author: GodSon
 * @date: 2020-06-18 16:15:54
 * @lasttime: 2020-06-18 16:15:54
 * @description: KMP?????
 */

#include "kmp.h"
using namespace std;

void GetNext(const SqString& s, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while (i < s.Length()) {
        if (j == 0 || s[i] == s[j]) {
            ++i;
            ++j;
            next[i] = j;  //若p[i]==p[j],则next[j+1]=next[j]+1
        } else
            j = next[j];  //否则令j=next[j],循环继续
    }
}

void GetNextval(const SqString& s, int nextval[]) {
    int i = 1, j = 0;
    nextval[1] = 0;
    while (i < s.Length()) {
        if (j == 0 || s[i] == s[j]) {
            ++i;
            ++j;
            if (s[i] != s[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];  //若果相等，则循环
        } else
            j = nextval[j];
    }
}

int IndexKMP(const SqString& s, const SqString& p) {
    int i = 1, j = 1;
    int* nextval = new int(p.Length());  //分配nextval数组内存空间
    GetNextval(p, nextval);              //求得nextval数组
    while (i <= s.Length() && j <= p.Length()) {
        if (j == 0 || s[i] == p[j]) {  //继续比较后续字符
            ++i;
            ++j;
        } else  //模式串向右移动
            j = nextval[j];
    }
    delete nextval;      //回收内存
    if (j > p.Length())  //匹配成功
        return i - p.Length();
    else
        return 0;
}
