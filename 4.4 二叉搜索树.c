//eg1.求二叉树的高度
int PostOrderGerHeight(BinTree BT){
        int HL,HR,MaxH;
        if(BT){
                HL = PostOrderGerHeight(BT->Left);
                HR = PostOrderGerHeight(BT->Right);
                MaxH = (HL > HR) ? HL : HR;
                return (MaxH + 1);
        }
        else return 0;   //如果没有左右节点,最大子树深度为0
}


/* 二叉搜索树
1.非空左子树的所有键值小于其根结点的键值。
2. 非空右子树的所有键值大于其根结点的键值。
3. 左、右子树都是二叉搜索树。
*/

//查找操作 --递归
typedef BinTree Position;
Postion Find(ElemType X, BinTree BST)
{
        if(!BST) return NULL;
        if(X > BST->Data)
                return Find(X, BST->Right);
        else if(X < BST->Data)
                return Find(X,BST->Left);
        else 
                return BST;
}


//查找操作--非递归
Position IterFind(ElemType X, BinTree BST){
        while(BST){
                if(X > BST->Data)
                        BST = BST->Right;
                else if(X < BST->Data)
                        BST = BST-> Left;
                else    
                        return BST;
        }
        return NULL:
}
        
//查找最大最小元素
Position FindMin(BinTree BST){
        if(!BST) return NULL;
        else if(!BST->Left)
                return BST;
        else
                return FindMin(BST->Left);
}

Position FindMax(BinTree BST){
        if(BST)
                while(BST->Right) BST = BST->Right;
        return BST;
}

//二叉搜索树--插入
BinTree Insert( ElementType X, BinTree BST ) {
        if( !BST ){
        /*若原树为空，生成并返回一个结点的二叉搜索树*/
                BST = malloc(sizeof(struct TreeNode));
                BST->Data = X;
                BST->Left = BST->Right = NULL;
        } else /*开始找要插入元素的位置*/
                if( X < BST->Data )
                        BST->Left = Insert( X, BST->Left);
                         /*递归插入左子树*/
                else if( X > BST->Data )
                        BST->Right = Insert( X, BST->Right);
                 /*递归插入右子树*/
                /* else X已经存在，什么都不做 */
        return BST; }


//二叉搜索树--删除
BinTree Delete(ElemType X, BinTree BST){
        Position Tmp;  ///临时变量
        if( !BST ) printf("要删除的元素未找到"); 
        else if( X < BST->Data ) 
                BST->Left = Delete( X, BST->Left); /* 左子树递归删除 */
        else if( X > BST->Data ) 
                 BST->Right = Delete( X, BST->Right); /* 右子树递归删除 */
        else /*找到要删除的结点 */ 
        if( BST->Left && BST->Right ) { /*被删除结点有左右两个子结点 */ 
                Tmp = FindMin( BST->Right ); 
                /*在右子树中找最小的元素填充删除结点*/
                BST->Data = Tmp->Data; 
                BST->Right = Delete( BST->Data, BST->Right);
                 /*在删除结点的右子树中删除最小元素*/
        } else { /*被删除结点有一个或无子结点*/
                Tmp = BST; 
        if( !BST->Left ) /* 有右孩子或无子结点*/
            BST = BST->Right; 
         else if( !BST->Right ) /*有左孩子或无子结点*/
                BST = BST->Left;
                free( Tmp );
        }
 return BST;
}
