//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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

ll n;

void input(){
	cin >> n;
}

void solve(){
	vll a(n);
	for(auto &it:a)cin >> it;
	vll ans(n), vis(a[n-1]+1, 0);
	if(sz(vis) == 1)vis.pb(0);
	for(auto &it:ans)it = -1;
	vis[a[n-1]] = 1;
	for(ll i = n-1; i >= 1; i--)if(a[i] != a[i-1])ans[i] = a[i-1], vis[a[i-1]] = 1;
	ll t = 0;
	while(t < sz(vis) and vis[t])t++;
	for(ll i = 0; i < n; i++){
		if(ans[i] == -1){
			ans[i] = t;
			ll tt = t;
			t++;
			while(t < sz(vis) and vis[t])t++;
			if(t == sz(vis))t = tt;			
		}
	}
	for(auto it:ans)cout<<it<<" ";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	//cin >> t;
	while(t--){
		input();
		solve();
		cout<<endl;
	}
	cin.get();
	return 0;
}