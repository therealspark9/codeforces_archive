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
	ll n, k;
	cin >> n >> k;
	vll a(n), b(2*k + 5, 0), c(2*k + 5, 0);
	for(auto &it:a)cin >> it;
	for(ll i = 0; i < n/2; i++){
		c[a[i]+a[n-1-i]]++;
		b[min(a[i], a[n-1-i])+1]++, b[max(a[i], a[n-1-i])+k+1	]--;
	}
	for(ll i = 1; i < sz(b); i++)b[i] += b[i-1];
	ll ans = inf;
	// for(auto it:b)cout<<it<<" ";
	for(ll i = 0; i < sz(b); i++)ans = min(ans, b[i] + (n/2-b[i])*2 - c[i]);
	cout<<ans;
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
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi