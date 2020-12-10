#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAXSIZE 100

//����Ԫ��
typedef struct
{
    int row, col;
    int e;
} Triple;

//������Ԫ��
typedef struct
{
    Triple data[MAXSIZE + 1];
    int m;
    int n;
    int len;
}TSMatrix;


//ϡ�����һ�ζ�λ����ת�� 
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
            num[A.data[t].col]++;  //���������±����������ÿһ�еķ���Ԫ�صĸ��� 
        position[1] = 1;
        for (col = 2; col <= A.n; col++)  //��col���е�һ������Ԫ����B.data[]�е���ȷλ�� 
            position[col] = position[col - 1] + num[col - 1];
        for (p = 1; p <= A.len; p++)  //����ת�þ������Ԫ���A��ͷ��βɨ��һ�Σ�ʵ�־���ת�� 
        {
            col = A.data[p].col;
            q = position[col];
            B->data[q].row = A.data[p].col;
            B->data[q].col = A.data[p].row;
            B->data[q].e = A.data[p].e;
            position[col]++;  //position[col]+1��ָ����һ���к�Ϊcol�ķ���Ԫ������Ԫ���B�еĴ��λ�� 
        } 
    }
}

int main()
{
    TSMatrix M;
    TSMatrix* N = (TSMatrix*)malloc(sizeof(TSMatrix));
    int i=0;
    printf("������ϡ�������������ͷ���Ԫ�صĸ�����\n");
    scanf("%d%d%d", &M.m, &M.n, &M.len);
    printf("���������Ԫ�ص�λ���±��Ԫ��ֵ��\n");
    for (i = 1; i <= M.len; i++)
        scanf("%d%d%d", &M.data[i].row, &M.data[i].col, &M.data[i].e);
    printf("\n ϡ��������Ԫ���ʾ��");
    for (i = 1; i <= M.len; i++)
        printf("\n%d %d %d", M.data[i].row, M.data[i].col, M.data[i].e);
    FastTransposeTSMatrix(M, N);
    printf("\n ת�ú����Ԫ��: ");
    for (i = 1; i <= N->len; i++)
        printf("\n%d %d %d", N->data[i].row, N->data[i].col, N->data[i].e);

    system("pause");
    return 0;
}

