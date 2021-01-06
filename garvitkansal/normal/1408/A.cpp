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

void input(){
	cin >> n;
}

void solve(){
	vll a(n), b(n), c(n);
	for(auto &it:a)cin >> it;
	for(auto &it:b)cin >> it;
	for(auto &it:c)cin >> it;
	vll ans(n);
	ans[1] = a[1];
	for(ll i = 2; i < n; i++){
		ll d[3] = {a[i], b[i], c[i]};
		for(ll k = 0; k < 3; k++){
			if(d[k] != ans[i-1])ans[i] = d[k];
		}
	}
	ll d[3] = {a[0], b[0], c[0]};
	for(ll k = 0; k < 3; k++) if(d[k] != ans[n-1] and d[k] != a[1])ans[0] = d[k];
	for(auto it:ans)cout << it << " ";
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