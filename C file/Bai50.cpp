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
void Max(int a[100][100],int n,int m)//Tong max o hang 2
{
	int max=a[2][0];
for(int j=0;j<m;j++)
{
	if(a[2][j]>max)
	max=a[2][j];
}
printf("%d",max);
}
int main()
{
	int a[100][100],n,m;
	do
	{
	printf("Nhap n,m:");
	scanf("%d %d",&n,&m);
}
while (n<3);
	nhapmang(a,n,m);
	printf("\nMa tran vua nhap la:\n");
	xuatmang(a,n,m);
	printf("\nPhan tu max o hang 2 la:\n");
	Max(a,n,m);
}

