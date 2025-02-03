#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<iomanip>

using ll = long long;

using namespace std;

bool checkPossible(double mid, int arr[], int k, int n){
    int currCount = 0;
    for(int i = 0; i < n; ++i){
        currCount += floor(arr[i] / mid);
    }

    return currCount >= k;
}

int main() {
    ios::sync_with_stdio(false);
    
    //? For Submitting on USACO
    // freopen("div7.in","r",stdin);
    // freopen("div7.out","w",stdout);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int n, k;   cin>>n>>k;

    int arr[n];

    for(int i = 0; i < n; ++i){
        cin>>arr[i];
    }

    double l = 0; // l is good
    double r = 1e8; // r is bad

    for(int i = 0; i < 100; ++i){
        double mid = (l + r) /2;

        if(!checkPossible(mid, arr, k, n)){
            r = mid;
        }
        else{
            l = mid;
        }
    }

    cout<<setprecision(20)<<l<<'\n';

    return 0;
}