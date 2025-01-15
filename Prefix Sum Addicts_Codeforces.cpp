#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main(){

    //? For Submitting on USACO
    // freopen("bcount.in","r",stdin);
    // freopen("bcount.out","w",stdout);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t;  cin>>t;

    while(t--){
        int n;  cin>>n;
        int k;  cin>>k;

        vector<long long> s(n + 1);

        for(int i = n - k + 1; i <= n; ++i){
            cin>>s[i];
        }
        if(k == 1){
            cout<<"Yes"<<'\n';
        }
        else{
            vector<long long> a(n + 1);

            for(int i = n - k + 2; i <= n; ++i){
                a[i] = s[i] - s[i - 1];
            }
            if(!is_sorted(a.begin() + n - k + 2, a.end())){
                cout<<"No"<<'\n';
            }
            else if(s[n - k + 1] > a[n - k + 2] * (n - k + 1)){
                cout<<"No"<<'\n';
            }
            else{
                cout<<"Yes"<<'\n';
            }
        }
    }
    
    return 0;
}