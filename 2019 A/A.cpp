#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<numeric>
#include<fstream>
#include<queue>
#include<unordered_map>
#define __LONG_LONG_MAX__ 922337203685477
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++){
        int n,p;
        cin>>n>>p;
        vector<int> pl;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            pl.push_back(a);
        }
        sort(pl.begin(),pl.end());
        vector<int> pre;
        pre.push_back(0);
        int sum=0;
        for(int i=0;i<pl.size();i++){
            sum+=pl[i];
            pre.push_back(sum);
        }
        long long mini=__LONG_LONG_MAX__;
        for(int i=0;i<n-p+1;i++){
            int high=pl[i+p-1];
            int s=high*p-(pre[i+p]-pre[i]);
            // for(int k=i;k<i+p-1;k++){
            //     s+=high-pl[k];
            // }
            if(s<mini){
                mini=s;
            }
        }
        cout<<"Case #"<<cas<<": "<<mini<<endl;
    }
}