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
	ll n, b, g;
	cin >> n >> g >> b;
	ll reqd = (n+1)/2;
	ll tot = (reqd / g) * (b+g);
	if(reqd%g == 0) tot -= b;
	else tot += reqd%g;
	cout << max(tot,n) << endl;
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