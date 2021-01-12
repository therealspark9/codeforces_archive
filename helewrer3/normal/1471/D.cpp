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

const ll nax = 1e6+5;
vll ispr(nax), vis(nax, 0);
void sieve(ll x){
	for(ll i = 0; i <= x; i++)ispr[i] = i;
	ispr[1] = 0;
	for(ll i = 2; i*i <= x; i++) if(ispr[i] == i)for(ll j = i*i; j <= x; j+= i)ispr[j] = i;
}

void solve(){
	ll n;
	cin >> n;
	vll a(n);
	for(auto &it:a)cin >> it;
	ll q;
	cin >> q;
	vll b(q);
	for(auto &it:b)cin >>  it;
	for(auto &it:a){
		vll c;
		while(it != 1){
			if(!vis[ispr[it]])c.pb(ispr[it]);
			vis[ispr[it]]++;
			it/=ispr[it];
		}
		for(auto jt:c) {
			if(vis[jt]%2)it *= jt;
			vis[jt] = 0;
		}
	}
	mll d;
	for(auto it:a)d[it]++;
	ll mx_l1 = 0, mx_m1 = 0;
	for(auto it:d)mx_l1 = max(it.s, mx_l1);
	for(auto it:d)if(it.f != 1 and it.s%2 == 0)d[1] += it.s;
	mx_m1 = max(mx_l1, d[1]);
	for(auto it:b){
		if(it < 1)cout<<mx_l1 << " ";
		else cout<<mx_m1 << " ";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	sieve(nax-1);
	ll t = 1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi