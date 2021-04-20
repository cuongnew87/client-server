#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class diemtongket 
{
	protected:
        float toan,ly,hoa;
	public:
	void nhap()
	{
		cout<<"Nhap diem:";
		cin>>toan>>ly>>hoa;
	}
	float diemtb()
	{
		return  (toan+ly+hoa)/3;
	}
	int phanloai()
	{
		if(diemtb() >= 8)
		return 1;
		if(diemtb() < 8 && diemtb() >= 7)
		return 2;
		if(diemtb() < 7 && diemtb()>= 5)
		return 3;
		else
		return 4;
	}
};
class sinhvien : public diemtongket
{
	char masv[10],tensv[10];
	int tuoi;
	public:
	void nhap()
	{
		cout<<"Nhap ma sinh vien"; fflush(stdin);
		gets(masv);
		cout<<"Nhap ten sinh vien"; fflush(stdin);
		gets(tensv);
		cout<<"Nhap tuoi sinh vien"; fflush(stdin);
		cin>>tuoi;
		diemtongket :: nhap();
	}
	
		void xuat()
	{
		cout<<setw(15)<<masv<<setw(15)<<tensv<<setw(10)<<tuoi<<setw(10)<<diemtb()<<endl;
	}
};
int main()
{
	int n;
	sinhvien a[100];
	cout<<"Nhap so luong sinh vien:";
	cin>>n;
	for(int i=i;i<n;i++)
	{
	a[i].nhap();
}
cout<<setw(15)<<"Ma sinh vien"<<setw(15)<<"Ten sinh vien"<<setw(10)<<"Tuoi"<<setw(10)<<"Diem trung binh"<<endl;
	for(int i=0;i<n;i++)
	{
	a[i].xuat();
}
cout<<"Danh sach sinh vien co diem tb tren 8:"<<endl;
for(int i=0;i<n;i++)
{
	float tb = a[i].diemtb();
	if(tb > 8)
	a[i].xuat();
}
int dem=0;
for(int i=0;i<n;i++)
{
	int xeploai=a[i].phanloai();
	if(xeploai == 2)
	dem++;
}
cout<<"Co "<<dem<<" sinh vien dat loai kha";
}
