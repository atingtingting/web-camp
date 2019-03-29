#include "duLinkedList.h"

Status InitList_DuL(DuLinkedList *L) {
    //仅使用头节点初始化空链表
    DuLinkedList p=NULL,q=NULL;
    *L=(DuLinkedList)malloc(sizeof(DuLinkedList));
    if(L==NULL){
        printf("申请内存失败！\n");
        exit(-1);
    }else printf("初始化成功，请输入一个整型数据：\n");
    (*L)->prior=NULL;
    (*L)->next=NULL;
    while(!(scanf("%d",&((*L)->data)))){
        printf("请输入一个整型数据：\n");
        setbuf(stdin, NULL);    //清空缓冲
        scanf("%d",&((*L)->data));
    }
    return 1;
}


void DestroyList_DuL(DuLinkedList *L) {
    //销毁链表
    DuLinkedList p = NULL;
    while(*L)
    {   p=(*L)->next;
        free(*L);
        if(p!=NULL)p->prior=NULL;
        *L=p;
    }
    printf("销毁完成\n");
}


Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    //在节点p之前插入节点q
    DuLNode *r=NULL;
    if(p->prior==NULL) return 0;
    else{
        r=p->prior;
        r->next=q;
        q->prior=r;
        q->next=p;
        p->prior=q;
        return 1;
    }
}


Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    //在节点p之后插入节点q
    if(p->next==NULL){
        p->next=q;
        q->prior=p;
        q->next=NULL;
    }else{
        DuLNode *r=NULL;
        r=p->next;
        p->next=q;
        q->prior=p;
        q->next=r;
        r->prior=q;
    }
    return 1;
}

Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    //删除节点p后的第一个节点，并将其值赋给e
    if(p->next==NULL)return 0;
    else{
        DuLNode *r=NULL;
        if(p->next->next==NULL){
            r=p->next;
            e=&r->data;
            p->next=NULL;
            r->prior=NULL;
        }else{
            DuLNode *q=NULL;
            r=p->next;
            p->next=r->next;
            r->prior=NULL;
            q=r->next;
            r->next=NULL;
            q->prior=p;
        }
        return 1;
    }
}

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    //遍历链表并调用函数访问 还是不会用函数orz
    DuLinkedList p;
    p=L;
    for(;p->next!=NULL;p=p->next){
        printf("%d ",p->data);
    }
    printf("%d\n",p->data);
}
