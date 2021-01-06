/*May the force be with me*/
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

ll a, b;

void input(){
	cin >> a >> b;
}

void solve(){
	map<ll, pll> mp;
	while(a%2 == 0){
		mp[2].f++;
		a/=2;
	}
	for(ll i = 3; i*i <= a; i+=2){
		while(a%i == 0){
			mp[i].f++;
			a/=i;
		}
	}
	if(a!=1)mp[a].f++;
	while(b%2 == 0){
		mp[2].s++;
		b/=2;
	}
	for(ll i = 3; i*i <= b; i+=2){
		while(b%i == 0){
			mp[i].s++;
			b/=i;
		}
	}
	if(b!=1)mp[b].s++;
	bool g = true;
	for(auto it:mp){
		g &= ((it.s.f + it.s.s)%3 == 0);
		g &= (it.s.f != 0);
		g &= (it.s.s != 0);
	}
	if(g)cout<<"Yes \n";
	else cout << "No \n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		input();
		solve();
	}
	cin.get();
	return 0;
}