#include<iostream>
#include<iomanip>
#define Pi 3.14159
using namespace std;
class hinhtron
{
	private:
	float r;
	public:
	void nhap();
	float chuvi();
	float dientich();
	void xuat();
};
void nhap()
	{
	cout <<"Nhap ban kinh:";
	cin>>r;
}
float hinhtron ::chuvi()
{
	return(4*Pi*r);
}
float hinhtron ::dientich()
{
	return(Pi*r*r);
}
void hinhtron ::xuat()
	{
	cout <<"Chu vi hinh tron la:"<<chuvi()<<endl;
	cout <<"Dien tich hinh tron la:"<<dientich()<<endl;
	}
int main()
{
	hinhtron ht;
	ht.nhap();
	ht.chuvi();
	ht.dientich();
	ht.xuat();
}

