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
void dem(int a[100][100],int n,int m)//Dem so chan
{
	int dem=0;
	for(int i=0;i<n;i++)
	{
for(int j=0;j<m;j++)
{
	if(a[i][j]%2==0)
	dem++;
}
}
printf("Co %d so chan",dem);
}

int main()
{
	int a[100][100],n,m;
	do
	{
	printf("Nhap n,m:");
	scanf("%d %d",&n,&m);
}
while (n<2);
	nhapmang(a,n,m);
	printf("\nMa tran vua nhap la:\n");
	xuatmang(a,n,m);
	dem(a,n,m);
}

