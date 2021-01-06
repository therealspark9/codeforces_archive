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
	ll n, m, q;
	cin >> n >> m >> q;
	ll ans = 0;
	vll row(n+1, 0), col(m+1, 0);
	while(q--){
		ll r, c;
		cin >> r >> c;
		row[r]++;
		col[c]++;
	}
	for(ll i = 1; i <= n; i++)if(!row[i])ans++;
	for(ll i = 1; i <= m; i++)if(!col[i])ans++;
	for(ll i = 1; i <= min(n,m); i++)if(!row[i] and !col[i])ans--;
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