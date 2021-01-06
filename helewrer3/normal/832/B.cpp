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
	vll b(30, 0);
	for(auto it:s)b[it-'a']++;
	cin >> s;
	reverse(all(s));
	ll n;
	cin >> n;
	for(ll j = 0; j < n; j++){
		string a;
		cin >> a;
		reverse(all(a));
		ll l = 0, r = 0;
		bool f = true;
		while(l < sz(s) and r < sz(a)){
			if(a[r] == s[l])l++, r++;
			else if(b[a[r]-'a']){
				if(s[l] != '?' and s[l] != '*'){
					f = false;
					break;
				}
				else if(s[l] == '*')l++;
				else l++, r++;
			}
			else{
				if(s[l] != '*'){
					f = false;
					break;
				}
				l++;
				if(l < sz(s))while(r < sz(a) and b[a[r]-'a'] == 0 and (a[r] != s[l]))r++;
				else while(r < sz(a) and b[a[r]-'a'] == 0 and (a[r] != s[l]))r++;
			}
		}
		if(l >= sz(s) and r < sz(a))f = false;
		if(f)cout<<"YES\n";
		else cout<<"NO\n";
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