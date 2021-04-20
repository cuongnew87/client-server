#include<iostream> 
#include<string.h>
#include<stdio.h>
#include<conio.h>

using namespace std; 
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
void heapify(SACH a[], int n, int i) 
{ 
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
  
    if (l < n && a[l].gia > a[largest].gia) 
        largest = l; 
  
    if (r < n && a[r].gia > a[largest].gia) 
        largest = r; 
        
    if (largest != i) 
    { 
        swap(a[i], a[largest]); 
        heapify(a, n, largest); 
    } 
}

void heapSort(SACH a[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(a, n, i); 
  
    for (int i=n-1; i>0; i--) 
    { 
        swap(a[0], a[i]); 
        heapify(a, i, 0); 
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
    heapSort(a,n);
    xuat(a,n);
} 

