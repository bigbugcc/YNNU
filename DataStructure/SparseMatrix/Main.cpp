#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAXSIZE 100

//定义元素
typedef struct
{
    int row, col;
    int e;
} Triple;

//定义三元组
typedef struct
{
    Triple data[MAXSIZE + 1];
    int m;
    int n;
    int len;
}TSMatrix;


//稀疏矩阵一次定位快速转置 
void FastTransposeTSMatrix(TSMatrix A, TSMatrix* B)
{
    int col, t, p, q;
    int num[MAXSIZE], position[MAXSIZE];
    B->len = A.len;
    B->n = A.m;
    B->m = A.n;
    if (B->len)
    {
        for (col = 1; col <= A.n; col++)
            num[col] = 0;
        for (t = 1; t <= A.len; t++)
            num[A.data[t].col]++;  //采用数组下标计数法计算每一列的非零元素的个数 
        position[1] = 1;
        for (col = 2; col <= A.n; col++)  //求col列中第一个非零元素在B.data[]中的正确位置 
            position[col] = position[col - 1] + num[col - 1];
        for (p = 1; p <= A.len; p++)  //将被转置矩阵的三元组表A从头到尾扫描一次，实现矩阵转置 
        {
            col = A.data[p].col;
            q = position[col];
            B->data[q].row = A.data[p].col;
            B->data[q].col = A.data[p].row;
            B->data[q].e = A.data[p].e;
            position[col]++;  //position[col]+1，指向下一个列号为col的非零元素在三元组表B中的存放位置 
        } 
    }
}

int main()
{
    TSMatrix M;
    TSMatrix* N = (TSMatrix*)malloc(sizeof(TSMatrix));
    int i=0;
    printf("请输入稀疏矩阵的行列数和非零元素的个数：\n");
    scanf("%d%d%d", &M.m, &M.n, &M.len);
    printf("请输入非零元素的位置下标和元素值：\n");
    for (i = 1; i <= M.len; i++)
        scanf("%d%d%d", &M.data[i].row, &M.data[i].col, &M.data[i].e);
    printf("\n 稀疏矩阵的三元组表示：");
    for (i = 1; i <= M.len; i++)
        printf("\n%d %d %d", M.data[i].row, M.data[i].col, M.data[i].e);
    FastTransposeTSMatrix(M, N);
    printf("\n 转置后的三元组: ");
    for (i = 1; i <= N->len; i++)
        printf("\n%d %d %d", N->data[i].row, N->data[i].col, N->data[i].e);

    system("pause");
    return 0;
}

