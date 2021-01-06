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
	vll a(k), b(61, 0), c(61, 0);
	for(auto &it:a)cin>>it;
	for(ll i = 60; i >= 0; i--){
		for(auto it:a)if(it&(1ll<<i))b[i]++;
		if(n&(1ll<<i))c[i]++;
	}
	// for(auto it:b)cout<<it;
	ll ans = 0;
	for(ll i = 0; i <= 60; i++){
		if(c[i]){
			ll t = 1ll<<i, idx = i;
			while(t and idx >= 0){
				ll d = min(b[idx], t/(1ll<<idx));
				b[idx] -= d;
				t -= d*(1ll<<idx);
				idx--;
			}
			if(t){
				idx = i;
				for(idx = i; idx <= 60; idx++) if(b[idx]) break;
				if(idx > 60){
					cout << -1;
					return;
				}
				ans += (idx-i);
				b[idx]--;
				for(ll j = idx-1; j >= i; j--)b[j]++;
			}
		}
		else{
			b[i+1] += b[i]/2;
			b[i] = b[i]%2;
		}
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