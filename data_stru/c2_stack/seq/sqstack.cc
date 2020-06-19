#include "sqstack.h"
#include <cstring>

SqStack::SqStack() : top(-1) {
    memset(data, 0, sizeof(data));
};
SqStack::~SqStack() {
    Destroy();
}
bool SqStack::Empty() const {
    if (top == -1)
        return true;
    return false;
}
bool SqStack::Push(ElemType e) {
    if (top == MAX_SIZE - 1)
        return false;
    data[++top] = e;
    return true;
}
bool SqStack::Pop(ElemType& e) {
    if ((top == -1))
        return false;
    e = data[top--];
    return true;
}
bool SqStack::GetTop(ElemType& e) const {
    if (top == -1)
        return false;
    e = data[top];
    return true;
}
void SqStack::Destroy() {
    memset(data, 0, sizeof(data));
    top = -1;
}
std::ostream& operator<<(std::ostream& os, const SqStack& s) {
    if (s.Empty()) {
        os << "当前是空栈";
        return os;
    }
    for (int i = 0; i <= s.top; ++i)
        os << s.data[i] << " ";
    return os;
}