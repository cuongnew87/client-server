#include<stdio.h>
#include<stdlib.h>
void nhapmang(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
	printf("a[%d]=",i);
	scanf("%5d",a+i);
}
}
void xuatmang(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%5d",*(a+i));
	}
}
void kiemtra(int *a,int n,int x)//kiem tra x co trong mang khong
{
	int kt;
	for(int i=0;i<n;i++)
	{
		if(x==a[i])
		{
		kt=1;
		break;
	}
}
if(kt==1)
printf("\n%d co trong mang\n",x);
else
printf("\n%d ko co trong mang\n",x);
}
void kiemtra2(int *a,int n)//kiem tra mang co tang dan hay ko
{
	int kt;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
			kt=1;
			break;
		}
	}
}
if(kt==1)
printf("\nMang ko tang dan\n");
else
printf("\nMang tang dan\n");
}
int kiemtra3(int *a,int n)//kiem tra mang co doi xung hay khong
{
	int kt;
	for(int i=1;i<n/2;i++)
	{
		if(a[i]!=a[n-i-1])
		{
		return -1;
		break;
	}
	return 1;
}
}
int main()
{
	int *pa,n,a[100];
 pa=(int *)	malloc (sizeof(int));
printf("Nhap n:");
scanf("%d",&n);
nhapmang(a,n);
printf("\nMang vua nhap la:\n");
xuatmang(a,n);
int x;
printf("\nNhap x:\n");
scanf("%d",&x);
kiemtra(a,n,x);
kiemtra2(a,n);
if(kiemtra3(a,n)==1)
printf("Mang doi xung");
else
printf("Mang ko doi xung");
}
