/**
 * @author: GodSon
 * @date: 2020-06-19 16:10:23
 * @lasttime: 2020-06-19 16:10:24
 * @description: 线索二叉树
 */

#ifndef THREAD_TREE_H
#define THREAD_TREE_H

#include <initializer_list>
#include <iostream>
#define DONT_CREATE_NODE 0  //宏定义当接收到数据为0时不创建结点

class ThreadTree {
public:
    using ElemType = int;
    using IniList = std::initializer_list<ElemType>;
    using IniIter = std::initializer_list<ElemType>::iterator;

private:
    struct ThreadNode;
    ThreadNode* root;  //头结点
    void InThread(ThreadNode*& node, ThreadNode*& pre);
    void InThread();  //中序线索化
    void Create(ThreadNode*& node, IniIter& il_iter, const IniIter& end);
    ThreadNode* FirstNode(ThreadNode* node);
    ThreadNode* NextNode(ThreadNode* node);

public:
    ThreadTree();
    ThreadTree(IniList il);
    ~ThreadTree();
    void InOrder(std::ostream& os = std::cout);  //中序遍历
};

struct ThreadTree::ThreadNode {
    ElemType data;       // 数据域
    ThreadNode* lchild;  // 左孩子指针或前驱
    ThreadNode* rchild;  // 右孩子指针或后继
    bool ltag;           // false:lchild表示左孩子;true:lchild表示前驱
    bool rtag;           // false:rchild表示右孩子;true:rchild表示后继
    ThreadNode();
    ThreadNode(ElemType e);
    ThreadNode(ElemType e, ThreadNode* l, ThreadNode* r, bool lt, bool rt);
};

#endif