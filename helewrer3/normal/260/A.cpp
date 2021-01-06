#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll a, b, n;
    bool flag;
    cin >> a >> b >> n;

    while(n--){
        flag = false;

        for(ll i = 0; i <= 9; i++){
            if((a*10 + i)%b == 0){
                flag = true;
                a = a*10 + i;
                break;
            }
        }

        if(flag == false)
            break;
    }

    if(flag)
        cout << a << endl;
    else
        cout << -1 << endl;

    return 0;
}