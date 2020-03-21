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

int dfsFindLoop(int st,map<int,set<int>> &m,map<int,int>&vis,int parent,set<int> &loop){
    vis[st]=1;
    for(auto i=m[st].begin();i!=m[st].end();i++){
        if(*i==parent){
            continue;
        }
        if(vis[*i]==0){
            int a=dfsFindLoop(*i,m,vis,st,loop);
            if(a==-1){
                if(loop.find(*i)!=loop.end()){
                    return 0;
                }
                loop.insert(*i);
                return a;
            }
        }
        else{
            if(loop.find(*i)!=loop.end()){
                    return 0;
            }
            loop.insert(*i);
            return -1;
        }
    }
    return 0;
}
map<int,int> bfsDist(int st,map<int,set<int>> &m,int N){
    queue<int> q;
    q.push(st);
    map<int,int> dist;
    for(int i=1;i<=N;i++){
        dist[i]=-1;
    }
    dist[st]=0;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(auto i=m[f].begin();i!=m[f].end();i++){
            if(dist[*i]==-1){
                 q.push(*i);
                 dist[*i]=dist[f]+1;
            }
        }
    }
    return dist;
}
void bfsDistFromCycle(set<int> &loop,int N,map<int,int> &dist,map<int,set<int>> &m){
    for(int i=1;i<=N;i++){
        dist[i]=INT_MAX;
    }
    for(auto i=loop.begin();i!=loop.end();i++){
        map<int,int> tempDist=bfsDist(*i,m,N);
        for(int i=1;i<=N;i++){
            dist[i]=min(dist[i],tempDist[i]);
        }
    }
}

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        map<int,set<int>> m;
        int n;
        cin>>n;
        int po=n;
        while(n--){
            int a,b;
            cin>>a>>b;
            m[a].insert(b);
            m[b].insert(a);
        }
        set<int> loop;
        map<int,int>vis;
        dfsFindLoop(1,m,vis,0,loop);
        // cout<<"loop "<<endl;
        // for(auto i=loop.begin();i!=loop.end();i++){
        //     cout<<*i<<endl;
        // }
        map<int,int> dist;
        bfsDistFromCycle(loop,po,dist,m);
        cout<<"Case #"<<i<<": ";
        for(int i=1;i<=po;i++){
            cout<<dist[i]<<" ";
        }
        cout<<endl;
    }
}

// 1
// 10
// 1 2
// 2 3
// 3 6
// 6 7
// 2 5
// 3 4
// 6 9
// 7 8
// 5 4