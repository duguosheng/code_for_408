#include "linkstack.h"

LinkStack::Node::Node() : data(0), next(nullptr) {}
LinkStack::Node::Node(ElemType e) : data(e), next(nullptr) {}
LinkStack::Node::Node(ElemType e, Node* pn) : data(e), next(pn) {}

//带头结点
LinkStack::LinkStack() noexcept : top(new Node), count(0) {}
LinkStack::~LinkStack() {
    Destroy();
    delete top;
}
bool LinkStack::Empty() const {
    if (!top->next)
        return true;
    return false;
}
bool LinkStack::Push(ElemType e) {
    Node* s = new Node(e);
    s->next = top;  //把当前栈顶元素赋值给新结点的直接后继
    top = s;        //将新的结点s赋值给栈顶指针
    ++count;
    return true;
}

bool LinkStack::Pop(ElemType& e) {
    if (Empty())
        return false;
    Node* p = top;    //将栈顶点赋值给p
    e = top->data;    //获取数据值
    top = top->next;  //栈顶指针下移一位
    delete p;         //释放结点p
    --count;
    return true;
}
bool LinkStack::GetTop(ElemType& e) const {
    if (Empty())
        return false;
    e = top->data;
    return true;
}
//仅保留头结点
void LinkStack::Destroy() {
    count = 0;
    Node* s;
    while (!Empty()) {
        s = top;
        top = top->next;
        delete s;
    }
}

using std::ostream;
ostream& operator<<(ostream& os, const LinkStack& item) {
    if (item.Empty()) {
        os << "当前是空栈";
        return os;
    }

    auto r = item.top;
    while (r->next) {
        os << r->data << " ";
        r = r->next;
    }
    return os;
}