/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> map;
        return dfs(node, map);
    }
    
private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& map) {
        if (!node) return NULL;
        if (map.count(node)) return map[node];
        Node* clone = new Node(node->val);
        map[node] = clone;
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor, map));
        }      
        return clone;   
    }
};