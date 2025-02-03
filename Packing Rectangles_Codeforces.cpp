#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<stdio.h>

using ll = long long;

using namespace std;

bool checkPossible(ll mid, ll w, ll h, ll n){
    ll l1 = mid / w;
    ll l2 = mid / h;

    return ((l1 * l2) >= n);
}

int main() {

    //? For Submitting on USACO
    // freopen("div7.in","r",stdin);
    // freopen("div7.out","w",stdout);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ll w, h, n;      cin>>w>>h>>n;

    ll l = 0;
    ll r = 1;

    while(!checkPossible(r, w, h, n)){
        r = r << 1;
    }

    while(r > l + 1){
        ll mid = (l + r) >> 1;

        if(checkPossible(mid, w, h, n)){
            r = mid;
        }
        else{
            l = mid;
        }
    }

    cout<<r;

    return 0;
}