//May the force be with me
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb emplace_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vll a(n);
	for(ll i = 0; i < n; i++)cin >> a[i];
	for(ll j = 30; j >= 0; j--){
		ll x = 1ll<<j, c = 0, idx = -1;
		for(ll i = 0; i < n; i++){
			if(x&a[i]){
				c++;
				idx = i;
			}
		}
		if(c == 1){
			cout<<a[idx]<<" ";
			for(ll i = 0; i < n; i++)if(i != idx)cout<<a[i]<<" ";
			return;
		}
	}
	for(auto it:a)cout<< it << " ";
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