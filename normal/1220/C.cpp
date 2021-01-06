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

string s;

void input(){
	cin >> s;
}

void solve(){
	string mn = "";
	mn += s[0];
	for(ll i = 1; i < sz(s); i++){
		char ch = mn[i-1];
		mn += min(ch, s[i]);
	}
	for(ll i = 0; i < sz(s); i++){
		if(!i)cout << "Mike";
		else if(s[i] > mn[i-1])cout<<"Ann";
		else cout << "Mike";
		cout << endl;
	}
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