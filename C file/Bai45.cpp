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
void tong(int a[100][100],int b[100][100],int c[100][100],int n,int m)//TInh tong ma tran
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
		c[i][j]=a[i][j]+b[i][j];
		}
}
}
int main()
{
	int a[100][100],b[100][100],c[100][100],n,m;
	printf("Nhap n,m:");
	scanf("%d %d",&n,&m);
	nhapmang(a,n,m);
	printf("\nMa tran A vua nhap la:\n");
	xuatmang(a,n,m);
	nhapmang(b,n,m);
	printf("\nMa tran B vua nhap la:\n");
	xuatmang(b,n,m);
	printf("\nTong 2 ma tran la:\n");
	tong(a,b,c,n,m);
	xuatmang(c,n,m);
}

