#include<iostream>
#include<queue>
#include<string.h>
#include<unordered_map>
#include<map>
using namespace std;

#define p                   push
#define ump                 unordered_map

map<string, int> ordering;

void mapper(){

    queue<string> temp;
    for(char i = 'a'; i <= 'z'; i++) temp.p(string(1, i));

    string temp0;
    int count = 1;
    while(!temp.empty()){
        temp0 = temp.front();
        temp.pop();

        ordering[temp0] = count;
        count++;

        if(temp0.size() == 5) continue;
        for(char x = temp0[temp0.size() - 1] + 1; x <= 'z'; x++) temp.p(temp0 + x);
    }

}


int main(){

    mapper();
    string s; 
    while(cin >> s){
        auto it = ordering.find(s);
        if(it != ordering.end()) cout << it->second << '\n';
        else cout << "0\n";
    }
}