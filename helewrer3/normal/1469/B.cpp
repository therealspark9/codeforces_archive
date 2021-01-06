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
	ll sum = 0, mx = 0, tsum = 0;
	ll n, m;
	cin >> n;
	vll a(n);
	for(auto &it:a)cin>>it;
	cin >> m;
	vll b(m);
	for(auto &it:b)cin>>it;
	for(ll i = -1; i < n; i++){
		if(i >= 0) tsum += a[i];
		sum = tsum;
		for(ll j = -1; j < m; j++){
			if(j >= 0) sum += b[j];
			mx = max(mx, sum);
		}
	}
	cout << mx;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi