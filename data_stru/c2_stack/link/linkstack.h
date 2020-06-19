/**
 * @author: GodSon
 * @date: 2020-06-13 17:20:44
 * @lasttime: 2020-06-13 17:20:44
 * @description: 链栈
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>

class LinkStack {
    friend std::ostream& operator<<(std::ostream& os, const LinkStack& item);

private:
    struct Node;  //结点类
    Node* top;    //栈顶指针
    int count;    //元素数量

public:
    using ElemType = int;
    LinkStack() noexcept;
    ~LinkStack();
    bool Empty() const;              //判断是否为空
    bool Push(ElemType e);           //入栈
    bool Pop(ElemType& e);           //出栈
    bool GetTop(ElemType& e) const;  //获取栈顶元素
    void Destroy();                  //销毁
};

struct LinkStack::Node {
    ElemType data;  //数据域
    Node* next;     //指针域
    Node();
    Node(ElemType e);
    Node(ElemType e, Node* pn);
};

std::ostream& operator<<(std::ostream& os, const LinkStack& item);
#endif
