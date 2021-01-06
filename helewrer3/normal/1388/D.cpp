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

ll const nax = 2* 1e5+5;
vll a(nax), b(nax), c(nax), in(nax, 0), vis(nax, 0), seg, tseg;
ll ans = 0;

void dfs(ll v){
	vis[v] = 1;
	ans += b[v];
	if(b[v] > 0)seg.pb(v);
	else tseg.pb(v);
	if(a[v] != -1){
		if(b[v] > 0)b[a[v]]+=b[v];
		in[a[v]]--;
		if(!vis[a[v]] and in[a[v]] <= 0){
			dfs(a[v]);
		}
	}
}

void solve(){
	ll n;
	cin >> n;
	for(ll i = 1; i <= n; i++)cin>>b[i];
	for(ll i = 1; i <= n; i++)cin>>c[i];
	for(ll i = 1; i <= n; i++){
		a[i]=c[i];
		if(c[i] != -1)in[c[i]]++;
	}
	for(ll i = 1; i <= n; i++){
		if(!vis[i] and in[i] <= 0)dfs(i);
	}
	cout<<ans<<endl;
	for(auto it:seg)cout<<it<<" ";
	reverse(all(tseg));
	for(auto it:tseg)cout<<it<<" ";
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