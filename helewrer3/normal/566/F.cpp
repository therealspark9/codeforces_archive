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

ll n;
ll const nax = 1e6+5;

void input(){
	cin >> n;
}

void solve(){
	vll a(n), dp(nax, 0);
	for(auto &it:a)cin >> it;
	for(auto &it:a)dp[it]++;
	for(ll i = 1; i < nax; i++){
		if(dp[i]){
			for(ll j = 2*i; j < nax; j += i){
				if(dp[j]) dp[j] = max(dp[j], dp[i]+1);
			}
		}
	}
	ll ans = 0;
	for(auto it:dp)ans = max(ans, it);
	cout << ans;
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