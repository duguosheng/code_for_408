#include "sqstring.h"
using namespace std;

int main(void) {
    SqString str1("hello");
    SqString str2;
    cout << "str1:" << str1 << " str2:" << str2 << endl;
    str2.Assign("world");
    cout << "str1:" << str1 << " str2:" << str2 << endl;
    str1 += str2;
    cout << "str1:" << str1 << endl;
    cout << str1.Index("rld") << endl;
    SqString str3 = str1.SubString(2, 5);
    cout << "str3:" << str3 << endl;
    cout << "str1:" << str1 << endl;
}