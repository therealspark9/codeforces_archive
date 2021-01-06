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

bool ispr(ll i){
	bool f = true;
	for(ll j = 2; j*j <= i; j++) if(i%j == 0)f = false;
	return f;
}

void solve(){
	ll n;
	cin >> n;
	if(n == 3)cout << "1 3";
	else if(n == 4)cout << "2 2 2";
	else{
		vll a;
		ll l = n, i = n;
		while(l){
			if(ispr(i) and (sz(a) < 1 or (ispr(l-i) and l-i != 1))){
				l -= i;
				a.pb(i);
				i = l;
			}
			else i--;
		}
		sort(all(a));
		cout << sz(a) << endl;
		for(auto it:a)cout<<it<<" ";
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