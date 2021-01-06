//May the force be with me
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb push_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
#define endl "\n"
using namespace std;


void solve(){
	ll n, a, b, c, t;
	cin >> n >> a >> b >> c >> t;
	vll v(n);
	for(auto &it:v)cin >> it;
	if(c-b <= 0)cout << n*a;
	else{
		ll ans = 0;
		vll time(t+1, 0);
		for(ll i = 0; i < n; i++) {
			ans += (a - (t-v[i])*b);
			time[v[i]]++;
		}
		ll cnt = 0;
		for(ll i = 0; i < t; i++){
			cnt += time[i];
			ans += cnt*c;
		}
		cout << ans;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	//cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi