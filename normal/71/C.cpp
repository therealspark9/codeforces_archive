/*May the force be with me*/
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
	vll a(n);
	for(auto &it:a)cin >> it;
	vll ans;
	for(ll i = 1; i*i <= n; i++){
		if(n%i == 0){
			ans.pb(i);
			if(i != n/i and i > 2)ans.pb(n/i);
		}
	}
	for(auto it:ans){
		vll cnt(n);
		for(ll i = 0; i < n; i++)cnt[i] = a[i];
		for(ll i = 0; i < n; i++){
			if(!a[i] or i - it < 0)continue;
			cnt[i] += cnt[i - it];
		}
		ll x = 0;
		for(auto jt:cnt)x = max(x, jt);
		if(x >= n/it and n/it > 2){
			cout << "YES";
			return;
		}
	}
	cout << "NO";
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