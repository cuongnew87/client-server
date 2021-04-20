#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void nhap(int *a,int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
		printf("a[%d][%d]=",i,j);
		scanf("%d",a+n*i+j);
	}
	}
}
void xuat(int *a,int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
		printf("%5d",*(a+n*i+j));
	}
	printf("\n");
	}
}
void xoa(int *a,int m,int n)
{
		for(int i=1;i<m-1;i++)
	{
		for(int j=0;j<n;j++)
		{
			*(a+n*i+j) = *(a+n*(i+1)+j);
	}
	}
	m--;
	xuat(a,m,n);
}
int main()
{
	int *a,m,n;
	a = (int *) malloc (sizeof (int));
	printf("Nhap m,n:");
	scanf("%d %d",&m,&n);
	nhap(a,m,n);
	printf("\nMang vua nhap la:\n");
	xuat(a,m,n);
	printf("\nMa tran sau khi xoa dong 0:\n");
	xoa(a,m,n);
}
