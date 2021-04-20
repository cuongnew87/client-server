#include<iostream> 
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

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

void xuat(SACH a[],int n)
{
	printf("%10s%10s%15s%10s\n","Ma sach","Ten sach","Nam xuat ban","Gia sach");
	for(int i=0;i<n;i++)
	{
	    printf("%10s%10s%15d%10d\n",a[i].masach,a[i].tensach,a[i].namxb,a[i].gia);	
	}
}

void merge(SACH a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    SACH L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i].gia <= R[j].gia)
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(SACH a[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
 
        merge(a, l, m, r);
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
    mergeSort(a,l,r);
    xuat(a,n);
} 

