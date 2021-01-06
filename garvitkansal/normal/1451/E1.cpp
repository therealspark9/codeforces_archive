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
	ll a, b, c, d, e, f, a1, a2, a3;
	cout << "AND 1 2" << endl;
	cout.flush();
	cin >> a;
	cout << "AND 2 3" << endl;
	cout.flush();
	cin >> b;
	cout << "AND 1 3" << endl;
	cout.flush();
	cin >> c;
	cout << "XOR 1 2" << endl;
	cout.flush();
	cin >> d;
	cout << "XOR 1 3" << endl;
	cout.flush();
	cin >> e;
	f = d^e;
	a1 = (d+2*a+e+2*c-f-2*b)/2;
	a2 = (d+2*a+f+2*b-e-2*c)/2;
	a3 = (e+2*c+f+2*b-d-2*a)/2;
	vll v(n);
	v[0] = a1, v[1] = a2, v[2] = a3;
	for(ll i = 4; i <= n; i++){
		cout << "XOR 3 " << " " << i << endl;
		cout.flush();
		ll x;
		cin >> x;
		v[i-1] = x^a3;
	}
	cout << "! ";
	for(auto it:v)cout<<it<<" ";
	cout << endl;
	cout.flush();
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