#include<iostream>
using namespace std;
class phanso
{
		int tu,mau;
	public:
	friend ostream & operator << (ostream & os, phanso a) //Hien thi phan so ra man hinh
	{
		os<<a.tu<<"/"<<a.mau;
		return os;
	}
	friend istream & operator >> (istream & is, phanso &a)//Nhap phan tu va mau
	{
		cout<<"Nhap tu:";
		is>>a.tu;
		cout<<"Nhap mau:";
		is>>a.mau;
	}
		void rutgon()
		{
			for(int i=1;i<=tu*mau;i++)
			{
				if(tu%i==0 && mau%i==0)
				{
					tu = tu/i;
					mau = mau/i;
				}
			}
		}
		phanso operator , (phanso b)
	{
		tu = tu * b.tu;
		mau = mau * b.mau;
	}
};

int main()
{
	phanso a,b,c,d;
	cin>>a;
	cin>>b;
	a.rutgon();
	b.rutgon();
	cout<<"Phan so vua nhap la:"<<endl;
    cout<<a<<endl;
	cout<<b<<endl;
	c = a , b;
	c.rutgon();
	cout<<"Tich cua 2 phan so la:";
	cout<<c<<endl;
}
