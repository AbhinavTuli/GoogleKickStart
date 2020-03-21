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

int maxIn2D(vector<vector<int>> dist,int r,int c){
    int m=INT_MIN;
    for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                m=max(m,dist[i][j]);
            }
        }
    return m;
}
void bfs(vector<vector<int> > arr, vector<vector<int>> &dist,int str,int stc,int r,int c){
    //dist[str][stc]=0;
    queue<pair<pair<int,int>,int> > q;
    q.push(make_pair(make_pair(str,stc),0));
    int vis[r][c];
    for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                vis[i][j]=0;
            }
        }
        //int k=INT_MI
    while(!q.empty()){
        pair<int,int> fr=q.front().first;
        int d=q.front().second;
        q.pop();
        vis[fr.first][fr.second]=1;
        //dist[fr.first][fr.second]=min(dist[fr.first][fr.second],d);
        if(dist[fr.first][fr.second]<d){
            continue;
        }
        else{
            dist[fr.first][fr.second]=d;
        }
        
        if(fr.first+1<r && vis[fr.first+1][fr.second]==0){
            q.push(make_pair(make_pair(fr.first+1,fr.second),d+1));
        }
        if(fr.first-1>=0 && vis[fr.first-1][fr.second]==0){
            q.push(make_pair(make_pair(fr.first-1,fr.second),d+1));
        }
        if(fr.second+1<c && vis[fr.first][fr.second+1]==0){
            q.push(make_pair(make_pair(fr.first,fr.second+1),d+1));
        }
        if(fr.second-1>=0 && vis[fr.first][fr.second-1]==0){
            q.push(make_pair(make_pair(fr.first,fr.second-1),d+1));
        }
    }
}
int main(){
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++){
        int r,c;
        cin>>r>>c;
        vector<vector<int> > arr( r , vector<int> (c));
        for(int i=0;i<r;i++){
            string tem;
            cin>>tem;
            for(int j=0;j<c;j++){
                if(tem[j]=='1'){
                    arr[i][j]=1;
                }
                else{
                    arr[i][j]=0;
                }
            }
        }
        vector<vector<int> > dist( r , vector<int> (c,INT_MAX));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(arr[i][j]==1){
                    bfs(arr,dist,i,j,r,c);
                }
                
            }
        }
        cout<<"down"<<endl;
        int ans=maxIn2D(dist,r,c);

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(arr[i][j]==1){
                    continue;
                }
                else{
                    vector<vector<int> > tempdist(dist.begin(),dist.end());
                    bfs(arr,tempdist,i,j,r,c);
                    ans=min(ans,maxIn2D(tempdist,r,c));
                }
            }
        }

        cout<<"Case #"<<cas<<": "<<ans<<endl;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<dist[i][j]<<" ";
        }
            cout<<endl;
        }
}
}