#include<string.h>
#include<iostream>
using namespace std;

int main(){
    int n;

    while(scanf("%d", &n) == 1){
        string older, younger;
        int old = 0, young = 2147483647;

        while(n--){
            string temp;
            int d, m, y;

            cin >> temp >> d >> m >> y;
            int age = d + (m*100) + (y*1000);
            if(age > old) old = age, older = temp;
            if(age < young) young = age, younger = temp;
        }

        cout << older << '\n';
        cout << younger << '\n';

    }
}