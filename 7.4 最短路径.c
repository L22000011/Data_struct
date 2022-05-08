/*  最短路径-1.迪杰斯特拉算法  --求起点到其余点的最短路径
            2.弗洛伊德算法-- 求任意一对顶点之间距离
     */


//迪杰斯特拉算法
/*  P[i][ ]：从源点到点vi 的最短路径 
• P[i][j]=0 ： vj不在从源点 到点vi 的最短路径上 
• P[i][j]=1 ： vj位于从源点 到点vi 的最短路径上
vk为起点
*/
void ShortestPath(AGraphs G,int k,int P[ ][ ], int D[ ]) 
{
        int i,w, j,min; 
        for (i=0;i<G.vexnum; i ++) 
        { 
                final[i]=0; D[i]=G.arcs[k][i]; 
                for(w=0;w<G.vexnum; w ++) 
                        P[i][w]=0; 
                if (D[i]<INFINITY) 
                {
                        P[i][k]=1; P[i][i]=1; 
                }
        }
        D[k]=0; 
        final[k]=1； 
        for(i=1; i<G.vexnum; i ++) 
        { 
                min=INFINITY;
                for (w=0;w<G.vexnum; w ++) 
                        if (!final[w]&&D[w]<min) 
                        {
                                j=w; min=D[w];
                                } 
                        if(min== INFINITY)
                        return;
                        final[j]=1; 
                        for(w=0;w<G.vexnum; w ++) 
                        if(!final[w]&&(min+G.arcs[j][w]<D[w])) 
                        { 
                                D[w]=min+G.arcs[j][w]; 
                                P[w]=P[j]; P[w][w]=1;
                        } 
                } 
        }
