//
//  main.cpp
//  LW2 (Mikozi)
//
//  Created by Никита on 3/8/22.
//

#include <iostream>
#include <vector>
#include <bitset>

bool findBit(int num, int bit) {
    return (num & (1 << (bit - 1))) != 0;
}

void setBit(int &num, int bit) {
    num |= 1 << (bit - 1);
}

std::vector <int> convertToBinary2(int num) {
   
    std::vector <std::vector <int>> keyNumBinary = {{1, 2, 3, 4, 5, 6, 7, 8},
                                                    {1, 2, 3, 4, 9, 10, 11, 12},
                                                    {5, 6, 7, 8, 12, 11, 10, 9}};
    
    std::vector <int> keyBinary (3);
    
    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < 8; ++i) {
            if (findBit(num, 13 - keyNumBinary[k][i])) {
                setBit(keyBinary[k], 8 - i);
            }
        }
    }
   
    return keyBinary;
    
}

int shuffleNum(int num) {
    std::vector <int> keyNumBinary = {1, 4, 7, 2, 5, 8, 3, 6};
    
    int resNum = 0;
    
    for (int i = 0; i < 8; ++i) {
        if (findBit(num, 9 - keyNumBinary[i])) {
            setBit(resNum, 8 - i);
        }
    }
    return resNum;
}

void splitNum(int num, int &part1, int &part2) {
    part1 = 0b11110000;
    part2 = 0b00001111;
    
    part1 &= num;
    part2 &= num;
    
    part1 >>= 4;
}

void printBinaryNum(std::vector <int> &numBinary) {
    for (int i = 0; i < numBinary.size(); ++i) {
        std::cout << std::bitset<8>(numBinary[i]) << ' ';
    }
    std::cout << '\n';
}

int encryptMessage(std::vector <int> keyBinary, int num) {
    std::vector <int> s1 = {14, 4, 6, 2, 11, 3, 13, 8, 12, 15, 5, 10, 0, 7, 1, 9};
    std::vector <int> s2 = {14, 7, 10, 12, 13, 1, 3, 9, 0, 2, 11, 4, 15, 8, 5, 6};
    
    int part1 {0};
    int part2 {0};
    
    for (int i = 0; i < 3; ++i) {
        num += keyBinary[i];
        splitNum(num, part1, part2);
        num = s1[part1] << 4 ^ s2[part2];
        num = shuffleNum(num);
        std::cout << "Iteration " << i + 1 << " : " << std::bitset<8>(num) << "\n";
    }
    return num;
}

int main(int argc, const char * argv[]) {

    int num = 102;
    int keyNum = 3634;
    
    std::vector <int> keyBinary = convertToBinary2(keyNum);
    
    printBinaryNum(keyBinary);
    
    int numChangeBit = num ^ 1;
    
    num = encryptMessage(keyBinary, num);
    
    std::cout << "---------------\n";
    
    numChangeBit = encryptMessage(keyBinary, numChangeBit);
    
    std::cout << std::bitset<8>(num) << "\n";
    
    std::cout << std::bitset<8>(numChangeBit) << "\n";
    
    return 0;
}
