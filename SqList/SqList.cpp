//
// Created by 32585 on 2024/1/21.
//

#include "SqList.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//函数声明
Status Init(SqList L);



int main(){

    return 0;
}

//初始化
Status Init(SqList L){
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
