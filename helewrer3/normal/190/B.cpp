//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb emplace_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
using namespace std;

long double x1,yy1,r1,x2,y2,r2;

void input(){
	cin >> x1 >> yy1 >> r1 >> x2 >> y2 >> r2;
}

void solve(){
	long double d = sqrt((x1-x2)*(x1-x2) + (yy1-y2)*(yy1-y2));
	if(d >= r1 + r2)cout << (d - r1 - r2)/2.0;
	else if(d >= max(r1,r2) - min(r1,r2)) cout << 0;
	else cout << (max(r1,r2) - d - min(r1,r2))/2.0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t;
	t = 1;
	//cin >> t;
	while(t--){
		input();
		solve();
	}
	cin.get();
	return 0;
}