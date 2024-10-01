#include<bits/stdc++.h>

int Calculate(const std::string &name) {
    int total = 0;
    for (char ch : name) {
        if (ch >= 'a' && ch <= 'z') {
            total += ch - 'a' + 1;
        } else if (ch >= 'A' && ch <= 'Z') {
            total += ch - 'A' + 1;
        }
    }
    
    while (total >= 10) {
        int temp = 0;
        while (total) {
            temp += total % 10;
            total /= 10;
        }
        total = temp;
    }
    
    return total;
}

int main() {
    std::string nameOne, nameTwo;

    while (std::getline(std::cin, nameOne) && std::getline(std::cin, nameTwo)) {
        int first = Calculate(nameOne);
        int second = Calculate(nameTwo);

        double percentage;
        if (first < second) {
            percentage = (first * 100.0) / second;
        } else {
            percentage = (second * 100.0) / first;
        }
        
        std::cout << std::fixed << std::setprecision(2) << percentage << " %\n";
    }

    return 0;
}
