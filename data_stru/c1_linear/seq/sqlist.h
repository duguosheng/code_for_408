/**
 * @author: GodSon
 * @date: 2020-06-12 15:33:45
 * @lasttime: 2020-06-12 15:33:45
 * @description: 线性表顺序存储
 */
#ifndef SQLIST_H
#define SQLIST_H

#include <iostream>

//定义数组最大长度
#define MAX_SIZE 100

class Sqlist {
public:
    using ElemType = int;             //假设元素类型是int
    ElemType data[MAX_SIZE];          //定义数组
    int length;                       //顺序表的当前长度
    bool Insert(int i, ElemType e);   //插入元素
    bool Delete(int i, ElemType* e);  //删除元素
    int Locate(ElemType e);           //查找元素
    Sqlist();
    ~Sqlist();
};
//插在输出运算符打印每一项元素
std::ostream& operator<<(std::ostream& os, const Sqlist& item);

#endif
