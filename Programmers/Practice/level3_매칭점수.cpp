//
// Created by 양시연 on 2020/09/04.
//

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

class WebPage{
public:
    int index = 0;
    double basicScore = 0;
    string url = "";
    map<string, int> link;
    double linkScore = 0;
    double matchingScore = 0;
};

bool cmp(WebPage a, WebPage b){
    return a.matchingScore > b.matchingScore;
}

vector<string> splitString(string str, char split){
    vector<string> temp;
    istringstream ss(str);
    string stringBuffer;
    while (getline(ss, stringBuffer, split)){
        temp.push_back(stringBuffer);
    }

    return temp;
}

string getUrl(int start, int end, string str){
    vector<string> temp = splitString(str.substr(start, end - start), '>');
    int urlStartIndex = 0;
    vector<string> url;

    for(int i = 0 ; i < temp.size(); i++){
        if(temp[i].find("<meta ") != string::npos
        && temp[i].find("https://") != string::npos
        && temp[i].find("\"") != string::npos){
            urlStartIndex = temp[i].find("https://");
            url = splitString(temp[i].substr(urlStartIndex), '"');
            break;
        }
    }
    return url[0];
}

map<string, int> getLink(string str){

    map<string, int> link;

    string::size_type start;
    start = str.find("<a href");
    string::size_type end;
    end = str.find("</a>");

    while(start != string::npos && end != string::npos){

        string temp = splitString(str.substr(start, end-start), '"')[1];
        if(link.count(temp) == 0) link[temp] = 1;
        else link[temp]++;

        str.erase(0, end + 4);

        start = str.find("<a href");
        end = str.find("</a>");
    }

    return link;
}

double getBasicScore(string word, string str){
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);

    double count = 0;
    string::size_type index = str.find(word);
    while(index != string::npos){
        if(!isalpha(str[index + word.length()])){
            count++;
            str.erase(0, index + word.length());
        }else{
            for(int i = index + word.length() + 1; i < str.size(); i++){
                if(!isalpha(str[i])){
                    str.erase(0, i);
                    break;
                }
            }
        }

        index = str.find(word);
    }

    return count;
}

int solution(string word, vector<string> pages) {
    int answer = 0;

    vector<WebPage> webPages;

    for(int i = 0; i< pages.size(); i++){
        WebPage webPage = WebPage();

        webPage.url = getUrl(pages[i].find("<head>"), pages[i].find("</head>"), pages[i]);
        webPage.link = getLink(pages[i]);
        webPage.basicScore = getBasicScore(word, pages[i]);
        webPage.index = i;
        webPages.push_back(webPage);
    }

    for(int i = 0; i < webPages.size(); i++){
        double linkScore = 0;
        for(int j = 0; j < webPages.size(); j++){
            if(i != j && webPages[j].link.count(webPages[i].url) != 0){
                linkScore += webPages[j].basicScore / webPages[j].link.size();
            }
        }
        webPages[i].linkScore = linkScore;
        webPages[i].matchingScore = webPages[i].basicScore + webPages[i].linkScore;

//        cout << webPages[i].index << " -- 기본 점수 : " <<  webPages[i].basicScore << ", 외부 링크 수 : " <<  webPages[i].link.size() << ", 링크 점수 : " <<  webPages[i].linkScore << ", 매칭 점수 : " <<  webPages[i].matchingScore << endl;
    }

    stable_sort(webPages.begin(), webPages.end(), cmp);
    answer = webPages[0].index;

    return answer;
}

int main(){
    cout << solution("Muzi", {"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"}) << endl;
}