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

vector<int> decToBinary(long long n) 
{ 
    // array to store binary number 
    int binaryNum[75]; 
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  
    // storing binary array in reverse order 
    vector<int> v;
    for (int j = i - 1; j >= 0; j--) {
        v.push_back(binaryNum[j]); 
    }
    return v;
} 

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        long long n,k,p;
        cin>>n>>k>>p;
        int arr[n];
        int temp[n];
        for(int j=0;j<n;j++){
            arr[j]=0;
            temp[j]=0;
        }
        vector<int> bin=decToBinary(p-1);
        // for(int i=0;i<bin.size();i++){
        //     cout<<"-"<<bin[i];
        // }
        // cout<<endl;

        while(k--){
            long long a,b,c;
            cin>>a>>b>>c;
            arr[a-1]=c;
            temp[a-1]=-1;
        }
        int h=bin.size()-1;
        for(int l=n-1;l>=0;l--){
            if(temp[l]==-1){
                //cout<<l<<" "<<"up\n";
                continue;
            }
            else{
                //cout<<l<<" "<<"down\n";
                if(h<0){
                    continue;
                }
                arr[l]=bin[h];
                h--;
            }
        }
        string ans;
        for(int j=0;j<n;j++){
            ans=ans+to_string(arr[j]);
        }
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
}