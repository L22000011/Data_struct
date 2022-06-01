//顺序表两种实现方式

//1. 静态数组
#define maxlen 100
	typedef struct {
		int elem[maxlen];
		int length;
	}SeqList;
	SeqList L;
	L.length = n;

	//静态数组的初始化操作
	int InitList(SeqList& L)
	{
		L.length = 0;
		return OK;
	}


	//2. 指针数组
#define List_size 100
#define List_creat 10
	typedef struct {
		int* elem;
		int length;
		int listsize;

	} SqList;
	SqList L;

	//指针数组的初始化操作
	int InitList(SqList & L)
	{
		L.elem = (int*)malloc(sizeof(int) * List_size);
		if (L.elem == 0)  exit(OVERFLOW);
		L.length = 0;
		L.listsize = List_size;
		return OK;
	}




**********
指针移动的方法
typedef struct Node{
int data;
struct Node* nex;
}Node, *LinkList;

LinkList Head;   //头指针
*pre,*cur, *next;
pre = Null;   cur = Head->nex;
{
next = cur->nex; //指针后移
cur ->nex = pre;   //前继指针此时和后继指针一致
pre = cur;   //为前继指针指向自己
cur = next;   //cur指针指向后继指针的下一个区域，循环可以完成数据的依次插入
}
**********







//数据结构单链表创建
//首插法  尾插法


//创建结构体
typedef struct node{
  ElemType data;
  struct node *next;}Node, *LinkList;
  LinkList h ,p;
  Node *q;
  
  //首插法    每次都用头节点去衔接
  /* 动态创建单链表 ， 逆序输入n个数据元素，建立单链表L */
  void Creat_L1(LinkList &L, int n)
  {
  LinkList p;
  int i;
  L = (LinkList)malloc(sizeof(Node));
  L->next = NULL;
  for(i = n; i > 0; --i)
  {
  p = (LinkList)malloc(sizeof(Node));  //申请节点空间
  scanf("%d", &p->data);    //循环嵌入节点数值
  p ->next = L->next;
  L->next = p;
  }
}
  
  
  
  //尾插法  每次用新的尾巴s去衔接下一个节点
// “正序”
void Creat_L2(ListLink &L, int n)
{
	LinkList p, s;
	int i;
	L = (LinkList),alloc(sizeof(Node));
		L->next = NULL;
	s = L;     //起初让s指向L，随着移动一次，s指向p
	for(i = 1; i <= n; ++i){
		p = (LinkList)malloc(sizeof(Node));
		scanf("%d", &p->data);
		p->next = NULL;
		s->next = p;
		s = p;

	}
}
  
  
    //尾插法  
// “正序”
void Creat_L2(ListLink &L, int n)
{
	LinkList p, s;
	int i;
	L = (LinkList),alloc(sizeof(Node));
		L->next = NULL;
	s = L;
	for(i = 1; i <= n; ++i){
		p = (LinkList)malloc(sizeof(Node));
		scanf("%d", &p->data);
		p->next = NULL;
		s->next = p;
		s = p;

	}
}
  


//首插法创建单链表传入数值
void creat1(LinkList &L){
    LinkList p;
    int x, i, n;
    L = (LinkList)malloc(sizeof(Node));
    L->next = NULL;
    scanf("%d",&n);
    for(i = 1; i <= n; ++i){
        scanf("%d",&x);
        p = (LinkList)malloc(sizeof(Node));
        p->data = x;
        p->next = L->next;
        L->next = p; 
    }
}


//尾插法创建单链表传入数值
void creat1(LinkList &L){
    LinkList p,s;
    int x, i, n;
    L = (LinkList)malloc(sizeof(Node));
    L->next = NULL;
    s = L;
    scanf("%d",&n);
    for(i = 1; i <= n; ++i){
        scanf("%d",&x);
        p = (LinkList)malloc(sizeof(Node));
        p->data = x;
        p->next = NULL;
        s->next = p; 
        s = p;
    }
}
