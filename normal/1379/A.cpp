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
	string s;
	cin >> s;
	string t = "abacaba";
	for(ll i = 0; i < n; i++){
		string ts = s;
		ll j = 0;
		if(i+sz(t)-1 >= n)break;
		for(ll k = i; k < i + sz(t); k++){		
			if(j >= sz(t))break;
			if(s[k] == '?'){
				s[k] = t[j];
				j++;
			}
			else if(s[k] == t[j])j++;
		}
		ll cnt = 0;
		for(ll k = 0; k < n; k++) if(s.substr(k, sz(t))==t)cnt++;
		if(cnt != 1) s = ts;
		else{
			for(auto &it:s)if(it == '?')it = 'x';
			cout << "Yes\n";
			cout << s;
			return;
		}
	}
	cout << "No";
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