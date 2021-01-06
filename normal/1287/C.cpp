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

ll dp[101][2][2];
map<tuple<ll, ll, ll>, vector<pll>> mp;

void mn(ll i, ll t1, ll t2, bool f){
	ll x = (t1 != t2);
	bool chk = false;
	for(auto it:mp[{i-1, t2, t2}]){
		if(t1) chk = it.s;
		else chk = it.f;
		if(chk or f){
			if(dp[i][t1][t2] > dp[i-1][t2][t2] + x){
				dp[i][t1][t2] = dp[i-1][t2][t2];
				dp[i][t1][t2] += x;
				mp[{i, t1, t2}].clear();
				pll p = it;
				if(!f){
					if(t1)p.s--;
					else p.f--;
				}
				mp[{i, t1, t2}].pb(p);
			}
			else if(dp[i][t1][t2] == dp[i-1][t2][t2] + x){
				pll p = it;
				if(!f){
					if(t1)p.s--;
					else p.f--;
				}
				mp[{i, t1, t2}].pb(p);
			}
		}	
	}
	for(auto it:mp[{i-1, t2, 1-t2}]){
		if(t1) chk = it.s;
		else chk = it.f;
		if(chk or f){
			if(dp[i][t1][t2] > dp[i-1][t2][1-t2] + x){
				dp[i][t1][t2] = dp[i-1][t2][1-t2];
				dp[i][t1][t2] += x;
				mp[{i, t1, t2}].clear();
				pll p = it;
				if(!f){
					if(t1)p.s--;
					else p.f--;
				}
				mp[{i, t1, t2}].pb(p);
			}
			else if(dp[i][t1][t2] == dp[i-1][t2][1-t2] + x){
				pll p = it;
				if(!f){
					if(t1)p.s--;
					else p.f--;
				}
				mp[{i, t1, t2}].pb(p);
			}
		}	
	}
}

void solve(){
	ll n;
	cin >> n;
	vll a(n+1);
	for(ll i = 1; i <= n; i++)cin>>a[i];
	ll x = n/2, y = (n+1)/2;
	for(ll i = 1; i <= n; i++){
		if(!a[i])continue;
		if(a[i]%2)y--;
		else x--;
	}
	dp[0][0][1] = dp[0][0][0] = dp[0][1][1] = dp[0][1][0] = 0;
	mp[{0,0,1}].pb({x, y});
	mp[{0,0,0}].pb({x, y});
	mp[{0,1,0}].pb({x, y});
	mp[{0,1,1}].pb({x, y});
	for(ll i = 1; i <= n; i++){
		dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = inf;
		if(!a[i] or a[i]%2 == 0){	
			mn(i, 0, 0, a[i]);
			mn(i, 0, 1, a[i]);
		}
		if(!a[i] or a[i]%2){
			mn(i, 1, 0, a[i]);
			mn(i, 1, 1, a[i]);
		}
	}
	ll ans = min({dp[n][0][0], dp[n][1][0], dp[n][0][1], dp[n][1][1]});
	cout <<ans;
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