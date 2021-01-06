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

ll n, m, k;
const ll nax = 505;
char a[nax][nax];
ll vis[nax][nax], dx[4] = {-1, 0, +1, 0}, dy[4] = {0, -1, 0, +1};

void dfs(ll i, ll j){
	if(vis[i][j]) return;
	vis[i][j] = 1;
	for(ll p = 0; p < 4; p++){
		ll r = i + dx[p], c = j + dy[p];
		if(r < 0 or r >= n or c < 0 or c >= m or a[r][c] == '#')continue;
		dfs(r, c);
	}
	
	if(k){
		k--;
		a[i][j] = 'X';
	}
}

void input(){
	cin >> n >> m >> k;
}

void solve(){
	ll x = 0, y = 0;
	for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) {
		cin >> a[i][j];
		if(a[i][j] == '.') x = i, y = j;
	}
	dfs(x, y);
	for(ll i = 0; i < n; i++) {
		for(ll j = 0; j < m; j++) cout << a[i][j];
		cout << endl;
	}
	
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