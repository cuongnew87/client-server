#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct sinhvien
{
	char Masv[10];
	char Hoten[30];
	char Quequan[30];
	double Dtb;
};
void nhap(sinhvien sv[],int n)
{
for(int i=1;i<=n;i++)
{
	printf("\nSinh vien %d\n",i);
	printf("Masv: "); fflush(stdin);
	gets(sv[i].Masv); 
	printf("Ho ten: "); fflush(stdin);
	gets(sv[i].Hoten);
	printf("Que quan: "); fflush(stdin);
	gets(sv[i].Quequan);
	printf("Diem tb: "); fflush(stdin);
	scanf("%lf",&sv[i].Dtb);
	}	
}
void xuat(sinhvien sv[],int n)
{
	for(int i=1;i<=n;i++)
	{
	printf("Sinh vien %d Ma sv: %s Ho ten: %s Que quan: %s Diem trung binh: %0.2f\n",i,sv[i].Masv,sv[i].Hoten,sv[i].Quequan,sv[i].Dtb);	
		}
	}
float tong(sinhvien sv[],int n)//tinh tong diem cua n sinh vien
{
	double tong=0;
	for(int i=1;i<=n;i++)
	{
		tong= tong + sv[i].Dtb;
	}
	return tong;
}
void cau1(sinhvien sv[],int n,char s1[50])//Nhap vào mot tên sinh viên bat ki tìm xem sinh viên dó có diem so là bao nhieu
{
	for(int i=1;i<=n;i++)
	{
		if(strcmp(sv[i].Hoten,s1)==0)
		printf("Diem trung binh: %0.2f\n",sv[i].Dtb);
}
}
tim1(sinhvien sv[],int n)// hien thi sinh vien co diem >=5
{
	for(int i=1;i<=n;i++)
{
	if(sv[i].Dtb>=5)
	{
		printf("Sinh vien %d\n",i);
		printf("Ma sv: %s\n",sv[i].Masv);
		printf("Ho ten: %s\n",sv[i].Hoten);
		printf("Que quan: %s\n",sv[i].Quequan);
		printf("Diem trung binh: %0.2lf\n",sv[i].Dtb);
	}
}
return 0;
}
tim2(sinhvien sv[],int n)// hien thi sinh vien co diem <5
{
	for(int i=1;i<=n;i++)
{
	if(sv[i].Dtb<5)
	{
		printf("Sinh vien %d\n",i);
		printf("Ma sv: %s\n",sv[i].Masv);
		printf("Ho ten: %s\n",sv[i].Hoten);
		printf("Que quan: %s\n",sv[i].Quequan);
		printf("Diem trung binh: %0.2lf\n",sv[i].Dtb);
	}
}
return 0;
}
int main()
{
	int n;
	struct sinhvien sv[n];
	printf("Nhap so luong :");
	scanf("%d",&n);
	nhap(sv,n);
	printf("\nDanh sach sinh vien vua nhap:\n");
	xuat(sv,n);
	printf("\nTong diem cua sinh vien:%lf",tong(sv,n));
	printf("\nSinh vien co tong diem >=5 :\n");
tim1(sv,n);
printf("\nSinh vien co tong diem <5:\n");
tim2(sv,n);
char s1[50];
printf("Nhap ten sinh vien can tra:");fflush(stdin);
gets(s1);
cau1(sv,n,s1);
	getch();
}
