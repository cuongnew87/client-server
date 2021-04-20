#include<stdio.h>
#include<conio.h>
struct SACH
{
	char masach[100];
	char tensach[100];
	int namxb;
	int gia;
};
void nhap(SACH a[],int n)
{
		for(int i=0;i<n;i++)
	{
		printf("Nhap ma sach:"); fflush(stdin);
		gets(a[i].masach);
		printf("Nhap ten sach:"); fflush(stdin);
	    gets(a[i].tensach);
		printf("Nhap nam xuat ban:");
		scanf("%d",&a[i].namxb);	
	    printf("Nhap gia sach:");
		scanf("%d",&a[i].gia);		
	}
}
void xuat(SACH a[],int n)
{
	printf("%10s%10s%15s%10s\n","Ma sach","Ten sach","Nam xuat ban","Gia sach");
	for(int i=0;i<n;i++)
	{
	    printf("%10s%10s%15d%10d\n",a[i].masach,a[i].tensach,a[i].namxb,a[i].gia);	
	}
}
void QuickSort(SACH a[],int l, int r)//Sap xep nhanh
{
    int i,j,x;
    x = a[(l +r)/2].gia;
    i = l;
    j = r;
	do{
		while(a[i].gia < x) i++;
		while(a[j].gia > x) j--;
		if(i <= j)
		{
			int tg = a[j].gia;
			a[j].gia = a[i].gia;
			a[i].gia = tg;
			i++;
			j--;
		}
	}
	while(i < j);
	{
		if(l<j) QuickSort(a,l,j);
		if(i<r) QuickSort(a,r,i);
	}
}
int main()
{
	SACH a[100];
	int n;
	printf("Nhap so phan tu:");
	scanf("%d",&n);
    nhap(a,n);
    printf("Danh sach sau khi nhap:\n");
    xuat(a,n);
    int l = 0;
    int r = n-1;
    printf("\nDanh sach sau khi sap xep la:\n");
    QuickSort(a,l,r);
    xuat(a,n);
}
