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
	for(auto &it:a)cin>>it;
	mll mp;
	for(auto it:a)mp[it]++;
	set<ll> s;
	for(auto it:mp)if(it.s > 1)s.insert(it.f);
	bool f = true;
	for(ll i = 0; i < n; i++){
		if(a[i]){
			mp[a[i]]--;
			mp[a[i]-1]++;
			if(mp[a[i]] < 2 and s.find(a[i]) != s.end())s.erase(a[i]);
			if(mp[a[i]-1] > 1)s.insert(a[i]-1);
			f&=(!s.empty());
			mp[a[i]]++;
			mp[a[i]-1]--;
			if(mp[a[i]] > 1)s.insert(a[i]);
			else if(s.find(a[i]) != s.end())s.erase(a[i]);
			if(mp[a[i]-1] > 1)s.insert(a[i]-1);
			else if(s.find(a[i]-1) != s.end())s.erase(a[i]-1);
		}
	}
	if(f)cout<<"cslnb";
	else{
		sort(all(a));
		ll cnt = 0;
		for(ll i = 0; i < n; i++)cnt+=a[i]-i;
		if(cnt%2)cout<<"sjfnb";
		else cout<<"cslnb";
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