#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct
{
	int fz;
	int fm;
}Ratio;//�������������Ͷ���

//���������������Լ��
int gcd(int m, int n)
{
	int g;
	if (m == 0)return n;
	else if (n == 0)return m;
	if (m < 0)m = -m;
	if (n < 0)n = -n;
	if (m < n) { int t = m; m = n; m = t; }//�ѽ�С���������ڱ���n��
	for (g = n; g >= 1; g--)
	{
		if (m % g == 0 && n % g == 0)return g;
	}

}

//�������ĺ�
Ratio Add(Ratio x, Ratio y)
{
	Ratio z;
	z.fz = x.fz * y.fm + x.fm * y.fz;
	z.fm = x.fm * y.fm;           //�������
	//Լ��
	int r = gcd(z.fm, z.fz);
	z.fm = z.fm / r;
	z.fz = z.fz / r;
	return z;
}

//�������Ĳ�
Ratio Minus(Ratio x, Ratio y)
{
	Ratio z;
	z.fz = x.fz * y.fm - x.fm * y.fz;
	z.fm = x.fm * y.fm;           //������� 
	//Լ��
	int r = gcd(z.fm, z.fz);
	z.fm = z.fm / r;
	z.fz = z.fz / r;
	return z;
}

//�������ĳ˻�
Ratio Mult(Ratio x, Ratio y)
{
	Ratio z;
	z.fm = x.fm * y.fm;
	z.fz = x.fz * y.fz;        //������� 
	int r = gcd(z.fm, z.fz);//Լ��
	z.fm = z.fm / r;
	z.fz = z.fz / r;
	return z;

}


//�������ĳ�
Ratio Except(Ratio x, Ratio y)
{
	Ratio z;
	z.fz = x.fz * y.fm;
	z.fm = x.fm * y.fz;
	int r = gcd(z.fm, z.fz);//Լ��
	z.fm = z.fm / r;
	z.fz = z.fz / r;
	return z;
}


int main()
{
	//�����Ķ���:
	Ratio a, b, c;
	//������ֵ�Ļ�ȡ��������߸�ֵ
	printf("����������������");
	scanf("%d/%d,%d/%d", &a.fz, &a.fm,&b.fz,&b.fm);

	//c=gcd(a,b); 
	//���������
	//printf("%d/%d+%d/%d=%d/%d\n",a.fz,a.fm,b.fz,b.fm,c.fz,c.fm);

	//�����Ĵ���:�����������ĺ�
	c = Add(a, b);
	//���������
	printf("�������ĺ�Ϊ ��");
	printf("%d/%d+%d/%d=%d/%d\n", a.fz, a.fm, b.fz, b.fm, c.fz, c.fm);


	c = Minus(a, b);
	//���������
	printf("�������Ĳ�Ϊ ��");
	printf("%d/%d-%d/%d=%d/%d\n", a.fz, a.fm, b.fz, b.fm, c.fz, c.fm);


	//�����Ĵ���:�����������ĳ�
	c = Mult(a, b);
	//���������
	printf("�������ĳ�Ϊ ��");
	printf("%d/%d*%d/%d=%d/%d\n", a.fz, a.fm, b.fz, b.fm, c.fz, c.fm);


	//�����Ĵ���:�����������ĳ� 
	c = Except(a, b);
	//���������
	printf("�������ĳ�Ϊ ��");
	printf("%d/%d/%d/%d=%d/%d\n", a.fz, a.fm, b.fz, b.fm, c.fz, c.fm);

	getch();
	return 0;

}

