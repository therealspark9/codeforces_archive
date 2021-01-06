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
	cin >> n;
	vll a(n), b(n), c(n);
	for(auto &it:a)cin>>it;
	for(auto &it:b)cin>>it;
	for(ll i= 0 ;i < n; i++)c[i] = a[i]-b[i];
	sort(all(c));
	ll ans = 0;
	for(ll i = 0; i < n; i++){
		if(c[i] > 0)ans += n-i-1;
		else{
			ll l = i, r = n-1, midd = n;
			while(l <= r){
				ll mid = l + (r-l)/2;
				if(c[mid] + c[i] <= 0) l = mid + 1;
				else midd = mid, r = mid - 1;
			}
			ans += n - midd;
		}
	}
	cout<<ans;
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