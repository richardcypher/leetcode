#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

map<int, UndirectedGraphNode*> clone;

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if(!node)
        return NULL;
    if(clone.find(node->label) != clone.end())
        return clone[node->label];
    clone[node->label] = new UndirectedGraphNode(node->label);
    for(auto neighbor : node->neighbors) {
        clone[node->label]->neighbors.push_back(cloneGraph(neighbor));
    }
    return clone[node->label];
}

int main() {
    return 0;
}