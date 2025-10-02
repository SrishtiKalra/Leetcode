class DisjointSet {
    public:
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findParent(int u){
        if(parent[u]==u){
            return u;
        }

        return parent[u]= findParent(parent[u]);
    }

    bool unionBySize(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if (ulp_u == ulp_v) return true;

        if(size[ulp_u]> size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];

        }
        return false;
    }

};

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {

        sort(edges.begin(), edges.end(),[](auto &a, auto &b){
            return a[2]<b[2];
        });

        DisjointSet dsu(n);
        vector<int> mstEdges;
        for(auto e: edges){
            if (!dsu.unionBySize(e[0], e[1])) {
                mstEdges.push_back(e[2]);
            }



        }
        sort(mstEdges.rbegin(), mstEdges.rend());

        for(int i=0;i<k-1 && !mstEdges.empty();i++){
            mstEdges.erase(mstEdges.begin());
        }

        return mstEdges.empty()?0:mstEdges[0];




        
        
    }
};