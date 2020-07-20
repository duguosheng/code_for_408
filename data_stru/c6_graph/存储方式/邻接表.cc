#define MAX_VERTEX_NUM 100

struct ALGraph {
    struct ArcNode {
        int adjvex;     //该弧所指向的顶点的位置
        ArcNode* next;  //指向下一条弧的指针
    };

    struct VNode {
        using VertexType = int;  //顶点数据类型
        VertexType data;         //顶点信息
        ArcNode* first;          //指向第一条依附该顶点的弧的指针
    };

    VNode vertices[MAX_VERTEX_NUM];  //邻接表
    int vexnum;                      //图当前顶点数
    int arcnum;                      //图当前弧数
};