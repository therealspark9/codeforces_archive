//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb emplace_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
using namespace std;

const ll nax = 10e5;
ll n, m;
vll a[nax], b[nax], d1(nax, -1), d2(nax, -1);

void input(){
	cin >> n >> m;
}

void solve(){
	for(ll i = 0; i < m; i++){
		ll u, v;
		cin >> u >> v;
		u--, v--;
		a[u].pb(v);
		a[v].pb(u);
	}
	for(ll i = 0; i < n; i++){
		vll c(n, 0);
		for(auto it:a[i])c[it] = 1;
		for(ll j = 0; j < n; j++) if(i != j and c[j] == 0) b[i].pb(j);
	}
	d1[0] = d2[0] = 0;
	queue<ll> q1, q2;
	q1.push(0), q2.push(0);
	while(!q1.empty()){
		ll v = q1.front();
		q1.pop();
		for(auto it:a[v]){
			if(d1[it] == -1){
				q1.push(it);
				d1[it] = 1 + d1[v];
			}
		}
	}
	while(!q2.empty()){
		ll v = q2.front();
		q2.pop();
		for(auto it:b[v]){
			if(d2[it] == -1){
				q2.push(it);
				d2[it] = 1 + d2[v];
			}
		}
	}
	if(d1[n-1] == -1 or d2[n-1] == -1)cout<<-1;
	else cout << max(d1[n-1], d2[n-1]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll T = 1;
	//cin >> T;
	while(T--){
		input();
		solve();
	}
	cin.get();
	return 0;
}