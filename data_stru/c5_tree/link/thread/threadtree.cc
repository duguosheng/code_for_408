#include "threadtree.h"

ThreadTree::ThreadNode::ThreadNode()
    : data(0), lchild(nullptr), rchild(nullptr), ltag(false), rtag(false) {}
ThreadTree::ThreadNode::ThreadNode(ElemType e)
    : data(e), lchild(nullptr), rchild(nullptr), ltag(false), rtag(false) {}
ThreadTree::ThreadNode::ThreadNode(ElemType e,
                                   ThreadNode* l,
                                   ThreadNode* r,
                                   bool lt,
                                   bool rt)
    : data(e), lchild(l), rchild(r), ltag(lt), rtag(rt) {}

ThreadTree::ThreadTree() : root(nullptr) {}

ThreadTree::ThreadTree(IniList il) {
    auto beg_iter = il.begin();
    auto end_iter = il.end();
    //令头结点的lchild指向二叉树的根节点
    Create(root, beg_iter, end_iter);
    InThread();
}

ThreadTree::~ThreadTree() {}

void ThreadTree::Create(ThreadNode*& node,
                        IniIter& il_iter,
                        const IniIter& end) {
    //到达初始化列表末尾或者数据等于DONT_CREATE_NODE
    if (il_iter >= end || *il_iter == DONT_CREATE_NODE)
        node = nullptr;
    else {
        node = new ThreadNode(*il_iter);
        Create(node->lchild, ++il_iter, end);
        //如果上一步递归执行完后il_iter==end,则下一步会导致il_iter>end
        Create(node->rchild, ++il_iter, end);
    }
}

void ThreadTree::InThread(ThreadNode*& node, ThreadNode*& pre) {
    if (node) {
        InThread(node->lchild, pre);  //递归，线索化左子树

        // *可以看出这段代码除了两个note注释中间的部分改变了，其余部分与遍历完全相同
        // note: 线索化执行代码 START
        if (!node->lchild) {  //左子树为空，建立前驱结点
            node->lchild = pre;
            node->ltag = true;
        }
        if (pre && !pre->lchild) {
            pre->rchild = node;  //建立前驱结点的后继线索
            pre->rtag = true;
        }
        pre = node;  //标记当前结点为刚刚访问过的节点
        // note: 线索化执行代码 END

        InThread(node->rchild, pre);  //递归，线索化右子树
    }
}
void ThreadTree::InThread() {
    ThreadNode* pre = nullptr;
    if (root) {
        InThread(root, pre);
        pre->rchild = nullptr;
        pre->rtag = true;
    }
}

ThreadTree::ThreadNode* ThreadTree::FirstNode(ThreadNode* node) {
    while (node->ltag)
        node = node->lchild;  //最左下结点，不一定是叶结点
    return node;
}
ThreadTree::ThreadNode* ThreadTree::NextNode(ThreadNode* node) {
    if (node->rtag)  //如果右指针为线索，则其指向结点为后继结点
        return node->rchild;
    else  //若右指针指向右孩子，则其右子树最左侧结点为其后继结点
        return FirstNode(node->rchild);
}
void ThreadTree::InOrder(std::ostream& os) {
    for (auto node = FirstNode(root); node; node = NextNode(node)) {
        os << node->data << " ";
    }
}