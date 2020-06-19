#include "linkqueue.h"

LinkQueue::LinkNode::LinkNode() : data(0), next(nullptr) {}
LinkQueue::LinkNode::LinkNode(ElemType e) : data(e), next(nullptr) {}
LinkQueue::LinkNode::LinkNode(ElemType e, LinkNode* pn) : data(e), next(pn) {}

//创建头结点
LinkQueue::LinkQueue() : front(new LinkNode), rear(front) {}
LinkQueue::~LinkQueue() {
    Destroy();
    delete front;
}
bool LinkQueue::Empty() const {
    if (front == rear)
        return true;
    return false;
}
void LinkQueue::EnQueue(ElemType e) {
    LinkNode* s = new LinkNode(e);
    rear->next = s;
    rear = s;
}
bool LinkQueue::DeQueue(ElemType& e) {
    if (Empty())
        return false;
    LinkNode* r = front->next;
    e = r->data;
    front->next = r->next;  //删除结点
    if (rear == r)  //若原队列中只有一个结点，删除后变空
        rear = front;
    delete r;  //释放存储空间
    return true;
}
void LinkQueue::Destroy() {
    if (Empty())
        return;
    LinkNode* r = front->next;
    while (r) {
        front->next = r->next;
        delete r;
        r = front->next;
    }
    rear = front;
}
using std::ostream;
ostream& operator<<(ostream& os, const LinkQueue& item) {
    if (item.Empty()) {
        os << "当前是空队列";
        return os;
    }
    auto iter = item.front->next;  //跳过头结点
    while (iter) {
        os << iter->data << " ";
        iter = iter->next;
    }
    return os;
}