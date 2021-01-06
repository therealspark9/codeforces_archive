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
	ll a, b;
	cin >> a >> b;
	ll p = abs(a-b);
	if(a>b)swap(a,b);
	if(a==b)cout<<0;
	else{
		vll v;
		for(ll i = 1; i*i <= p; i++){
			if(p%i == 0){
				v.pb(i);
				if(i != p/i)v.pb(p/i);
			}
		}
		pll mn = {inf, inf};
		for(auto it:v){
			ll k = (it-a%it)%it;
			pll tmn = {(a+k)*(b+k)/__gcd(a+k, b+k), k};
			mn = min(mn, tmn);
		}
		cout<<mn.s;
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