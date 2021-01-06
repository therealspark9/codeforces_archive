//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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

ll n, p;

void input(){
	cin >> n >> p;
}

void solve(){
	ll r[31] = {0};
	r[0] = r[1] = 1;
	for(ll i = 2; i <= 30; i++)r[i] = 2*r[i-1];
	for(ll i = 1; i <= 1000000; i++){
		ll t = n - p*i, x = (1ll)<<32, y = 0;
		if(p*i > n) break;
		for(ll k = 30; k >= 0; k--)
			if(t >= ((1ll)<<k))x |= (1ll)<<k, t -= (1ll)<<k;
		ll z = 0;
		for(ll k = 30; k >= 0; k--)
			if((x&((1ll)<<k)) != 0)y++, z += r[k];
		if((y == i) or (y <= i and z >= i and !t)){
			cout<<i;
			return;
		}
	}
	cout<<-1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t;
	t = 1;
	//cin >> t;
	while(t--){
		input();
		solve();
	}
	cin.get();
	return 0;
}