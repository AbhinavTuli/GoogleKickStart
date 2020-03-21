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

int main(){
    ifstream fin; 
    fin.open("/Users/abhinav/Documents/Kickstart/2013/CAPTAINHAMMER/B-small-practice.in");
    int t;
    fin>>t;
    for(int i=1;i<=t;i++){
        double v,d;
        double g=9.8;
        fin>>v>>d;
        double ans;
        //cout<<v<<" "<<d<<endl;
        ans=0.5*asin(g*d/(v*v))*(180.00/M_PI);
        if(g*d/(v*v)>1){
            ans=45;
        }
        cout<<"Case #"<<i<<": "<<fixed<<setprecision(7)<<ans<<endl;
    }
}