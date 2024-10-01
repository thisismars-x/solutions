#include<bits/stdc++.h>
using namespace std;

int main(){
    int ncase; cin >> ncase;

    string pro[30], word, line;
    int w[30], p[30];

    while(ncase--){
        int n; cin >> n;
        map<string, int> R[30];

        for(int i = 0; i < n; i++){
            cin >> pro[i] >> w[i] >> p[i];

            for(int j = 0; j < w[i]; j++){
                cin >> word;
                R[i][word] = 0;
            }
        }

        cin.ignore(256, '\n');

        while(getline(cin, line)){
            int len = line.size();
            if(!len) break;

            for(int i = 0; i < len; i++){
                if(isalpha(line[i])){
                    char buf[100], idx=0;
                    while(i < len and isalpha(line[i])){
                        buf[idx++] = line[i++];
                    }

                    buf[idx] = '\0';
                    for(int j = 0; j < n; j++){
                        if(R[j].find(buf) != R[j].end()){
                            R[j][buf] = 1;
                        }
                    }
                }
            }
        }

        int first = 0;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(auto it = R[i].begin(); it != R[i].end(); it++){
                cnt += it -> second;
            }


            if(cnt >= p[i]){
                first++;
                if(first != 1) cout << ",";
                cout << pro[i];
            }
        }

        if(!first) cout << "SQF Problem.";
        cout << '\n';
    }
}