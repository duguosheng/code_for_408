#include "singly_list.h"
using std::ostream;

LinkList::Node::Node() : data(0), next(nullptr) {}
LinkList::Node::Node(ElemType e) : data(e), next(nullptr) {}
LinkList::Node::Node(ElemType e, Node* pn) : data(e), next(pn) {}

LinkList::LinkList() noexcept
    : head(new Node)  //创建头结点
{}

LinkList::~LinkList() {
    Destroy();
}

bool LinkList::Insert(int i, ElemType e) {
    int pos = 1;
    Node *precursor, *successor;  //定义前驱和后继结点
    precursor = head;
    while (precursor && pos < i) {
        precursor = precursor->next;
        ++pos;
    }
    if (precursor && pos == i) {
        //为新插入的元素分配行间
        successor = new Node(e);
        //将precursor的后继赋值给successor的后继
        successor->next = precursor->next;
        //将precursor的后继赋值为successor
        precursor->next = successor;
        return true;
    }
    return false;
}

void LinkList::HeadInsert(const ElemType* data, std::size_t size) {
    Node* precursor = NULL;
    for (int i = size - 1; i >= 0; --i) {
        precursor = new Node(data[i]);
        precursor->next = head->next;
        head->next = precursor;  //插入到表头
    }
}

void LinkList::TailInsert(const ElemType* data, std::size_t size) {
    Node* successor = NULL;  //后继结点
    Node* tail = head;       //表尾指针
    //找到尾结点
    while (tail->next) {
        tail = tail->next;
    }
    for (int i = 0; i < size; ++i) {
        successor = new Node(data[i]);
        tail->next = successor;  //尾插法插入
        successor->next = NULL;
        tail = successor;
    }
}

bool LinkList::Delete(int i, ElemType* e) {
    int pos = 0;
    Node* del_node;  //要删除的结点
    Node* rnode = head;
    while (rnode && pos < i) {
        rnode = rnode->next;
        ++pos;
    }
    if (rnode && rnode->next && pos == i) {
        del_node = rnode->next;
        rnode->next = del_node->next;  //删除结点
        *e = del_node->data;           //取得结点数据
        delete del_node;               //释放空间
        return true;
    }
    return false;
}

void LinkList::Destroy() {
    Node *precursor, *successor;
    precursor = head->next;
    while (precursor) {
        successor = precursor->next;  //保存后继结点的地址
        delete precursor;             //释放当前结点
        precursor = successor;
    }
    head->next = NULL;
}

bool LinkList::GetElem(int i, ElemType* e) {
    if (i < 1) return false;
    int pos = 1;               //记录当前位置
    Node* rnode = head->next;  //指向第一个结点
    while (rnode && pos < i) {
        rnode = rnode->next;
        ++pos;
    }
    if (rnode && pos == i) {
        *e = rnode->data;
        return true;
    }
    return false;
}

int LinkList::Locate(ElemType e) {
    int pos = 1;
    Node* rnode = head->next;
    while (rnode && rnode->data != e) {
        rnode = rnode->next;
        ++pos;
    }
    if (rnode) return pos;
    return 0;
}

ostream& operator<<(ostream& os, const LinkList& item) {
    LinkList::Node* pnode = item.head;
    pnode = pnode->next;  //跳过头结点
    while (pnode != nullptr) {
        os << pnode->data << " ";
        pnode = pnode->next;
    }
    return os;
}
