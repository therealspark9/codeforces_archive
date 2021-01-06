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

string s, t;
vll a, b;

bool check(ll x){
	ll i = 0;
	for(ll j = 0; j < sz(s); j++){
		char it = s[j];
		if(i >= sz(t))break;
		if(it==t[i] and b[j] > x)i++;
	}
	return i >= sz(t);
}

void solve(){
	cin >> s >> t;
	a.resize(sz(s));
	b.resize(sz(s));
	for(auto &it:a)cin>>it;
	for(ll i = 0; i < sz(s); i++)b[a[i]-1] = i;
	ll l = 0, r = sz(s)-1, midd=-1;
	while(l <= r){
		ll mid = l + (r-l)/2;
		if(check(mid)){
			l=mid+1;
			midd=mid;
		}
		else r=mid-1;
	}
	cout<<midd+1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll T = 1;
	//cin >> t;
	while(T--){
		solve();
		cout << endl;
	}
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi