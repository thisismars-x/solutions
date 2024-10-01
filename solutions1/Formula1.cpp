#include<bits/stdc++.h>
using namespace std;

#define MAIN                        int main(){solve();}
#define rep(i, a, b)                for(int i = a; i < b; i++)
#define dfor(i,j,a,b,c,d)           for(int i = a; i < b; i++) for(int j = c; j < d; j++)
#define vi                          vector<int>
#define vvi                         vector<vi>
#define pb                          push_back
#define all(r)                      r.begin(), r.end()

void solve(){

    int nraces, npilots;
    while((cin >> nraces >> npilots), nraces, npilots){

        vvi result(nraces, vi(npilots));

        dfor(i, j, 0, nraces, 0, npilots){
            int temp; cin >> temp;
            result[i][temp-1] = j;
        }

        int nsys; cin >> nsys;
        while(nsys--){
            int nprizes; cin >> nprizes;

            vi prizes(nprizes);
            rep(i, 0, nprizes) cin >> prizes[i];


            vi scores(npilots);
            dfor(i, j, 0, nraces, 0, nprizes){
                scores[result[i][j]] += prizes[j];
            }

            auto it = max_element(scores.begin(), scores.end());
            bool ifspace = false;

            rep(i, 0, npilots){
                if(scores[i] == *it){
                    if(ifspace) cout << " ";
                    else ifspace = true;
                    cout << i + 1;
                }
            }

            cout << '\n';


        }

    }


}

                        MAIN