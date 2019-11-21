#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <set>
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
    list<Node> nodes;
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
        for(list<Node>::iterator nodeiter = nodes.begin(); nodeiter != nodes.end(); nodeiter++){
            for(list<Node*>::iterator iter = nodeiter->Adjacent.begin(); iter != nodeiter->Adjacent.end(); iter++){
                if((*iter)->value == val){
                    iter = nodeiter->Adjacent.erase(iter);          
                }
            }
        }

        for(list<Node>::iterator nodeiter = nodes.begin(); nodeiter != nodes.end(); nodeiter++){
            if(nodeiter->value == val){
                nodes.erase(nodeiter++);
                break;
            }
        }

        for(int i = 0; i < edges.size(); i++){
            if (edges[i].first.value == val || edges[i].second.value == val){
                edges.erase(edges.begin() + i);
                i--;
            }
        }
    }

    void DeleteNode(string val){
        for(list<Node>::iterator nodeiter = nodes.begin(); nodeiter != nodes.end(); nodeiter++){
            for(list<Node*>::iterator iter = nodeiter->Adjacent.begin(); iter != nodeiter->Adjacent.end(); iter++){
                if((*iter)->name == val){
                    iter = nodeiter->Adjacent.erase(iter);          
                }
            }
        }

        for(list<Node>::iterator nodeiter = nodes.begin(); nodeiter != nodes.end(); nodeiter++){
            if(nodeiter->name == val){
                nodes.erase(nodeiter++);
                break;
            }
        }

        for(int i = 0; i < edges.size(); i++){
            if (edges[i].first.name == val || edges[i].second.name == val){
                edges.erase(edges.begin() + i);
                i--;
            }
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
        edge.weight = weight;
        edges.push_back(edge);
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
        
        
        first->Adjacent.push_back(second);
        second->Adjacent.push_back(first);
        Edge edge;
        edge.first = *first;
        edge.second = *second;
        edge.weight = weight;
        edges.push_back(edge);
    }

    void DeleteEdge(int val1, int val2){
        for(int i = 0; i < edges.size(); i++){
            if(edges[i].first.value == val1 || edges[i].first.value == val2 || edges[i].second.value == val1 || edges[i].second.value == val2){
                edges.erase(edges.begin() + i);
                i--;
            }
        }

        for(list<Node>::iterator nodeiter = nodes.begin(); nodeiter != nodes.end(); nodeiter++){
            if(nodeiter->value == val1 || nodeiter->value == val2){
                for(list<Node*>::iterator iter = nodeiter->Adjacent.begin(); iter != nodeiter->Adjacent.end(); iter++){
                    if((*iter)->value == val1 || (*iter)->value == val2){
                        iter = nodeiter->Adjacent.erase(iter);          // https://stackoverflow.com/questions/596162/can-you-remove-elements-from-a-stdlist-while-iterating-through-it
                    }
                }
            }
        }
    }

    void DeleteEdge(string val1, string val2){
        for(int i = 0; i < edges.size(); i++){
            if(edges[i].first.name == val1 || edges[i].first.name == val2 || edges[i].second.name == val1 || edges[i].second.name == val2){
                edges.erase(edges.begin() + i);
                i--;
            }
        }

        for(list<Node>::iterator nodeiter = nodes.begin(); nodeiter != nodes.end(); nodeiter++){
            if(nodeiter->name == val1 || nodeiter->name == val2){
                for(list<Node*>::iterator iter = nodeiter->Adjacent.begin(); iter != nodeiter->Adjacent.end(); iter++){
                    if((*iter)->name == val1 || (*iter)->name == val2){
                        iter = nodeiter->Adjacent.erase(iter);          // https://stackoverflow.com/questions/596162/can-you-remove-elements-from-a-stdlist-while-iterating-through-it
                    }
                }
            }
        }
    }

    bool FindPath(int val1, int val2){
        bool IsFirstIn = false, IsSecondIn = false;
        Node first;
        for(list<Node>::iterator nodeiter = nodes.begin(); nodeiter != nodes.end(); nodeiter ++){
            if(nodeiter->value == val1){
                IsFirstIn = true;
                first = *nodeiter;
            }
            else if(nodeiter->value == val2)
                IsSecondIn = true;
        }
        if(!IsFirstIn || !IsSecondIn)
            return false;

        queue<Node> q; 
        set<int> visited; 
        q.push(first);
        while(q.size() > 0){
            Node parent = q.front();
            visited.insert(parent.value);
            q.pop();
            for(list<Node*>::iterator nodeiter = parent.Adjacent.begin(); nodeiter != parent.Adjacent.end(); nodeiter++){
                if((*nodeiter)->value == val2){
                    return true;
                }
                if(visited.find((*nodeiter)->value) == visited.end())
                    q.push(**nodeiter);
            }
        }
        return false;
    }

    bool FindPath(string name1, string name2){
        bool IsFirstIn = false, IsSecondIn = false;
        Node first;
        for(list<Node>::iterator nodeiter = nodes.begin(); nodeiter != nodes.end(); nodeiter ++){
            if(nodeiter->name == name1){
                IsFirstIn = true;
                first = *nodeiter;
            }
            else if(nodeiter->name == name2)
                IsSecondIn = true;
        }
        if(!IsFirstIn || !IsSecondIn){
            return false;
        }

        queue<Node> q; 
        q.push(first);
        set<int> visited; 
        while(q.size() > 0){
            Node parent = q.front();
            visited.insert(parent.value);
            q.pop();
            for(list<Node*>::iterator nodeiter = parent.Adjacent.begin(); nodeiter != parent.Adjacent.end(); nodeiter++){
                if((*nodeiter)->name == name2){
                    return true;
                }
                if(visited.find((*nodeiter)->value) == visited.end())
                    q.push(**nodeiter);
            }
        }
        return false;
    }

    void Print(){
        cout << "------------------\nNodes:\n";
        for(Node &node: nodes){
            cout << node.name << " " << node.value; // << " " << &node;
            cout << ", Adjacent to: "; 
            for(Node* neighbor : node.Adjacent){
                cout << neighbor->value << " " << neighbor->name << "; ";
            }
            cout << "\n";
        }
        cout << "\nEdges:\n";
        for(Edge edge: edges){
            cout << edge.first.name << " " << edge.first.value << " <-> ";
            cout  << edge.second.name << " " << edge.second.value << "; - weight of edge = " << edge.weight << endl;
        }
        cout <<"------------------\n";
    }
};
int main(){
    Graph graph;
    graph.AddNode(1, "jeden");
    graph.AddNode(3, "trzy");
    graph.AddNode(2, "dwa");
    graph.AddEdge(1, 2, 1);
    graph.AddEdge(1, 3, 1);
    graph.AddEdge(3, 2, 10);
    graph.AddNode(31, "trzyjeden");
    graph.AddEdge(3, 31, 1);
    graph.AddNode(4, "cztery");
    graph.AddNode(5, "piec");
    graph.AddEdge("cztery", "piec", 0);
    
    cout << "Sciezka od 1 do 4: " << graph.FindPath(1, 4) << ", " << graph.FindPath("jeden", "cztery") << endl;
    cout << "Sciezka od 1 do 3: " << graph.FindPath(1, 3) << ", " << graph.FindPath("jeden", "trzy") << endl;
    cout << "Sciezka od 1 do 31: " << graph.FindPath(1, 31) << ", " << graph.FindPath("jeden", "trzyjeden") << endl;
    graph.Print();
    /*graph.DeleteNode(1);
    graph.Print();
    graph.DeleteEdge(3, 2);
    graph.Print();*/
}