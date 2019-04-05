//
//  main.c
//  LQueue
//
//  Created by 李晓彤 on 2019/4/5.
//  Copyright © 2019年 李晓彤. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LQueue.h"

int DataSize=0;

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
    Node *p=NULL;
    p=(Node*)malloc(sizeof(Node));
    if(p==NULL)printf("初始化失败\n");
    else {
        p->next=NULL;
        Q->front=p;
        Q->rear=p;
        Q->length=0;
        printf("初始化完成\n");
    }
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
    ClearLQueue(Q);
    free(Q->front);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
    if(Q->length==0)return 1;
    else return 0;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e){
    if(IsEmptyLQueue(Q))return 0;
    else {
        memcpy(e, Q->front->next->data, DataSize);
        return 1;
    }
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
    return (int)Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
    Node *p;
    p=(Node*)malloc(sizeof(Node));
    if(p==NULL){
        printf("申请内存失败！\n");
        return 0;
    }else{
        p->data=(void*)malloc(DataSize);
        memcpy(p->data, data, DataSize);
        p->next=NULL;
        Q->rear->next=p;
        Q->rear=p;
        Q->length++;
        return 1;
    }
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
    Node *p=NULL;
    p=(Node*)malloc(sizeof(Node));
    p=Q->front->next;
    Q->front->next=p->next;
    if(Q->rear==p)Q->rear=Q->front;
    free(p);
    Q->length--;
    return 1;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
    if(Q->length==0)return;
    else {
        Node *p=NULL,*q=NULL;
        Q->rear=Q->front;
        p=Q->rear->next;
        Q->rear->next=NULL;
        while(p->next!=NULL){
            q=p;
            p=p->next;
            free(q);
        }
        free(p);
        Q->length=0;
        return;
    }
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
    if(IsEmptyLQueue(Q))return 0;
    else {
        Node *p=NULL;
        for(p=Q->front->next;p->next!=NULL;p=p->next)LPrint(p->data);
        LPrint(p->data);
        printf("\n");
        return 1;
    }
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q){
    if(DataSize==4)printf("%d",*(int*)q);
    if(DataSize==1)printf("%c",*(char*)q);
    if(DataSize==8)printf("%lf",*(double*)q);
    printf("<-");
}

int main(int argc, const char * argv[]) {
    LQueue q;
    void *data=NULL,*d=NULL;
    void *e=NULL;
    char cho = '\0';
    printf("请选择：\n【a】初始化队列\n【b】结束程序\n");
    cho=getchar();
    switch (cho) {
        case 'a':
            while(getchar()!='\n')continue;
            printf("请选择数据类型：\n【a】int\n【b】char\n【c】double\n【d】退出程序\n");
            scanf("%c",&cho);
            switch (cho) {
                case 'a':
                    DataSize=4;
                    break;
                case 'b':
                    DataSize=1;
                    break;
                case 'c':
                    DataSize=8;
                    break;
                case 'd':
                    exit(1);
                default:
                    printf("请输入正确的指令！\n");
                    exit(-1);
                    break;
            }
            while(getchar()!='\n')continue;
            InitLQueue(&q);
            break;
        case 'b':exit(1);break;
        default:
            printf("请输入正确的指令！\n");
            exit(-1);
            break;
    }
    while(1){
        printf("请选择：\n【a】遍历并打印\n【b】判断队列是否为空\n【c】清空队列\n【d】销毁队列\n【e】检测队列长度\n【f】入队\n【g】出队\n【h】得到队头元素\n【z】结束程序\n");
        cho=getchar();
        switch (cho) {
            case 'a':
                if(!(TraverseLQueue(&q, e)))printf("无法遍历\n");
                break;
            case 'b':
                if(IsEmptyLQueue(&q))printf("该队列为空\n");
                else printf("该队列不为空\n");
                break;
            case 'c':
                ClearLQueue(&q);
                printf("清空完成\n");
                break;
            case 'd':
                DestoryLQueue(&q);
                printf("销毁完成\n");
                exit(1);
                break;
            case 'e':
                if(LengthLQueue(&q))printf("该队列长度为%zu\n",q.length);
                else printf("该队列无长度\n");
                break;
            case 'f':
                printf("请输入入队数据：\n");
                if(DataSize==4){
                    d=(int*)malloc(sizeof(int));
                    while(scanf("%d", (int*)d) != 1){
                        printf("请输入正确类型\n");
                        while(getchar() != '\n');
                    }
                    printf("%d",*(int*)d);
                }
                if(DataSize==1){
                    setbuf(stdin, NULL);
                    d=(char*)malloc(sizeof(char));
                    scanf(" %c",(char*)d);   //秘技·空格吃回车
                    printf("%c",*(char*)d);
                }
                if(DataSize==8){
                    d=(double*)malloc(sizeof(double));
                    while(scanf("%lf", (double*)d) != 1){
                        printf("请输入正确类型\n");
                        while(getchar() != '\n');
                    }
                    printf("%lf",*(double*)d);
                }
                data=(void*)malloc(sizeof(DataSize));
                memcpy(data,d,DataSize);
                if(EnLQueue(&q, data))printf("入队成功！\n");
                else printf("入队失败！\n");
                break;
            case 'g':
                if(IsEmptyLQueue(&q))printf("该队已空！\n");
                else {
                    if(DeLQueue(&q))printf("出队成功！\n");
                    else printf("出队失败！\n");
                }
                break;
            case 'h':
                e=(void*)malloc(sizeof(DataSize));
                if(GetHeadLQueue(&q, e)){
                    printf("该队列元素为");
                    if(DataSize==4)printf("%d\n",*(int*)e);
                    if(DataSize==1)printf("%c\n",*(char*)e);
                    if(DataSize==8)printf("%lf\n",*(double*)e);
                }
                else printf("该队列无队顶元素\n");
                break;
            case 'z':exit(1);break;
            default:
                printf("请输入正确的指令！\n");
                exit(-1);
                break;
        }
        while(getchar()!='\n')continue;
    }
    return 0;
}
