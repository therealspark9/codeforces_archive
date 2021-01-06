//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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

string s;

void input(){
	cin >> s;
}

void solve(){
	map<ll, char> mp;
	ll vis[26];
	for(auto &it:vis)it = inf;
	ll dir = 1, x = 0;
	for(auto it:s){
		if(vis[it-'a'] == inf){
			x += dir;
			vis[it-'a'] = x;
			if(!mp.count(x))mp[x] = it;
			else{cout<<"NO\n";return;}
		}
		else{
			if(vis[it-'a'] > x)dir = 1;
			else dir = -1;
			x += dir;
			if(mp[x] != it){cout<<"NO\n";return;}
		}
	}
	string ans = "";
	for(auto it:mp)ans += it.s;
	for(ll i = 0; i < 26; i++){
		if(vis[i] == inf)ans+='a'+i;
	}
	cout<< "YES\n" << ans <<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		input();
		solve();
	}
	cin.get();
	return 0;
}