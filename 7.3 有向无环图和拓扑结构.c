/* 有向无环图AOV网：（无回路）
顶点表示活动
弧表示活动之间的优先关系 */
/* AOV的拓扑排序可能有多个，并不唯一
        1.选择一个入读为0的点，输出
        2.删除该节点以及他的出发边
        3.循环1.2
        4.如果最后还有剩余点，说明有回路，不是AOV网
 */


//拓扑排序算法‘
#define MAXSIZE 100
typedef struct ArcNode{
        int vex; struct ArcNode * link;
        }ArcNode; 
typedef struct VNode{
        VertexType data;
        int id;
        ArcNode * firstarc;
        }VNode; 
typedef struct { 
        VNode arc[MAXSIZE]; 
        int vexnum,arcnum;
        }Graphs;

        ///计算所有顶点入度，将入度为0 的顶点放入队列
        for(v=0;v<T.vexnum;v++) 
                T.arcs[v].id=0;
        for (v=0;v<T.vexnum;v++)
                for(p=T.arc[v].firstarc; p!=Null;p=p->link) 
                {
                        u=p->vex; T. arc[u].id++;
                        }
                for (v=0;v<T.vexnum;v++) 
                        if (T. arc[v].id==0)
                                 q[t++]=v ;

                                 /*判断队列是否会溢出*/
