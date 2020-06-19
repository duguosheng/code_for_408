/**
 * @author: GodSon
 * @date: 2020-06-14 19:09:56
 * @lasttime: 2020-06-14 19:09:57
 * @description: 队列的链式存储
 */

#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <iostream>

class LinkQueue {
    friend std::ostream& operator<<(std::ostream& os, const LinkQueue& item);

public:
    using ElemType = int;
    LinkQueue();
    ~LinkQueue();
    bool Empty() const;         //判断是否为空
    void EnQueue(ElemType e);   //入队
    bool DeQueue(ElemType& e);  //出队
    void Destroy();             //销毁

private:
    struct LinkNode;
    LinkNode* front;  //队头指针,指向队头元素
    LinkNode* rear;   //队尾指针,指向队尾元素
};

struct LinkQueue::LinkNode {
    ElemType data;
    LinkNode* next;
    LinkNode();
    LinkNode(ElemType e);
    LinkNode(ElemType e, LinkNode* pn);
};

std::ostream& operator<<(std::ostream& os, const LinkQueue& item);
#endif