/**
 * @author: GodSon
 * @date: 2020-06-13 20:03:32
 * @lasttime: 2020-06-13 20:03:33
 * @description: 顺序存储的循环队列
 */

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

#define MAX_SIZE 100

/**
 * @note:通过牺牲一个单元来区分队空还是队满
 */
class SqQueue {
    friend std::ostream& operator<<(std::ostream& os, const SqQueue& item);

public:
    using ElemType = int;
    SqQueue();
    ~SqQueue();
    bool Empty() const;               //是否为空
    bool EnQueue(ElemType e);         //进队
    bool Dequeue(ElemType& e);        //出队
    bool GetHead(ElemType& e) const;  //获取队头元素
    bool GetTail(ElemType& e) const;  //获取队尾元素
    void Destroy();                   //销毁

private:
    ElemType data[MAX_SIZE];  //存放队列元素

    int front;  //队头指针,指向队头元素
    int rear;   //队尾指针,指向队尾元素的下一个位置
};

std::ostream& operator<<(std::ostream& os, const SqQueue& item);

#endif