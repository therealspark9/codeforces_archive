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
	vll c(3, 0), d(3, 0);
	while(a%2 == 0){
		a/=2;
		c[0]++;
	}
	while(a%3 == 0){
		a/=3;
		c[1]++;
	}
	while(a%5 == 0){
		a/=5;
		c[2]++;
	}
	while(b%2 == 0){
		b/=2;
		d[0]++;
	}
	while(b%3 == 0){
		b/=3;
		d[1]++;
	}
	while(b%5 == 0){
		b/=5;
		d[2]++;
	}
	
	if(a != b)cout << -1;
	else cout << (max(c[0], d[0]) + max(c[1], d[1]) + max(c[2], d[2])) - (min(c[0], d[0]) + min(c[1], d[1]) + min(c[2], d[2]));
	
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