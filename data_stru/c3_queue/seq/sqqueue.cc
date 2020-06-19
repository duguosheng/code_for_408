#include "sqqueue.h"
#include <cstring>

SqQueue::SqQueue() : front(0), rear(0) {
    memset(data, 0, sizeof(data));
}
SqQueue::~SqQueue() {
    Destroy();
}
bool SqQueue::Empty() const {
    if (rear == front)  //队空条件
        return true;
    return false;
}
bool SqQueue::EnQueue(ElemType e) {
    if ((rear + 1) % MAX_SIZE == front)  //队满条件
        return false;
    data[rear] = e;
    rear = (rear + 1) % MAX_SIZE;  //取模形成循环队列
    return true;
}
bool SqQueue::Dequeue(ElemType& e) {
    if (Empty())
        return false;
    e = data[front];
    front = (front + 1) % MAX_SIZE;
    return true;
}
bool SqQueue::GetHead(ElemType& e) const {
    if (Empty())
        return false;
    e = data[front];
    return true;
}
bool SqQueue::GetTail(ElemType& e) const {
    if (Empty())
        return false;
    e = data[(rear - 1 < 0 ? MAX_SIZE - 1 : rear - 1)];
    return true;
}
void SqQueue::Destroy() {
    front = rear = 0;
    memset(data, 0, sizeof(data));
}

using std::ostream;
ostream& operator<<(ostream& os, const SqQueue& item) {
    if (item.Empty()) {
        os << "当前是空队列";
        return os;
    }
    if (item.front < item.rear)
        for (int i = item.front; i < item.rear; ++i)
            os << item.data[i] << " ";
    else {
        for (int i = item.front; i < MAX_SIZE; ++i)
            os << item.data[i] << " ";
        for (int i = 0; i < item.rear; ++i)
            os << item.data[i] << " ";
    }
    return os;
}