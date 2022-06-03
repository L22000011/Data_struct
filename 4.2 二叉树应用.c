//递归实现二叉树高度

int Height_Tree(BinTree BT)
{
	int HL, HR, MaxH;
	if(BT){
		HL = Height_Tree(BT->Left);
		HR = Height_Tree(BT->Right);
		MaxH = (HL>HR)? HL : HR;
		return (MaxH + 1);
	}
	else return 0;
}



//应用1：静态查找-顺序查找
int SeSearch(Static *Tbl, ElemType K){
        int i;
        Tbl->ElemType[0] = K;
        for(i = Tbl->Length;Tbl->ElemType[i] != K; --i)
                return i;
}

// 静态查找-二分查找
int BinarySearch ( StaticTable * Tbl, ElementType K)
{ 
        /*在表Tbl中查找关键字为K的数据元素*/
        int left, right, mid, NoFound=-1;
        left = 1; /*初始左边界*/
        right = Tbl->Length; /*初始右边界*/
        while ( left <= right ){
                mid = (left+right)/2; /*计算中间元素坐标*/
                if( K < Tbl->Element[mid]) right = mid-1; /*调整右边界*/
                else if( K > Tbl->Element[mid]) left = mid+1; /*调整左边界*/
                else return mid; /*查找成功，返回数据元素的下标*/
                }
        return NotFound; /*查找不成功，返回-1*/
}


/*  应用2 遍历二叉树和线索二叉树 
   遍历二叉树：先序，中序，后序遍历
   **只要给定中序遍历和任意一个先序（或者后序）遍历可确定唯一序列
*/

//先序遍历(根+左+右)，递归算法 + 非递归算法

/* 递归算法 */
void PreOrderTraversal(BinTree BT)
{
        if(BT){
                printf("%d", BT->Data);
                PreOrderTraversal(BT->Left);
                PreOrderTraversal(BT->Right);
        }
}

/* 中序遍历非递归实现（利用堆栈完成）
   首先往左走，遇到的元素全部压入栈，到底部时停止
   返回上一个元素，往右走，重读上述步骤，如果没有接着返回
 */
void InOrderTraversal(BinTree BT)
{   //BinTree是二叉树结构体指针类型
        BinTree T=BT;
        Stack S = CreatStack(MaxSize);
        while(T || !IsEmpty(S)){
                while(T){
                        Push(S,T);
                        T = T->Left;
                }
                if(!IsEmpty(S)){
                        T = Pop(S); /*结点弹出堆栈*/
                        printf(“%5d”, T->Data); /*（访问）打印结点*/
                        T = T->Right; /*转向右子树*/
                }
        }
}

//先序遍历-非递归算法
void InOrderTraversal(BinTree BT)
{   //BinTree是二叉树结构体指针类型
        BinTree T=BT;
        Stack S = CreatStack(MaxSize);
        while(T || !IsEmpty(S)){
                while(T){
                        //中序改先序将printf提到此处即可
                        printf(“%5d”, T->Data); /*（访问）打印结点*/
                        Push(S,T);
                        T = T->Left;
                }
                if(!IsEmpty(S)){
                        T = Pop(S); /*结点弹出堆栈*/
                        
                        T = T->Right; /*转向右子树*/
                }
        }
}


//后序遍历-非递归算法
/* 最复杂的部分 */
void PostOrder(BiTree T){
	InitStack(S);
	p=T;
	r=NULL;
	while(p!=NULL||!IsEmpty(s)){
		if(p！=NULL){				//走到最左边 
			push(S,p);
			p=p->lchild;
		}
		else{				//向右
			GetTop(S,p);	//读栈顶节点（非出栈） 
			if(p->rchild&&p->rchild!=r){	//若右子树存在，且未被访问过 
				p=p->rchild;	//转向右 	
			}
			else{				//否则弹出结点并访问 
				pop(S,p);
				visit(p->data); //访问该结点
				r=p;			//记录最近访问的结点 
				p=NULL;			//结点访问完后，重置p指针
			}
		}
	}





//  2 层序遍历(队列)
void LevelOrdersal(BinTree BT)
{
        Queue Q;
        BinTree T;
        if(!BT) return ;
        Q = CreatQueue(MaxSize);
        AddQ(Q, BT);
        while(!IsEmptyQ( Q )){
                T = Delete(Q);
                printf("%d", T->Data);
                if(T->Left) AddQ(Q，T->Left);
                if(T-=>Right) AddQ(Q, T->Right);
        }
}


/* 层序遍历输出二叉树中的叶子节点 */

void LevelPrint(BinTree BT){
        if(BT){
                if(!BT->Left && !BT->Right)  //当只有一个根节点是直接输出值
                        printf("%d", BT-> Data);
                LevelOrdersal(Bt->Left);  //左右节点都存在时进入递归
                LevelOrdersal(BT->Right);
        }
}
