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
	vector<pll> a;
	if(k < n-1){
		cout << "Impossible";
		return;
	}
	for(ll i = 2; i <= n; i++){
		if(!k){
			cout<<"Possible"<<endl;
			for(auto it:a)cout<<it.f<<" "<<it.s<<endl;
			return;
		}
		a.pb({1,i});
		k--;
	}
	for(ll i = 2; i <= n; i++){
		ll j = i;
		while(j <= n){
			if(__gcd(j,i) != 1){
				j++;
				continue;
			}
			if(!k){
				cout<<"Possible"<<endl;
				for(auto it:a)cout<<it.f<<" "<<it.s<<endl;
				return;
			}
			a.pb({i,j});
			k--;	
			j++;
		}
	}
	if(!k){
		cout<<"Possible"<<endl;
		for(auto it:a)cout<<it.f<<" "<<it.s<<endl;
		return;
	}
	cout<<"Impossible";
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