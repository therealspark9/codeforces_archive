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

const ll nax = 5*1e6+5;
vll ispr(nax), ans(nax, 0);
void sieve(ll x){
	for(ll i = 0; i <= x; i++)ispr[i] = i;
	ispr[1] = 0;
	for(ll i = 2; i*i <= x; i++) if(ispr[i] == i)for(ll j = i*i; j <= x; j+= i)ispr[j] = i;
	for(ll i = 2; i <= x; i++){
		ll y = i;
		while(y != 1){
			ans[i]++;
			y /= ispr[y];
		}
		ans[i] += ans[i-1];
	}
}

void solve(){
	ll r, l;
	cin >> r >> l;
	ll res = ans[r]-ans[l];
	cout<<res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	sieve(nax-1);
	while(t--){
		solve();
		cout << endl;
	}
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi