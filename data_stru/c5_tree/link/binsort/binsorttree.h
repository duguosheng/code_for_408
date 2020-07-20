/**
 * @author: GodSon
 * @date: 2020-06-23 20:51:27
 * @lasttime: 2020-06-23 20:59:15
 * @description: file content
 */
#ifndef BIN_SORT_TREE_H
#define BIN_SORT_TREE_H
#include "bitree.h"

class BinSortTree : public BiTree {
public:
    BiNode* Search(ElemType key);                    //查找值
    BiNode* Search1(ElemType key);                   //递归查找值
    bool Insert(ElemType k);                         //插入值
    void Create(ElemType data[], std::size_t size);  //构造二叉树

private:
    bool Insert(BiNode* node, ElemType k);
    BiNode* Search1(BiNode* node, ElemType key);  //递归查找值
};

#endif