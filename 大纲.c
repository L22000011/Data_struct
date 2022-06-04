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
}ListNode, *LinkList;

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

4.掌握一元多项式的表示和相加算法（自学）。
