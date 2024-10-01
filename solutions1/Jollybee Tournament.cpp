#include<bits/stdc++.h>
using namespace std;

int main(){
    int t0; cin >> t0;

    while(t0--){
        int N, M;
        cin >> N >> M;

        int numbers = pow(2, N);
        bitset<1024> bits; bits.set();

        while(M--){
            int temp; cin >> temp;
            bits.reset(temp-1);
        }

        int result = 0;

        while(numbers){
            int idx = 0;

            for(int i = 1; i < numbers; i+=2){
                result += (bits.test(i) ^ bits.test(i-1));
                bits[idx++] = bits.test(i) | bits.test(i-1);
            }

            numbers >>= 1;
        }

        cout << result << '\n';
    }
}