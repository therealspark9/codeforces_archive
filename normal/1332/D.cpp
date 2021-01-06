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

ll len(ll x){
	ll res = 0;
	while(x){
		x/=2;
		res++;
	}
	return res;
}

ll binpow(ll a,ll b){
	if(!b)return 1;
	ll res = binpow(a, b/2);
	if(b%2)return res*res*a;
	else return res*res;
}

void solve(){
	ll k;
	cin >> k;
	
	ll res = len(k);
	cout << 2 << " " << 3 << endl;
	cout << binpow(2, res+1)-1 << " ";
	cout << binpow(2, res)-1 << " ";
	cout << 0 << endl;
	cout << binpow(2, res) << " ";
	cout << binpow(2, res+1)-1 << " ";
	cout << k;
	
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