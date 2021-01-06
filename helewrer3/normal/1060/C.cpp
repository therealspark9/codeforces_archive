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


void solve(){
	ll n, m, x;
	cin >> n >> m;
	vll a(n+1), b(m+1), sa(n+1, 0), sb(m+1, 0);
	for(ll i = 1; i < n+1; i++)cin >> a[i];
	for(ll i = 1; i < n+1; i++)sa[i] = sa[i-1]+a[i];
	for(ll i = 1; i < m+1; i++)cin >> b[i];
	for(ll i = 1; i < m+1; i++)sb[i] = sb[i-1]+b[i];
	cin >> x;
	vll ta(n+1), tb(m+1);
	for(auto &it:ta)it = inf;
	for(auto &it:tb)it = inf;
	for(ll i = 1; i < n+1; i++) for(ll j = i; j < n+1; j++) ta[j-i+1] = min(ta[j-i+1], sa[j]-sa[i-1]);
	for(ll i = 1; i < m+1; i++) for(ll j = i; j < m+1; j++) tb[j-i+1] = min(tb[j-i+1], sb[j]-sb[i-1]);
	ll ans = 0;
	for(ll i = 1; i < n+1; i++) for(ll j = 1; j < m+1; j++) if(ta[i]*tb[j] <= x)ans = max(ans, i*j);
	cout<<ans;
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