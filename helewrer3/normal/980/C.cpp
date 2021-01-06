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
	ll n, k;
	cin >> n >> k;
	vll a(n), b(300, 0), c(300, 0);
	for(auto &it:b)it = -1;
	for(ll i = 0; i < n; i++) cin >> a[i];
	for(ll i = 0; i < n; i++){
		if(b[a[i]] != -1)continue;
		ll tk = k, idx = a[i], l = a[i];
		tk--, idx--;
		while(tk and idx >= 0){
			l = idx;
			if(b[l] != -1) break;
			idx--;
			tk--;
		}
		if(c[l] and k - c[l] >= a[i] - l){
			for(ll j = 1; j < k; j++){
				if(b[l+j] != -1 or l + j > a[i]) break;
				b[l+j] = b[l];
				c[l+j] = c[l+j - 1] + 1;
			}
		}
		else{
			if(c[l])l++;
			for(ll j = 0; j < k; j++){
				if(b[l+j] != -1 or l + j > a[i]) break;
				b[l+j] = l;
				if(j)c[l+j] = c[l+j - 1] + 1;
				else c[l] = 1;
			}
		}
	}
	for(ll i = 0 ; i < 256; i++)if(b[i] == -1)b[i] = i;
	for(auto &it:a)it = b[it];
	for(auto it:a)cout << it << " "; 
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