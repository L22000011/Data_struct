/*                          第七章 图 
掌握图的基本概念和术语，掌握图的邻接矩阵和邻接表存储结构，
了解 图的十字链表和邻接多重链表存储结构。
掌握图的深度优先搜索和广度优先搜索算法、过程、及其应用，
掌握图 的深度优先搜索生成树和广度优先搜索生成树的定义和构造方法 
掌握生成树定义及构造最小生成树的普里姆算法和过程，掌握克鲁斯卡 尔构造最小生成树的过程。
掌握求最短路径的迪杰斯特拉算法和弗洛伊德算法及相应的求解过程 n 掌握拓扑排序算法、相关概念和求解过程 
掌握求解关键路径的方法
*/

//图的基本概念性质
1.简单路径：序列中没有重复点的路径
2.简单回路：第一个点和最后一个相等的路径
3.连通图：若无向图G中任意两个顶点之间都有路径相通，则称此图为连通图。
4.连通分量：若无向图为非连通图，则图中各个极大连通
子图称作此图的连通分量。
5.强连通图：有向图中若任意两个顶点之间都存在一条有
向路径，则称此有向图为强连通图。

6.生成树：假设一个连通图有 n 个顶点和 e 条边，其中 n-1 
条边和 n 个顶点构成一个极小连通子图，称该极小连通
子图为此连通图的生成树
7.有向树：如果一个有向图恰有1个顶点的入度为0，其余的
顶点入度均为1，则称该图为一棵有向树
8.对于非强连通图的一个强连通分量：包含其全部n个顶点、
n-1条弧、且只有1个顶点的入度为0、其余的顶点入度均为
1的子图称为该连通分量的有生成向树。
9.对于非强连通图的所有强连通分量的有向生成树构成该有
向图的生成森林


/*
图的存储结构 （非顺序存储） ：1.邻接表 2. 邻接矩阵 
3. 有向图的十字链表  4. 无向图的临界多重矩阵表
*/

// 1.邻接矩阵：画个矩阵，有向图标记，无向图为对称的
typedef struct {
VertexType vexs[MAXSIZE]; //一维数组存放顶点信息
int arcs[MAXSIZE][MAXSIZE];//邻接矩阵
int vexnum, arcnum; //顶点数和边数
int kind; //图的类型：有向图还是无向图
} MGraph;
MGraph T;

//2.邻接表表示  （与树的兄弟孩子表示法一致）

typedef struct ArcNode {
int vex; // 该弧所指向的顶点的位置
struct ArcNode *link; // 指向下一条弧的指针
InfoType *info; // 该弧相关信息的指针
} ArcNode;//单链表节点类型
typedef struct VNode { 
VertexType data; // 顶点信息
ArcNode *firstarc; // 指向第一条依附该顶点的弧
} VNode;//数组元素类型
typedef struct { 
VNode arc[MAXSIZE];
int vexnum, arcnum; 
int kind; //表示有向图还是无向图
} Graphs;

3.有向图十字链表

typedef struct ArcBox { // 弧的结构表示
int tailvex, headvex; InfoType *info;
struct ArcBox *hlink, *tlink; 
} ArcBox; 

typedef struct VexNode { // 顶点的结构表示
VertexType data;
ArcBox *firstin, *firstout; 
} VexNode;

4.无向图 临界多重表


*********************
//DFS算法（递归）
********************

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

*********************
//BFS算法（非递归）

应用
1.判断从顶点 i 到顶点 s 是否存在简单路径  
2.判断一个图是否为连通图 
3.求两个顶点之间的一条路径长度最短的路径
********************
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













/*第九章 查找 
查找表的基本概念 
掌握静态查找表的顺序查找和折半查找（二分查找）算法（包括二分查 找判定树）及其性能分析方法，
了解索引顺序表的分块查找方法。 
掌握二叉排序树的定义，掌握其查找、插入过程和算法，掌握删除过程 ，掌握其各种操作的性能分析
掌握平衡二叉树的定义；了解平衡二叉树的旋转方法。 
掌握B-树和B+树定义和查找方式；了解B-树和B+树的插入、删除方法
掌握哈希表插入、查找，删除，包括哈希函数的构造、解决冲突的方法
*/


/*第十章 排序 
掌握直接插入排序和折半插入排序算法、排序过程及其性能分析（最好、最坏 、平均情况，稳定性），
掌握希尔排序过程及其性能分析（稳定性） 
掌握冒泡排序（自学）和快速排序的排序算法、排序过程及其性能分析（最好 、最坏、平均情况，稳定性）
掌握简单选择排序（自学）和堆排序的排序算法、排序过程及其性能分析（最 好、最坏、平均情况，稳定性）
掌握归并排序的排序算法、排序过程及其性能分析（最好、最坏、平均情况， 稳定性） 
掌握基数排序的排序过程及其性能分析（时间复杂度，稳定性），及使用条件 
掌握各种排序方法之间的比较*/
                  最好       最坏        平均         辅助空间
直接插入排序











1.直接插入排序  -- 从第二个到最后一个进行排序，选择在队伍的合适位置插入

void insret(SqList &L)
{ int i , j;
        for(i = 2; i < L.length; i++)
        {
                if(L.r[i].key < L.r[i - 1].key)
                {
                        L.r[0] = L.r[i];    //此元素小于他前面的时，将他放进哨兵
                        L[i] = L.r[i - 1];
                        for(j = i - 2; L.r[0].key < L.r[j].key; --j)  
                          //只有当前项大于哨兵时，才进入
                        {
                                L.r[j + 1] = L.r[j];
                                L.r[j + 1] = L.r[0];
                        }
                }  } }
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
