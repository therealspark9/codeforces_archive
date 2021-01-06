#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb emplace_back
#define vll vector<long long>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long)(x).size())
#define mll map<long long, long long>
#define pll pair<long long, long long>
using namespace std;

ll n;
vll a;

void input(){
	cin >> n;
}

bool check(ll x){
	vll cnt(n+1,0);
	for(ll i = 0; i < n; i++)cnt[a[i]]++;
	set<pll, greater<pll>> s;
	for(ll i = 1; i <= n; i++)if(cnt[i])s.insert({cnt[i],i});
	vll b(n, 0);
	for(ll i = 0; i < n; i++){
		if(i >= x and cnt[b[i-x]])s.insert({cnt[b[i-x]], b[i-x]});
		if(s.empty())return 0;
		b[i]=s.begin()->s;
		cnt[b[i]]--;
		s.erase(s.begin());
	}
	return 1;
}

void solve(){
	a.resize(n);
	for(auto &it:a)cin>>it;
	ll l = 0, r = n, midd = 1;
	while(l <= r){
		ll mid = l + (r-l)/2;
		if(check(mid))midd = mid, l = mid+1;
		else r = mid - 1;
	}
	cout<<midd-1 << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	cout.precision(20);
	ll t;
	t = 1;
	cin >> t;
	while(t--){
		input();
		solve();
	}
	cout << endl;
	return 0;
}