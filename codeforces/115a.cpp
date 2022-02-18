#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:    
    int id;
    vector<Node*> children;
    
    Node(int nodeId){
        id = nodeId;
    }
};

enum Color{
    white, gray, black
};

class Tree{
    public:
    vector<Node*> vertices;
    vector<Color> color;
    vector<int> d;//depth of this node
    //int time;


    Tree(size_t numOfVertices){
        for(size_t i=0; i<numOfVertices; i++){
            vertices.push_back(new Node(i));
            color.push_back(white);
            d.push_back(-1);
        }
    }

    void addEdge(int u, int v){// edge (u,v)
        vertices[u]->children.push_back(vertices[v]);
    }



    int dfs_visit(int u){//returns depth of dfs tree
        int depth = 1;
        color[u] = gray;
        int v;

        size_t n = vertices[u]->children.size();
        for(size_t i=0; i<n; i++){
            v = vertices[u]->children[i]->id;
            if(color[v] == white){
                int temp = dfs_visit(v) + 1;//child +1 
                depth = max(depth, temp);
            }
            else{
                depth = max(depth, d[v] + 1);
            }
        }
        //color[u] = black;

        d[u] = depth;
        return depth;
    }

    int dfs(){//returns max dfs depth of graph
        int max_depth = 1;
        //time =0;
    
        size_t n = vertices.size();
        for(size_t u=0; u<n; u++){//for all u element of V
            if(color[u] == white){
                int temp = dfs_visit(u);
                max_depth = max(max_depth, temp);
            } 
            else{
                max_depth = max(max_depth, d[u]);
            }
        }
        return max_depth;
    }

};

int main(){
    
    int n;
    int sup;

    cin >> n;
    Tree t = Tree(n);

    for(int i =0; i<n; i++){
        cin >> sup;
        if(sup != -1){
            sup--;
            t.addEdge(sup, i);
        }
        
    }

    if(n != 0){
        cout << t.dfs() << endl;
    }
    else{
        cout << 0;
    }

    

    return 0;
}
