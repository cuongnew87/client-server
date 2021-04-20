#include<stdio.h>
#include<string.h>
#define MAX 100
struct Sinhvien
{
	char ten[30];
	char masv[10];
	float diem;
	char que[30];
};
struct DSachke
{
	Sinhvien A[MAX];
	int n;
};
void Khoitao(DSachke &a)
{
	a.n = 0;
}
int Ktrarong(DSachke a)
{
	if(a.n == 0)
	return 1;
	return 0;
}
int Ktraday(DSachke a)
{
	if(a.n == MAX)
	return 1;
	return 0;
}
void Chendau(DSachke &a,Sinhvien x)
{
	if(Ktraday(a) == 1)
	{
		return;
	}
	if(a.n > 0)
	{
	for(int i=a.n;i>=1;i--)
	{
		a.A[i] = a.A[i-1];
	}
	a.A[0] = x;
	a.n++;
}
}
void Chencuoi(DSachke &a,Sinhvien x)
{
	if(Ktraday(a) == 1)
	{
		return;
	}
		a.A[a.n] = x;
		a.n ++;
}
void Chenvitri(DSachke &a,Sinhvien x,int p)
{
	if(Ktraday(a) == 1)
	{
		return;
	}
	if(p == 0)
	{
	Chendau(a,x);
	}
    else if(p == a.n)
	{
	Chencuoi(a,x);
	}
	else
	{
		for(int i=a.n;i>p;i++)
		{
			a.A[i] = a.A[i-1];
		}
		a.A[p] = x;
	}
}
void Xoadau(DSachke &a)
{
	if(Ktrarong(a) == 1)
	{
		return;
	}
	else
	{
		for(int i=0;i<a.n;i++)
		{
			a.A[i] = a.A[i+1];
		}
		a.n--;
	}
}
void Xoacuoi(DSachke &a)
{
	if(Ktrarong(a) == 1)
	{
		return;
	}
	else
	{
		a.n--;
	}
}
void Xoavitri(DSachke &a,int p)
{
	if(Ktrarong(a) == 1)
	{
		return;
	}
	if(p == 0)
	{
		Xoadau(a);
	}
	else if(p == a.n-1)
	{
		Xoacuoi(a);
	}
	else
	{
		for(int i=p;i<a.n;i++)
		{
			a.A[i] = a.A[i+1];
		}
		a.n--;
	}
}
void nhapsv(Sinhvien &a)
{
	printf("Ma sinh vien:");
	fflush(stdin);  gets(a.masv);
	printf("Ten sinh vien:");
	fflush(stdin);  gets(a.ten);
	printf("Que quan:");
	fflush(stdin);  gets(a.que);
	printf("Diem:");
	scanf("%f",&a.diem);
}
void xuat(Sinhvien a)
{
		printf("%10s%10s%10s%10.2f\n",a.masv,a.ten,a.que,a.diem);
}
void xuatds(DSachke a)
{
	for(int i=0;i<a.n;i++)
	{
		xuat(a.A[i]);
	}
}
int main()
{
	int n;
	DSachke ds;
	Sinhvien x,y;
	printf("Nhap so luong sinh vien:");
	scanf("%d",&n);
	Khoitao(ds);
	for(int i=0;i<n;i++)
	{
		nhapsv(x);	
		Chencuoi(ds,x);
	}
	xuatds(ds);
	nhapsv(y);
	Chendau(ds,y);
	printf("\nDanh sach sinh vien sau khi chen dau:\n");
	xuatds(ds);
}
