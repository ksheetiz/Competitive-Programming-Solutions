#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<stdio.h>

using namespace std;

int binarySearchLeft(int arr[], int key, int n){
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

    return r+1;
}

int binarySearchRight(int arr[], int key, int n){
    int l = -1, r = n;

    while(l + 1 < r){
        int mid = (l + r) / 2;

        if(arr[mid] <= key){
            l = mid;
        }
        else{
            r = mid;
        }
    }

    return l+1;
}

int main() {

    //? For Submitting on USACO
    // freopen("div7.in","r",stdin);
    // freopen("div7.out","w",stdout);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int n;  cin>>n;

    int arr[n];

    for(int i = 0; i < n; ++i){
        cin>>arr[i];
    }

    sort(arr, arr+n);

    int t;  cin>>t;

    int idxL, idxR;

    t--;

    while(t--){
        int l, r;   cin>>l>>r;
        
        idxL = binarySearchLeft(arr, l, n);
        idxR = binarySearchRight(arr, r, n);

        cout<<idxR-idxL + 1<<" ";
    }

    int l, r;   cin>>l>>r;
        
        idxL = binarySearchLeft(arr, l, n);
        idxR = binarySearchRight(arr, r, n);

        cout<<idxR-idxL + 1;

    return 0;
}