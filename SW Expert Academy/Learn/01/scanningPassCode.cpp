#include <iostream>
#include <vector>
#include <string>

using namespace std;

char input[500][2000];
string binaryArr[16] = {
        "0000", "0001","0010","0011",
        "0100","0101","0110","0111",
        "1000","1001","1010","1011",
        "1100","1101","1110","1111"
};


string HexToBinary(string str){

    string result = "";
    for(int i = 0; i < str.size(); i++){
        if(str[i] < 58)
            str[i] -= 48;
        else
            str[i] -= 55;

        result.append(binaryArr[str[i]]);

    }

    return result;

}

int main() {

    int test_case;
    cin >> test_case;
    for(int test_num = 1; test_num <= test_case; test_num++){
        int N, M;
        cin >> N >> M;

        bool notZero = false;
        vector <string> hexCodes;

        // 입력 받고, 암호 코드를 포함한 행 찾기
        for(int n = 0; n < N; n++){
            for(int m = 0; m < M; m++){
                cin >>input[n][m];
                if(input[n][m] != '0') {
                    notZero = true;
                }
            }
            if(notZero){
                if(hexCodes.size() == 0)
                    hexCodes.push_back(input[n]);

                bool isNewPassCode = true;
                for(int i = 0; i < hexCodes.size(); i++){
                    if(hexCodes.at(i) == input[n])
                        isNewPassCode = false;
                }
                if(isNewPassCode){
                    hexCodes.push_back(input[n]);
                }
                notZero = false;
            }

        }

        // 16진수 배열을 2진수 배열로
        vector <string> binaryCodes;
        vector <string> passCodes;
        for(int i = 0; i<hexCodes.size(); i++){
            binaryCodes.push_back(HexToBinary(hexCodes.at(i)));

            int codeLength = 1;
            for(int l = binaryCodes.at(i).size() - 1; l >=0; l--){

                if(binaryCodes.at(i)[l] == '1'){
                    while(binaryCodes.at(i)[l - 56*codeLength] != '0'){
                        codeLength++;
                    }
                    passCodes.push_back(binaryCodes.at(i).substr(l-(56*codeLength)+1, 56*codeLength));

                    l -= 56;
                }
            }
        }



        for(int i = 0; i < passCodes.size(); i++){
            cout << passCodes.at(i) << endl;
        }
    }
}
