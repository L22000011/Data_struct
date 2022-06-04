                           第一章
1.掌握算法、数据结构的基本概念、有关术语，     
    ·数据是能输入到计算机并被处理的符号的总称
    ·数据元素是数据的基本单位
    ·一个数据元素可以由 多个数据项 构成
    ·数据对象是相同性质的数据元素集合
    ·算法   有穷性， 确定性， 可行性， 输入（可以无） ，输出
2.时间复杂性分析和空间复杂性分析


                          第二章
1.掌握线性结构的特点。

2.掌握线性表的定义，顺序和链式存储结构和基本运算的实现。

//线性表创建
typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}*Position, *Link;

typedef struct {
  Link head, tail;
  int len;
}LinkList;

//顺序表（静态数组）

typedef struct{
  int elem[maxlen]; 
  int length;
} SeqList;
SeqList L; 
L.length=n

//指针数组
typedef struct {
int *elem;
int length; 
int listsize; 
} SqList;
SqList L;


线性表的插入
int InsertList (SqList &L, int i, int x)//线性表用指针数组实现
//在线性表的第i个数据元素前插入一个值为 x 的新元素
{ int j,*newbase; 
if ( i <1|| i>L.length+1) return -1;
   if (L.length==L.listsize) {
   //空间不够用时，增大空间 
   newbase=(int*)realloc(L.elem,(L.listsize+ LISTINCREMENT)* sizeof(int));
   if(newbase==0) exit(OVERFLOW);
   L.elem=newbase;
   L.listsize= L.listsize+LISTINCREMENT;
   }
   for(j=L.length;j>=i;j--) L.elem[j]=L.elem[j-1]; 
   L.elem[i-1]=x;
   //插入新元素 ++L.length;
   return 1; }


线性表删除
int DeleteList (SqList &L; int i){
int j; 
if(i<1 || i>L.length) {
printf (＂不存在第i个元素＂); return 0;
//直接返回，返回0代表要删除的元素不存在，没用删除任何数据
} 
for(j=i+1;j<=L.length;j++) 
L.elem[j-2]=L.elem[j-1]; 
 L.length--;  
 return 1;  
 }
3.掌握循环链表、双向链表的特点，以及相应的运算的实现。 
//创建——插入数据
int insert_list(list *head){
    int data;   //插入的数据类型
    printf("请输入要插入的元素：");
    scanf("%d",&data);
  
    list *node=initlist();
    node->data=data;
    //初始化一个新的结点，准备进行链接
  
    if(head!=NULL){
        list *p=head;
        //找到最后一个数据
        while(p->next!=head){
            p=p->next;
        }
        p->next=node;
        node->next=head;
        return 1;
    }else{
        printf("头结点已无元素\n");
        return 0;
    }
  
}
4.掌握一元多项式的表示和相加算法（自学）。

typedef struct node{
int coef;
int exp ;
struct node *next;}PNode, *Poly;

Void add(poly &pa,poly &pb)
{ 
poly qa,qb,q;
qa=pa->next;q=pa;qb=pb->next;
while(qa&&qb)
if(qa->exp<qb->exp){q=qa;qa=qa->next}
else if(qa->exp==qb->exp)
{ sum= qa->coef+qb->coef;
pb->next=qb->next;
free(qb);qb=pb->next;
if(sum==0){ q->next=qa->next;
free(qa);qa=q->next; }
else{qa->coef=sum;q=qa;qa=qa->next;}
}
else{ pb->next=qb->next;
qb->next=qa;q->next=qb;
q=qb;qb=pb->next;}
if(qb)q->next=qb;
free(pb);
}


                 第三章 
栈和队列
掌握栈和队列的基本概念。
掌握栈和队列的顺序存储结构、链式存储结构以及基本操作的实现 （算法）。
--循环队列（队列的顺序存储结构）
掌握栈和队列的区别 
掌握栈、队列与线性表的区别



第五章 数组和广义表
掌握数组的定义和存储方式。
掌握特殊矩阵（对称阵，上三角阵，下三角阵，对角阵）的压缩存 储方法。
掌握稀疏矩阵的压缩存储方法，
了解相应运算(加法、转置)的实现 （稀疏矩阵的快速转置自学）。



第六章 树和二叉树 
掌握树的基本概念和术语。
掌握二叉树的定义、性质和几种特殊形态的二叉树。
掌握二叉树的存储结构和先序、中序和后序遍历算法，掌握二叉树的层次遍 历算法。
掌握线索二叉树的定义，了解线索二叉树建立方法，掌握根据线索二叉树进 行二叉树的遍历算法（先序，中序）。
掌握树的存储结构、遍历算法；掌握森林的存储结构和遍历算法；掌握树、 森林与二叉树的相互转换。 
掌握哈夫曼树的构建方法、构造哈夫曼编码的方法及带权路径长度的计算（ 自学）



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














