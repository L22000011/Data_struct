/* 最小生成树（MST）算法
Prim Kruskal 

Kruskal算法：首先寻找最小权值，如果有多个，全部加入，将这些权值所连接的点
相连接，寻找次小值，如果加不加入都能使得任意两点之间保持联通，则不加入此值
依次进行，直到形成完全连通图为止停止，为MST

Prim：可以任意选取一个点A，找与A直接连接的所有点中权值最小的，连接起来，然后
将连接后的这些点看作为一个整体，寻找权值最小的，且能开拓新的连通性的点

 */

//prim算法
#define MaxSzie 100
#define MaxEdge 100000  //边数
typedef struct {
        int arcs[MaxSize][MaxSize];  //邻接矩阵存放法
        int vexnum, arcnum;
        /* 顶点数和边数 */
}AGrapgs;

void prim(AGrapgs G, int u){
        int i , j, k;
        EdgeType closedge[MaxSize];
        for(j = 0; j < G.vexnum; ++j){
                closedge[j].adjvex = u;
                closedge[j].lowcost = G.arcs[u][j];
        }
        closedge[u].lowcost = 0;
        for(i = 1; i < G.vexnum; ++i){
                k = minclosedge(closedge);
                printf("(%d%d)",closedge[k].adjvex, k);
                closedge[k].lowcost = 0;
                for(j = 0; j < G.vexnum; ++j)
                        if(G.arcs[k][j] < closedge[j].lowcost)
                        {
                                closedge[j].lowcost = G.arcs[k][j];
                                closedge[j].adjvex = k;
                        }
        }
}

int minclosedge(EdgeType closedge[])
{
        int min, j ,k;
        min = MaxEdge;
        k = -1;
        for(j = 0; j < G.vexnum; ++j)
        {
                if (closedge[j].lowcost !=0&&closedge[j].lowcost<min)
                {
                        min=closedge[j].lowcost; k=j;
                        }
                 return k;
        }
}



/* kruskal算法 */
