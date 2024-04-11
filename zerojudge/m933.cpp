#include<iostream>
#include<map>
#include<vector>
#include<utility>
using namespace std;

int p,q,r,m,maxdepth=-1;
vector<int> inputtypes(1005);
vector<int> gatetypes(1005);
vector<int> results(1005);
map<int,pair<int,int>> graph;

int searching(int n,int depth) {
    maxdepth = max(maxdepth,depth);
    if (n<=p) {
        return inputtypes[n];
    } else if (n>p&&n<=p+q) {
        int grabtype = gatetypes[n-p];
        if (grabtype == 1) {
           return searching(graph[n].first,depth+1)&searching(graph[n].second,depth+1);
        } else if (grabtype == 2) {
            return searching(graph[n].first,depth+1)|searching(graph[n].second,depth+1);
        } else if (grabtype == 3) {
            return searching(graph[n].first,depth+1)^searching(graph[n].second,depth+1);
        } else {
            return !searching(graph[n].second,depth+1);
        }
    } else if (n>p+q) {
        return searching(graph[n].first,depth);
    }
    return 0;
}

int main() {
    cin >> p >> q >> r >> m;
    for (int i=1;i<=p;i++) {
        cin >> inputtypes[i];
    }
    for (int i=1;i<=q;i++) {
        cin >> gatetypes[i];
    }
    for (int i=0;i<m;i++) {
        int from,to;
        cin >> from >> to;
        if (graph[to].first>0) { 
            graph[to].second = from;
        } else if (graph[to].second>0) {   
        } else {
            graph[to].first = from;
        }
    }
    for (int i=1;i<=r;i++) {
        int request=p+q+i;
        results[i] = searching(request,0);
    }
    cout << maxdepth << "\n";
    for (int i=1;i<=r;i++) {
        cout << results[i] << " ";
    }
}
