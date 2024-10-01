#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int p, available, temp;
    scanf("%d\n", &p);

    while(p--){
        scanf("%d\n", &available);
        vector<int> red;
        vector<int> blue;

        int prev = 0, res = 0;

        while(available--){
            scanf("%d\n", &temp);
            if(temp > 0) blue.push_back(temp);
            else red.push_back(temp);
        }

        sort(blue.begin(), blue.end());
        sort(red.begin(), red.end(), greater<int>());

        auto r_start = red.begin(), b_start = blue.begin();


        while(prev == 0 or (prev>0 and r_start != red.end()) or (prev<0 and b_start != blue.end())){
            if(prev == 0){
                prev = abs(*r_start) < *b_start? *r_start : *b_start;
                if(prev == *b_start) b_start++;
                else r_start++;
                res++;
            }else if(prev < 0){
                if(*b_start > abs(prev)){
                    prev = *b_start;
                    res ++ ;
                }
                b_start++;
            }else{
                if(abs(*r_start) > prev){
                    prev = *r_start;
                    res++;
                }

                r_start++;
            }
        }

        cout << res << '\n';
    }


}