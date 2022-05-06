//堆栈和队列
/* 相对应的函数 */

//生成空栈
Stack CreateStack(int MaxSize);
//判断栈满
int IsFull(Stack S, int MaxSize);
//入栈
void Push(Stack S, Elemtype item);
//判断栈是否空
int IsEmpty(Stack S);
//删除并返回栈顶元素
ElemType Pop(Stack S);



/* 结构体定义 */
#define MaxSize <max_number>
typedef struct SNode *Stack;
struct SNode{
    ElemType Data[MaxSize];
    int top;
}

//入栈
void Push(Stack S, Elemtype item){
    //首先判断栈满
    if(S->Top == MaxSize - 1){
        printf("栈满"); return ;  //栈满可以直接返回空
    } else{
        S->Data[++(S->Top)] = item;
        return;
    }
}


//出栈
ElemType Pop(Stack S){
    if(S->Top == -1){
        printf("栈空")；
        return EROOR;
    } else
        return (S->Data[(S->top)--]);
}




//堆栈的应用：表达式，括号匹配；
//前缀表达式（波兰式）
//中缀表达式

/* 此处只写逆波兰式实现，表达式多由数输出 */

//后缀表达式（逆波兰式）
int top,S[1000];
void push(int x){//元素入栈
    top++;
    S[top] = x;
    }
int pop(){//元素出栈
    top--;
    return S[top+1];
    }
int main()
{
    int a,b,i=0;
    top = 0;
    char s[100];
    while(scanf("%s",s)!= EOF){//输入数据以空格相断 如1 2 * 3 4而不是12*34因为scanf("%s",s)读取不了空格后面的，但是while并没有结束，还可以接着输入
        if (s[0] == '+'){
            a = pop();
            b = pop();
            push(a+b);
        }
        else if(s[0] == '-'){
            a = pop();
            b = pop();
            push(b - a);
        }
        else if(s[0] == '*'){
            a = pop();
            b = pop();
            push(a*b);
        }
        else{

            push(atoi(s));
            printf("%d\n",atoi(s));//把字符串变为数字，传入的字符串首地址
        }

    }
    printf("%d",pop());
    return 0;
}


//队列顺序存储实现
#define MaxSize <max>
struct QNode{
    ElemType Data[MaxSiaze];
    int rear;  //尾指针指向哪里，入队的元素就放在那
    int front;  //队列采用双指针，头指针指谁，谁出队
}
typedef struct QNode *Queue;

/* 队列顺序存储实现 */
/* 入队列 */
void AddQ(Queue PtrQ, ElemType item){
    if((PtrQ->rear + 1) % MaxSize == PtrQ->front){
        //循环队列判断队列满的条件
        printf("队列满");
        return ERROR;
    }
    PtrQ->rear = (PtrQ->rear+1) % MAxSize;
    // 将要插入的值放在rear + 1处
    PtrQ-> Data[PtrQ->rear] = item;
}
//    删除元素从队列中
ElemType DeleteQ(Queue PtrQ){
    if(PtrQ->front == PtrQ->rear){
        printf("队列空");
        return ERROR;
    } else{
        PtrQ->front = (PtrQ->front + 1) % MaxSize;
        return PtrQ-> Data[PtrQ->front];
    }
}

///////////////
/* 队列链式存储 */
struct Node{
    ElemType Data;
    struct *Next;
};
struct QNode{
    struct Node *rear;
    struct Node *front;
};
typedef struct QNode *Queue;
Queue PtrQ;



//  eg.不带头结点的链式队列出队操作
/* front指向第一个元素，rear始终指向最后一个元素，不断更新 */
ElemType DeleteQ(Queue PtrQ){
    struct Node *FrontCell;  //结构体指针
    ElemType FrontElem;

    if(PtrQ->front == NULL){
        printf("队列空");
        return ERROE;
    }

    FrontCell = PtrQ->front;
    if(PtrQ->front == PtrQ->rear)
    //当队列只有一个元素时，删除后队列为空
        PtrQ->front = PtrQ->rear = NULL;
    else
        PtrQ->front = PtrQ->front->Next;
    FrontElem = FrontCell->Data;
    free(FrontCell);
    retutrn FrontElem;
}
