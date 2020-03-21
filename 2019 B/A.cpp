#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<numeric>
#include<fstream>
#include<queue>
#include<unordered_map>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++){
        int n,q;
        cin>>n>>q;
        map<int,vector<int> >m;
        vector<int> v(26,0);
        string st;
        cin>>st;
        m[-1]=v;
        for(int i=0;i<n;i++){
            v[st[i]-'A']+=1;
            m[i]=v;
        }
        int ans=0;
        for(int i=0;i<q;i++){
            int l,r;
            cin>>l>>r;
            //cout<<"l "<<l<<" r "<<r<<endl;
            l--;
            r--;
            //m[r]-m[l-1]
            vector<int> new1(26);
            for(int u=0;u<26;u++){
                new1[u]=m[r][u]-m[l-1][u];
            }
            int oddCt=0;
            for(int bt=0;bt<26;bt++){
                if(new1[bt]%2==1){
                    oddCt++;
                }
                if(oddCt>1){
                    break;
                }
            }
            if(oddCt<=1){
                ans+=1;
            }
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
}