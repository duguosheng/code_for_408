
#include "binsorttree.h"
BinSortTree::BiNode* BinSortTree::Search(ElemType key) {
    BiNode* p = root;
    while (p && key != p->data) {
        if (key < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    return p;
}

BinSortTree::BiNode* BinSortTree::Search1(BiNode* node, ElemType key) {
    if (!node)
        return nullptr;
    if (key == node->data)
        return node;
    else if (key < node->data)
        return Search1(node->lchild, key);
    else
        return Search1(node->rchild, key);
}

BinSortTree::BiNode* BinSortTree::Search1(ElemType key) {
    return Search1(root, key);
}

void BinSortTree::Create(ElemType data[], std::size_t size) {
    for (int i = 0; i < size; ++i) {
        Insert(root, data[i]);
    }
}

bool BinSortTree::Insert(BiNode* node, ElemType k) {
    if (!node) {
        node = new BiNode(k);
        return true;
    } else if (k = node->data)
        return false;         //关键字相同，插入失败
    else if (k < node->data)  //小于，则插入左子树
        return Insert(node->lchild, k);
    else if (k > node->data)  //大于，插入到右子树
        return Insert(node->rchild, k);
}

bool BinSortTree::Insert(ElemType k) {
    Insert(root, k);
}