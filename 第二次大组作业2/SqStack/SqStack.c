//顺序栈

Status initStack(SqStack *s,int sizes){
    s->elem=(ElemType*)malloc(sizes*sizeof(ElemType));
    if(s->elem==NULL)return 0;
    else{
        s->top=-1;
        s->size=sizes;
        return 1;
    }
}  //初始化栈

Status isEmptyStack(SqStack *s){
    if(s->top==-1)return 1;
    else return 0;
}   //判断栈是否为空

Status getTopStack(SqStack *s,ElemType *e){
    if(s->top==-1)return 0;
    else{
        *e=s->elem[s->top];
        return 1;
    }
}   //得到栈顶元素

Status clearStack(SqStack *s){
    if(s->elem==NULL)return 0;
    else{
        s->top=-1;
        return 1;
    }
}   //清空栈

Status destroyStack(SqStack *s){
    free(s->elem);
    s->top=-1;
    s->size=0;
    s->elem=NULL;
    return 1;
}  //销毁栈

Status stackLength(SqStack *s,int *length){
    if(s->top==-1)return 0;
    else{
        *length=s->top+1;
        return 1;
    }
}   //检测栈长度

Status pushStack(SqStack *s,ElemType data){
    if(s==NULL||s->top>=s->size-1)return 0;
    else{
        s->top++;
        s->elem[s->top]=data;
        return 1;
    }
}  //入栈

Status popStack(SqStack *s,ElemType *data){
    if(s==NULL||s->top==-1)return 0;
    else {
        *data=s->elem[s->top];
        s->top--;
        return 1;
    }
}   //出栈