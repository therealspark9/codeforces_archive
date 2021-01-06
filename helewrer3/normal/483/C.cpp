/*May the force be with me*/
#include "bits/stdc++.h"
#define endl "\n"
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

ll n, k;

void input(){
	cin >> n >> k;
}

void solve(){
	k--;
	if(k){
		ll l = 1, r = n;
		cout << l << " " << r << " ";
		k--;
		l++, r--;
		bool f = k%2;
		while(k){
			if(k%2 == f){
				cout << l << " ";
				l++;
			}
			else {
				cout << r << " ";
				r--;
			}
			k--;
		}
		if(k%2 == f)for(ll i = r; i >= l; i--)cout << i << " ";
		else for(ll i = l; i <= r; i++)cout << i << " ";
	}
	else for(ll i = 1; i <= n; i++)cout << i << " ";
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