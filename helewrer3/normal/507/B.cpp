#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll r, x, y, x1, y1;
	cin >> r >> x >> y >> x1 >> y1;
	double d = (x-x1)*(x-x1) + (y-y1)*(y-y1);
	d = sqrt(d);
	r*=2;
	if(d != (ll)d)d++;
	cout << (ll)(d + r-1)/(r);
	return 0;
}