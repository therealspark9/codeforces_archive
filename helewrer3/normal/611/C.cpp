#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb emplace_back
#define vll vector<long long>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long)(x).size())
#define mll map<long long, long long>
#define pll pair<long long, long long>
using namespace std;

ll n, m;
ll const nax = 505;

void input(){
	cin >> n >> m;
}

void solve(){
	char a[n][m];
	for(ll i = 0; i < n; i++)for(ll j = 0; j < m; j++)cin >> a[i][j];
	ll h[nax][nax] = {0}, v[nax][nax] = {0};
	for(int y = 0; y < n; ++y) for(int x = 0; x < m; ++x) {
		h[x+1][y+1] = h[x][y+1] + h[x+1][y] - h[x][y];
		v[x+1][y+1] = v[x][y+1] + v[x+1][y] - v[x][y];
		if(a[y][x] != '.') continue;
		if(x != m - 1 && a[y][x+1] == '.') ++h[x+1][y+1];
		if(y != n - 1 && a[y+1][x] == '.') ++v[x+1][y+1];
	}
	ll q;
	cin >> q;
	while(q--){
		ll x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		x1--, y1--;
		ll ans = 0;
		ans += h[x2-1][y2] - h[x1][y2] - h[x2-1][y1] + h[x1][y1];
		ans += v[x2][y2-1] - v[x1][y2-1] - v[x2][y1] + v[x1][y1];
		cout<<ans<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	cout.precision(20);
	ll t;
	t = 1;
	//cin >> t;
	while(t--){
		input();
		solve();
	}
	cout << endl;
	return 0;
}