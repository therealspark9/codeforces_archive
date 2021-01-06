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
const ll nax = 10e5+5;
vll dp(nax, 0);

void input(){
	cin >> n;
}

void solve(){
	vll a(n+1);
	dp[0] = 1;
	for(ll i = 1; i <= n; i++)cin >> a[i];
	for(ll i = 1; i <= n; i++){
		set<ll, greater<ll>> x;
		for(ll j = 1; j*j <= a[i]; j++){
			if(a[i]%j == 0){
				if(j <= i)x.insert(j);
				if(j != a[i]/j and a[i]/j <= i)x.insert(a[i]/j);
			}
		}
		for(auto it:x)dp[it] = (dp[it] + dp[it-1])%mod;
	}
	ll ans = 0;
	for(ll i = 1; i <= n; i++)ans = (ans + dp[i])%mod;
	cout<<ans;
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