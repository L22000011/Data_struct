
/* 数组和广义表 */


//稀疏矩阵的存储
/*
1.三元组顺序表
2.行逻辑连接的顺序表
3.十字链表
*/

//三元组顺序表
/* 存储方式为（行[row]，列[col]，值[val]） */
typedef struct{
    int row, col;  //非零元行列坐标
    ElemType val;  //非零元数值
} Triple;

/* 稀疏矩阵结构 */
#define MaxSize 100  //非零元最大数目
typedef struct{
    Triple Data[MaxSize+1];
    int col_size, col_size, num_size;
    //分别为矩阵行数，列数，非零元个数
} TSMatrix;

/* 注：三元组存储方式中data[0]  = [row,col,nums]并不存放非零元的信息
    存储的时矩阵的[行数，列数，非零元个数]
    非零元信息从data[1]开始存储
 */

//三元存储实现矩阵转置
Status trans(TSMatrix M, TSMtrix &T)  //T为转置矩阵
{
    int col,p, k, num[N], cpot[N];
    /*
      num[col]：矩阵M中第col列中非零元个数
      cpot[col]：矩阵M中第col列第一个非零元在T.data中位置
    **显然有:   cpot[first]=1;  
    **cpot[col]=cpot[col-1]+ num[col-1]; (2<=col <= M.col_size)
    */
    T.row_size = M.col_size;    //矩阵行列数先对换
    T.col_size = M.row_size;
    T.num_size = M.num_size;  //非零元个数不变
    if(T.num_size)
    {
        for(col = 1; col <= M.col_size; ++col)
            num[col] = 0;
        for(p = 1; p <= M.num_size; ++p)
            num[M.data[p].j]++;
        cpot[0]=0; cpot[1]=1;
        for(col=2; col<=M.col_size;++col )
            cpot[col]=cpot[col-1]+num[col-1];
        for(p=1;p<=M.num_size; p++ ) { 
    col=M.data[p].j; k=cpot[col];
    T.data[k].i=M.data[p].j; T.data[k];
    T.data[k].e=M.data[p].e; cpot[col];
    }
    }
    return OK;
}




/* 稀疏矩阵链式存储 */
  //节点结构
typedef struct OLNode{
    int row, col;    //每个节点存储行，列，值
    ElemType val;   //down表示同列的下一个非零元，right为同行的下一个
    struct OLNode *right, *down;
}OLNode, *OLink;

//十字链表结构
typedef struct
{
    OLink row_head[M], col_head[N];  //结构体 行，列 指针数组
    int row_size, col_size, num_size;  //行和列数，非零元个数
}CrosssList;
