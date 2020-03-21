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
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int a;
        int b;
        cin>>a>>b;
        int ans=b-a+1;
        int firstMulOf9=a+(9-(a%9));
        int lastMulOf9=b-b%9;
        if(firstMulOf9>b || lastMulOf9<a){
            ans=ans;
        }
        else{
            ans-=1+((lastMulOf9-firstMulOf9)/9);
        }

        
    }