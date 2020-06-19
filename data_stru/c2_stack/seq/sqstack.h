/**
 * @author: GodSon
 * @date: 2020-06-13 16:23:10
 * @lasttime: 2020-06-13 16:23:10
 * @description: 栈的顺序存储
 */

#ifndef SQSTACK_H
#define SQSTACK_H

#include <iostream>

#define MAX_SIZE 50

class SqStack {
    friend std::ostream& operator<<(std::ostream& os, const SqStack& s);

public:
    using ElemType = int;

    SqStack();
    ~SqStack();
    bool Empty() const;              //判断是否为空
    bool Push(ElemType e);           //入栈
    bool Pop(ElemType& e);           //出栈
    bool GetTop(ElemType& e) const;  //获取栈顶元素
    void Destroy();                  //销毁栈

private:
    ElemType data[MAX_SIZE];  //存放栈中元素
    int top;                  //栈顶指针
};

std::ostream& operator<<(std::ostream& os, const SqStack& s);

#endif