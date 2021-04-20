#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
struct sinhvien
{
	char Masv[10];
	char Hoten[30];
	char Quequan[30];
	double Dtb;
};
int main()
{
	int n;
	printf("Nhap so luong sv:");
	scanf("%d",&n);
struct sinhvien  sv , D13CNPM4[n];
for(int i=1;i<=n;i++)
{
	printf("\nSinh vien %d\n",i);
	printf("Masv: "); fflush(stdin);
	gets(sv.Masv); 
	printf("Ho ten: "); fflush(stdin);
	gets(sv.Hoten);
	printf("Que quan: "); fflush(stdin);
	gets(sv.Quequan);
	printf("Diem tb: "); fflush(stdin);
	scanf("%lf",&sv.Dtb);
	}	
	printf("\nDanh sach sinh vien vua nhap:\n");
	for(int i=1;i<=n;i++)
	{
		printf("Sinh vien %d\n",i);
		printf("Ma sv: %s\n",sv.Masv);
		printf("Ho ten: %s\n",sv.Hoten);
		printf("Que quan: %s\n",sv.Quequan);
		printf("Diem trung binh: %lf\n",sv.Dtb);
	}
	return 0;
}
