/*第六章 树和二叉树 
掌握树的基本概念和术语。
掌握二叉树的定义、性质和几种特殊形态的二叉树。
掌握二叉树的存储结构和先序、中序和后序遍历算法，掌握二叉树的层次遍 历算法。
掌握线索二叉树的定义，了解线索二叉树建立方法，掌握根据线索二叉树进 行二叉树的遍历算法（先序，中序）。
掌握树的存储结构、遍历算法；掌握森林的存储结构和遍历算法；掌握树、 森林与二叉树的相互转换。 
掌握哈夫曼树的构建方法、构造哈夫曼编码的方法及带权路径长度的计算（ 自学）*/
//树和二叉树

二叉树只有五种状态
 1.空树 2.只含根节点 3. 左子树空 4.右子树空  5.左右子树都不空
二叉树性质
1.第i层最多有2^(i-1)个节点
深度为k的二叉树最多有 2^(k)-1 个节点
* 对二叉树都有等式：n0 = n2 + 1 *
 ·满二叉树：全部长满节点的二叉树
 ·完全二叉树：对应于满二叉树，所有现存节点序号不改变节点没有左孩子一定没有右孩子
 ·有N个节点的完全二叉树深度为[log2N] + 1


  
//建立二叉树
  
void CreateTree(BiThrTree * tree){
    char data;
    scanf("%c",&data);
    if (data!='#'){
        if (!((*tree)=(BiThrNode*)malloc(sizeof(BiThrNode)))){
            printf("申请结点空间失败");
            return;
        }else{
            (*tree)->data=data;//采用前序遍历方式初始化二叉树
            CreateTree(&((*tree)->lchild));//初始化左子树
            CreateTree(&((*tree)->rchild));//初始化右子树
        }
    }else{
        *tree=NULL;
    }
}


//二叉树存储结构  -- 顺序存储
typedef ElemType SqBiTree[Max_Tree_Size];   
//顺序存储就是数组形式
SqBiTree bt;  


/* 二叉树链式存储
1.二叉链表 2.三叉链表 3. 双亲数组 4.线索链表
*/

//二叉链表：[lchild，data，rchild]

typedef struct BiTNode
{
        ElemType data;
        struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//三叉链表：[parent，lchild，data，rchild]
typedef struct TriTNode
{
        ElemType data;
        struct TriTNode *parent, *lchild, *rchild;
};TriTNode, *TriTree;


//双亲数组：[data，parent，Tag]  Tag标志物
/* 双亲数组的缺点：不能保证二叉树根节点存放于下标为0的第一个数组元素 */
typedef struct BPTNode{
        ElemType data;
        int parent;
        char Tag;  //Tag为L时，为左分支，R为右分支
}BPTNdoe
typedef struct BPTree{
        BPTNode nodes[MaxSize];
        int nums, start;   // nums为树节点个数，strat为根节点位置
}BPTree;


//线索二叉树的建立

//节点创建
#define TElemType int//宏定义，结点中数据域的类型
//枚举，Link为0，Thread为1
typedef enum PointerTag{
    Link,
    Thread
}PointerTag;
//结点结构构造
typedef struct BiThrNode{
    TElemType data;//数据域
    struct BiThrNode* lchild,*rchild;//左孩子，右孩子指针域 
   PointerTag Ltag,Rtag;//标志域，枚举类型
}BiThrNode,*BiThrTree;



//中序对二叉树进行线索化
void InThreading(BiThrTree p){
    //如果当前结点存在
    if (p) {
        InThreading(p->lchild);//递归当前结点的左子树，进行线索化
        //如果当前结点没有左孩子，左标志位设为1，左指针域指向上一结点 pre
        if (!p->lchild) {
            p->Ltag=Thread;
            p->lchild=pre;
        }
        //如果 pre 没有右孩子，右标志位设为 1，右指针域指向当前结点。
        if (!pre->rchild) {
            pre->Rtag=Thread;
            pre->rchild=p;
        }
        pre=p;//线索化完左子树后，让pre指针指向当前结点
        InThreading(p->rchild);//递归右子树进行线索化
    }
}


//中序遍历线索二叉树
void InOrderThraverse_Thr(BiThrTree p)
{
    while(p)
    {
        //一直找左孩子，最后一个为中序序列中排第一的
        while(p->Ltag == Link){
            p = p->lchild;
        }
        printf("%c ", p->data);  //操作结点数据
        //当结点右标志位为1时，直接找到其后继结点
        while(p->Rtag == Thread && p->rchild !=NULL){
            p = p->rchild;
            printf("%c ", p->data);
        }
        //否则，按照中序遍历的规律，找其右子树中最左下的结点，也就是继续循环遍历
        p = p->rchild;
    }
}



第七章 图 
掌握图的基本概念和术语，掌握图的邻接矩阵和邻接表存储结构，
了解 图的十字链表和邻接多重链表存储结构。
掌握图的深度优先搜索和广度优先搜索算法、过程、及其应用，
掌握图 的深度优先搜索生成树和广度优先搜索生成树的定义和构造方法 
掌握生成树定义及构造最小生成树的普里姆算法和过程，掌握克鲁斯卡 尔构造最小生成树的过程。
掌握求最短路径的迪杰斯特拉算法和弗洛伊德算法及相应的求解过程 n 掌握拓扑排序算法、相关概念和求解过程 
掌握求解关键路径的方法


第九章 查找 
查找表的基本概念 
掌握静态查找表的顺序查找和折半查找（二分查找）算法（包括二分查 找判定树）及其性能分析方法，
了解索引顺序表的分块查找方法。 
掌握二叉排序树的定义，掌握其查找、插入过程和算法，掌握删除过程 ，掌握其各种操作的性能分析
掌握平衡二叉树的定义；了解平衡二叉树的旋转方法。 
掌握B-树和B+树定义和查找方式；了解B-树和B+树的插入、删除方法
掌握哈希表插入、查找，删除，包括哈希函数的构造、解决冲突的方法



第十章 排序 
掌握直接插入排序和折半插入排序算法、排序过程及其性能分析（最好、最坏 、平均情况，稳定性），
掌握希尔排序过程及其性能分析（稳定性） 
掌握冒泡排序（自学）和快速排序的排序算法、排序过程及其性能分析（最好 、最坏、平均情况，稳定性）
掌握简单选择排序（自学）和堆排序的排序算法、排序过程及其性能分析（最 好、最坏、平均情况，稳定性）
掌握归并排序的排序算法、排序过程及其性能分析（最好、最坏、平均情况， 稳定性） 
掌握基数排序的排序过程及其性能分析（时间复杂度，稳定性），及使用条件 

掌握各种排序方法之间的比较
