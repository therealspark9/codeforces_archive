//May the force be with me
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


void solve(){
	ll n, x;
	cin >> n >> x;
	vll a(n), b(n);
	mll mp;
	for(auto &it:a)cin>>it;
	for(ll i = 0; i < n; i++) b[i] = a[i]&x;
	bool f = false;
	//0
	for(ll i = 0; i < n; i++){
		if(mp.count(a[i]))f = true;
		mp[a[i]]=1;
	}
	if(f){
		cout << 0;
		return;
	}
	//1
	mp.clear();
	for(auto it:a)mp[it]++;
	for(ll i = 0; i < n; i++){
		ll y = a[i]&x;
		if(y != a[i] and mp[y])f = true;
	}
	if(f){
		cout << 1;
		return;
	}
	//2
	mp.clear();
	for(ll i = 0; i < n; i++){
		if(mp.count(b[i]))f = true;
		mp[b[i]]=1;
	}
	if(f){
		cout << 2;
		return;
	}
	cout<<-1;
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