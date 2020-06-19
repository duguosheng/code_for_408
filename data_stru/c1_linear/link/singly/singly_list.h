/**
 * @author: GodSon
 * @date: 2020-06-12 17:09:29
 * @lasttime: 2020-06-12 17:09:29
 * @description: 单链表
 */

#ifndef SINGLY_LIST_H
#define SINGLY_LIST_H

#include <iostream>

class LinkList {
    friend std::ostream& operator<<(std::ostream& os, const LinkList& item);

private:
    struct Node;  //结点类
    Node* head;   //头指针

public:
    using ElemType = int;
    LinkList() noexcept;
    ~LinkList();

    /**
     * @description: 插入元素
     * @param {L:单链表头指针 i:插入位置，在此之前插入 e:插入的值}
     * @return: 状态码
     */
    bool Insert(int i, ElemType e);
    /**
     * @description: 头插法插入元素
     * @param {data:插入值的数组 size:插入数据个数}
     * @return: void
     */
    void HeadInsert(const ElemType* data, std::size_t size);
    /**
     * @description: 尾插法插入元素
     * @param {data:插入值的数组 size:插入数据个数}
     * @return: void
     */
    void TailInsert(const ElemType* data, std::size_t size);
    /**
     * @description: 删除元素
     * @param {L:单链表头指针 i:删除位置 e:存储删除的值}
     * @return: 状态码
     */
    bool Delete(int i, ElemType* e);

    /**
     * @description: 整表删除
     * @return: 状态码
     */
    void Destroy();

    /**
     * @description: 获取元素
     * @param {L:单链表 i:位置 e:获取值存储的位置}
     * @return: 状态码
     */
    bool GetElem(int i, ElemType* e);

    /**
     * @description: 查找链表中第一个与e相等元素的位置
     * @param {e:查找的值}
     * @return: 位序
     */
    int Locate(ElemType e);
};

struct LinkList::Node {
    ElemType data;  //数据域
    Node* next;     //指针域
    Node();
    Node(ElemType e);
    Node(ElemType e, Node* pn);
};

std::ostream& operator<<(std::ostream& os, const LinkList& item);
#endif
