#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList.h"

Status add(LinkedList *L){
    LinkedList q=NULL,p=NULL;
    ElemType a = 0;
    while(!(scanf("%d",&a))){
        printf("请输入正确的数据类型!\n");
        setbuf(stdin, NULL);
    }
    if((*L)->next==NULL){
        p=(LinkedList)malloc(sizeof(LNode));
        (*L)->next=p;
        p->data=a;
    }else{
        for(q=*L;q->next!=NULL;q=q->next)continue;
        p=(LinkedList)malloc(sizeof(LNode));
        q->next=p;
        p->data=a;
    }
    p->next=NULL;
    return 1;
}


int main(int argc, const char * argv[])
{
    LinkedList L=NULL,L0=NULL,newNode=NULL,insert=NULL,del=NULL;
    ElemType delete=0;
    ElemType c=0,search=0,searched=0;
    void (*visit)(ElemType e) = NULL;
    int cho=0,f=0;
    do{
        printf("*****************请选择********************\n");
        printf("**************1.构造链表*******************\n");
        printf("**************2.结束程序*******************\n");
        setbuf(stdin, NULL);
        scanf("%d",&cho);
        switch(cho){
            case 1:
                if(InitList(&L)){
                    printf("构造完成\n");
                    f=0;
                }
                else {
                    printf("构造失败\n");
                    f=1;
                }
                break;
            case 2:exit(1);break;
            default:
                printf("请输入正确的指令！\n");
                f=1;
        }
    }while(f);
    do{
        printf("*****************请选择********************\n");
        printf("**************1.销毁链表*******************\n");
        printf("**************2.插入节点*******************\n");
        printf("**************3.删除节点*******************\n");
        printf("**************4.遍历链表*******************\n");
        printf("**************5.寻找节点*******************\n");
        printf("**************6.反转链表*******************\n");
        printf("**************7.判断循环*******************\n");
        printf("**************8.寻找中点*******************\n");
        printf("**************9.输入数据*******************\n");
        printf("**************0.结束程序*******************\n");
        setbuf(stdin, NULL);
        scanf("%d",&cho);
        switch(cho){
            case 1:DestroyList(&L);break;
            case 2:
                printf("请输入想要查找的节点数据：\n");
                scanf("%d",&search);
                searched=SearchList(L, search);
                while(!searched){
                    printf("未找到该节点，请重新输入：\n");
                    setbuf(stdin, NULL);
                    scanf("%d",&search);
                    searched=SearchList(L, search);
                }
                setbuf(stdin, NULL);
                printf("已找到该节点，请输入想插入的数据：\n");
                newNode=(LinkedList)malloc(sizeof(LNode));
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
                if(InsertList(insert,newNode))printf("插入成功\n");
                else printf("插入失败\n");
                break;
            case 3:
                printf("请输入想要查找的节点数据：\n");
                scanf("%d",&delete);
                searched=SearchList(L, delete);
                while(!searched){
                    printf("未找到该节点，请重新输入：\n");
                    setbuf(stdin, NULL);
                    scanf("%d",&delete);
                    searched=SearchList(L,delete);
                }
                setbuf(stdin, NULL);
                printf("已找到该节点 位于第%d位\n",searched);
                del=L;
                for(ElemType i=1;i<searched;i++){
                    del=del->next;
                }
                if(DeleteList(del,&delete)) printf("删除成功\n");
                else printf("该节点不可删除\n");
                break;
            case 4:TraverseList(L,(*visit));break;
            case 5:
                printf("请输入要查询的数据：\n");
                scanf("%d",&c);
                if(SearchList(L,c))printf("已找到 在第%d个节点\n",SearchList(L,c));
                else printf("未找到\n");
                break;
            case 6:
                if(ReverseList(&L))printf("反转完成\n");
                else printf("该链表不可反转\n");
                break;
            case 7:
                if(IsLoopList(L))printf("存在成环\n");
                else printf("没有成环\n");
                break;
            case 8:L0=FindMidNode(&L);break;
            case 9:
                printf("请输入一个整型数据：\n");
                if(add(&L))printf("添加成功！\n");
                break;
            case 0:exit(1);
            default:printf("请输入正确的指令！\n");
        }
    }while(L!=NULL);
    return 0;
}
