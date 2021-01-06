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
using namespace std;

ll binpow(ll a,ll b){
	if(!b)return 1;
	ll res = binpow(a, b/2);
	if(b%2)return res*res*a;
	else return res*res;
}


void solve(){
	ll a, b;
	vll cnt(10, 0);
	cin >> a >> b;
	ll ta = a, tb = b, na = 0, nb = 0;
	while(ta){
		cnt[ta%10]++;
		na++;
		ta/=10;
	}
	while(tb){
		nb++;
		tb/=10;
	}
	ll n = min(na, nb);
	ll dp[n+1][10][100*n+1];
	for(ll i = 0; i < n+1; i++)for(ll j = 0; j < 10; j++)for(ll k = 1; k <= 100*n; k++)dp[i][j][k] = -1;
	for(ll i = 0; i < 10; i++) if(i*binpow(10, na-1) <= b and cnt[i])dp[1][i][1] = i;
	for(ll i = 2; i <= n; i++){
		for(ll j = 0; j < 10; j++){
			ll pt = 1;
			for(ll k = 0; k < 10; k++){
				for(ll l = 1; l <= 100*n; l++){
					if(dp[i-1][k][l] == -1) break;
					ll tx = dp[i-1][k][l], x = dp[i-1][k][l];
					vll tcnt = cnt;					
					while(tx){
						tcnt[tx%10]--;
						tx/=10;
					}
					if(tcnt[j] <= 0)continue;
					x = x*10+j;
					if(x*binpow(10, n-i) <= b){
						dp[i][j][pt] = max(dp[i][j][pt], x);
						pt++;
						pt%=(100*n+1);
						if(!pt)pt++;
					}
				}
			}
		}
	}
	ll ans = 0;
	for(ll i = 0; i < 10; i++)for(ll j = 1; j <= 100*n; j++)ans = max(dp[n][i][j], ans);
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