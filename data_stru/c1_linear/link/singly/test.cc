#include "singly_list.h"

using std::cout;
using std::endl;
int main(void) {
    LinkList list;
    LinkList::ElemType data[] = {2, 3, 5, 79, 1};
    LinkList::ElemType data1 = 111;
    //!测试插入
    list.HeadInsert(data, 5);
    cout << list << endl;
    list.HeadInsert(&data1, 1);
    cout << list << endl;
    list.TailInsert(data, 5);
    cout << list << endl;
    list.Insert(3, 999);
    cout << list << endl;
    //!测试删除
    list.Delete(3, &data1);
    cout << list << "delete data=" << data1 << endl;
    //!测试获取元素
    list.GetElem(3, &data1);
    cout << data1 << endl;
    //!测试查找
    cout << list.Locate(79) << endl;
    //!测试销毁
    list.Destroy();
    cout << list << endl;
}