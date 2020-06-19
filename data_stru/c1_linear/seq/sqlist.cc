/**
 * @author: GodSon
 * @date: 2020-06-12 15:33:34
 * @lasttime: 2020-06-12 15:33:35
 * @description: file content
 */

#include "sqlist.h"
#include <cstring>

using std::ostream;
Sqlist::Sqlist() : length(0) {
    //内存清零
    memset(data, 0, sizeof(data));
}
Sqlist::~Sqlist() {}
bool Sqlist::Insert(int i, ElemType e) {
    // i无效或存储空间不足
    if (i < 1 || i > length + 1 || length >= MAX_SIZE)
        return false;

    // 将第i个元素之后的元素全部后移
    for (int j = length; j >= i; --j)
        data[j] = data[j - 1];

    data[i - 1] = e;  //插入数据
    ++length;

    return true;
}
bool Sqlist::Delete(int i, ElemType* e) {
    // i无效
    if (i < 1 || i > length)
        return false;

    *e = data[i - 1];
    // 将第i个元素之后的元素全部前移
    for (int j = i; j < length; ++j)
        data[j - 1] = data[j];
    --length;
    return true;
}
int Sqlist::Locate(ElemType e) {
    for (int i = 0; i < length; ++i)
        if (data[i] == e)
            return i + 1;  //下标为i，返回其位序i+1
    return 0;
}
ostream& operator<<(ostream& os, const Sqlist& item) {
    os << "length:" << item.length << "; data:";
    for (int i = 0; i < item.length; ++i) {
        os << item.data[i] << " ";
    }
    return os;
}