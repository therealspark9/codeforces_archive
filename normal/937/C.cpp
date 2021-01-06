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
	double k, d, t;
	cin >> k >> d >> t;
	ll rem;
	if((ll)k%(ll)d == 0)rem = 0;
	else{
		if(d<k)d = ((ll)k/(ll)d)*(ll)d+d;
		rem = d-k;
	}
	double frac = (k/t) + ((double)rem)/(2*t);
	double real_time = k + rem;
	ll q = 1/frac;
	double r = (1/frac-q)*frac;
	double ans = q*real_time;
	if(r <= (k/t)) ans += r*t;
	else ans += k + 2*(r-(k/t))*t;
	cout<<ans;
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