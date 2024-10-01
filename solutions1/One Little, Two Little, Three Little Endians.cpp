#include<bits/stdc++.h>
using namespace std;

int main() {
    int number, result;

    while(scanf("%d", &number) == 1){
        result = 0;
        int n = number;

        for(int i = 0; i < 4; i++, number >>= 8){
            result <<= 8;
            result |= (number) & 0xFF;
        }

        cout << n << " converts to " << result << '\n';
    }
}

