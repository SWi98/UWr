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

    void AddEdge(int val, int val2, int weight){
        if (val == val2)
            return;
        bool firstPresent = false, secondPresent = false;
        Node *first;
        Node *second;
        for(Node &n : nodes){
            if(n.value == val){
                firstPresent = true;
                first = &n;
                break;
            }
        }
        for(Node &n : nodes){
            if(n.value == val2){
                secondPresent = true;
                second = &n;
                break;
            }
        }
        if (!firstPresent || !secondPresent)
            return;
        
        first->Adjacent.push_back(second);
        second->Adjacent.push_back(first);
        Edge edge;
        edge.first = *first;
        edge.second = *second;
    }

    void AddEdge(string name1, string name2, int weight){
        if (name1 == name2)
            return;
        bool firstPresent = false, secondPresent = false;
        Node *first;
        Node *second;
        for(Node &n : nodes){
            if(n.name== name1){
                firstPresent = true;
                first = &n;
                break;
            }
        }
        for(Node &n : nodes){
            if(n.name == name2){
                secondPresent = true;
                second = &n;
                break;
            }
        }
        if (!firstPresent || !secondPresent)
            return;
        
        Edge edge;
        edge.first.Adjacent.push_back(second);
        edge.second.Adjacent.push_back(first);
        edge.first = *first;
        edge.second = *second;
    }

    void Print(){
        for(Node &node: nodes){
            cout << node.name << " " << node.value << endl;
            cout << "Adjacent to: "; 
            for(Node* neighbor : node.Adjacent){
                cout << neighbor->value<< " " << neighbor->name << "; ";
            }
            cout << "\n";
        }
    }
};
int main(){
    Graph graph;
    graph.AddNode(1, "jeden");
    graph.AddNode(3, "trzy");
    graph.AddNode(2, "dwa");
    graph.AddEdge(1, 2, 1);
    graph.AddEdge(1, 3, 1);
    graph.Print();
}