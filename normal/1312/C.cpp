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
	ll n, k;
	cin >> n >> k;
	vll a(n);
	for(auto &it:a) cin >> it;
	ll b = 1ll<<60;
	bool f = false;
	ll x = log(1e16)/log(k) + 1;
	ll mul = 1;
	for(ll i = 0; i < x; i++)mul*=k;
	for(ll i = x; i >= 0; i--){
		for(ll j = 0; j < n; j++){
			if(a[j] >= mul) {
				f|= (b&1ll<<i);
				a[j] -= mul;
				b |= 1ll<<i;
			}
		}
		mul /= k;
	}
	bool g = false;
	for(auto it:a)g |= it;
	if(f or g)cout<<"NO";
	else cout<<"YES";
	cout<<"\n";
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