#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<stdio.h>

using namespace std;

int main() {

    //? For Submitting on USACO
    freopen("div7.in","r",stdin);
    freopen("div7.out","w",stdout);


    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int n; cin>>n;

    long long prefix[n+1] = {0};
    
    for(int i = 0; i < n; ++i){
        int x;  cin>>x;
        prefix[i + 1] = prefix[i] + x;
    }

    int poi_x = 1, poi_y = n;

    long long totSum = prefix[n];
    int currlen = n;

    while(totSum % 7 != 0 and poi_x <= poi_y){
        int rem = totSum % 7;

        if(rem < 4){
            totSum -= prefix[poi_x];
            poi_x++;
        }
        else{
            long long dif = prefix[poi_y] - prefix[poi_y - 1];
            totSum -= dif;
            poi_y--;
        }
        currlen--;
    }

    cout<<currlen;

    return 0;
}