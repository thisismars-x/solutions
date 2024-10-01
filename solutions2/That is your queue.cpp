#include<iostream>
#include<list>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b;
    char temp;
    
    int cases{0};
    while(cin >> a >> b and (a or b)){
        list<int> line;
        for(int i = 1; i <= min(a,b); i++) line.push_back(i);

        list<int> output;

        for(int i = 0; i < b; i++){
            cin >> temp;

            if(temp == 'N'){
                output.push_back(line.front());
                line.push_back(line.front());
                line.pop_front();
            }else{
                int t; cin >> t;
                line.remove(t);
                line.push_front(t);
            }
        }

        cout << "Case " << ++cases << ":\n";
        for(auto it: output) cout << it << '\n';
    }
}