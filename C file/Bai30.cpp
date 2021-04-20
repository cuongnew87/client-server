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
void tb(int *a,int n)//Tinh trung binh cac phan tu le o vi tri chan
{
	int dem=0;
	int tong=0;
	for(int i=0;i<n;i=i+2)
	{
		if(a[i]%2==1)
		{
	tong= tong + a[i];
	dem++;
}
}
float tb=(float)tong/dem;
if(dem==0)
printf("\nKhong co gia tri");
else
printf("\nGia tri trung binh= %f",tb);

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
	tb(a,n);
}
