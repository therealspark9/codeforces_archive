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
	double x,y;
	cin >> n >> x >> y;
	map<double, ll> mp;
	while(n--){
		double x1,y1;
		cin >> x1 >> y1;
		if(x1 == x) mp[100000.0]++;
		else mp[(y1-y)/(x1-x)]++;
	}
	cout << mp.size();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t;
	t = 1;
	//cin >> t;
	while(t--)solve();
	return 0;
}