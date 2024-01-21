//
// Created by 32585 on 2024/1/21.
//

#ifndef DATA_STRUCT_SQLIST_H
#define DATA_STRUCT_SQLIST_H

#define Status int
#define ElemType int

#define OK 1
#define ERROR -1

#define MAXSIZE 100
#define In_Size 10

typedef struct {
    ElemType * elem;
    int capacity;
    int size;
}SqList;


#endif //DATA_STRUCT_SQLIST_H
