//
//  main.cpp
//  LW2 (Mikozi)
//
//  Created by Никита on 3/8/22.
//

#include <iostream>
#include <vector>

std::vector <int> convertToBinary(int &num) {
    std::vector <int> numBinary;
    for (int i = 0; num > 0; ++i) {
        numBinary.push_back(num % 2);
        num /= 2;
    }
    reverse(numBinary.begin(), numBinary.end());
    return numBinary;
}

void printBinaryNum(std::vector <int> &numBinary) {
    for (int i = 0; i < numBinary.size(); ++i) {
        std::cout << numBinary[i] << ' ';
    }
    std::cout << '\n';
}

int main(int argc, const char * argv[]) {

    std::cout << "Programm start!\n";
    std::cout << "N = 16, 7 * 16 = 102\n";
    int num = 102;
    std::vector <int> numBinary = convertToBinary(num);
    printBinaryNum(numBinary);
    
    std::cout << "key = 4096 – 11 * 7 * 6 = 3634; q = 6; r = 7\n";
    
    int keyNum = 3634;
    std::vector <int> keyNumBinary = convertToBinary(keyNum);
    printBinaryNum(keyNumBinary);
    return 0;
}
