#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int l=1;
    int r=1;
    int sum=1;
    while(r<=n){

        if(sum==n){
            answer+=1;
        }
        if(sum>=n) sum-=l++;
        else if(sum<n)sum+=++r;
        
    }
    return answer;
}