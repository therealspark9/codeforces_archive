//May the force be with me
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


void solve(){
	ll n;
	cin >> n;
	vll a(n), b(n);
	for(auto &it:a)cin >> it;
	for(auto &it:b)cin >> it;
	sort(rall(a));
	sort(rall(b));
	ll l = 0, r = 0, sca = 0, scb = 0;
	bool f = true;
	while(l < n or r < n){
		if(f){
			if(l >= n)r++;
			else{
				if(r >= n or a[l] > b[r]){
					sca += a[l];
					l++;
				}
				else r++;
			}
		}
		else{
			if(r >= n)l++;
			else{
				if(l >= n or b[r]>a[l]){
					scb += b[r];
					r++;
				}
				else l++;
			}
		}
		f = !f;
	}
	cout << sca - scb;
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