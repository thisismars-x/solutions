#include<bits/stdc++.h>
using namespace std;

int main(){

    int T, N, M;
    cin >> T;

    int matrix[10][10];
    int n = 1;

    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++) scanf("%1d", &matrix[i][j]);

        cin >> M;
        string temp;
        while(M--){
            cin >> temp;
            if(temp == "transpose"){
                for(int i = 0; i < N; i++){
                    for(int j = 1 + i; j < N; j++){
                        swap(matrix[i][j], matrix[j][i]);
                }}
            }else if(temp == "inc"){
                for(int i = 0; i < N; i++)
                    for(int j = 0; j < N; j++)
                        matrix[i][j] = (matrix[i][j] + 1) % 10;
            }else if(temp == "dec"){
                for(int i = 0; i < N; i++)
                    for(int j = 0; j < N; j++){
                        matrix[i][j] = (matrix[i][j]+9)%10;
                        if(matrix[i][j] < 0)
                            matrix[i][j] = 9;
                    }
            }else{
                int a, b; cin >> a >> b;
                a--; b--;
                
                if(temp == "col"){
                    for(int i = 0; i < N; i++)
                        swap(matrix[i][a], matrix[i][b]);
                }else if(temp == "row"){
                    for(int i = 0; i < N; i++)
                        swap(matrix[a][i], matrix[b][i]);
                }
            }
        }

        cout << "Case #" << n++ << '\n';
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout << matrix[i][j];
            }
            cout << '\n';
        }

        cout << '\n';
    }

}