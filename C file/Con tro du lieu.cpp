#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct sinhvien
{
	char masv[30];
	char tensv[30];
	char quequan[30];
	float diem;
};
void nhap(sinhvien *sv,int n)
{
for(int i=1;i<=n;i++)
{
	printf("Sinh vien %d:\n",i);
	printf("Ma sinh vien:"); fflush(stdin);
	gets((sv+i)->masv);
	printf("Ten sinh vien:"); fflush(stdin);
	gets((sv+i)->tensv);
	printf("Que quan sinh vien:"); fflush(stdin);
	gets((sv+i)->quequan);
	printf("Diem sinh vien:"); fflush(stdin);
	scanf("%f",&(sv+i)->diem);
}
}
void xuat(sinhvien *sv,int n)
{
	printf("%-10s%-10s%-10s%-10s\n","Ma sv","Ten sv","Que quan","Diem");
	for(int i=1;i<=n;i++)
	{	
		printf("%-10s%-10s%-10s%-10.2f\n",((sv+i)->masv),((sv+i)->tensv),((sv+i)->quequan),((sv+i)->diem));
	}
}
void sapxep(sinhvien *sv,int n)
{
	sinhvien *tg;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
		if(((sv+i)->diem)>((sv+j)->diem))
		{
            *tg = *(sv+i);
			*(sv+i) = *(sv+j);
			*(sv+j) = *tg;
	}
}
}
}
int main()
{
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	struct sinhvien *sv;
	sv=(struct sinhvien*) malloc (sizeof(struct sinhvien*));
	nhap(sv,n);
	printf("\nDanh sach sv vua nhap la:\n");
	xuat(sv,n);
	printf("\nDanh sach sv co so diem tang dan la:\n");
	sapxep(sv,n);
	xuat(sv,n);
}
