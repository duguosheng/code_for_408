#include "static_list.h"
#include <cstring>

StaticList::StaticList() {
    memset(slist, 0, sizeof(slist));
    for (int i = 0; i < MAX_SIZE; ++i)
        slist[i].cur = i + 1;
    slist[MAX_SIZE - 1].cur = 0;  //当前为空链表
}

StaticList::~StaticList() {}

bool StaticList::Empty() const {
    if (!Length()) return true;
    return false;
}

int StaticList::Length() const {
    int len = 0;
    int elem = slist[MAX_SIZE - 1].cur;  //指向第一个元素的位置
    while (elem) {                       //为0时到达终点
        elem = slist[elem].cur;          //下一个元素的位置
        ++len;
    }
    return len;
}

bool StaticList::Insert(int i, ElemType e) {
    if (i < 1 || i > Length() + 1) return false;
    int newelem = MallocSl();
    if (newelem) {
        int precur = MAX_SIZE - 1;
        slist[newelem].data = e;
        for (int j = 1; j < i; ++j) {
            precur = slist[precur].cur;  //找到前驱结点
        }
        //插入新的结点
        slist[newelem].cur = slist[precur].cur;
        slist[precur].cur = newelem;
        return true;
    }
    return false;
}

bool StaticList::Delete(int pos, ElemType& e) {
    if (pos < 1 || pos > Length()) return false;
    int precur = MAX_SIZE - 1;
    for (int i = 1; i < pos; ++i) {
        precur = slist[precur].cur;  //获取删除结点的前驱
    }
    int current = slist[precur].cur;         //获取要删除结点的游标
    e = slist[current].data;                 //获取数据
    slist[precur].cur = slist[current].cur;  //从链表中删除
    FreeSl(current);                         //回收空间
    return true;
}

int StaticList::MallocSl() {
    int pos = slist[0].cur;  // slist[0].cur就是第一个备用空间的下标
    if (pos)                 //当pos==0时说明空间已满
        slist[0].cur = slist[pos].cur;
    return pos;
}

void StaticList::FreeSl(int i) {
    slist[i].cur = slist[0].cur;
    slist[0].cur = i;
}

using std::ostream;
ostream& operator<<(ostream& os, const StaticList& item) {
    if (item.Empty()) {
        os << "当前静态链表为空";
        return os;
    }
    os << "length:" << item.Length() << "  data:";

    int cur = MAX_SIZE - 1;
    while (true) {
        cur = item.slist[cur].cur;
        if (!cur) break;
        os << item.slist[cur].data << " ";
    }
    return os;
}
