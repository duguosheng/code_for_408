/**
 * @author: GodSon
 * @date: 2020-06-19 15:23:04
 * @lasttime: 2020-06-19 15:23:04
 * @description: 二叉链表
 */

#ifndef BITREE_H
#define BITREE_H

#include <initializer_list>
#include <iostream>

#define DONT_CREATE_NODE 0  //宏定义当接收到数据为0时不创建结点

class BiTree {
public:
    using ElemType = int;
    using IniList = std::initializer_list<ElemType>;
    using IniIter = std::initializer_list<ElemType>::iterator;

private:
    struct BiNode;
    BiNode* root;
    void PreOrder(BiNode* node, std::ostream& os);   //递归完成前序遍历
    void InOrder(BiNode* node, std::ostream& os);    //递归完成中序遍历
    void PostOrder(BiNode* node, std::ostream& os);  //递归完成后序遍历
    void Create(BiNode*& node, std::istream& is);    //创建二叉树
    void Create(BiNode*& node, IniIter& iter, const IniIter& end);  //创建二叉树

public:
    BiTree();
    BiTree(IniList il);  //通过初始化列表创建二叉树
    void CreateByIstream(std::istream& = std::cin);  //通过输入流创建二叉树
    //重载成员访问运算符
    BiNode& operator*() const;
    BiNode* operator->() const;

    //递归遍历算法
    void PreOrder(std::ostream& os = std::cout);   //前序遍历
    void InOrder(std::ostream& os = std::cout);    //中序遍历
    void PostOrder(std::ostream& os = std::cout);  //后序遍历
    //非递归遍历算法，利用栈
    void PreOrder1(std::ostream& os = std::cout);   //前序遍历
    void InOrder1(std::ostream& os = std::cout);    //中序遍历
    void PostOrder1(std::ostream& os = std::cout);  //后序遍历
    //层序遍历
    void LevelOrder(std::ostream& os = std::cout);
};

struct BiTree::BiNode {
    ElemType data;   //结点数据
    BiNode* lchild;  //左孩子结点指针
    BiNode* rchild;  //右孩子结点指针
    BiNode();
    BiNode(ElemType e);
    BiNode(BiNode* l, BiNode* r);
    BiNode(ElemType e, BiNode* l, BiNode* r);
};

#endif
