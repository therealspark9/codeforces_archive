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
	vll a(n), b(n+1,0), c(n+1,0);
	for(auto &it:a)cin >> it;
	set<ll> s;
	for(ll i = 0; i < n; i++){
		if(sz(s)){
			auto it = s.upper_bound(a[i]);
			if(it != s.end()){
				auto jt = it;
				jt++;
				if(jt == s.end())b[(*it)]++;
			}
			else c[a[i]]=1;
		}
		else c[a[i]] = 1;
		s.insert(a[i]);
	}
	for(auto &it:b)if(!it)it = 1;
	ll mx = 1;
	for(auto it:b)mx = max(mx, it);
	vll ans;
	for(ll i = 1; i < n+1; i++) if(mx == b[i])ans.pb(i);
	for(auto it:ans){
		if(c[it] == 0){
			cout << it;
			return;
		}
	}
	cout << ans[0];
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