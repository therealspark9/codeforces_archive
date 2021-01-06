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
	ll n;
	cin >> n;
	ll tn = n;
	mll mp;
	for(ll i = 2; i*i <= n; i++){
		while(n%i == 0){
			mp[i]++;
			n/=i;
		}
	}
	ll pos = 1;
	for(auto it:mp)pos = max(pos, it.s);
	if(pos == 1)cout << 1 << endl << tn;
	else{
		cout << pos << endl;
		for(auto it:mp){
			if(it.s == pos){
				ll div = 1;
				while(pos != 1){
					div *= it.f;
					cout << it.f << " ";
					pos--;
				}
				cout << tn/div;
				return;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi