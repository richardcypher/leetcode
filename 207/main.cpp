/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月28日 星期三 11时08分35秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
    bool result = true;
    vector<int> *matrix = new vector<int>[numCourses];
    vector<int> incoming(numCourses, 0);
    int edges = prerequisites.size();
    queue<int> nodes;
    for(int i = 0; i < edges; i++) {
        matrix[prerequisites[i].first].push_back(prerequisites[i].second);
        incoming[prerequisites[i].second]++;
    }
    for(int i = 0; i < numCourses; i++) {
        if(incoming[i] == 0)
            nodes.push(i);
    }
    while(!nodes.empty()) {
        int node = nodes.front();
        nodes.pop();
        for(int i = 0; i < matrix[node].size(); i++) {
            edges--;
            incoming[matrix[node][i]]--;
            if(incoming[matrix[node][i]] == 0)
                nodes.push(matrix[node][i]);
        }
    }
    return edges == 0;
}

int main() {
    vector<pair<int, int> > pre;
    pre.push_back(make_pair(0,1));
    cout<<canFinish(2, pre)<<endl;
    return 0;
}
