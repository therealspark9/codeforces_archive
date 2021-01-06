/*May the force be with me*/
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

ll n, k;

void input(){
	cin >> n >> k;
}

void solve(){
	vll a(n), b(n, 0), vis(n, 0);
	for(auto &it:a)cin >> it;
	map<ll, vll> mp;
	for(ll i = 0; i < n; i++)mp[a[i]].pb(i);
	for(ll i = 0; i < n; i++){
		if(vis[i]) continue;
		if(k - a[i] == a[i]){
			bool f = 0;
			for(auto it:mp[a[i]]){
				b[it] = f;
				f = !f;
				vis[it] = 1;
			}
		}
		else{
			for(auto it:mp[k - a[i]]){
				b[it] = 1;
				vis[it] = 1;
			}
		}
	}
	for(auto it:b)cout << it << " ";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		input();
		solve();
        cout<<endl;
	}
	cin.get();
	return 0;
}