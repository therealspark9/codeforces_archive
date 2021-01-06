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
	vll a(n+1, 0), vis(n+1,0), vis2(n+1, 0);
	map<ll, mll> mp;
	for(ll i = 0; i < n-2; i++){
		ll x, y, z;
		cin >> x >> y >> z;
		a[x]++;
		a[y]++;
		a[z]++;
		mp[x][y]++;
		mp[x][z]++;
		mp[y][z]++;
		mp[y][x]++;
		mp[z][x]++;
		mp[z][y]++;
	}
	ll st, cur;
	for(ll i = 0; i <= n; i++) if(a[i] == 1)st = i;
	vll ans;
	cur = st;
	while(1){
		if(sz(ans) >= n)break;
		vis2[cur] = 1;
		if(cur == st){
			ll nx, nxnx;
			for(auto it:mp[cur]){
				if(a[it.f] == 2)nx = it.f;
				if(a[it.f] == 3)nxnx = it.f;
			}
			vis[cur] = 1;
			vis[nx] = 1;
			vis[nxnx] = 1;
			ans.pb(cur);
			ans.pb(nx);
			ans.pb(nxnx);
			cur = nx;
		}
		else{
			ll nx, nxnx;
			for(auto it:mp[cur]){
				if(!vis[it.f])nxnx = it.f;
				if(vis[it.f] and !vis2[it.f])nx = it.f;
			}
			ans.pb(nxnx);
			vis[nxnx] = 1;
			cur = nx;
		}
	}
	for(auto it:ans)cout << it << " ";
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