一棵二叉树的繁茂度定义为各层结点数的最大 值与树的高度的乘积。
用类C语言设计算法求 二叉树的繁茂度。
#define MAX 100 n #define D 20 n //二叉链表的类型定义 
typedef struct node 
{
int data; struct node * lc, * rc;
} Node, * Bitree;  //队列中数据元素的类型定义 

typedef struct{
  Node * node; int layer;
} BTNRecord;

int FanMao(Bitree T) 
{
  int count[D];
  int f=r=0; int k, maxn,i;
  BTNRecord Q[MAX],p;
  if(T==NULL) return 0;
  Q[r].node=T; 
  Q[r++].layer=1; 
  for(k=0;k<D;k++)count[k]=0;
  while(f<r) {p=Q[f++];
      count[p.layer]++; 
      if(p.node->lc) {
         Q[r].node= p.node->lc; 
        Q[r++].layer= p.layer+1;
      }
  if(p.node->rc) {
    Q[r].node= p.node->rc; 
    Q[r++].layer= p.layer+1;
  }
  }
  h=p.layer; 
  //最后一个访问的结点所在层就是树的高度 
  for(maxn=count[1],i=2;i<=h;i++) 
    if(count[i]>maxn) maxn=count[i]; 
  //求层最大结点数 return h*maxn; }
