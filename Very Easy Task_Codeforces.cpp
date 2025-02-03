#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<iomanip>

using ll = long long;

using namespace std;

ll n; 
int x, y;

bool checkPossible(ll time){
   ll l1 = floor(time / x);
   ll l2 = floor(time / y);

   return (l1 + l2) >= n;
}

int main() {
    ios::sync_with_stdio(false);
    
    //? For Submitting on USACO
    // freopen("div7.in","r",stdin);
    // freopen("div7.out","w",stdout);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    cin>>n>>x>>y;

    n--;

    if(n == 0){
        cout<<min(x,y)<<'\n';
        return 0;
    }

    ll l = 0; // l is bad
    ll r = 2*1e9; // r is good
    
    while(l + 1 < r){
        ll mid = (l + r) / 2;

        if(checkPossible(mid)){
            r = mid;
        }
        else{
            l = mid;
        }
    }

    cout<<r+min(x,y)<<'\n';

    return 0;
}