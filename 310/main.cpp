/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月26日 星期四 20时01分31秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;


struct Node
        {
            unordered_set<int> neighbor;
            bool isLeaf()const{return neighbor.size()==1;}
        };
int height(vector<int> * vertex, int root) {
    map<int, bool> visited;
    int h = 0, hstart = -1, tmp, i;
    queue<int> q;
    q.push(root);
    visited[root] = true;
    while(!q.empty()) {
        tmp = q.front();
        q.pop();
        if(tmp == hstart){
            hstart = -1;
            h++;
        }
        for(i = 0; i < vertex[tmp].size(); i++) {
            if(visited.count(vertex[tmp][i]) == 0) {
                visited[vertex[tmp][i]] = true;
                q.push(vertex[tmp][i]);
                if(hstart == -1)
                    hstart = vertex[tmp][i];
            }
        }
    }
    return h;
}

vector<int> findMinHeightTrees1(int n, vector<pair<int, int> >& edges) {
    vector<int> trees;
    if(edges.empty())
        return trees;
    vector<int> *vertex = new vector<int>[n];
    for(int i = 0; i < edges.size(); i++) {
        vertex[edges[i].first].push_back(edges[i].second);
        vertex[edges[i].second].push_back(edges[i].first);
    }
    vector<int> heights(n, n);
    int min = n;
    for(int i = 0; i < n; i++) {
        heights[i] = height(vertex, i);
        if(min > heights[i])
            min = heights[i];
    }
    for(int i = 0; i < n; i++) {
        if(min == heights[i])
            trees.push_back(i);
    }
    return trees;
}

        vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {

            vector<int> buffer1;
            vector<int> buffer2;
            vector<int>* pB1 = &buffer1;
            vector<int>* pB2 = &buffer2;
            if(n==1)
            {
                buffer1.push_back(0);
                return buffer1;
            }
            if(n==2)
            {
                buffer1.push_back(0);
                buffer1.push_back(1);
                return buffer1;
            }

            // build the graph
            vector<Node> nodes(n);
            for(auto p:edges)
            {
                nodes[p.first].neighbor.insert(p.second);
                nodes[p.second].neighbor.insert(p.first);
            }

            // find all leaves
            for(int i=0; i<n; ++i)
            {
                if(nodes[i].isLeaf()) pB1->push_back(i);
            }

            // remove leaves layer-by-layer            
            while(1)
            {
                for(int i : *pB1)
                {
                    for(auto n: nodes[i].neighbor)
                    {
                        nodes[n].neighbor.erase(i);
                        if(nodes[n].isLeaf()) pB2->push_back(n);
                    }
                }
                if(pB2->empty())
                {
                    return *pB1;
                }
                pB1->clear();
                swap(pB1, pB2);
            }

        }

int main(){
    vector<pair<int, int> >es;
    es.push_back(make_pair(1,0));
    es.push_back(make_pair(1,2));
    es.push_back(make_pair(1,3));
    vector<int> r = findMinHeightTrees(4, es);
    for(int i = 0; i < r.size(); i++)
        cout<<r[i]<<'\t';
    cout<<endl;
}
