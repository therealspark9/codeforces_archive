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
	ll a[26] = {0};
	string s;
	cin >> s;
	for(ll i = 0; i < sz(s); i++)a[s[i]-'a']++;
	string o = "", e = "";
	for(ll i = 0; i < 26; i++){
		if(i%2)o += string(a[i], 'a'+i);
		else e += string(a[i], 'a'+i);
	}
	if(abs(o[sz(o)-1]-e[0])!=1)cout<<o<<e;
	else if(abs(o[0]-e[sz(e)-1])!=1)cout<<e<<o;
	else if(abs(o[0]-e[0])!=1){
		reverse(all(o));
		cout<<o<<e;
	}
	else if(abs(o[sz(o)-1]-e[sz(e)-1])!=1){
		reverse(all(e));
		cout<<e<<o;
	}
	else cout<<"No answer";
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