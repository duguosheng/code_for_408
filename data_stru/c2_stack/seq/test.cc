#include "sqstack.h"

using namespace std;

int main(void) {
    SqStack s;
    //!测试Empty()
    cout << s << endl;
    //!测试Push()
    for (int i = 0; i < 5; ++i)
        s.Push(i * i);
    cout << s << endl;
    //!测试Pop()
    SqStack::ElemType data;
    s.Pop(data);
    cout << s << "pop:" << data << endl;
    //!测试GetTop()
    s.GetTop(data);
    cout << "TopData:" << data << endl;
}