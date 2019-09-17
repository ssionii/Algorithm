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

string numArr[10] = {
        "3211","2221","2122","1411",
        "1132", "1231", "1114","1312",
        "1213", "3112"
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

int getNumFromBinary(string str, int codeLength){
    bool isZero = true;
    int tempSize = 0;
    string result = "";

    for(int i = 0; i < str.size(); i++){

        if(isZero && str[i] == '0'){  // 앞에도 0, 현재도 0
            tempSize++;
        }else if(isZero && str[i] == '1'){  // 앞에는 0, 현재는 1
            result.append(to_string(tempSize));
            isZero = false;
            tempSize = 1;
        }else if(!isZero && str[i] =='0') { // 앞에는 1, 현재는 0
            result.append(to_string(tempSize));
            isZero = true;
            tempSize = 1;
        }else{ // 앞에도 1, 현재도 1
            tempSize++;
        }
    }
    result.append(to_string(tempSize));

    for(int i = 0; i< 4; i++){
        result[i]/=codeLength;
    }

    int num;
    for(num = 0; num <10; num++){
        if(result == numArr[num])
            break;
    }

    return num;

}

int main() {

    int test_case;
    cin >> test_case;
    for(int test_num = 1; test_num <= test_case; test_num++){
        int N, M;
        cin >> N >> M;

        bool notZero = false;
        vector <string> hexCodes;

        int result = 0;

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
        int passCode[8];
        bool isDuplicate = false;
        for(int i = 0; i<hexCodes.size(); i++){
            binaryCodes.push_back(HexToBinary(hexCodes.at(i)));

            int codeLength = 1;
            for(int l = binaryCodes.at(i).size() - 1; l >=0; l--){

                if(binaryCodes.at(i)[l] == '1'){
                    while(binaryCodes.at(i)[l - 56*codeLength] != '0'){
                        codeLength++;
                    }

                    // passCode 중복 없애기
                    for(int d = 0; d < passCodes.size(); d++){
                        if(passCodes.at(d) == binaryCodes.at(i).substr(l-(56*codeLength)+1, 56*codeLength)){
                            isDuplicate = true;
                            break;
                        }
                    }
                    if(!isDuplicate) {
                        passCodes.push_back(binaryCodes.at(i).substr(l - (56 * codeLength) + 1, 56 * codeLength));
                        // passCode 10진수 숫자로 바꾸기?

                        int sum = 0, resultTemp = 0;
                        for(int index = 0; index < 8; index ++){
                            passCode[index] = getNumFromBinary(passCodes.back().substr(index*7*codeLength,7*codeLength), codeLength);

                            if(index % 2 == 0) { // 짝수
                                sum += passCode[index];
                            }else if((index % 2 == 1) && index != 7){ // 홀수
                                sum += passCode[index]*3;
                            }else if(index == 7){
                                sum += passCode[index];
                            }

                            cout << passCode[index] <<" ";
                        }

                        // 검증 코드 확인
                        if(sum % 10 != 0){
                            sum -= passCode[7];
                            int lastCode = 10 - (sum%10);
                            passCode[7] = lastCode;
                        }

                        // 결과 출력
                        for(int index = 0; index < 8; index ++){
                            cout << passCode[index] <<" ";
                            resultTemp +=passCode[index];
                            result = resultTemp;
                        }

                    }

                    l -= 56;
                    codeLength = 1;
                    isDuplicate = false;
                }
            }
        }

        cout << "#" << test_num << " " << result<<endl;
    }
}
