#include<math.h>
#include<iostream>
using namespace std;
int sqr(int x) {
    return x*x;
}

int pow(int a, int b, int MOD) {
    if (b == 0) return 1 % MOD;
    else
        if (b % 2 == 0)
            return sqr(pow(a, b/2)) % MOD;
        else
            return a * (sqr(pow(a, b/2)) % MOD) % MOD;
}
int main()
{
	int a,b,c;
	cout<<"Nhap a,b,c:";
	cin>>a>>b>>c;
	int x = pow(a,b,c);
	cout<<"a^b % c = "<<x;
}
