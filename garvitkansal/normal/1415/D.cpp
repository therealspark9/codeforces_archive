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
	ll n;
	cin >> n;
	vll a(n);
	for(auto &it:a)cin>>it;
	vll b(n, 0);
	for(ll i = 0; i < n; i++){
		ll t = 9, it = a[i];
		while(it){
			it/=2;
			t++;
		}
		b[i] = t;
	}
	for(ll i = 0; i < n-2; i++){
		if(b[i] == b[i+2]){
			cout << 1;
			return;
		}
	}
	ll ans = inf;
	for(ll l = 0; l < n; l++){
		for(ll r = l; r < n; r++){
			for(ll m = l; m <= r; m++){
				ll x=-inf, y=inf;
				for(ll j = l; j <= m; j++){
					if(x == -inf)x = a[j];
					else x = x^a[j];
				}
				for(ll j = m+1; j <= r; j++){
					if(y == inf)y = a[j];
					else y = y^a[j];
				}
				if(x > y)ans = min(ans, (m-l)+(r-(m+1)));
			}
		}
	}
	if(ans == inf)cout<<-1;
	else cout<<ans;
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