#include "linkqueue.h"
using namespace std;
#define PT(x) (cout << x)
#define PTLN(x) (cout << x << endl)

int main(void) {
    LinkQueue lq;
    PTLN(lq);
    for (int i = 0; i < 5; ++i) {
        lq.EnQueue(i * i);
    }
    PTLN(lq);
    int data;
    lq.DeQueue(data);
    PT(lq) << "dequeue data:" << data << endl;
    lq.Destroy();
}