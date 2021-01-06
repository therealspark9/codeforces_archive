//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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

ll n, m, k;

ll dx[4] = {-1, 0, +1, 0};
ll dy[4] = {0, -1, 0, +1};

void input(){
	cin >> n >> m >> k;
}

void solve(){
	ll a[n][m];
	for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++)a[i][j] = inf;
	queue<pll> q;
	for(ll i = 0; i < k; i++){
		ll u, v;
		cin >> u >> v;
		u--, v--;
		q.push({u, v});
		a[u][v] = 0;
	}
	
	while(!q.empty()){
		pll v = q.front();
		q.pop();
		for(ll i = 0; i < 4; i++){
			if(v.f+dx[i] < 0 or v.f+dx[i] >= n or v.s + dy[i] < 0 or v.s + dy[i] >= m) continue;
			if(a[v.f+dx[i]][v.s + dy[i]] != inf) continue;
			a[v.f+dx[i]][v.s+dy[i]] = a[v.f][v.s] + 1;
			q.push({v.f+dx[i], v.s+dy[i]});
		}
	}
	
	ll dis = -inf, x = 1, y = 1;
	for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++){
		if(dis < a[i][j]){
			dis = a[i][j];
			x = i+1, y = j+1;
		}
	}
	
	cout << x << " " << y;
	
}

int main(){	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
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