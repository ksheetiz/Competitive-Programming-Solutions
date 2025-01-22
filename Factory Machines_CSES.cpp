#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<stdio.h>

using namespace std;

bool checkProd(long long arr[], long long time, long long t, long long n){
    long long currProd = 0;
    for(long long i = 0; i < n; ++i){
        currProd += time / arr[i];
        if(currProd >= t){
            return true;
        }
    }

    return false;
}

long long binarySearch(long long arr[], long long n, long long t){
    long long l = 1;
    long long r = *min_element(arr, arr+n) * t;
    long long ans = r;
    while(l <= r){
        long long mid = l + (r - l) / 2;
        if(checkProd(arr, mid, t, n)){
            ans = mid;
            r = mid - 1; 
        }
        else{
            l = mid + 1;
        }
    }

    return ans;
}

int main() {

    //? For Submitting on USACO
    // freopen("div7.in","r",stdin);
    // freopen("div7.out","w",stdout);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    long long n, t;  cin>>n>>t;

    long long arr[n];

    for(long long i = 0; i < n; ++i){
        cin>>arr[i];
    }

    cout<<binarySearch(arr, n, t)<<'\n';

    return 0;
}