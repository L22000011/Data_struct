//树和二叉树

/*二叉树只有五种状态
 1.空树 2.只含根节点 3. 左子树空 4.右子树空  5.左右子树都不空
  二叉树性质
第i层最多有2^(i-1)个节点
深度为k的二叉树最多有 2^(k)-1 个节点
* 对二叉树都有等式：n0 = n2 + 1 *



 满二叉树：全部长满节点的二叉树
   完全二叉树：对应于满二叉树，所有现存节点序号不改变
              节点没有左孩子一定没有右孩子
              就有N个节点的完全二叉树深度为[log2N] + 1
*/


//二叉树存储结构

/* 二叉树顺序存储结构 */

#define Max_Tree_Size 100 //最多的树结点数
typedef ElemType SqBiTree[Max_Tree_Size];   
//顺序存储就是数组形式
SqBiTree bt;  


/* 二叉树链式存储
1.二叉链表 2.三叉链表 3. 双亲数组 4.线索链表
*/

//二叉链表：[左子树指针，data，右子树指针]

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

