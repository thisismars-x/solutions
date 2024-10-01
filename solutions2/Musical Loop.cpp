#include<iostream>
#include<vector>
using namespace std;

int main(){
    while(true){
        int n;
        cin >> n;

        if(n == 0) break;

        vector<int> notes(n);
        for(int i = 0; i < n; i++) cin >> notes[i];

        int peaks = 0;
        for(int i = 1; i < n-1; i++){
            if((notes[i] > notes[i+1]) && (notes[i] > notes[i-1])) ++peaks;
            if((notes[i] < notes[i+1]) && (notes[i] < notes[i-1])) ++peaks; 
        }


        if((notes[0] > notes[1]) && (notes[0] > notes[n-1])) ++peaks;
        if((notes[0] < notes[1]) && (notes[0] < notes[n-1])) ++peaks;
        if((notes[n-1] > notes[0]) && (notes[n-1] > notes[n-2])) ++peaks;
        if((notes[n-1] < notes[0]) && (notes[n-1] < notes[n-2])) ++peaks;
    
    
        cout << peaks << endl;
    }
}