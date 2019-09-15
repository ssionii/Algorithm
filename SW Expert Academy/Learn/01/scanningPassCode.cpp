#include <iostream>
#include <string>

using namespace std;

string binaryArr[16] = {
        "0000", "0001","0010","0011",
        "0100","0101","0110","0111",
        "1000","1001","1010","1011",
        "1100","1101","1110","1111"
};


string HexToBinary(char hex){

    if(hex < 58)
        hex -= 48;
    else
        hex -= 55;

    return binaryArr[hex];

}

int main() {

    string input;
    cin >> input;

    string output;
    for (int i = 0; i < input.size() - 1; i++) {
        output.append(HexToBinary(input[i]));
    }
    cout << output << endl;
}
