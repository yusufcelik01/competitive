#include <iostream>


bool G[250][250] {false};
int degrees[250] {0};
bool visited[250] {false};

using namespace std;

bool dfs(int src, int v_count){
    static int visited_count = 0;
    visited[src] = true;

    visited_count++;
    for(int i=0; i < v_count; i++){
        if(G[src][i] && !visited[i]){
            dfs(i, v_count);
        }
    }

    return visited_count == v_count;
}

int main(){
    int v_count, e_count;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v_count >> e_count;

    for(int i=0; i < e_count; i++){
        int src, dst;
        cin >> src >> dst;
        degrees[src]++;
        degrees[dst]++;

        G[src][dst] = G[dst][src] = 1;
    }

    int odds = 0;
    for(int i=0; i < v_count; i++){
        if(degrees[i] % 2 != 0){
            odds++;
            if(odds > 2){
                cout << "INVALID" << endl;
                exit(0);
            }
        }
    }
    if(odds != 2 && odds != 0){
        cout << "INVALID" << endl;
        exit(0);
    }

    cout << (dfs(0, v_count) ? "VALID" : "INVALID") << endl;
    

    
    return 0;
}
