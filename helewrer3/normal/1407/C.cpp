//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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

ll n;

ll q(ll a, ll b){
	cout << "? " << a+1 << " " << b+1 << endl;
	ll x;
	cin >> x;
	return x;
}

void input(){
	cin >> n;
}

void solve(){
	ll idx = 0;
	vll a(n, -1);
	for(ll i = 1; i < n; i++){
		ll x = q(idx, i), y = q(i, idx);
		if(x > y){
			a[idx] = x;
			idx = i;
		}
		else a[i] = y;
	}
	a[idx] = n;
	cout << "! ";
	for(auto it:a)cout << it << " ";
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	//cin >> t;
	while(t--){
		input();
		solve();
        cout<<endl;
	}
	cin.get();
	return 0;
}