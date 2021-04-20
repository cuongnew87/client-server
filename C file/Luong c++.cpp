#include<iostream>
#include<string.h>
#include<iomanip>
#include<conio.h>
using namespace std;
class NV
{
		char hoten[30];
		char CMND[10];
		char phongban[10];
	public:
		NV()
		{
			strcpy(hoten,"Nguyen Van A");
			strcpy(CMND,"12345");
			strcpy(phongban,"ky thuat");
		}
		NV(char hoten[30],char CMND[10],char phongban[10])
		{
			hoten = hoten;
			CMND = CMND;
			phongban = phongban;
		}
	virtual    void nhap()
		{
			cout<<"Nhap ten:"; fflush(stdin);
			gets(hoten);
			cout<<"CMND:"; fflush(stdin);
			gets(CMND);
			cout<<"Que quan:"; fflush(stdin);
			gets(phongban);
		}
	virtual	 void xuat()
		{
			cout<<setw(15)<<hoten<<setw(15)<<CMND<<setw(15)<<phongban;
		}
	virtual	float tongBC()
	{
	}
	virtual float tongHD()
	{
	}
};
class BC : public NV
{
	float bacluong;
	float luongcb = 10;
	public:
	void nhap()
	{
		NV :: nhap();
		cout<<"Nhap bac luong:";
		cin>>bacluong;
	}
	float tongBC()
	{
		NV :: tongBC();
		return luongcb * bacluong;
	}
	void xuat()
	{
		NV :: xuat();
		cout<<setw(15)<<bacluong<<endl;
	}
};
class HD : public NV
{
	float sogio;
	float sotien;
	public:
	void nhap()
	{
		NV :: nhap();
		cout<<"Nhap so gio:";
		cin>>sogio;
		cout<<"Nhap so tien trong 1 gio:";
		cin>>sotien;
	}
	float tongHD()
	{
		NV :: tongHD();
		return sogio * sotien;
	}
		void xuat()
	{
		NV :: xuat();
		cout<<setw(15)<<sogio<<setw(15)<<sotien<<endl;
	}
};
int main()
{
	int n;
 NV *a[100];
float tongBC = 0;
float tongHD = 0;
	cout<<"Nhap so luong nhan vien:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Chon dang huong luong:"<<endl;
		cout<<"1.Bien che"<<endl;
		cout<<"2.Hopdong"<<endl;
		int chon;
		cin>>chon;
		if(chon == 1)
		{
		a[i] = new BC;
		a[i] ->nhap();
		tongBC += a[i]->tongBC();
		}
		if(chon == 2)
		{
			a[i] = new HD;
			a[i] ->nhap();
			tongHD += a[i]->tongHD();
		}
		}
	for(int i=0;i<n;i++)
	{
		a[i] ->xuat();
	}
	cout<<"Tong luong cua BC la:";	
	cout<<tongBC<<endl;
	cout<<"Tong luong cua HD la:";
	cout<<tongHD;
	}

