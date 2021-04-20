#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class sinhvien
{
	private:
	char masv[12];
	float T,L,H;
	public:
sinhvien()
{
	strcpy(masv,"Nguyen Van A");
	T = 0;
	L = 0;
	H = 0;
}
void nhap()
{
	cout<<"Ma sinh vien:"; fflush(stdin);
	gets(masv);
	cout<<"Diem Toan,Ly,Hoa:";
	cin>>T>>L>>H;
}
void xuat()
{
	cout<<setw(10)<<masv<<setw(10)<<T<<setw(10)<<L<<setw(10)<<H<<setw(10)<<tong()<<setw(10)<<TB()<<endl;
}
float tong()
{
	return T + L + H;
}
float TB()
{
	return tong()/3;
}
};
class DS
{
	sinhvien a[100];
	int n;
	public:
	void nhapN()
	{
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
	cout<<setw(10)<<"Masv"<<setw(5)<<"Toan"<<setw(5)<<"Ly"<<setw(5)<<"Hoa"<<endl;
	for(int i=0;i<n;i++)
	a[i].xuat();	
	}
};
int main()
{
	DS a;
	cout<<"Nhap so luong sinh vien:";
	a.nhapN();
	a.nhap();
	a.xuat();
	
}
