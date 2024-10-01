#include<iostream>
using namespace std;

int main(){
    int num;
    while(cin >> num, num){
        unsigned int a = 0, b = 0;
        int incr_a = true;
        int add = 1;

        while(num){

            if(num & 1){
                if(incr_a) a += add;
                else b += add;

                incr_a = !incr_a;
            }

            add *= 2;
            num/=2;
        }

        cout << a << " " << b << '\n';
    }
}