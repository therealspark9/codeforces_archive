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
	vll a(n, 0), b, c(2*n,0), cc(n, 0);
	ll ct = -1;
	for(ll i = 0; i < 2*n; i++){
		char ch;
		cin >> ch;
		if(ch == '+'){
			ct++;
			b.pb(ct);
		}
		else{
			ll d;
			cin >> d;
			c[i] = d;
			if((!sz(b)) or (c[i-1] > c[i])){
				cout << "NO";
				return;
			}
			if(d < cc[b.back()]){
				cout << "NO";
				return;
			}
			a[b.back()] = d;
			b.pop_back();
			if(sz(b))cc[b.back()] = max(d, cc[b.back()]);
		}
	}
	cout<<"YES"<<endl;
	for(auto it:a)cout<<it<<" ";
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