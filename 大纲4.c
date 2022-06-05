
/*第九章 查找 
查找表的基本概念 
掌握静态查找表的顺序查找和折半查找（二分查找）算法（包括二分查 找判定树）及其性能分析方法，
了解索引顺序表的分块查找方法。 
掌握二叉排序树的定义，掌握其查找、插入过程和算法，掌握删除过程 ，掌握其各种操作的性能分析
掌握平衡二叉树的定义；了解平衡二叉树的旋转方法。 
掌握B-树和B+树定义和查找方式；了解B-树和B+树的插入、删除方法
掌握哈希表插入、查找，删除，包括哈希函数的构造、解决冲突的方法
*/


1.静态查找表--顺序表查找

Define max 100
typedef struct
{KeyType key; 
 ……; }ElemType;//说明： KeyType代表关键字的类型
typedef struct 
{ 
	ElemType elem[max];
	int length; 
}SqList; SqList L;

int search(SqList L, KeyType x)
	// KeyType代表关键字的类型
{ 
	int i; 
	for(i=0;i<L.length;i++)
		if(L.elem[i].key==x)
			return i+1;
	return 0; }


-------------------------------------
二分查找
-------------------------------------
int binaryS(SqList L, KeyType x)
{
	int low=0, high=L.length-1, m;
	while(low<=high) 
	{
		m=(low+high)/2;
		if(L.elem[m].key==x) return m+1;
		if(L.elem[m].key>x) high=m-1;
		else low=m+1; 
	}
	return 0; }




------------------------------------------------------
二叉排序树  --（性能分析）


1.若它的左子树不空，则左子树上所有结 点的值均小于根结点的值；
2. 若它的右子树不空，则右子树上所有结 点的值均大于根结点的值；


  平衡二叉树（不要求算法）
  查找的时间复杂度为O(logn)
了解旋转
------------------------------------------------------

1.二叉排序树  检索
typedef struct NODE 
{
	int key;
	//数据元素的关键字 … ;/
	/数据元素的其他数据项 
struct NODE *lc,*rc; 
}BiNode,*BiTree;

Bitree Search(BiNode *t, int x) 
{ 
	BiTree p; p=t; while(p!=NULL)
	{
		if (x==p->key) return p;
		if (x<p->key) p=p->lc;
		else p=p->rc; 
	} 
	return p;}



2.二叉排序树  -- 插入
int Insert(Bitree &t,int x)
	//二叉排序树的插入算法
{
	BiTree q, p, s; q=NULL; p=t;//p为正在查看的节点，初始从根节点开始；q为p的双亲节点，根节点无双亲节点
	while(p!=NULL) {
		if (x==p->key) return 0;//在当前的二叉排序树中找到x，直接返回，不再做插入 q=p;
		if (x<p->key) p=p->lc; 
		else p=p->rc;
	}
	s=(BiTree)malloc(sizeof(Binode)) ;//没找到x，做插入：先申请节点空间 
	s->key=x;s->lc=NULL; s->rc=NULL ;//存放x，设为叶节点 
	if (q==NULL)t=s; //若原先的二叉树是一棵空树，新插入的x对应的节点s为插入后二叉树的根节点 
	else if (x<q->key) q->lc=s; ;//插入s为q的孩子 
	else q->rc=s;
	return 1; }


3.二叉排序树  -- 删除
（算法不要求）



4.平衡二叉树
深度为 h 的二叉平衡树中所含结点的最小值 Nh 是多少？
h = 0         N0 = 0
h = 1         N1 = 1
h = 2         N2 = 2
h = 3         N3 = 4 
h = 4         N4 = 7

Nh = Nh-1 + Nh-2 + 1 利用归纳法可证得 
Nh = Fh+2 – 1 

	hn = log(根号5 (n+1)) - 2。





------------------------------------------------------------------
B-树
叶子节点存储的是没查到的空区域
m阶B树
1.最多由m个子树  最多有3个分叉， 不算叶子层
2.最少有m/2个子树  （向上取整）
3.n个关键字的B树有 n + 1个叶节点
4.最大最小高度不算叶子层
5.只支持多路查找
------------------------------------------------------------------

------------------------------------------------------------------
B+树：
1.有n棵子树的结点中含有n个关键字
2.所有叶子节点才包含节点信息
3.相当于分块查找
4.查找成功与否都要进入最后一层
5.支持顺序查找和多路查找
------------------------------------------------------------------

------------------------------------------------------------------
根据设定的哈希函数 h(key) 和所选中的处理冲突 的方法，
将一组关键字映象到一个有限的、地址 连续的地址集 (区间) 上，
并以关键字在地址集中 的“象”作为相应记录在表中的存储位置，如此 
构造所得的查找表称之为“哈希表”

构造哈希函数的方法
1. 直接定址法 2. 数字分析法 3. 平方取中法 4. 折叠法 5. 除留余数法 6. 随机数法

处理冲突的方法：
1. 开放定址法 2. 再哈希法 3. 链地址法 4. 建立一个公共溢出区

开放定址法 ：删除一个数据，为保证查找 工作的正常进行不能真删----加删除标志
链地址法：直接删除 
再哈希法：保证删除后查找表的操作正常进行 
建立一个公共溢出区：保证删除后查找表的操作 正常进行






决定哈希表查找的ASL的因素：
1) 选用的哈希函数； 2) 选用的处理冲突的方法； 
3) 哈希表饱和的程度，装载因子 α=n/m 值的大小（n— 数据数，m—表的长度）

线性探测再散列 Sn = 0.5（1 + 1/（1 - α））
随机探测再散列  
链地址法

哈希表的平均查找长度是α的函数，而不是 n的函数。
这说明，用哈希表构造查找表时，可以选择一个适当的装填因子α，
使得平均 查找长度限定在某个范围内。 —— 这是哈希表所特有的特点。
------------------------------------------------------------------



/*第十章 排序 
掌握直接插入排序和折半插入排序算法、排序过程及其性能分析（最好、最坏 、平均情况，稳定性），
掌握希尔排序过程及其性能分析（稳定性） 
掌握冒泡排序（自学）和快速排序的排序算法、排序过程及其性能分析（最好 、最坏、平均情况，稳定性）
掌握简单选择排序（自学）和堆排序的排序算法、排序过程及其性能分析（最 好、最坏、平均情况，稳定性）
掌握归并排序的排序算法、排序过程及其性能分析（最好、最坏、平均情况， 稳定性） 
掌握基数排序的排序过程及其性能分析（时间复杂度，稳定性），及使用条件 
掌握各种排序方法之间的比较*/
                   最好        最坏         平均         空间        稳定性   
                   
1.直接插入排序      O(n)       O(n^2)        O(n^2)       O(1)        稳定
2.希尔排序         O(n^1.3)    O(n^2)        O(nlogn)     O(1)       不稳定
3.二分插入排序     O(log2n)    O(n^2)        O(n^2)       O(1)        稳定
4.直接选择排序     O(n^2)      O(n^2)        O(n^2)       O(1)       不稳定
5.堆排序          O(nlogn)     O(nlogn)      O(nlogn)     O(1)       不稳定
6.冒泡排序          O(n)       O(n^2)        O(n^2)       O(1)        稳定
7.快速排序         O(nlogn)    O(n^2)        O(nlogn)    O(nlogn)    不稳定
8.归并排序         O(nlogn)     O(nlogn)     O(nlogn)      O(n)       稳定
9.基数排序         O(d(r+1))    O(d(r+1))    O(n)        O(rd)链式     稳定
10.简单选择排序               O(n^2)                       O(1)       不稳定
11.树排序                    O(nlogn)                       O(1)       不稳定


/*不稳定的：希尔排序 + 直接选择排序 + 堆排序 + 快速排序 */ 

当待排记录序列按关键字顺序有序时  
`直接插入和冒泡排序：O(n) 
`快速排序：O(n2)
`简单选择排序、堆排序和归并排序的时间性能
`不随记录序列中关键字的分布而改变




1.直接插入排序  -- 从第二个到最后一个进行排序，选择在队伍的合适位置插入

void insret(SqList &L)
{ int i , j;
        for(i = 2; i < L.length; i++)
        {
                if(L.r[i].key < L.r[i - 1].key)
                {
                        L.r[0] = L.r[i];    //此元素小于他前面的时，将他放进哨兵
                        L[i] = L.r[i - 1];
                        for(j = i - 2; L.r[0].key < L.r[j].key; --j)  
                          //只有当前项大于哨兵时，才进入
                        {
                                L.r[j + 1] = L.r[j];
                                L.r[j + 1] = L.r[0];
                        }
                }  } }


/* 简单代码 */
int InsertSort(int A[], int n) {  /* 自定义函数 InsertSort()*/
	int i,j;
	for(i=2; i<=n; i++) { //数组下标从2开始，A[0]做监视哨，A[1]一个数据无可比性
		A[0]=A[i];    //A[0]为哨兵
		for(j=i-1; A[0]<A[j]; j--) {
			A[j+1]=A[j]; 	//元素后移
		}
		A[j+1]=A[0];    //将A[j+1] ,即A[i]插入
	}
	return 0;
}


2.二分插入排序   --用二分查找方法找出Ri应该插入的 位置，将Ri插入。

void Binsert(SqList &L)
{
        int i , low, high, mid;
        for(i = 2; i < L.lengthl i++)
                if(L.r[i].key < L.r[r-1].key)
                {
                        L.r[0] = L.r[i];
                        low = 1;
                        high = i - 1;
                        while(low <= high)
                        {
                                mid = (low + high)/2;
                                if(L.r[0].key < L.r[mid].key)  high = mid - 1;
                                else low = mid + 1;
                        }
                        for(j = i - 1; j 》= high + 1; j--)
                                L.r[j++] = L.r[j];
                        L.r[high + 1] = L.r[o];
                }
}

                        
/* 简单代码 */                        
  while(left<=right){
			mid=(left+right)/2;
			if(temp<a[mid]){
				//低位
				right=mid-1;
			}else{
			    //高位
			    left=mid+1;
		    }
	   }
	   //大于插入元素元素后移
	   for(int j=i-1;j>=left;j--){
			a[j+1] = a[j];
		}
		//插入元素left or high + 1
		a[left] = temp;
}                   
                        

3.冒泡排序  --每次交换相邻两个
void mppx(SqList &L)
{
	int i; int j = 1, k = 1;
	while( (j < L.length) && (K > 0) )
	{
		k = 0;
		for(i = 1; i < L.length; i++)
			if(L.r[i + 1].key < L.r[i].key)
			{
				L.r[0] = L.r[i];
				L.r[i] = L.r[i+1];
				L.r[i+1] = L.r[0];
				k++;}
		j++}
}

4.快速排序   -- 选第一个做基准（low指针指向第一个， high指向最后一个元素）
从最后一个开始比较，当high指向大于基准，则不变，小于基准时，将low指向内容改为high指向的
并且从low开始向high移动

int partition( SqList L, int l, int h )
{ 
	L.r[0]=L.r[l]; 
	while(l<h) {
		while(( l < h) && (L.r[h].key >=L.r[0].key) ) h--;
		if (l < h ) {L.r[l]=L.r[h]; l++;
			    } 
		while( (l < h) && (L.r[l] ].key <L.r[0].key )) l++; 
		if( l < h ) {
			L.r[h]=L.r[l]; h--;} }L.r[l]=L.r[0]; 
	return l; } 
                        
                        
void QSort (SqList &L,int l,int h) 
{
	int t; if (l<h)
	{
		t = partition( L, l, h);
		QSort (L, l, t-1); QSort (L, t+1, h);
	} }
                        
         


                        
5.简单选择排序
每次选一个最大值，与第一个“交换”，次大值与“第二个交换”，依次进行

int i,j,k，temp;
for(i=0; i<n-1; i++) //依次遍历序列中每一个元素，进行n-1轮，最后一轮只剩下最后一个元素
{
	k = i; //默认该轮的第一个元素是最小值
	for(j=i+1; j<n; j++) //遍历其余元素
	{
		if(arr[j] < arr[k]) //若其余元素有比该轮第一个元素小的，则记录元素下标
			k = j; //记录元素下标
	}
	if(k != i) //进行交换
	{
		temp = arr[k];
		arr[k] = arr[i];
		arr[i] = temp;
	}
}


6.堆排序
从小到大排列时，先建立大顶堆，然后进行堆排序
适用于待排序元素较多的情况。

void HeapAdjust(SqList &L,int s,int m)
{ 
	int j; L.r[0]=L.r[s]; 
	for (j=2*s,j<=m;j=j*2） 
	     {
		if(j<m&&L.r[j].key< L.r[j+1].key) ++j;
		     if(L.r[0].key>=L.r[j].key) break;
		     L.r[s]=L.r[j]; s=j; 
	     } 
	     L.r[s]=L.r[0]; 
}


void HeapSort(SqList &L) 
{ 
	int i,j,k; 
	for (i=L.Length/2;i>0;--i）
	     HeapAdjust(L,i,L.Length);
	     for(i=L.Length;i>1;--i) 
	     {
		     L.r[0]=L.r[i];
		     L.r[i]=L.r[1];
		     L.r[1]=L.r[0];
		     HeapAdjust(L,1,i-1);
	     } 
	     }
	     HeapAdjust(L,i,L.Length);



7.归并排序;将待排序序列划分成若干有序子序列；
	  将两个或两个以上的有序子序列 “合并” 为一个有序序列
	     
初始序列 [23] [52] [67] [6] [18] [10] 
一趟归并后 [23 52] [6 67] [10 18] 
二趟归并后 [6 23 52 67] [10 18] 
三趟归并后 [6 10 18 23 52 67]
void Merge (ElemType SR[ ], ElemType TR[ ], int s, int m, int t) 
{
	// 将有序的序列 SR[s..m] 和 SR[m+1..t]归并为有序的序列 
	TR[s..t] for (i=s, j=m+1, k=s; i<=m && j<=t; ++k) 
	{ 
		if (SR[i].key<=SR[j].key) TR[k] = SR[i++];
		// i为第一个有序序列 SR[s..m] 当前正在查看的数据，该序列的第一个数据元素在s处； // j为第二个有序序列 SR[m+1..t]当前正在查看的数据，该序列的第一个数据元素在m+1处；
		// k为合并后的有序序列 TR[s..t]的存放位置，第一个位置为s
		else TR[k] = SR[j++];
	} 
	if (i<=m) // 第一个有序序列 还有数据没有比较，将其复制到合并后的序列； 
		for( ; i<=m; ) TR[k++] = SR[i++]; 
	if (j<=t) 
		for( ; j<=t; ) TR[k++] = SR[j++]; 
	// 第二个有序序列 还有数据没有比较，将其复制到合并后的序列； 
}	     
	     
	     
void Msort (ElemType SR[], ElemType TR1[], int s, int t )
{
	// 将SR[s..t] 归并排序为 TR1[s..t] 
if (s= =t) TR1[s]=SR[s];//序列中只有一个数据元素，序列自然有序，不用再排序 
else  //序列中包含2个或2个以上数据元素
{ 
	m=(s+t)/2;    //计算序列的中间位置，以此为界划分为2个序列
	Msort (SR, TR2, s, m);//对第一个子序列递归调用归并排序算法，使其有序 
	Msort (SR, TR2, m+1, t); //对第二个子序列递归调用归并排序算法，使其有序 
	Merge (TR2, TR1, s, m, t); //将2个有序子序列合并为一个有序序列 
	}
} 



8.桶排序
桶排序不要求掌握算法
	     
9.基 数 排 序   -- （只掌握排序过程）
最高位优先MSD法：
最低位优先LSD法：                      
                        
                        
                        
                        
                        

	     
	     
	     
