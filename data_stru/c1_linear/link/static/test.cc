#include "static_list.h"
using namespace std;

#define PR(x) (cout << x)
#define PRLN(x) (cout << x << endl)

int main(void) {
    StaticList sl;
    PRLN(sl);
    for (int i = 0; i < 10; ++i)
        sl.Insert(i + 1, i * i);
    PRLN(sl);
    sl.Insert(3, 333);
    PRLN(sl);
    int data;
    sl.Delete(4, data);
    PR(sl) << "del:" << data << endl;
    return 0;
}
