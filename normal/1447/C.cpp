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
	ll n, w;
	cin >> n >> w;
	vector<pll> a(n);
	for(ll i = 0; i < n; i++)cin>>a[i].f, a[i].s = i+1;
	sort(all(a));
	ll su = 0, l = 0, r = 0;
	while(r < n){
		su+=a[r].f;
		if(su >= (w+1)/2 and su <= w){
			cout<<r-l+1<<endl;
			for(ll j = l; j <= r; j++)cout<<a[j].s<<" ";
			return;
		}
		while(su > w){
			su -= a[l].f;
			l++;
		}
		if(su >= (w+1)/2 and su <= w){
			cout<<r-l+1<<endl;
			for(ll j = l; j <= r; j++)cout<<a[j].s<<" ";
			return;
		}
		r++;
	}
	cout << -1;
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