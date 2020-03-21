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
class dj_set{
    public:
    int label;
    int rank;
    dj_set* parent;
    
    dj_set(int x){
        label=x;
        rank=0;
        parent=NULL;
    }
};

void union1(dj_set* dj1,dj_set* dj2){
    if(dj1->rank==dj2->rank){
        dj1->rank++;
        dj2->parent=dj1;
    }
    if(dj1->rank>dj2->rank){
        dj2->parent=dj1;
    }
    if(dj1->rank<dj2->rank){
        dj1->parent=dj2;
    }
}

dj_set* findset(dj_set* dj){
    dj_set* x;
    if(dj->parent==NULL){
        return dj;
    }
    else{
        x=findset(dj->parent);
    }
    dj->parent=x;
    return x;
}

//in kruskal, we first sort the vertices in ascending order and then for each edge in order, if adding it joins 2 different dj_sets then we include it
//i.e we find set for each vertex in edge and if it is same then we don't add it, if it's different we add it and merge the sets
//and add edge's weight to mst weight. In the end we get mst

//in the below implementation, sorting wasn't required as edges with weight 1 and 2 were already given (essentially in order)
int main(void){
    int n,b,c,d,e;
    cin>>n;
    for(int q=1;q<=n;q++){
        int ans=0;
        unordered_map<int,dj_set*>m;
        cin>>c;
        for(int i=1;i<=c;i++){
            m[i]=new dj_set(i);
        }
        cin>>b;
        while(b--){
            cin>>d;
            cin>>e;
            if(findset(m[e])!=findset(m[d])){
                union1(findset(m[e]),findset(m[d]));
                ans+=1;
            }
        }
        unordered_map<dj_set*,int> m2; //finds out how many disjoint sets remain using m2.size()
        for(int i=1;i<=c;i++){
            m2[findset(m[i])]=1;
        }
        ans+=(m2.size()-1)*2; //for eg. if 3 sets remain then 2 strands can joint them and both have 2 sugar
        cout<<"Case #"<<q<<": "<<ans<<endl;
    }
}