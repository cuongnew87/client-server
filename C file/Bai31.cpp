//Chuong 2: Mang 1 chieu
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void nhapmang(int *a,int n)//Nhap mang
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",a+i);
	}
}
void xuatmang(int *a,int n)//Xuat mang
{
	for(int i=0;i<n;i++)
		printf("%5d",*(a+i));
}
void chiahet(int *a,int n)//Hien thi phan tu chia het cho 3
{
	for(int i=0;i<n;i++)
	{
		if(a[i]%3==0)
		printf("%5d",a[i]);
	}
 }
 int main()
{
	int *pa,n,a[100];
	pa= (int*) malloc(sizeof (int));
	printf("Nhap n:");
	scanf("%d",&n);
	nhapmang(a,n);
	printf("\nMang vua nhap la:\n");
	xuatmang(a,n);
	printf("\nPhan tu chia chet cho 3 la:\n");
	chiahet(a,n);
} 
