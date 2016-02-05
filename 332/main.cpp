/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年02月05日 星期五 10时29分16秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

map<string, multiset<string> > targets;
vector<string> route;
void visit(string airport) {
    while(targets[airport].size()) {
        string next = *targets[airport].begin();
        targets[airport].erase(targets[airport].begin());
        visit(next);
    }
    route.push_back(airport);
}

vector<string> findItinerary(vector<pair<string, string> >tickets) {
    for(auto ticket : tickets) {
        targets[ticket.first].insert(ticket.second);
    }
    visit("JFK");
    return vector<string>(route.rbegin(), route.rend());
}

int main(){}
