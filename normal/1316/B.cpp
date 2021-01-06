#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#define ll long long
#define vll vector<long long>
#define mll map<long long, long long>
#define f first
#define s second
#define pb emplace_back
#define all(a) a.begin(),a.end()
#define rall(a) a.end(),a.begin()
using namespace std;

void solve(){
	ll n;
	string s;
	cin >> n >> s;
	string ans = s;
	ll val = 1;
	for(ll k = 1; k <= n; k++){
		string t = "";
		for(ll i = k-1; i < n; i++)t += s[i];
		if((n-k)%2)for(ll i = 0; i < k-1; i++)t+=s[i];
		else for(ll i = k-2; i >= 0; i--)t+=s[i];
		if(t < ans)ans = t, val = k;
	}
	cout << ans << endl << val << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t;
	t = 1;
	cin >> t;
	while(t--)solve();
	return 0;
}