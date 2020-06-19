/**
 * @author: GodSon
 * @date: 2020-06-14 20:29:52
 * @lasttime: 2020-06-14 20:29:53
 * @description: 静态链表实现
 */
#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include <iostream>
#define MAX_SIZE 1000

class StaticList {
    friend std::ostream& operator<<(std::ostream& os, const StaticList& item);

public:
    using ElemType = int;
    StaticList();
    ~StaticList();
    bool Empty() const;
    int Length() const;               //长度
    bool Insert(int i, ElemType e);   //插入
    bool Delete(int i, ElemType& e);  //删除

private:
    struct Component {
        ElemType data;  //数据值
        int cur;        //游标cursor
    };
    Component slist[MAX_SIZE];
    int MallocSl();
    void FreeSl(int i);
};

std::ostream& operator<<(std::ostream& os, const StaticList& item);

#endif
