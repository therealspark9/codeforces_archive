//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb emplace_back
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
	vll a(n);
	for(auto &it:a)cin >>  it;
	vll b = a;
	sort(all(b));
	bool f = false;
	for(ll i = 0; i < n; i++)f |= (a[i] != b[i] and a[i]%b[0]);
	if(f)cout<<"NO";
	else cout<<"YES";
	cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll T = 1;
	cin >> T;
	while(T--){
		input();
		solve();
	}
	cin.get();
	return 0;
}