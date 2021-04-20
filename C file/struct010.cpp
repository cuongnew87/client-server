#include <stdio.h>
#include <string.h>
typedef struct SV{//khong duoc dung dau cach dat ten struct
	char masv[10];//188103104
	char ten[25];
	char que[30];
	float dtb;
};
void nhap( SV A[100],int n)
{
	for(int i=0;i<n;i++)
	{
		//a[i] la 1 sinh vien co day du thong tin : masv,ten,que,dtb
		printf("Nhap ma: ");
		fflush(stdin);
		gets(A[i].masv);
		printf("Nhap ten: ");
		fflush(stdin);
		gets(A[i].ten);
		printf("Nhap que: ");
		fflush(stdin);
		gets(A[i].que);	
		printf("Nhap dtb: ");
		scanf("%f",&A[i].dtb);
	}
}
void xuat(SV A[100],int n)
{
	printf("%-10s%-15s%-15s%-10s\n","Ma SV","Ho Ten","Que","DTB");
	for(int i=0;i<n;i++)
	{
		printf("%-10s%-15s%-15s%-10.2f\n",A[i].masv,A[i].ten,A[i].que,A[i].dtb);
	}
}
void sapxep(SV A[100],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(strcmp(A[i].ten,A[j].ten) > 0)
			{
				SV tg = A[i];
				A[i] = A[j];
				A[j] = tg;
			}
		}
	}
	
}

void dsmaxDTB(SV A[100], int n)
{
	int max = A[0].dtb;
	for(int i = 0; i < n; i++)
	{
		if(A[i].dtb > max)
			max = A[i].dtb;
	}
	printf("%-10s%-15s%-15s%-10s\n","Ma SV","Ho Ten","Que","DTB");
	for(int i = 0; i < n; i++)
	{
		if(A[i].dtb == max)
			printf("%-10s%-15s%-15s%-10.2f\n",A[i].masv,A[i].ten,A[i].que,A[i].dtb);
	}
}
void timkiem(SV A[100], int n, char chuoitimkiem[100])
{
	printf("Diem sv co ten %s la:",chuoitimkiem);
	for(int i = 0; i < n; i++)
	{
		if( strcmpi(A[i].ten,  chuoitimkiem)==0)
			printf("%-10.2f\n",A[i].dtb);
	}
}
float TongDiem(SV A[100],int n)
{
	float T = 0;
	for(int i = 0; i < n; i++)
	{
		T = T + A[i].dtb;
	}
	//printf("Tong diem tat ca sv bang %f",T);
	return T;
}
float TongDiemQueND(SV A[100],int n)
{
	float T = 0;
	for(int i = 0; i < n; i++)
	{
		if(strcmpi(A[i].que,  "Nam Dinh")==0)
			T = T + A[i].dtb;
	}
	return T;
}
void DiemTBlonhon5(SV A[100], int n)
{

	for(int i = 0; i < n; i++)
	{
		if( A[i].dtb>5)
			printf("%-10s%-15s%-15s%-10.2f\n",A[i].masv,A[i].ten,A[i].que,A[i].dtb);
	}
}
int main()
{
	SV a[100];
	nhap(a,2);
	xuat(a,2);
	sapxep(a,2);
	xuat(a,2);
	dsmaxDTB(a,2);
	char str[100];
	printf("Nhap ten sv can tim: ");
	fflush(stdin);
	gets(str);
	timkiem(a,2,str);
	float Tong = TongDiem(a,2);
	printf("Tong diem tat ca sv bang %10.2f",Tong);
	printf("TB Tong diem tat ca sv bang %10.2f",Tong/2);
	
}






