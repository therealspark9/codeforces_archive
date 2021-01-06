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
	for(auto &it:a)cin >> it;
	ll o = (n+1)/2, e = n/2;
	for(auto it:a){
		if(!it)continue;
		if(it%2)o--;
		else e--;
	}
	ll l_val = -1, l_idx = -1;
	vector<pll> v11, v00, v10, v01;
	for(ll i = 0; i < n; i++){
		ll it = a[i];
		if(!it)continue;
		if(it%2){
			if(l_val == -1) v11.pb({i-l_idx-1,1});
			else if(l_val%2) v11.pb({i-l_idx-1,0});
			else v01.pb({i-l_idx-1,0});
		}
		else{
			if(l_val == -1)v00.pb({i-l_idx-1,1});
			else if(l_val%2 == 0)v00.pb({i-l_idx-1,0});
			else v10.pb({i-l_idx-1,0});
		}
		l_idx = i, l_val = it%2;
	}
	if(l_val != -1){
		if(l_val%2)v11.pb({n-l_idx-1,1});
		else v00.pb({n-l_idx-1,1});
	}
	sort(all(v00));
	sort(all(v11));
	ll ans = sz(v01)+sz(v10);
	for(auto it:v11){
		if(it.s == 1)continue;
		if(o >= it.f)o -= it.f;
		else ans+=2;
	}
	for(auto it:v11){
		if(it.s == 0)continue;
		if(o >= it.f)o -= it.f;
		else ans++;
	}
	for(auto it:v00){
		if(it.s == 1)continue;
		if(e >= it.f)e -= it.f;
		else ans+=2;
	}
	for(auto it:v00){
		if(it.s == 0)continue;
		if(e >= it.f)e -= it.f;
		else ans++;
	}
	bool f = 0;
	for(auto it:a)f|=it;
	if(!f and n > 1)ans++;
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