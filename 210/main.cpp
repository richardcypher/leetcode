/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年10月30日 星期五 12时24分47秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
    vector<int> result;
    vector<int>* edges = new vector<int>[numCourses];
    vector<int> parent(numCourses, 0);
    int count = prerequisites.size();
    for(int i = 0; i < count; i++) {
        edges[prerequisites[i].second].push_back(prerequisites[i].first);
        parent[prerequisites[i].first]++;
    }
    queue<int> q;
    for(int i = 0; i < numCourses; i++) {
        if(parent[i] == 0)
            q.push(i);
    }
    while(!q.empty()) {
        int course = q.front();
        q.pop();
        result.push_back(course);
        for(int i = 0; i < edges[course].size(); i++) {
            count--;
            parent[edges[course][i]]--;
            if(parent[edges[course][i]] == 0)
                q.push(edges[course][i]);
        }
    }
    if(count != 0)
        result.clear();
    return result;
}

int main() {
     vector<pair<int, int> > pre;
     pre.push_back(make_pair(1,0));
     vector<int> r = findOrder(2, pre);
     for(auto i : r)
        cout<<i<<endl;
    return 0;
}
