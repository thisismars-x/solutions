#include<bits/stdc++.h>
using namespace std;

map<string, int> ordering;
int total_words{0};

void order(string& in){
    in = regex_replace(in, regex("[\\s()\",.:;!?]"), " ");
    transform(in.begin(), in.end(), in.begin(), ::tolower);

    istringstream input{in};
    string temp;
    while(input >> temp){
        ordering[temp]++;
        total_words++;
    }

}

int main(){
    string in;
    while(getline(cin, in) and in != "****END_OF_INPUT****"){
        ordering.clear(); total_words = 0;
        
        order(in);
        while(getline(cin, in) and in != "****END_OF_TEXT****"){
            order(in);
        }

        double ET = 0, ER = 0;
        if(total_words){
            for(auto &i: ordering){
                ET += i.second*(log10(total_words) - log10(i.second));
            }

            ET /= total_words;
            ER = ET * 100.0 / log10(total_words);
        }

        printf("%d %.1f %.0f\n", total_words, ET, ER);
    }
}