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

ll n, k;
mll mp;

void input(){
	cin >> n >> k;
}

void solve(){
	vll a(n);
	for(auto &it:a)cin >> it;
	sort(all(a));
	for(auto it:a){
		if(it%k)mp[it] = 0;
		else if(!mp.count(it/k))mp[it] = 0;
		else mp[it] = 1 - mp[it/k];
	}
	ll ans = 0;
	for(auto it:mp)ans += it.s;
	cout << max(ans, n - ans);
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