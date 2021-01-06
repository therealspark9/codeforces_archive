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


void solve(){
	ll n, b;
	cin >> n >> b;
	mll mpb;
	while(b%2 == 0){
		mpb[2]++;
		b/=2;
	}
	for(ll i = 3; i*i <= b; i++){
		while(b%i == 0){
			mpb[i]++;
			b/=i;
		}
	}
	if(b != 1)mpb[b]++;
	ll ans = inf;
	for(auto it:mpb){
		ll x = 0, y = it.f, N = n;
		while(N){
			x += N/y;
			N/= y;
		}
		ans = min(x/it.s, ans);
	}
	cout << ans;
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