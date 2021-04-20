#include<stdio.h>
#include<stdlib.h>
void nhapmang(int a[100][100],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void xuatmang(int a[100][100],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
}
void tong(int a[100][100],int n)//Tong duong cheo chinh
{
	int tong=0;
	for(int i=0;i<n;i++)
	{
		
		tong += a[i][i];
		
	}
			printf("%d",tong);
}

int main()
{
	int a[100][100],n;
	printf("Nhap n:");
	scanf("%d",&n);
	nhapmang(a,n);
	printf("\nMa tran vua nhap la:\n");
	xuatmang(a,n);
	printf("\nTong cac phan tu o duong cheo chinh la:\n");
	tong(a,n);
}

