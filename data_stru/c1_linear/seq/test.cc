#include "sqlist.h"
using std::cout;
using std::endl;

int main(int argc, char const* argv[]) {
    Sqlist sl;

    //!测试插入
    for (int i = 0; i < 10; ++i)
        sl.Insert(i + 1, i * 2 - 3);
    cout << sl << endl;
    sl.Insert(3, 100);
    cout << sl << endl;

    //!测试删除
    int deldata;
    sl.Delete(3, &deldata);
    cout << sl << " deldata:" << deldata << endl;

    //!测试获取元素
    cout << "在顺序表中查找7：位置是" << sl.Locate(7) << endl;
    cout << "在顺序表中查找1000：位置是" << sl.Locate(1000) << endl;
    return 0;
}