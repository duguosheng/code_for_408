#include "bitree.h"

//由于自己写的结构未使用模板泛型编程，这里使用STL标准库中的结构
#include <queue>
#include <stack>

using namespace std;

//结点构造函数
BiTree::BiNode::BiNode() : data(0), lchild(nullptr), rchild(nullptr) {}
BiTree::BiNode::BiNode(ElemType e)
    : data(e), lchild(nullptr), rchild(nullptr) {}
BiTree::BiNode::BiNode(BiNode* l, BiNode* r) : data(0), lchild(l), rchild(r) {}
BiTree::BiNode::BiNode(ElemType e, BiNode* l, BiNode* r)
    : data(e), lchild(l), rchild(r) {}

BiTree::BiTree() : root() {}

BiTree::BiTree(initializer_list<ElemType> il) {
    auto beg_iter = il.begin();
    auto end_iter = il.end();
    Create(root, beg_iter, end_iter);
}

void BiTree::Create(BiNode*& node, IniIter& il_iter, const IniIter& end) {
    //到达初始化列表末尾或者数据等于DONT_CREATE_NODE
    if (il_iter >= end || *il_iter == DONT_CREATE_NODE)
        node = nullptr;
    else {
        node = new BiNode(*il_iter);
        Create(node->lchild, ++il_iter, end);
        //如果上一步递归执行完后il_iter==end,则下一步会导致il_iter>end
        Create(node->rchild, ++il_iter, end);
    }
}
void BiTree::Create(BiNode*& node, istream& is) {
    ElemType data;
    is >> data;
    if (data == DONT_CREATE_NODE)  //这里假设输入为0时为空结点
        node = nullptr;
    else {
        node = new BiNode(data);
        Create(node->lchild, is);
        Create(node->rchild, is);
    }
}

void BiTree::CreateByIstream(istream& is) {
    Create(root, is);
}

BiTree::BiNode& BiTree::operator*() const {
    return *root;
}
BiTree::BiNode* BiTree::operator->() const {
    return &this->operator*();
}

//前序遍历，根节点->左孩子->右孩子
void BiTree::PreOrder(BiNode* node, std::ostream& os) {
    if (!node)
        return;
    os << node->data << " ";
    PreOrder(node->lchild, os);
    PreOrder(node->rchild, os);
}

//中序遍历，左孩子->根节点->右孩子
void BiTree::InOrder(BiNode* node, std::ostream& os) {
    if (!node)
        return;
    InOrder(node->lchild, os);
    os << node->data << " ";
    InOrder(node->rchild, os);
}

//后序遍历，左孩子->右孩子->根节点
void BiTree::PostOrder(BiNode* node, std::ostream& os) {
    if (!node)
        return;
    PostOrder(node->lchild, os);
    PostOrder(node->rchild, os);
    os << node->data << " ";
}

void BiTree::PreOrder(std::ostream& os) {
    PreOrder(root, os);
}
void BiTree::InOrder(std::ostream& os) {
    InOrder(root, os);
}
void BiTree::PostOrder(std::ostream& os) {
    PostOrder(root, os);
}

void BiTree::PreOrder1(std::ostream& os) {
    stack<BiNode*> sbn;          //利用栈进行遍历
    BiNode* p = root;            // p是遍历指针
    while (p || !sbn.empty()) {  //栈不为空或p有意义则循环继续
        if (p) {
            os << p->data << " ";  //访问栈顶元素
            sbn.push(p);           //当前结点入栈
            p = p->lchild;         //左孩子不空，一直向左走
        } else {                   //出栈，并转向出栈结点的右子树
            p = sbn.top();         //获取栈顶元素
            sbn.pop();             //清除栈顶元素
            p = p->rchild;  //向右子树走，p赋值为当前节点的右孩子
        }
    }
}
void BiTree::InOrder1(std::ostream& os) {
    stack<BiNode*> sbn;          //利用栈进行遍历
    BiNode* p = root;            // p是遍历指针
    while (p || !sbn.empty()) {  //栈不为空或p有意义则循环继续
        if (p) {
            sbn.push(p);           //当前结点入栈
            p = p->lchild;         //左孩子不空，一直向左走
        } else {                   //出栈，并转向出栈结点的右子树
            p = sbn.top();         //获取栈顶元素
            sbn.pop();             //清除栈顶元素
            os << p->data << " ";  //访问栈顶元素
            p = p->rchild;  //向右子树走，p赋值为当前节点的右孩子
        }
    }
}

void BiTree::PostOrder1(std::ostream& os) {}
void BiTree::LevelOrder(std::ostream& os) {
    queue<BiNode*> qbn;        //利用队列遍历
    BiNode* p;                 // p是遍历指针
    qbn.push(root);            //将根结点入队
    while (!qbn.empty()) {     //队列不为空则继续循环
        p = qbn.front();       //获取队头元素
        qbn.pop();             //删除队头元素
        os << p->data << " ";  //访问队头元素
        if (p->lchild)
            qbn.push(p->lchild);  //左子树不为空，将左子树入队
        if (p->rchild)
            qbn.push(p->rchild);  //右子树不为空，将右子树入队
    }
}