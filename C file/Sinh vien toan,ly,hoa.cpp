#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class sinhvien //Lop 1 sinh vien
{
	protected:
	char masv[10];
	char ten[30];
	float toan,ly,hoa;
	public:
		sinhvien() //Ham khoi tao
		{
			strcpy(masv,"01"); //Ma sinh vien = 01
			strcpy(ten,"A");  // Ten sinh vien = A
			toan=0;     
			ly=0;
			hoa=0;
		}
		~sinhvien() //Ham huy
		{
		}
		void nhap()
		{
		cout<<"Nhap ma sinh vien:"; fflush(stdin); gets(masv);
		cout<<"Nhap ten sinh vien:"; fflush(stdin); gets(ten);
		cout<<"Nhap diem toan:"; cin>>toan;
		cout<<"Nhap diem ly:"; cin>>ly;
		cout<<"Nhap diem hoa:"; cin>>hoa;
		}
		void xuat()
		{
			cout<<masv<<setw(10)<<ten<<setw(10)<<toan<<setw(10)<<ly<<setw(10)<<hoa<<endl; // setw(10) = Khoang cach giua cac chu la 10 don vi
		}
		float trungbinh() //Tinh diem trung binh cua 1 sinh vien
		{
			return ((toan+ly+hoa)/3);
		}
};
class DanhSach //Lop danh sach gom n sinh vien
{
	sinhvien a[100];
	int n;
	public:
	void nhapN() //Nhap so luong sinh vien
	{
	cout<<"Nhap so luong sinh vien:";
	cin>>n;
	}
	void nhap()
	{
	for(int i=0;i<n;i++)
	{
		a[i].nhap();
	}
}
	void xuat()
	{
	for(int i=0;i<n;i++)
	{
		a[i].xuat();
	}
}
	void trungbinh() //Tinh diem trung binh cua n sinh vien
	{
		float trungbinh[100];
		for(int i=0;i<n;i++)
		{
		trungbinh[i]=a[i].trungbinh();
		}
		cout<<"Danh sach diem trung binh cua sinh vien:"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<trungbinh[i]<<endl;
		}
	}
};
int main()
{
	int n;
	DanhSach ds;
	ds.nhapN();
	ds.nhap();
	ds.xuat();
	ds.trungbinh();
	
}
