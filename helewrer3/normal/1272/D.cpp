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
	vll a(n+1);
	for(ll i = 1; i <= n; i++)cin >> a[i];
	vll pre(n+1, 0), suf(n+1, 0);
	ll t = 1;
	pre[2] = 1;
	for(ll i = 3; i <= n; i++){
		if(a[i-1] > a[i-2])t++;
		else t = 1;
		pre[i] = t;
	}
	suf[n-1] = 1, t = 1;
	for(ll i = n-2; i >= 1; i--){
		if(a[i+1] < a[i+2])t++;
		else t = 1;
		suf[i] = t;
	}
	ll ans = 0;
	for(ll i = 1; i <= n; i++){
		ll tans = 0;
		if(i==1){
			tans = suf[i];
			ans = max(tans, ans);
		}
		else if(i==n){
			tans = pre[i];
			ans = max(ans, tans);
		}
		else{
			tans = pre[i] + suf[i];
			if(a[i-1] < a[i+1])ans = max(ans, tans);
			else ans = max({ans, pre[i], suf[i]});
		}
	}
	t = 1;
	for(ll i = 2; i <=2; i++){
		if(a[i] > a[i-1])t++;
		else t = 1;
		ans = max(t, ans);
	}
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