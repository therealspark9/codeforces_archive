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
	map<char, ll>mp;
	for(auto it:s)mp[it]++;
	if(mp.size() > 4 or mp.size() < 2)cout<<"No";
	else{
		if(mp.size() == 4)cout<<"Yes";
		else if(mp.size() == 2){
			bool f = true;
			for(auto it:mp)f &= it.s>=2;
			if(f)cout<<"Yes";
			else cout<<"No";
		}
		else if(mp.size() == 3){
			ll a = 0;
			for(auto it:mp)a += it.s==1;
			if(a == 3)cout<<"No";
			else cout<<"Yes";
		}
		else cout<<"No";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t;
	t = 1;
	//cin >> t;
	while(t--){
		input();
		solve();
	}
	cin.get();
	return 0;
}