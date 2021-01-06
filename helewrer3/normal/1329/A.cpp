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
	ll n, m;
	cin >> n >> m;
	vll a(m), b(m), c(m), vis(m, 0), ans(m, 0);
	for(auto &it:a)cin>>it;
	ll su = 0;
	for(auto it:a)su+=it;
	if(su<n){
		cout<<-1;
		return;
	}
	for(ll i = 0; i < m; i++){
		if(a[i]+i > n){
			cout<<-1;
			return;
		}
	}
	b[m-1] = n - a[m-1] + 1;
	c[m-1] = m-1;
	for(ll i = m-2; i >= 0; i--){
		b[i] = max(b[i+1], n - a[i] + 1);
		if(b[i] == n - a[i] + 1)c[i] = i;
		else c[i] = c[i+1];
	}
	vll tans(m);
	ll tend = 1, tidx = 1;
	for(ll i = 0; i < m; i++){
		tans[i] = tidx;
		tend = max(tend, a[i]+tidx);
		tidx = tend;
	}
	bool g = true;
	for(ll i = 0; i < m; i++)if(tans[i] > n - a[i] + 1)g = false;
	if(g){
		for(auto it:tans)cout<<it<<" ";
		return;
	}
	ll idx = 1, end = 1;
	for(ll i = 0; i < m; i++){
		if(vis[i])continue;
		if(end >= b[i] and end <= n){
			ans[c[i]] = b[i];
			vis[c[i]] = 1;
			end = n+1;
			if(c[i] != i){
				ans[i] = idx;
				idx++;
			}
		}
		else{
			ans[i] = idx;
			end = max(end, a[i]+idx);
			idx++;
		}
		// cout << end << " ";
	}
	// cout << endl;
	for(auto it:ans)cout<<it<<" ";
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