#define MAX_VERTEX_NUM 100  //顶点数目的最大值

struct MGraph {
    using VertexType = char;  //顶点的数据类型
    using EdgeType = int;     //边上权值的数据类型

    VertexType vex[MAX_VERTEX_NUM];                 //顶点表
    EdgeType edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  //边表

    int vexnum;  //图当前顶点数
    int arcnum;  //图当前弧数
};