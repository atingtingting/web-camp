#include "LinkStack.h"



Status initLStack(LinkStack *s){
    s->top=(LinkStackPtr)malloc(sizeof(StackNode));
    if(s->top){
        s->count=0;
        s->top->next=NULL;
        return 1;
    }
    else return 0;
}//初始化

Status isEmptyLStack(LinkStack *s){
    if(!(s->count))return 1;
    else return 0;
}//判断链栈是否为空

Status getTopLStack(LinkStack *s,ElemType *e){
    if(!(s->count))return 0;
    else{
        *e=s->top->data;
        return 1;
    }
}  //得到栈顶元素

Status clearLStack(LinkStack *s){
    if(s->top->next==NULL)s->count=0;
    else{
        LinkStackPtr p = NULL;
        while(p){
            p=s->top->next;
            free(s->top);
            s->top=p;
        }
        s->count=0;
    }
    return 1;
}   //清空栈

Status destroyLStack(LinkStack *s){
    if(s->top->next==NULL){
        free(s->top);
        s->count=0;
    }else{
        LinkStackPtr p = NULL;
        while(p){
            p=s->top->next;
            free(s->top);
            s->top=p;
        }
        free(s->top);
        s->count=0;
    }
    return 1;
}   //销毁栈

Status LStackLength(LinkStack *s,int *length){
    if(!(s->count))return 0;
    else{
        *length=s->count;
        return 1;
    }
}    //检测栈的长度

Status pushLStack(LinkStack *s,ElemType data){
    LinkStackPtr p;
    p=(LinkStackPtr)malloc(sizeof(StackNode));
    if(p==NULL)return 0;
    else {
        p->data=data;
        p->next=s->top;
        s->top=p;
        s->count++;
        return 1;
    }
}   //入栈

Status popLStack(LinkStack *s,ElemType *data){
    if(s->count==0)return 0;
    else{
        LinkStackPtr p;
        *data=s->top->data;
        p=s->top;
        s->top=s->top->next;
        free(p);
        s->count--;
        return 1;
    }
}   //出栈
