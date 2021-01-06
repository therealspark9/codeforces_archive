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

vll seg[8], num = {6,2,5,5,4,5,6,3,7,6};

void solve(){
	seg[1] = {0,2,3,5,6,7,8,9};
	seg[2] = {0,4,5,6,8,9};
	seg[3] = {0,1,2,3,4,7,8,9};
	seg[4] = {2,3,4,5,6,8,9};
	seg[5] = {0,2,6,8};
	seg[6] = {0,1,3,4,5,6,7,8,9};
	seg[7] = {0,2,3,5,6,8,9};
	ll n, k;
	cin >> n >> k;
	string a[n+1];
	for(ll i = 1; i <= n; i++)cin >> a[i];
	pll dp[n+1][k+1];
	for(ll i = 0; i <= n; i++)for(ll j = 0; j <= k; j++)dp[i][j] = {-1,-1};
	for(ll i = n; i; i--){
		vll b(10,0);
		ll cnt = 0;
		for(ll j = 0; j < 7; j++) if(a[i][j] == '1'){cnt++;for(auto it:seg[j+1])b[it]++;}
		for(ll j = 0; j <= 9; j++){
			if(b[j]!=cnt)continue;
			if(i == n){
				if(num[j]-cnt>k)continue;
				dp[i][num[j]-cnt].f = max(dp[i][num[j]-cnt].f, j);
			}
			else{
				for(ll l = 0; l <= k; l++){
					if(dp[i+1][l].f == -1 or l+(num[j]-cnt) > k)continue;
					if(dp[i][l+(num[j]-cnt)].f < j){
						dp[i][l+(num[j]-cnt)].f = j;
						dp[i][l+(num[j]-cnt)].s = l;
					}
				}
			}
		}
	}
	if(dp[1][k].f == -1)cout << -1;
	else{
		pll x = dp[1][k];
		ll i = 1;
		while(i <= n){
			cout<<x.f;
			x = dp[i+1][x.s];
			i++;
		}
	}
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