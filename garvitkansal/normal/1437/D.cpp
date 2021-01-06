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
	ll n;
	cin >> n;
	vll a(n);
	for(ll i = 0; i < n; i++)cin >> a[i];
	a.pb(-inf);
	ll sz = 1, nsz = 0, dep = 0;
	for(ll i = 1; i < n; i++){
		ll tsz = 1;
		while(a[i] < a[i+1]){
			i++;
			tsz++;
		}
		sz--;
		nsz += tsz;
		if(!sz){
			sz = nsz;
			nsz = 0;
			dep++;
		}
	}
	if(nsz)dep++;
	cout<<dep;
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