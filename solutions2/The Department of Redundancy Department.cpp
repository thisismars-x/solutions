#include<bits/stdc++.h>
using namespace std;

vector<int> ordering;
map<int, int> freq;

int main(){
    int temp;
    while(scanf("%d", &temp) != EOF){
        if(freq.count(temp) == 0){
            freq[temp] = 1;
            ordering.push_back(temp);
        }else{
            freq[temp] += 1;
        }
    }

    for(auto i: ordering){
            cout << i << " " << freq[i] << '\n';
        }
}