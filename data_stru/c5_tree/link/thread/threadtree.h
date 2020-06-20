/**
 * @author: GodSon
 * @date: 2020-06-19 16:10:23
 * @lasttime: 2020-06-19 16:10:24
 * @description: 线索二叉树
 */

#ifndef THREAD_TREE_H
#define THREAD_TREE_H

class ThreadTree {
private:
    struct ThreadNode;
    ThreadNode* root;

public:
    using ElemType = int;
};

struct ThreadTree::ThreadNode {
    ElemType data;       // 数据域
    ThreadTree* lchild;  // 左孩子指针或前驱
    ThreadTree* rchild;  // 右孩子指针或后继
    bool ltag;           // false:lchild表示左孩子;true:lchild表示前驱
    bool rtag;           // false:rchild表示右孩子;true:rchild表示后继
};

#endif