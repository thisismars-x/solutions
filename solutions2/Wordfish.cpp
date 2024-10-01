#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;
int distance(string& temp){
    int d = 26;
    for(int i = 1; i < temp.length(); i++){
        d = min(abs(temp[i]-temp[i-1]), d);
    }

    return d;
}

int main(){
    string in;
    while(getline(cin, in) , !in.empty()){
        int max_dist = distance(in);
        string best = in;

        string curr{in}, next{in};
        bool curr_ = true, next_ = true;

        for(int i = 0; i < 10; i++){
            next_ = next_ ? next_permutation(next.begin(), next.end()): false;
            curr_ = curr_ ? prev_permutation(curr.begin(), curr.end()): false;

            int dist = distance(curr);
            if(curr_ && dist >= max_dist){
                best = curr;
                max_dist = dist;
            }

            dist  = distance(next);
            if(next_ && dist > max_dist){
                best = next;
                max_dist = dist;
            }
        }

        cout << best << max_dist << '\n';
    }
}