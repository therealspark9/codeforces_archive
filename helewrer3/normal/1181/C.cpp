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

bool chkcur(pll p1, pll p2, pll p3){
	return (p2.f != p1.f and p2.f != p3.f and p1.s >= p2.s and p3.s >= p2.s);
}

void solve(){
	ll n, m;
	cin >> n >> m;
	char a[n][m];
	for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++)cin>>a[i][j];
	vector<pair<char, ll>> b[m];
	for(ll j = 0; j < m; j++) {
		ll t = 1;
		for(ll i = 0; i < n-1; i++){
			if(a[i][j] == a[i+1][j]){
				b[j].pb({a[i][j], t});
				t++;
			}
			else{
				b[j].pb({a[i][j], t});
				t = 1;
			}
		}		
		b[j].pb({a[n-1][j], t});
	}
	ll ans = 0, tans = 0;
	for(ll i = 0; i < n; i++){
		tans = (i - b[0][i].s >= 0 and i+b[0][i].s < n and chkcur(b[0][i-b[0][i].s], b[0][i], b[0][i+b[0][i].s]));
		for(ll j = 1; j < m; j++){
			if(!chkcur(b[j][i-b[j][i].s], b[j][i], b[j][i+b[j][i].s]) or i+b[j][i].s >= n or i-b[j][i].s<0){
				ans += tans*(tans+1)/2;
				tans = 0;
			}
			else if(b[j][i] == b[j-1][i] and b[j][i-b[j][i].s].f == b[j-1][i-b[j][i].s].f and b[j][i+b[j][i].s].f == b[j-1][i+b[j][i].s].f and b[j-1][i+b[j][i].s].s >= b[j][i].s and b[j-1][i-b[j][i].s].s >= b[j][i].s)tans++;
			else{
				ans += tans*(tans+1)/2;
				tans = 1;
			}
		}
		ans += tans*(tans+1)/2;
	}
	cout << ans;
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