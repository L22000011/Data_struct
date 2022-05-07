/*  堆（heap）
堆是一种优先队列，取出元素的顺序是按照：元素的关键字大小，
并不取决于元素进入队列的先后顺序
   ·结构性：数组表示的“完全二叉树”
   ·有序性：任意关键字是所有节点的最大值或者最小值
*/



//创建最大堆
typedef struct HeapStruct *MaxHeap;
//MaxHeap为HeapStruct结构体指针
struct HeapStruct{
        ElemType *Elemments; /* 存储堆元素的数组 */
        int size;         /* 堆当前元素个数 */
        int Capacity;   //堆的最大容量
}

//创建最大堆
MaxHeap Create(int MaxSize)
{
        MaxHeap H = malloc(sizeof(struct HeapStruct));
        H->Elements = malloc((MaxSize + 1) * sizeof(ElemType));
        // + 1 是为了存放哨兵
        H->Size = 0;
        S->Capacity = MaxSize;
        H->Elements[0] = MaxData;
        //数组首位置存放的是哨兵，为了方便判断
         return H;
}


//插入(最大堆指的是每个节点都比他的子节点大即可，不分左右子树谁大)
void Insert(MaxHeap H, ElemType item){
        int i;
        if(IsFull(H)){
                printf("最大堆满");
                return;
        }
        i = ++H->Size;   //最大堆的个数在此处更新
        for(; H->Elements[i/2] < item; i /= 2)
                H->Elements[i] = H->elements[i/2];
        H->Elements[i] = item;
}

//删除
ElementType DeleteMax( MaxHeap H )
{ /* 从最大堆H中取出键值为最大的元素，并删除一个结点 */
        int Parent, Child;
        ElementType MaxItem, temp;
        if ( IsEmpty(H) ) {
                 printf("最大堆已为空");
        return;
        }
        MaxItem = H->Elements[1]; /* 取出根结点最大值 */
         /* 用最大堆中最后一个元素从根结点开始向上过滤下层结点 */
        temp = H->Elements[H->Size--];
        for( Parent=1; Parent*2<=H->Size; Parent=Child ) {
                 Child = Parent * 2;  //左儿子节点
                if( (Child!= H->Size) &&
                         (H->Elements[Child] < H->Elements[Child+1]) )
                        Child++; /* Child指向左右子结点的较大者 */
                if( temp >= H->Elements[Child] ) break;
                 else /* 移动temp元素到下一层 */
                         H->Elements[Parent] = H->Elements[Child];
                }
        H->Elements[Parent] = temp;
        return MaxItem;
}
