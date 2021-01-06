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

ll dx[]{0,1,0,-1};
ll dy[]{-1,0,1,0};

void solve(){
	ll n, m, r, c, x, y;
	cin >> n >> m >> r >> c >> x >> y;
	r--, c--;
	char a[n][m];
	pll b[n][m];
	for(ll i = 0; i < n; i++)for(ll j = 0; j < m; j++)cin>>a[i][j];
	for(ll i = 0; i < n; i++)for(ll j = 0; j < m; j++)b[i][j] = {0,0};
	queue<pll> q, p;
	q.push({r,c});
	b[r][c] = {x,y};
	while(!q.empty()){
		pll v = q.front();
		a[v.f][v.s] = '+';
		q.pop();
		for(ll k = 0; k < 4; k++){
			pll tu = b[v.f][v.s];
			if(v.f+dx[k]<0 or v.f+dx[k]>=n or v.s+dy[k]<0 or v.s+dy[k]>=m)continue;
			if(a[v.f+dx[k]][v.s+dy[k]] != '.') continue;
			if(k == 0 and tu.f == 0)continue;
			if(k == 2 and tu.s == 0)continue;
			if(k == 0)tu.f--;
			if(k == 2)tu.s--;
			b[v.f+dx[k]][v.s+dy[k]] = tu;
			q.push({v.f+dx[k], v.s+dy[k]});
		}
	}
	ll ans = 0;
	for(ll i = 0; i < n; i++)for(ll j = 0; j < m; j++)if(a[i][j] == '+')ans++;
	cout<<ans;
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