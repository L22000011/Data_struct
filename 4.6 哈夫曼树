
/*  哈夫曼树（最优二叉树）：WPL最小的二叉树
      WPL = Wk*Ik    [权值×节点长度]
*/

typedef struct TreeNode *HuffmanTree;
struct TreeNode{
        int Weight;
        HuffmanTree  Left, Right;
}
HuffmanTree Huffman(MinHeap H){
        /* 假设H->Size个权值已经存在H->Elements[]->Weight里 */
        int i ;  HuffmanTree T;
        BuildMinHeap(H);  //创建最小堆
        for(i = 1; i ,H->Size; ++i){
                T = malloc(sizeof(struct TreeNode));
                T->Left = DeleteMin(H);  //从最小堆中删除最小值并给T->Left
                T->Right = DeleteMin(H); //找第二小的值给T->Right
                T->Weight = T->Left->Weight + T->Right->Weight;
                /* 权重相加构成新的权重，原本的删除 */
                Insert(H,T);
        }
        T = DeleteMin(H);
        return T;
}



/*
        哈夫曼树没有度为1的节点
        n个叶子节点的哈夫曼树有2*n-1个节点
*/
