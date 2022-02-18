#include <iostream>
#include <vector>

using namespace std;



int main(){

    vector<int> v;

    v.push_back(-1);

    size_t n;
    cin >> n;

    for(size_t i = 0; i<n; i++){
        int temp; 

        cin >>temp;
        v.push_back(temp);
    }

    for(size_t i = 1; i <= n; i++){
        int a;
        a = v[v[v[i]]];

        if(a == i){
            cout << "YES";
            exit(0);
        }

    }

    cout << "NO";
    
    
    
    

    return 0;
}


