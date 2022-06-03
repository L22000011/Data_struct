
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
        /* arc表示结构体数组（包含节点信息，弧） */
        int vexnum, arcnum;  //顶点数和边数
        int kind;  //图的类型
}Graphs;


/*  图的遍历
BFS（广度优先搜索）  DFS（深度优先搜索）
*/


//DFS算法

void DFSTraverse(Graphs G)
{
        for(v = 0; v < G.vexnum; ++v)
        /*  vexnum顶点数 */
                visted[v] = 0;
                //首先初始化
        for(v = 0; v < G.vexnum; ++v)
                if(!visted[v])
                        DFS(G,v);
}

void DFS(Graphs G,int v){
        printf("%d",v);
        visited[v] = 1;
        p = G.arc[v].firstarc;
        /* arc表示结构体数组（包含节点信息，弧） */
        while(p){
                i = p->vex;
                //vex ；该弧所指向的顶点位置
        /*visted[w]表示一个一维数组 判断是否访问过此节点
        visted[w] == 1 ，表示已访问，为0表示未访问 */
                if(visited[i] == 0)
                        DFS(G,i);
                p = p->link;
        }
}


/* BFS广度优先遍历 */
int visted[MaxSize];
void BFSTraverse(Graphs G){
        for(v = 0; v < G.vexnum; ++v)
                visted[v] = 0;
        for(v = 0; v < G.vexnum; ++v)
                if(!visted[v])  BFS(G,v);
}
//BFS
void BFS(Graphs G,int v)
{
        int Q[MaxSize], f = 0 ,r = 0;
        printf("%d",v);
        visted[v] = 1;
        Q[r++] = v;
        while(f < r){
                x = Q[f++];
                p = G.arc[x].firstarc;
                while(p){
                        w = p->vex;
                        if(visited[w] == 0){
                                visted[w] = 1;
                                printf("%d\t",w);
                                Q[r++] = w;
                        }
                p = p->link;
                }
        }
}
