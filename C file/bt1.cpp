#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void nhapmang(int *a,int n)
{
for(int i=0;i<n;i++)
{
	printf("a[%d]=",i);
	scanf("%d",a+i);
	}	
}
void xuatmang(int *a,int n)
{
	for(int i=0;i<n;i++)
	printf("%5d",*(a+i));
}
void min(int *a,int n)
{
	int min=a[0];
	for(int i=0;i<n;i++)
	{
		if(*(a+i)<min)
		min=*(a+i);
	}
	for(int i=0;i<n;i++)
	{
		if(*(a+i) == min)
		printf("%d",i+1);
	}
}
int max(int *a,int n)
{
	int max=a[0];
		for(int i=0;i<n;i++)
	{
		if(*(a+i)>max)
		max=*(a+i);
	}
	return max;
}
int duongmin(int *a,int n)
{
	int min;
	for(int i=0;i<n;i++)
	{
		if(*(a+i)>0)
		{
		min=*(a+i);
		break;
	}
}
    for(int i=0;i<n;i++)
    {
    	if(*(a+i)>0 && *(a+i)<min )
    	min = *(a+i);
	}
	return min;
}
int ammax(int *a,int n)
{
	int max;
	for(int i=0;i<n;i++)
	{
		if(*(a+i)<0)
		{
		max=*(a+i);
		break;
	}
}
    for(int i=0;i<n;i++)
    {
    	if(*(a+i)<0 && *(a+i)>max )
    	max = *(a+i);
	}
	return max;
}
int kiemtra(int *a,int n,int x)
{
	for(int i=0;i<n;i++)
	{
		if(x == *(a+i))
		return 1;
	}
	return 0;
}
void sapxep(int *a,int n)
{
	int tg;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
		if(*(a+i)>*(a+j))
		{
			tg=*(a+i);
			*(a+i)=*(a+j);
			*(a+j)=tg;
		}
	}
}
}
int tong(int *a,int n)
{
	int tong=0;
	for(int i=0;i<n;i++)
	{
		if(*(a+i)%2!=0)
		tong+=*(a+i);
	}
	return tong;
}
float tbc(int *a,int n)
{
	int tong=0;
	for(int i=0;i<n;i++)
		tong+=*(a+i);
		return (float)tong/n;
	}
int tich(int *a,int n)
{
	int tich=1;
	for(int i=0;i<n;i++)
	if(*(a+i)>0)
	tich *= *(a+i);
	return tich;
}
void chia3(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		if(*(a+i)%3==0)
		printf("%5d",*(a+i));
	}
}
int main()
{
	int n,*a;
	a= (int *) malloc (sizeof (int));
	printf("Nhap n:");
	scanf("%d",&n);
	nhapmang(a,n);
	printf("\nDay vua nhap la:\n");
	xuatmang(a,n);
	printf("\nVi tri co phan tu nho nhat la: ");
	min(a,n);
	printf("\nPhan tu lon nhat la:%d",max(a,n));
	printf("\nPhan tu duong nho nhat la:%d",duongmin(a,n));
	printf("\nPhan tu am lon nhat la:%d",ammax(a,n));
	int x;
	printf("\nNhap x:");
	scanf("%d",&x);
	if(kiemtra(a,n,x) == 1)
	printf("\nX co trong mang");
	else
	printf("\nX khong co trong mang");
	sapxep(a,n);
	printf("\nThu tu sau khi sap xep:\n");
	xuatmang(a,n);
	printf("\nTong cac phan tu le la: %d",tong(a,n));
	printf("\nTBC=%f",tbc(a,n));
	printf("\nTich cac so duong la: %d",tich(a,n));
	printf("\nPhan tu chia het cho 3 la:");
	chia3(a,n);
}
