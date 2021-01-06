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

ll n;
ll const nax = 10e3 + 5;
vll a(nax);


void input(){
	cin >> n;
}

void solve(){
	for(ll i = 0; i <= nax-5; i++){
		a[i] = i+1;
		for(ll j = 0; j <= i-2; j++)a[i] += (a[j]-1);
	}
	for(ll i = 0; i <= nax-5; i++){
		if(a[i] > n){
			cout << i-1;
			return;
		}
	}
	//Thank you, s4shyam95, for the idea.
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