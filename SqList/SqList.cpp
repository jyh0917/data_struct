//
// Created by 32585 on 2024/1/21.
//

#include "SqList.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//函数声明
//空间初始化
Status Init(SqList &L);
//元素初始化
void Init_SqList(SqList &L);
//打印顺序表
Status printf_Sq(SqList L);

int main(){
    SqList L;
    Init(L);
    Init_SqList(L);
    printf_Sq(L);
    return 0;
}

//初始化
Status Init(SqList &L){
    //创建空间
    L.elem = (ElemType*)malloc(MAXSIZE*sizeof (ElemType));
    //断言
    assert(L.elem);
    //其他元素初始化
    L.capacity = MAXSIZE;
    L.size = 0;
    return OK;
}

//用输入的元素初始化顺序表
void Init_SqList(SqList &L){
    //这是初始化的起始位置
    int start = 0;
    //如果顺序表已存在元素
    if(L.size!=0){
        printf("顺序表中已有元素,请问是否继续输入\n");
        int choose = 1;
        printf("1.继续输入\n2.从头输入\n3.结束\n请输入您的选择:\n");
        while(choose!=3) {
            scanf_s("%d", &choose, sizeof(choose));
            if (choose == 1) {
                //从元素下一个位置开始
                start = L.size;
                goto here;
            } else if (choose == 2) {
                //从顺序表起始位置开始
                start = 0;
                goto flag;
            } else if(choose == 3){
                return;
            }else
                printf("输入错误\n请重新输入:\n");
        }
    }else{
        here:
        flag:
        //输入元素初始化
        printf("下面开始输入您需要输入的元素\n");
        ElemType e = 0;
        printf("输入-9999表示结束输入\n");
        ElemType *p = L.elem + start;
        while(1){
            scanf_s("%d",&e,sizeof (ElemType));
            if(e == -9999){
                printf("请问该元素是否是结束标志\n1.是\n2.不是\n");
                int cho = 0;
                scanf_s("%d",&cho,sizeof (cho));
                if(cho==1)break;
            }
            //开始正式初始化
            *p = e;
            L.size++;
            p++;
        }
        printf("顺序表初始化结束\n");
    }

}

//输出顺序表
Status printf_Sq(SqList L){
    if(L.size==0){
        printf("顺序表为空\n");
        return ERROR;
    } else{
        printf("顺序表元素如下\n");
        ElemType*p = L.elem;
        int count = 0;
        while (count<L.size){
            printf("%d\t",*p++);
            count++;
            if(count%5==0){
                printf("\n");
            }
        }
    }
}