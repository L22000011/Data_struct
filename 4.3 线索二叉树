/*  线索二叉树
在[lchild,data,rchild]的基础上，如果有空指针，
则让他的空指针指向它的左（右）节点
***此处指针指向取决于先序（中序/后序）遍历顺序：
    ·若先序遍历为：A-B-C-D-E-F
    ·若C右边有空指针，则->D，
    ·若D左边有空指针，指向->C即可
*/


/*
存在的问题：无法判断非空指针的指向是孩子指针还是线索指针
解决：增加标志物LTag,RTag，指示存放的是什么类型指针
[lchild,LTag,data,RTag,rchild]
*/

//线索二叉树结构体描述
typedef enum{Link,Thread} PointerTag;
//Link == 0；代表孩子指针  Thread == 1,线索指针
typedef struct BiThrNode{
        ElemType data;
        struct BinThrNode *lchild, *rchild;
        PointerTag LTag, RTag;
}BiThrNode, *BiThrTree;

void lnorderThreading(BiThrTree &Thrt, BiThrTree T)
{       Thrt=(BiThrTree)malloc(sizeof(BiThrNode));
        if(!Thrt)exit(overflow); 
                Thrt->LTag=Link ； Thrt->RTag= Thread ；
                Thrt->rchild=Thrt ；
        if(!T) Thrt->lchild=Thrt;
        else{
                Thrt->lchild=T; pre=Thrt;
                InThreading(T);
                pre->rchild=Thrt;pre->RTag=Thread;
                Thrt->rchild=pre;           
        } 
}
