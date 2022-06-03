1.判断从顶点 i 到顶点 s 是否存在简单路径 

/*这是浙江大学考研试题。主要考查图的广度优先遍历。通过从顶点u
开始对图进行广度优先遍历，如果访问到顶点v，
则说明从顶点u到顶点v存在一条路径。因为在图的遍历过程中，
要求每个顶点只能访问一次，所以该路径一定是简单路径。
在遍历过程中，将当前访问到的顶点都记录下来，就得到了从顶点u到顶点v的简单路径。
————————————————
2.判断一个图是否为连通图

bool visited[MaxVertexNum];         //访问标记数组

//从顶点v出发，采用递归，深度遍历图G
void DFS(ALGraph G, int v)
{
    visit(G, v);                    //访问v
    visited[v]=true;                //设已访问标记
    for(int w=FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w))
    {                               //w为v的尚未访问的邻接顶点
        if(!visited[w])
        {
            DFS(G, w);
        }
    }
}

//判断一个图是否连通
bool Judge(ALGraph G)
{
    for(int v=0; v<G.vexnum; v++)
    {
        visited[v]=false;
    }
    DFS(G, 0);                      //从任意一点遍历，这里从下标为0的点开始
    for(int v=0; v<G.vexnum; v++)
    {
        if(!visited[v])
        {
            return false;
        }
    }
    return true;
}

3.求两个顶点之间的一条路径长度最短的路径 
若两个顶点之间存在多条路径，则其中必有一条路径 长度最短的路径。如何求得这条路径?






