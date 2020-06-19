/**
 * @author: GodSon
 * @date: 2020-06-13 20:13:32
 * @lasttime: 2020-06-13 20:13:33
 * @description: file content
 */

#include "sqqueue.h"
using namespace std;
int main() {
    SqQueue sq;
    cout << sq << endl;
    for (int i = 0; i < 10; ++i)
        sq.EnQueue(i * i);
    cout << sq << endl;
    int data;
    for (int i = 0; i < 11; ++i) {
        sq.Dequeue(data);
        cout << sq << "dequeue data:" << data << endl;
    }
}