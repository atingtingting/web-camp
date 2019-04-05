//
//  main.c
//  AQueue
//
//  Created by 李晓彤 on 2019/4/5.
//  Copyright © 2019年 李晓彤. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AQueue.h"

int DataSize=0;

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q){
    int i;
    for(i=0;i<MAXQUEUE;i++){
        Q->data[i]=(void*)malloc(DataSize);
        if(Q->data[i]==NULL){
            printf("初始化失败！\n");
            exit(-1);
        }
    }
    Q->front=0;
    Q->rear=0;
    Q->length=0;
    printf("初始化成功！\n");
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q){
    int i;
    for(i=0;i<MAXQUEUE;i++)free(Q->data[i]);
    Q->length=0;
    Q->front=0;
    Q->rear=0;
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q){
    if(Q->length==MAXQUEUE)return 1;
    else return 0;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q){
    if(Q->length==0)return 1;
    else return 0;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e){
    if(IsEmptyAQueue(Q))return 0;
    else{
        memcpy(e, Q->data[Q->front], sizeof(Q->data[Q->front]));
        return 1;
    }
}



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
    return (int)Q->length;
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data){
    memcpy(Q->data[Q->rear],data,DataSize);
    Q->length++;
    Q->rear=(Q->rear+1)%MAXQUEUE;
    return 1;
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
    Q->front=(Q->front+1)%MAXQUEUE;
    Q->length--;
    return 1;
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
    Q->front=0;
    Q->rear=0;
    Q->length=0;
}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
    if(IsEmptyAQueue(Q))return 0;
    else{
        int i;
        if((Q->length+Q->front)>MAXQUEUE){       //  排前面了
            for(i=Q->front;i<MAXQUEUE;i++)APrint(Q->data[i]);
            for(i=0;i<Q->rear;i++)APrint(Q->data[i]);
        }else{
            for(i=Q->front;i<Q->front+Q->length;i++)APrint(Q->data[i]);
        }
        printf("\n");
        return 1;
    }
}


/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q){
    if(DataSize==4)printf("%d",*(int*)q);
    if(DataSize==1)printf("%c",*(char*)q);
    if(DataSize==8)printf("%lf",*(double*)q);
    printf("<-");
}


int main(int argc, const char * argv[]) {
    AQueue q;
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
            InitAQueue(&q);
            break;
        case 'b':exit(1);break;
        default:
            printf("请输入正确的指令！\n");
            exit(-1);
            break;
    }
    while(1){
        printf("请选择：\n【a】判断队列是否为满\n【b】判断队列是否为空\n【c】清空队列\n【d】销毁队列\n【e】检测队列长度\n【f】入队\n【g】出队\n【h】得到队头元素\n【i】遍历并打印\n【z】结束程序\n");
        cho=getchar();
        switch (cho) {
            case 'a':
                if(IsFullAQueue(&q))printf("该队列为满\n");
                else printf("该队列不为满\n");
                break;
            case 'b':
                if(IsEmptyAQueue(&q))printf("该队列为空\n");
                else printf("该队列不为空\n");
                break;
            case 'c':
                ClearAQueue(&q);
                printf("清空完成\n");
                break;
            case 'd':
                DestoryAQueue(&q);
                printf("销毁完成\n");
                exit(1);
                break;
            case 'e':
                if(LengthAQueue(&q))printf("该队列长度为%zu\n",q.length);
                else printf("该队列无长度\n");
                break;
            case 'f':
                if(IsFullAQueue(&q))printf("该队已满！\n");
                else{
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
                    if(EnAQueue(&q, data))printf("入队成功！\n");
                    else printf("入队失败！\n");
                }
                break;
            case 'g':
                if(IsEmptyAQueue(&q))printf("该队已空！\n");
                else {
                    if(DeAQueue(&q))printf("出队成功！\n");
                    else printf("出队失败！\n");
                }
                break;
            case 'h':
                e=(void*)malloc(sizeof(DataSize));
                if(GetHeadAQueue(&q, e)){
                    printf("该栈队列元素为");
                    if(DataSize==4)printf("%d\n",*(int*)e);
                    if(DataSize==1)printf("%c\n",*(char*)e);
                    if(DataSize==8)printf("%lf\n",*(double*)e);
                }
                else printf("该队列无队顶元素\n");
                break;
            case 'i':
                if(!(TraverseAQueue(&q, e)))printf("无法遍历\n");
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
