#include<stdio.h>
#include<stdlib.h>
void nhapmang(int a[100][100],int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void xuatmang(int a[100][100],int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
}
void tong(int a[100][100],int n,int m)//Tong cac phan tu
{
	int tong=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
		tong += a[i][j];
		}
	}
		printf("%d",tong);
}
int main()
{
	int a[100][100],n,m;
	printf("Nhap n,m:");
	scanf("%d %d",&n,&m);
	nhapmang(a,n,m);
	printf("\nMa tran vua nhap la:\n");
	xuatmang(a,n,m);
	printf("\nTong cac phan tu la:\n");
	tong(a,n,m);
}

