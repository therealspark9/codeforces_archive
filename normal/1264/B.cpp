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
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a+b+c+d == 1){
		if(a)cout<<"YES\n0";
		if(b)cout<<"YES\n1";
		if(c)cout<<"YES\n2";
		if(d)cout<<"YES\n3";
	}
	else if(a+b==a+b+c+d or b+c==a+b+c+d or c+d==a+b+c+d){
		if(a+b==a+b+c+d){
			if(abs(a-b) > 1)cout<<"NO";
			else{
				cout<<"YES\n";
				if(a>b){
					cout<<"0 ";
					for(ll i = 0; i < b; i++)cout<<"1 0 ";
				}
				else if(b>a){
					cout<<"1 ";
					for(ll i = 0; i < a; i++)cout<<"0 1 ";
				}
				else for(ll i = 0; i < a; i++)cout<<"1 0 ";
			}
		}
		else if(c+b==a+b+c+d){
			if(abs(c-b) > 1)cout<<"NO";
			else{
				cout<<"YES\n";
				if(c>b){
					cout<<"2 ";
					for(ll i = 0; i < b; i++)cout<<"1 2 ";
				}
				else if(b>c){
					cout<<"1 ";
					for(ll i = 0; i < c; i++)cout<<"2 1 ";
				}
				else for(ll i = 0; i < c; i++)cout<<"1 2 ";
			}
		}
		else if(c+d==a+b+c+d){
			if(abs(c-d) > 1)cout<<"NO";
			else{
				cout<<"YES\n";
				if(d>c){
					cout<<"3 ";
					for(ll i = 0; i < c; i++)cout<<"2 3 ";
				}
				else if(c>d){
					cout<<"2 ";
					for(ll i = 0; i < d; i++)cout<<"3 2 ";
				}
				else for(ll i = 0; i < c; i++)cout<<"3 2 ";
			}
		}
	}
	else if(abs((b+d)-(a+c)) > 1)cout<<"NO";
	else{
		if((b+d)-(a+c) == 1){
			if(b < a+1)cout<<"NO";
			else{
				cout<<"YES"<<endl;
				for(ll i = 0; i < a; i++)cout<<"1 0 ";
				cout<<1<<" ";
				b -= a+1;
				for(ll i = 0; i < b; i++)cout<<"2 1 ";
				for(ll i = 0; i < d; i++)cout<<"2 3 ";
			}
		}
		else if((b+d)-(a+c) == -1){
			if(b < a)cout<<"NO";
			else{
				cout<<"YES"<<endl;
				for(ll i = 0; i < a; i++)cout<<"0 1 ";
				b -= a;
				for(ll i = 0; i < b; i++)cout<<"2 1 ";
				for(ll i = 0; i < d; i++)cout<<"2 3 ";
				cout<<2<<" ";
			}
		}
		else{
			if(b < a)cout<<"NO";
			else{
				cout<<"YES"<<endl;
				if(b>a)cout<<"1 ",b--;
				for(ll i = 0; i < a; i++)cout<<"0 1 ";
				b -= a;
				for(ll i = 0; i < b; i++)cout<<"2 1 ";
				c-=b;
				for(ll i = 0; i < d; i++)cout<<"2 3 ";
				c-=d;
				if(c)cout<<2;
			}
		}
	}
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