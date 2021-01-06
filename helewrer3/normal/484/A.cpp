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

ll binpow(ll a,ll b){
	if(!b)return 1;
	ll res = binpow(a, b/2);
	if(b%2)return res*res*a;
	else return res*res;
}

ll len(ll x){
	ll res = 0;
	while(x){
		x/=2;
		res++;
	}
	return res-1;
}

void solve(){
	ll l, r;
	cin >> l >> r;
	ll ans = 0;
	while(1){
		ll a = len(l), b = len(r);
		ll x = binpow(2, a), y = binpow(2, b);
		if(l==r){
			ans += l;
			break;
		}
		if(b > a){
			if(r == 2*y-1)ans += 2*y-1;
			else ans += y-1;
			break;
		}
		else if(b==a){
			l -= x;
			r -= y;
			ans += x;
		}
	}
	cout<<ans;
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