#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "duLinkedList.h"


Status add(DuLinkedList *L){
    DuLinkedList q=NULL,p=NULL;
    ElemType a = 0;
    while(!(scanf("%d",&a))){
        printf("请输入正确的数据类型!\n");
        setbuf(stdin, NULL);
    }
    if((*L)->next==NULL){
        p=(DuLinkedList)malloc(sizeof(DuLNode));
        (*L)->next=p;
        p->prior=*L;
        p->data=a;
    }else{
        for(q=*L;q->next!=NULL;q=q->next)continue;
        p=(DuLinkedList)malloc(sizeof(DuLNode));
        q->next=p;
        p->prior=q;
        p->data=a;
    }
    p->next=NULL;
    return 1;
}

Status Search(DuLinkedList L, ElemType e) {
    //根据e找到链表中的第一个节点
    DuLinkedList p;
    ElemType i=0,f=0;
    if(L->data==e){
        i=1;
        f=1;
        return i;
    }else{
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


int main(int argc, const char * argv[]) {
    int cho=0;
    ElemType search=0,searched=0,delete=0;
    DuLinkedList newNode=NULL,insert=NULL,del=NULL;
    DuLinkedList L=NULL;
    void (*visit)(ElemType e) = NULL;
    printf("******************请选择*******************\n");
    printf("**************1.初始化链表******************\n");
    printf("**************2.结束程序*******************\n");
    scanf("%d",&cho);
    switch(cho){
        case 1:
            if(InitList_DuL(&L))printf("构造完成\n");
            break;
        case 2:exit(1);break;
        default:
            printf("请输入正确的指令！\n");
            exit(-1);
    }
    do{
        printf("******************请选择*******************\n");
        printf("**************1.销毁链表*******************\n");
        printf("**************2.在前插入节点****************\n");
        printf("**************3.在后插入节点****************\n");
        printf("**************4.删除节点*******************\n");
        printf("**************5.遍历链表*******************\n");
        printf("**************6.输入数据*******************\n");
        printf("**************7.寻找节点*******************\n");
        printf("**************0.结束程序*******************\n");
        setbuf(stdin, NULL);
        scanf("%d",&cho);
        switch(cho){
            case 1:DestroyList_DuL(&L);break;
            case 2:
                printf("请输入想要查找的节点数据：\n");
                scanf("%d",&search);
                searched=Search(L,search);
                while(!searched){
                    printf("未找到该节点，请重新输入：\n");
                    setbuf(stdin, NULL);
                    scanf("%d",&search);
                    searched=Search(L, search);
                }
                setbuf(stdin, NULL);
                printf("已找到该节点\n");
                if(searched==1)printf("该位置不可插入节点\n");
                else{
                    newNode=(DuLinkedList)malloc(sizeof(DuLNode));
                    if(newNode==NULL){
                        printf("申请内存失败\n");
                        exit(-1);
                    }
                    printf("请输入想插入的数据：\n");
                    while(!(scanf("%d",&(newNode->data)))){
                        printf("请输入正确的数据类型!\n");
                        setbuf(stdin, NULL);
                    }
                    insert=L;
                    for(ElemType i=1;i<searched;i++){
                        insert=insert->next;
                    }
                    if(InsertBeforeList_DuL(insert,newNode))printf("插入成功\n");
                    else printf("插入失败\n");
                }
                break;
            case 3:
                printf("请输入想要查找的节点数据：\n");
                scanf("%d",&search);
                searched=Search(L,search);
                while(!searched){
                    printf("未找到该节点，请重新输入：\n");
                    setbuf(stdin, NULL);
                    scanf("%d",&search);
                    searched=Search(L, search);
                }
                setbuf(stdin, NULL);
                printf("已找到该节点，请输入想插入的数据：\n");
                newNode=(DuLinkedList)malloc(sizeof(DuLNode));
                if(newNode==NULL){
                    printf("申请内存失败\n");
                    exit(-1);
                }
                while(!(scanf("%d",&(newNode->data)))){
                    printf("请输入正确的数据类型!\n");
                    setbuf(stdin, NULL);
                }
                insert=L;
                for(ElemType i=1;i<searched;i++){
                    insert=insert->next;
                }
                if(InsertAfterList_DuL(insert,newNode))printf("插入成功\n");
                else printf("插入失败\n");
                break;
            case 4:
                printf("请输入想要查找的节点数据：\n");
                scanf("%d",&delete);
                searched=Search(L, delete);
                while(!searched){
                    printf("未找到该节点，请重新输入：\n");
                    setbuf(stdin, NULL);
                    scanf("%d",&delete);
                    searched=Search(L,delete);
                }
                setbuf(stdin, NULL);
                printf("已找到该节点 位于第%d位\n",searched);
                del=L;
                for(ElemType i=1;i<searched;i++){
                    del=del->next;
                }
                if(DeleteList_DuL(del,&delete)) printf("删除成功\n");
                else printf("该节点不可删除\n");
                break;
            case 5:TraverseList_DuL(L,(*visit));break;
            case 6:
                printf("请输入一个整型数据：\n");
                if(add(&L))printf("添加成功！\n");
                break;
            case 7:
                printf("请输入要查询的数据：\n");
                scanf("%d",&search);
                if(Search(L,search))printf("已找到 在第%d个节点\n",Search(L,search));
                else printf("未找到\n");
                break;
            case 0:exit(1);break;
            default:printf("请输入正确的指令！\n");
        }
    }while(L!=NULL);
    return 0;
}
