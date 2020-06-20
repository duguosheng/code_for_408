#include "bitree.h"
using namespace std;

#ifdef DONT_CREATE_NODE
#define DC DONT_CREATE_NODE  //方便书写
#else
#define DC 0
#endif

int main(void) {
    //先序遍历序列创建二叉树，需要补全为扩展二叉树，空结点用DONT_CREATE_NODE表示
    BiTree btree{1, 2, 4,  7, DC, DC, 8, DC, DC, DC,
                 3, 5, DC, 9, DC, DC, 6, DC, DC};
    btree.PreOrder();
    cout << endl;
    btree.InOrder();
    cout << endl;
    btree.PostOrder();
    cout << endl;
    btree.PreOrder1();
    cout << endl;
    btree.InOrder1();
    cout << endl;
    btree.LevelOrder();
    cout << endl;
}