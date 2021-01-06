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
	vll b[30];
	for(ll i = 0; i < n; i++)b[a[i]].pb(i);
	ll ans = 0;
	for(ll i = 1; i < 30; i++){
		ans = max(ans, sz(b[i]));
		for(ll k = 0; k < sz(b[i])-1; k++){
			for(ll m = k+1; m < sz(b[i]); m++){
				ll l = b[i][k], r = b[i][m], c = min(k+1, sz(b[i])-1-(m-1));
				for(ll j = 0; j < 30; j++){
					if(i==j)continue;
					auto lt = upper_bound(all(b[j]), l);
					auto rt = upper_bound(all(b[j]), r);
					if(lt == b[j].end())continue;
					rt--;
					ll lp = lt - b[j].begin(), rp = rt - b[j].begin();
					ans = max(ans, 2*c + (rp-lp+1));
				}
			}
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