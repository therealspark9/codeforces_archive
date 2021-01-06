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

mll mpp, mpq;

ll binpow(ll a,ll b){
	if(!b)return 1;
	ll res = binpow(a, b/2);
	if(b%2)return res*res*a;
	else return res*res;
}

void solve(){
	ll p, q;
	cin >> p >> q;
	mpq.clear();
	while(q%2 == 0){
		mpq[2]++;
		q/=2;
	}
	for(ll i = 3; i*i <= q; i+=2){
		while(q%i == 0){
			mpq[i]++;
			q/=i;
		}
	}
	if(q!=1)mpq[q]++;
	vll b;
	ll P = p;
	for(auto it:mpq){
		if(p%it.f){
			cout << P;
			return;
		}
		ll x = 0;
		while(p%it.f == 0){
			x++;
			p/=it.f;
		}
		if(x >= (it.s-1))b.pb(binpow(it.f, (x - (it.s - 1))));
	}
	if(sz(b)){		
		sort(all(b));
		P/=b[0];
	}
	cout << P;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
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