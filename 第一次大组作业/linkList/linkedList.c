#include "linkedList.h"


/**
 *  @name        : Status InitList(LinkList *L);
 *    @description : initialize an empty linked list with only the head node without value
 *    @param         : L(the head node)
 *    @return         : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    //初始化链表
    *L=(LinkedList)malloc(sizeof(LNode));
    if(*L==NULL)return 0;
    else {
        (*L)->next=NULL;
        printf("请输入一个整型数据：\n");
        while(!(scanf("%d",&((*L)->data)))){
            printf("请输入正确的数据类型!\n");
            setbuf(stdin, NULL);
        }
        return 1;
    }
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *    @description : destroy a linked list, free all the nodes
 *    @param         : L(the head node)
 *    @return         : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L){    //销毁链表
    LinkedList p = *L;
    while((*L)->next){
        p=(*L)->next;
        free(*L);
        *L=p;
    }
    free(*L);
    *L = NULL;
    printf("销毁完成\n");
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *    @description : insert node q after node p
 *    @param         : p, q
 *    @return         : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
    //在节点p之后插入节点q
    LNode *r;
    if(p==NULL){
        return 0;
    }else{
        if(p->next==NULL){
            p->next=q;
            q->next=NULL;
        }else{
            r=p->next;
            p->next=q;
            q->next=r;
        }
        return 1;
    }
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *    @description : delete the first node after the node p and assign its value to e
 *    @param         : p, e
 *    @return         : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    //删除节点p后的第一个节点，并将其值赋给e
    if(p==NULL||p->next==NULL)return 0;
    else{
        if(p->next->next==NULL){
            e=&(p->next)->data;
            p->next=NULL;
        }else{
            e=&(p->next)->data;
            p->next=p->next->next;
        }
        return 1;
    }
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *    @description : traverse the linked list and call the funtion visit
 *    @param         : L(the head node), visit
 *    @return         : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    //遍历
    LinkedList p;
    for(p=L;p->next!=NULL;p=p->next)printf("%d ",p->data);
    printf("%d\n",p->data);
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *    @description : find the first node in the linked list according to e
 *    @param         : L(the head node), e
 *    @return         : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    //根据e找到链表中的第一个节点
    LinkedList p;
    ElemType i=0,f=0;
    if(L->data==e){
        i=1;
        f=1;
        return i;
    }
    else{
        for(p=L;p!=NULL;i++){
            if(p->data==e){
                f=1;
                break;
            }
            if(p->next==NULL)break;
            p=p->next;
        }
        if(f)return i+1;
        else return 0;
    }
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *    @description : reverse the linked list
 *    @param         : L(the head node)
 *    @return         : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    //反转
    LinkedList p=NULL,q=NULL,r=NULL;
    int i=1;
    if((*L)->next==NULL)i=0;
    else if((*L)->next->next==NULL){
        p=(*L)->next;
        (*L)->next=NULL;
        p->next=(*L);
        *L=p;
        for(;(*L)->next!=NULL;*L=(*L)->next){
            printf("%d ",(*L)->data);
        }
        printf("%d\n",(*L)->data);
        *L=p;
    }else{
        p=*L;
        q=(*L)->next;
        r=(*L)->next->next;
        p->next=NULL;
        while(1){
            q->next=p;
            p=q;
            q=r;
            if(q->next==NULL){
                r->next=p;
                break;
            }
            r=r->next;
        }
        for(*L=r;r->next!=NULL;r=r->next)printf("%d ",r->data);
        printf("%d\n",r->data);
    }
    return i;
    
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *    @description : judge whether the linked list is looped
 *    @param         : L(the head node)
 *    @return         : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    //判断是否循环
    LinkedList q=NULL,p=NULL;
    int i=0;
    q=p=L;
    while(q->next!=NULL&&q->next->next!=NULL){
        p=p->next;
        q=q->next->next;
        if(p==q){
            i=1;
            break;
        }
    }
    return i;
    
}
/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *    @description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *    @param         : L(the head node)
 *    @return         : LNode(the new head node)
 *  @notice      : choose to finish
 */
//LNode* ReverseEvenList(LinkedList *L) {
//
//}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *    @description : find the middle node in the linked list
 *    @param         : L(the head node)
 *    @return         : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
    LinkedList p=NULL,q=NULL;
    p=q=*L;
    if(p->next==NULL||p->next->next==NULL){
        printf("%d \n",p->data);
        return p;
    }else{
        while(q->next!=NULL&&q->next->next!=NULL){
            p=p->next;
            q=q->next->next;
        }
        printf("%d \n",p->data);
        return p;
    }
    }
