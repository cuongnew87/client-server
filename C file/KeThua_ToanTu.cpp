#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>

using namespace std;
class CNguoi
{
	protected:
		char m_strHoTen[30];
		int m_iTuoi;
		char m_strDiaChi[30];
	public:
		friend istream & operator>>(istream & is,CNguoi& x)
		{
			fflush(stdin);
			cout<<"Nhap ten :";
			is.getline(x.m_strHoTen,30);
			cout<<"nhap tuoi :";
			is>>x.m_iTuoi;
			fflush(stdin);
			cout<<"Nhap dia chi :";
			is.getline(x.m_strDiaChi,30);
			return is;
		}
		friend ostream & operator<<(ostream &os,CNguoi &x)
		{
		
			os<<"Ten :"<<x.m_strHoTen<<endl;
			os<<"Tuoi :"<<x.m_iTuoi<<endl;
			os<<"Dia chi :"<<x.m_strDiaChi;
			return os;
		}
};
class CHocSinh :public CNguoi
{
	protected:
		float m_fToan;
		float m_fVan;
		float m_fDTB;
	public:
		friend istream & operator>>(istream &is,CHocSinh &x)
		{
			CNguoi *t = &x;
			is>>*t;
			cout<<"Nhap diem toan :";
			is>>x.m_fToan;
			cout<<"Nhap diem van :";
			is>>x.m_fVan;
			x.m_fDTB = (x.m_fVan + x.m_fToan )/2;
			return is;
		}
		friend ostream & operator<<(ostream &os,CHocSinh &x)
		{
			CNguoi *t = &x;
			os<<*t;
			os<<"ho ten :"<<x.m_strHoTen<<endl;
			os<<"toan :"<<x.m_fToan<<" van :"<<x.m_fVan;
			os<<" DTB :"<<x.m_fDTB;
			return os;
		}
};;

int main()
{
	CHocSinh obj;
	
	cin>>obj;
	cout<<obj;
	return(0);
}
