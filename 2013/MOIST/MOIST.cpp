#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<numeric>
#include<fstream>
#include<queue>
#include<cmath>
using namespace std;

int comp(string a, string b){ //returns 1 if a>b and 0 otherwise
    int l=min(a.length(),b.length());
    for(int i=0;i<l;i++){
        if(a[i]>b[i]){
            return 1;
        }
        else if(a[i]<b[i]){
            return 0;
        }
        else{
            continue;
        }
    }

}
int main(){
    ifstream fin; 
    fin.open("/Users/abhinav/Documents/Kickstart/2013/MOIST/C-small-practice-2.in");
    int t;
    fin>>t;
    for(int i=1;i<=t;i++){
        int ans=0;
        int n;
        fin>>n;
        string prev;
        string curr;
        getline(fin,prev);
        getline(fin,prev);
        //cout<<prev<<endl;
        for(int i=1;i<n;i++){
            //getline(fin,curr);
            getline(fin,curr);
            //cout<<curr<<endl;
            if(comp(curr,prev)==0){
                ans+=1;
            }
            else{
                prev=curr;
            }
        }
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
}