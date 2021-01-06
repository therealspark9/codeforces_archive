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

const ll nax = 1e7+5;
vll ispr(nax), sum(nax, 0);
void sieve(ll x){
	for(ll i = 0; i <= x; i++)ispr[i] = i;
	ispr[1] = 0;
	for(ll i = 2; i*i <= x; i++) if(ispr[i] == i)for(ll j = i*i; j <= x; j+= i)ispr[j] = i;
}

void solve(){
	sieve(nax-1);
	ll n;
	cin >> n;
	vll a(n);
	for(auto &it:a)cin >> it;
	for(auto it:a){
		while(it != 1){
			ll b = ispr[it];
			sum[b]++;
			while(it%b==0)it /= b;
		}
	}
	for(ll i = 1; i < nax; i++)sum[i] += sum[i-1];
	ll m;
	cin >> m;
	while(m--){
		ll l, r;
		cin >> l >> r;
		cout << sum[min(r, nax-1)]-sum[min(l, nax)-1] << endl;
	}
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