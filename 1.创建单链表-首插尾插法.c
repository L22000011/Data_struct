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
