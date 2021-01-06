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
	ll x = 0, N = n;
	while(n){
		x++;
		n>>=1;
	}
	ll ans = 1;
	while(x--) ans <<= 1;
	ans--;
	if(N != ans)cout << ans;
	else{
		ans = 1;
		for(ll i = 2; i*i <= N; i++){
			if(N%i == 0){
				ans = max(ans, i);
				ans = max(ans, N/i);
			}
		}
		cout<<ans;
	}
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