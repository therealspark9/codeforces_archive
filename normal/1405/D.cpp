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
ll n, a, b, da, db;
vll disa, vis;
unordered_map<ll, vll> adj;

void input(){
	cin >> n >> a >> b >> da >> db;
	disa.resize(n+5);
	adj.clear();
	for(auto &it:disa)it = -1;
}

void solve(){
	for(ll i = 0; i < n-1; i++){
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v), adj[v].pb(u);
	}
	disa[a] = 0;
	queue<ll> q;
	q.push(a);
	while(!q.empty()){
		ll v = q.front();
		q.pop();
		for(auto it:adj[v]){
			if(disa[it] == -1){
				disa[it] = disa[v]+1;
				q.push(it);
			}
		}
	}
	
	if((disa[b] <= da))cout<<"Alice\n";
	else if(da >= db/2 + (db%2))cout<<"Alice\n";
	else cout<<"Bob\n";
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