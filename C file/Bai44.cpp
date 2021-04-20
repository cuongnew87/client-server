//chuong3: Mang 2 chieu
#include<stdio.h>
#include<stdlib.h>
void nhapmang(int *a,int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("a[%d][%d]=",i,j);
			scanf("%d",a+m * i+j);
		}
	}
}
void xuatmang(int *a,int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%5d",*(a+m*i+j));
		}
		printf("\n");
	}
}
void chuyenvi(int *a,int n,int m)//Hien thi ma tran chuyen vi
{
	for(int i=n-1;i>=0;i--)
	{
		for(int j=m-1;j>=0;j--)
		printf("%5d",*(a+m*i+j));
		printf("\n");
	}
}
int main()
{
	double **pa;
	int a[100][100],n,m;
	pa=(double **) malloc(n * sizeof(double));
	printf("Nhap n,m:");
	scanf("%d %d",&n,&m);
	nhapmang(*a,n,m);
	printf("\nMa tran vua nhap la:\n");
	xuatmang(*a,n,m);
	printf("\nMang dao la:\n");
	chuyenvi(*a,n,m);
}

