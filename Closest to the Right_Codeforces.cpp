#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<stdio.h>
 
using namespace std;
 
int binarySearch(int arr[], int key, int n){
    int l = -1, r = n;
 
    while(l + 1 < r){
        int mid = (l + r) / 2;
 
 
        if(arr[mid] < key){
            l = mid;
        }
        else{
            r = mid;
        }
    }
 
   // cout<<"L = "<<l<<", R = "<<r<<'\n';
 
    if(arr[r] < key){
        return n + 1;
    }
 
    return r + 1;
}
 
int main() {
 
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
 
    while(k--){
        int q;  cin>>q;
        cout<<binarySearch(arr, q, n)<<'\n';
    }
 
    return 0;
}