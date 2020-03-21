#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<numeric>
#include<fstream>
#include<queue>

using namespace std;

//Reasoning

// DFS to detect cycle in an undirected graph in O(V+E) time. We do a DFS traversal of the given graph. For every visited vertex ‘v’,
//if there is an adjacent ‘u’ such that u is already visited and u is not parent of v, 
//then there is a cycle in graph. If we don’t find such an adjacent for any vertex, we say that there is no cycle. 

//Naming of arguments
//o is the origin or the first vertex, m is the adjacency list of each vertex, parent is the node from which we reached the current node
//here the graph might not be strongly connected and thus this code has been run starting from all vertices in main
int dfsFindCycle(string o,set<string> &visited,map<string,set<string>> &m,string parent){ //returns 1 if cycle found and 0 otherwise
    //cout<<"inner origin is "<<o<<endl;
    int ans=0;
    for(auto i=m[o].begin();i!=m[o].end();i++){
        if(parent==*i){ //if it is parent then don't go back into it
            continue;
        }

        //cout<<"origin "<<o<<" "<<"visiting "<<*i<<endl;
        if(parent!=*i && visited.find(*i)!=visited.end()){ //it isn't parent and it exists in visited set
            //cout<<"Problem at origin "<<o<<" "<<"visiting "<<*i<<endl; 
            return 1;
        }

        visited.insert(*i);
        ans+=dfsFindCycle(*(i),visited,m,o);
        // if(ans>0){
        //     break;
        // }
    }
    if(ans>0){
        return 1;
    }
    else{
        return 0;
    }
}

//Naming of arguments
//o is the origin or the first vertex, m is the adjacency list of each vertex, color is the color assigned to that node in an attempt to create a graph of 2 colors
//here the graph might not be strongly connected and thus this code has been run starting from all vertices in main

//the traversal of vertices is somewhat like bfs but no visited array instead color indirectly keeps track of visited 
int detectBipartite(string o, map<string,set<string>> &m,map<string,int> color){ //returns 0 if bipartite else 1
    int ans=0;
    color[o]=1; //will be coloring vertices with 1 and 2. By default will be 0
    queue<string> q;
    q.push(o);
    while(!q.empty()){
        string f=q.front();
        q.pop();
        int newColor=1+((color[f])%2);    //2 becomes 1 and vice versa
        for(auto i=m[f].begin();i!=m[f].end();i++){
            if(color[*i]==0){ //color not assigned yet i.e not visited
                color[*i]=newColor;
                q.push(*i);
            }
            else{
                if(color[*i]!=newColor){ //visited before but conflict in color and thus not bipartite
                    return 1;
                }
            }

        }

    }
    return 0;
}
int main(){
    ifstream fin; 
    fin.open("/Users/abhinav/Documents/Kickstart/2013/A-small-practice-1.in");
    int t;
    fin>>t;
    for(int i=1;i<=t;i++){
        map<string,set<string>> m;
        string ans="idk";
        int n;
        fin>>n;
        while(n--){
            string a;
            string b;
            fin>>a>>b;
            // cout<<"a: "<<a<<endl;
            // cout<<"b: "<<b<<endl;
            m[a].insert(b);
            m[b].insert(a);
        }
        int res=0;
        for(auto i=m.begin();i!=m.end();i++){
            set<string> visited;
            //cout<<"\n\nstarting with "<<i->first<<endl;
            visited.insert(i->first);
            //res+=dfsFindCycle(i->first,visited,m,"");
            map<string,int> color;
            res+=detectBipartite(i->first,m,color);
        }
        if(res>0){
            ans="No";
        }
        else{
            ans="Yes";
        }
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
}