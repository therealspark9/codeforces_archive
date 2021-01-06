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
	string s;
	cin >> s;
	ll cnt = 0;
	stack<ll> o, z;
	vll a[sz(s) + 5];
	for(ll i = 0; i < sz(s); i++){
		if(s[i] == '1'){
			if(!sz(z)){
				cout << -1;
				return;
			}
			else{
				ll v = z.top();
				z.pop();
				a[v].pb(i);
				o.push(v);
			}
		}
		else{
			if(!sz(o)){
				cnt++;
				z.push(cnt);
				a[cnt].pb(i);
			}
			else{
				ll v = o.top();
				o.pop();
				a[v].pb(i);
				z.push(v);
			}
		}
	}
	if(sz(o)){
		cout << -1;
		return;
	}
	cout << cnt << endl;
	for(ll i = 1; i <= cnt; i++){
		cout << sz(a[i]) << " ";
		for(auto it:a[i])cout << it+1 << " ";
		cout << endl;
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