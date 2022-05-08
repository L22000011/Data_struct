/*  图用数组（邻接矩阵）存储
     0或者无穷表示无连接
*/

//存储--邻接矩阵表示
typedef struct 
{
        VertexType vexs[MaxSize]; //一维矩阵存放顶点信息
        int arcs[MaxSize][MaxSize];  //邻接矩阵
        int vexnum, arcnum;   //顶点数和边数
        int kind;  //图的类型
}MGraph;
Mgraph T;


//存储--邻接表表示  [vex,weight,link]

typedef struct ArcNode{
        int vex;  //该弧所指向的顶点位置
        struct ArcNode *link;  //指向下一条弧的指针
        InfoType *info;  //该弧相关的指针
}ArcNode;  //单链表节点类型

typedef struct VNode{
        Vertex data;  //顶点信息
        ArcNode *firstarc;  //指向第一条依附该顶点的弧
}VNode;  //数组元素类型

typedef struct{
        VNode arc[MaxSize];
        int vexnum, arcnum;
        int kind;  //图的类型
}Graphs;
