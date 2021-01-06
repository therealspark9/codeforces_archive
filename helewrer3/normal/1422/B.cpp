//May the force be with me
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

ll eq(vll a){
	sort(all(a));
	ll x = a[sz(a)/2], y = a[sz(a)/2-1];
	ll ans1 = 0, ans2 = 0;
	for(auto it:a)ans1 += abs(x-it);
	for(auto it:a)ans2 += abs(y-it);
	return min(ans1, ans2);
}


void solve(){
	ll n, m;
	cin >> n >> m;
	ll a[n][m], ans = 0;
	for(ll i = 0; i < n; i++)for(ll j = 0; j < m; j++)cin >> a[i][j];
	for(ll i = 0; i < n/2; i++) for(ll j = 0; j < m/2; j++){
		ans += eq({a[i][j], a[n-1-i][j], a[i][m-1-j], a[n-1-i][m-1-j]});
	}
	if(n%2){
		for(ll i = 0; i < m/2; i++)ans+=eq({a[n/2][i], a[n/2][m-1-i]});
	}
	if(m%2){
		for(ll i = 0; i < n/2; i++)ans+=eq({a[i][m/2], a[n-1-i][m/2]});
	}
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