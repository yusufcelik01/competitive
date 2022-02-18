#include <iostream>

using namespace std;

int main()
{
    char c;
    unsigned int k,n;

    cin >> n >> k;

    char word[n];

    for(unsigned i=0; i<n; i++){
        cin >> c;// c is betwenn 0-9 
        if(k > 0){
            if(i==0 && n > 1){
                if(c != '1'){
                    word[i] = '1';
                    k--;
                }
                else{
                    word[i] = c;
                }
            }
            else{
                if(c != '0'){
                    word[i] = '0';
                    k--;
                }
                else{
                    word[i] = c;
                }
            }
        }
        else{
            word[i] = c;
        }
        cout << word[i];
    }
  
    

    return 0;
}

