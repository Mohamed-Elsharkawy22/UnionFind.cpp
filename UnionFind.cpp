#include <vector>
#include <iostream>
class DSU{
public:
   int nsets;
     vector<int>par,size;
    DSU(int n)
    {
     par.resize(n);
     size.resize(n, 1);
        nsets=n;
        iota(par,par+n,0);
    }

    int find(int u)
    {
        return u==par[u]?u:par[u]=find(par[u]);
    }

    bool isSameSet(int u, int v) { return find(u) == find(v);

        bool join(int u,int v)
        {
            if(isSameSet(u,v)){
                return 0;
            }
        u=find(u),v=find(v);
        if(u==v)
            return 0;

            if(size[u] > size[v]) swap(u, v);

            par[u] = v;
            size[v] += size[u];
            --nsets;

            return 1;
        }

        int numDisjointSets() { return nsets; }

        int sizeOfSet(int i) { return size[find(i)]; }
    };
