#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

int main(int argc, const char * argv[]) {
    LinkStack s;
    ElemType e=0,data=0;
    int length=0,f=1,f0=0;
    char cho = '\0';
    printf("请选择：\n【a】初始化栈\n【b】结束程序\n");
    cho=getchar();
    while(f){
        switch (cho) {
            case 'a':
                if(initLStack(&s)){
                    printf("初始化完成\n");
                    f=0;
                }
                else {
                    printf("初始化失败\n");
                    f=1;
                }
                break;
            case 'b':exit(1);break;
            default:
                if(!f0)while(getchar()!='\n')continue;
                f0=1;
                printf("请输入正确的指令！\n");
                f=1;
                cho=getchar();
                break;
        }
        while(getchar()!='\n')continue;
    }
    f=1;
    f0=0;
    while(s.top){
        printf("请选择：\n【a】判断栈是否为空\n【b】得到栈顶元素\n【c】清空栈\n【d】销毁栈\n【e】检测栈长度\n【f】入栈\n【g】出栈\n【z】结束程序\n");
        cho=getchar();
        switch (cho) {
            case 'a':
                if(isEmptyLStack(&s))printf("该栈为空\n");
                else printf("该栈不为空\n");
                break;
            case 'b':
                if(getTopLStack(&s,&e))printf("该栈栈顶元素为%d\n",e);
                else printf("该栈无栈顶元素\n");
                break;
            case 'c':
                if(clearLStack(&s))printf("清空完成\n");
                else printf("该栈无法清空\n");
                break;
            case 'd':
                if(destroyLStack(&s))printf("销毁完成\n");
                f=1;
                while(getchar()!='\n')continue;
                printf("请选择：\n【a】初始化栈\n【b】结束程序\n");
                cho=getchar();
                while(f){
                    switch (cho) {
                        case 'a':
                            if(initLStack(&s)){
                                printf("初始化完成\n");
                                f=0;
                            }
                            else {
                                printf("初始化失败\n");
                                f=1;
                            }
                            break;
                        case 'b':exit(1);break;
                        default:
                            while(getchar()!='\n')continue;
                            printf("请输入正确的指令！\n");
                            f=1;
                            cho=getchar();
                            break;
                    }
                }
                break;
            case 'e':
                if(LStackLength(&s,&length))printf("该栈长度为%d\n",length);
                else printf("该栈无长度\n");
                break;
            case 'f':
                printf("请输入一个整型数据：\n");
                while(!(scanf("%d",&data))){
                    setbuf(stdin, NULL);
                    printf("请输入正确的数据类型!\n");
                }
                if(pushLStack(&s,data))printf("入栈成功\n");
                else printf("无法入栈\n");
                break;
            case 'g':
                if(popLStack(&s,&data))printf("出栈成功\n");
                else printf("无法出栈\n");
                break;
            case 'z':exit(1);break;
            default:
                printf("请输入正确的指令！\n");
                cho=getchar();
                break;
        }
        while(getchar()!='\n')continue;
    }
    return 0;
}

