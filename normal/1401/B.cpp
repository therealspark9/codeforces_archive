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

ll a,b,c,x,y,z;

void input(){
	cin >> a >> b >> c >> x >> y >> z;
}

void solve(){
	ll ans = 0;
	ans += 2*min(c,y);
	ll d = min(c,y);
	c -= d;
	y -= d;
	z -= min(z,a);
	z -= min(z,c);
	b -= min(b,x);
	b -= min(b,y);
	ans -= 2*min(z, b);
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll T = 1;
	cin >> T;
	while(T--){
		input();
		solve();
	}
	cin.get();
	return 0;
}