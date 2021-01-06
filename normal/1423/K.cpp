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

ll const nax = 1e6+7;
vll a(nax,0);
void f(){
	for(auto &it:a)it = 1;
	for(ll i = 2; i < nax; i++){
		if(!a[i])continue;
		for(ll j = 2*i; j < nax; j += i)a[j] = 0;
	}
	for(ll i = 2; i < nax; i++) {
		if(i*i < nax and a[i] == 1)a[i*i]--;
		a[i] += a[i-1];
	}
}

void solve(){
	ll n;
	cin >> n;
	cout << a[n];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	f();
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