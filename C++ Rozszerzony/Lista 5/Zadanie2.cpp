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
        //cout << val << endl;
        
        for(int i = 0; i < nodes.size(); i++){
            //cout << nodes[i].name << ", liczba sasiadow = " << nodes[i].Adjacent.size() << ": ";
            for(list<Node*>::iterator iter = nodes[i].Adjacent.begin(); iter != nodes[i].Adjacent.end(); iter++){
               // cout << (*iter)-> name << ", ";
                cout << (*iter)->name << " " << *iter << endl;
                if((*iter)->value == val){
                    //cout << nodes[i].name << " " << (*iter)->name << endl;
                    //nodes[i].Adjacent.remove(*iter);  // https://stackoverflow.com/questions/596162/can-you-remove-elements-from-a-stdlist-while-iterating-through-it
                }
            }
           // cout << endl;
        }
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
            cout << node.name << " " << node.value << " " << &node;
            cout << ", Adjacent to: "; 
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
    graph.DeleteNode(1);
    //graph.Print();
}