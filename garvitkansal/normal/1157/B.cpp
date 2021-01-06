//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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
using namespace std;

ll n;

void input(){
	cin >> n;
}

void solve(){
	string s;
	cin >> s;
	vll a(9);
	for(auto &it:a)cin >> it;
	for(ll i = 0; i < sz(s); i++){
		if(s[i] - '0' <= a[s[i] - '1']){
			while(i < n and s[i] - '0' <= a[s[i] - '1']){
				s[i] = a[s[i]-'1']+'0';
				i++;
			}
			break;
		}
	}
	cout<<s;
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