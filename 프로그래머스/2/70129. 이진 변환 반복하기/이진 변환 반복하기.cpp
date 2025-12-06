#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int cnt=0;
string solu(string a){
    int n=a.length();
    int oneCnt=0;
    string ans="";
    for(int i=0;i<n;i++){
        if(a[i]=='0')cnt+=1;
        else{
            oneCnt+=1;
        }
    }
    vector<string>arr;
    while(oneCnt!=0){
        int aa=oneCnt%2;
        oneCnt/=2;
        arr.push_back(to_string(aa));
    }
    while(!arr.empty()){
        ans+=arr.back();
        arr.pop_back();
    }
    
    return ans;
}

vector<int> solution(string s) {
    vector<int> answer;
    int an=0;
    while(true){
        an+=1;
        s= solu(s);
        if(s=="1"){
            break;
        }
    }
    answer.push_back(an);
    answer.push_back(cnt);

    return answer;
}