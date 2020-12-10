#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct
{
	int fz;
	int fm;
}Ratio;//有理数数据类型定义

//求两个整数的最大公约数
int gcd(int m, int n)
{
	int g;
	if (m == 0)return n;
	else if (n == 0)return m;
	if (m < 0)m = -m;
	if (n < 0)n = -n;
	if (m < n) { int t = m; m = n; m = t; }//把较小的数放置在变量n中
	for (g = n; g >= 1; g--)
	{
		if (m % g == 0 && n % g == 0)return g;
	}

}

//有理数的和
Ratio Add(Ratio x, Ratio y)
{
	Ratio z;
	z.fz = x.fz * y.fm + x.fm * y.fz;
	z.fm = x.fm * y.fm;           //分数求和
	//约分
	int r = gcd(z.fm, z.fz);
	z.fm = z.fm / r;
	z.fz = z.fz / r;
	return z;
}

//有理数的差
Ratio Minus(Ratio x, Ratio y)
{
	Ratio z;
	z.fz = x.fz * y.fm - x.fm * y.fz;
	z.fm = x.fm * y.fm;           //分数求差 
	//约分
	int r = gcd(z.fm, z.fz);
	z.fm = z.fm / r;
	z.fz = z.fz / r;
	return z;
}

//有理数的乘积
Ratio Mult(Ratio x, Ratio y)
{
	Ratio z;
	z.fm = x.fm * y.fm;
	z.fz = x.fz * y.fz;        //分数求乘 
	int r = gcd(z.fm, z.fz);//约分
	z.fm = z.fm / r;
	z.fz = z.fz / r;
	return z;

}


//有理数的除
Ratio Except(Ratio x, Ratio y)
{
	Ratio z;
	z.fz = x.fz * y.fm;
	z.fm = x.fm * y.fz;
	int r = gcd(z.fm, z.fz);//约分
	z.fm = z.fm / r;
	z.fz = z.fz / r;
	return z;
}


int main()
{
	//变量的定义:
	Ratio a, b, c;
	//变量的值的获取：输入或者赋值
	printf("输入两个有理数：");
	scanf("%d/%d,%d/%d", &a.fz, &a.fm,&b.fz,&b.fm);

	//c=gcd(a,b); 
	//变量的输出
	//printf("%d/%d+%d/%d=%d/%d\n",a.fz,a.fm,b.fz,b.fm,c.fz,c.fm);

	//变量的处理:两个有理数的和
	c = Add(a, b);
	//变量的输出
	printf("有理数的和为 ：");
	printf("%d/%d+%d/%d=%d/%d\n", a.fz, a.fm, b.fz, b.fm, c.fz, c.fm);


	c = Minus(a, b);
	//变量的输出
	printf("有理数的差为 ：");
	printf("%d/%d-%d/%d=%d/%d\n", a.fz, a.fm, b.fz, b.fm, c.fz, c.fm);


	//变量的处理:两个有理数的乘
	c = Mult(a, b);
	//变量的输出
	printf("有理数的乘为 ：");
	printf("%d/%d*%d/%d=%d/%d\n", a.fz, a.fm, b.fz, b.fm, c.fz, c.fm);


	//变量的处理:两个有理数的除 
	c = Except(a, b);
	//变量的输出
	printf("有理数的除为 ：");
	printf("%d/%d/%d/%d=%d/%d\n", a.fz, a.fm, b.fz, b.fm, c.fz, c.fm);

	getch();
	return 0;

}

