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
using namespace std;


// a - (, b - )

void solve(){
	string st;
	cin >> st;
	stack<char> s;
	for(auto it:st){
		if(s.empty())s.push(it);
		else if(s.top() == 'A' and it == 'B')s.pop();
		else s.push(it);
	}
	string b = "";
	while(!s.empty()) {
		b += s.top();
		s.pop();
	}
	ll ans = sz(b), t = 0;
	for(ll i = 0; i < sz(b); i++){
		if(b[i] == 'B')t++;
		else{
			ans -= (t/2)*2;
			t = 0;
		}
	}
	ans -= (t/2)*2;
	cout<<ans;
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