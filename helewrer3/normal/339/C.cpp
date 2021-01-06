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

ll n;
string s;

void recur(ll i, ll sl, ll sr, ll prev, vll ans){
	if(sz(ans) == n){
		cout<<"YES\n";
		for(auto it:ans)cout<<it<<" ";
		exit(0);
	}
	ll d = abs(sl-sr);
	for(ll j = 0; j < 10; j++){
		if(s[j] == '1' and j+1 > d and j+1 != prev){
			ans.pb(j+1);
			if(i%2)recur(i+1, sl+j+1, sr, j+1, ans);
			else recur(i+1, sl, sr+j+1, j+1, ans);
			ans.pop_back();
		}
	}
	return;
}

void solve(){
	cin >> s >> n;
	vll ans;
	recur(0,0,0,0,ans);
	cout<<"NO";
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