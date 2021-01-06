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
using namespace std;


void solve(){
	ll n;
	cin >> n;
	vll a(n);
	for(auto &it:a)cin >> it;
	vector<pll> ans;
	ll v = a[0], cnt = 1;
	for(ll i = 1; i < n; i++) {
		if(a[i] != v)ans.pb({1, i+1});
		else cnt++;
	}
	if(!sz(ans))cout << "NO";
	else{
		if(cnt > 1){			
			ll p = 0;
			for(ll i = 0; i < n; i++)if(a[i] != v) p = i;
			for(ll i = 1; i < n; i++)if(a[i] == v) ans.pb({p+1, i+1});
		}
		cout << "YES\n";
		for(auto it:ans)cout << it.f << " " << it.s << endl;
	}
	
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