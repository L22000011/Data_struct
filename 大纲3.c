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

****************************************
//BFS算法（非递归）

应用
1.判断从顶点 i 到顶点 s 是否存在简单路径  
2.判断一个图是否为连通图 
3.求两个顶点之间的一条路径长度最短的路径
****************************************
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






***************************************
prim算法
每次随便选取点，但是要根据最小权值判断路径，不连通时才连接

时间复杂度              
O（n^2） n为边数        
***************************************
define MAXEDGE 1000000 
typedef struct
{ 
	int arcs[MAX][MAX]; 
	int vexnum,arcnum;
}AGraphs;

void prim(AGraphs G,int u) 
{
	int i,j,k;
	EdgeType closedge[MAX];
	for(j=0;j<G.vexnum;j++)
	{
		closedge[j]. adjvex=u;
		closedge[j]. lowcost=G.arcs[u][j];
	} 
	closedge[u]. lowcost=0;
	for(i=1;i<G.vexnum;i++) 
	{ 
		k=minclosedge(closedge);
		printf(“(%d,%d)”, closedge[k]. adjvex,k); 
		closedge[k]. lowcost=0; 
		for(j=0;j<G.venum;j++) 
			if(G.arcs[k][j]< closedge[j]. lowcost) 
			{ 
				closedge[j]. lowcost= G.arcs[k][j];
				closedge[j]. adjvex =k; 
			}
	} 
}

int minclosedge(EdgeType closedge[ ]) 
{
	int min,j,k; min=MAXEDGE;
	k=-1; 
	for(j=0;j<G.vexnum;j++) 
		if (closedge[j]. lowcost !=0&&closedge[j]. lowcost<min) 
		{ 
			min=closedge[j]. lowcost; k=j;
		} 
	return k; 
}




******************************************
Kruskal算法-----  适合稀疏国   
直接最小权值路径，不连通时才连接，然后选点

时间复杂度              平均时间复杂度
O（nlogn） n为边数        O（nlogn）  

不要求代码
******************************************




/*  ---------------------------------------------------
AOV网:用顶点表示活动，弧 表示活动之间的制约（优先）关系。
测试AOV网是否具有回路的方法，就是在AOV网的偏序集 合下构造一个线性序列，
该线性序列具有以下性质：
若顶点i优先于j，则在线性序列中i仍然优先于j；
对于网中原来没有优先关系的顶点i与顶点j ，
在线性序列中 也建立一个先后关系，或者i优先于j，或者j优先于i。 
满足这样性质的线性序列称为拓扑有序序列。

一个AOV网的拓扑结构可能  “多个”
--------------------------------------------------------*/


拓扑排序算法
typedef struct ArcNode
{
	int vex; struct ArcNode * link;
} ArcNode; 
typedef struct VNode
{
	VertexType data;
	int id; ArcNode * firstarc;
	//id是入度数
}VNode; 
typedef struct 
{ 
	VNode arc[MAXSIZE];
	int vexnum,arcnum;
}Graphs;                        


计算所有顶点入度，将入度为0 的顶点放入队列；count=0;     

while (h!=t ) //队列不空
{
	v=q[h++]; printf(“%d”,v); count++;  
	//将队头V输出
	for(p=T.arc[v].firstarc; p!=Null;p=p->link)
	{ 
		u=p->vex; T. arc[u].id--;
		if (T. arc[u].id==0) q[t++]=u ;
		//自己加判断队列是否会溢出！ 
	} 
} 
  
if (count<T.vexnum) 
{
	printf(“There is a cycle”);
	return 0;
} 
else return 1;	     


/*
AOE网：有向图表示工程计划，顶点表示事件， 弧表示活动，
弧上的权值表示完成一 项活动需要的时间
AOE网中的某些活动可以并行进行， 
完成工程的最短时间是从开始顶点到 完成顶点的最长路径长度。
路径长度最长的路径为关键路径。
关键路径上 所有活动都叫做关键活动。*/

/*
网络中的关键路径并不唯一，对于有几 条关键路径的网来说，
仅仅提高某一条关键路 径上关键活动的速度，是不能缩短整个工程工 期的，
而必须同时提高几条关键路径上关键活 动的速度*/





------------------------------------------------------------
迪杰斯特拉算法--最短路径   从一个源点到其它各点的 最短路径
/* 该算法只适用于静态网络 网络上边的权值不能为负数 */
------------------------------------------------------------

//迪杰斯特拉算法，v0表示有向网中起始点所在数组中的下标
void Dijkstra_minTree(MGraph G, int v0, int p[V], int D[V]) {
    int final[V];//为各个顶点配置一个标记值，用于确认该顶点是否已经找到最短路径
    //对各数组进行初始化
    for (int v = 0; v < G.vexnum; v++) {
        final[v] = 0;
        D[v] = G.arcs[v0][v];
        p[v] = 0;
    }
    //由于以v0位下标的顶点为起始点，所以不用再判断
    D[v0] = 0;
    final[v0] = 1;
    int k = 0;
    for (int i = 0; i < G.vexnum; i++) {
        int min = INFINITY;
        //选择到各顶点权值最小的顶点，即为本次能确定最短路径的顶点
        for (int w = 0; w < G.vexnum; w++) {
            if (!final[w]) {
                if (D[w] < min) {
                    k = w;
                    min = D[w];
                }
            }
        }
        //设置该顶点的标志位为1，避免下次重复判断
        final[k] = 1;
        //对v0到各顶点的权值进行更新
        for (int w = 0; w < G.vexnum; w++) {
            if (!final[w] && (min + G.arcs[k][w] < D[w])) {
                D[w] = min + G.arcs[k][w];
                p[w] = k;//记录各个最短路径上存在的顶点
            }
        }
    }
}


------------------------------------------------------------
弗洛伊德算法- 每一对顶点之间的最短路径

------------------------------------------------------------
// 实现弗洛伊德算法,graph[][V] 为有向加权图
void floydWarshall(int graph[][V]) {
    int  i, j, k;
    //遍历每个顶点，将其作为其它顶点之间的中间顶点，更新 graph 数组
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                //如果新的路径比之前记录的更短，则更新 graph 数组
                if (graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    //记录此路径
                    P[i][j] = k;
                }
            }
        }
    }
    // 输出各个顶点之间的最短路径
    printMatrix(graph);
}
