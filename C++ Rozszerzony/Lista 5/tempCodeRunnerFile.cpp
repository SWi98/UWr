#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Node{
    int value;
    string name;
    list<Node*> Adjacent;
};

struct Edge{
    Node first;
    Node second;
    int weight;
};

class Graph{
    private:
    vector<Node> nodes;
    vector<Edge> edges;

    public:
    void AddNode(int val, string name){
        for(Node n : nodes){
            if (n.value == val || n.name == name)
                return;
        }
        Node node; 
        node.value = val;
        node.name = name;
        nodes.push_back(node);
    }

    void DeleteNode(int val){
        // How to iterate with foreach over vector using pointers