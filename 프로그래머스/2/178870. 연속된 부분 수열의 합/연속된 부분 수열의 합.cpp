#include <string>
#include <vector>
#include <climits>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int n=sequence.size();
    int left=0;
    int right=0;
    int sum=sequence[0];
    int minLne=INT_MAX;
    int start=0;
    int end=0;
    while(left<n && right<n){
        if(sum==k){
            if(right-left<minLne){
                start=left;
                end=right;
                minLne=right-left;
            }
            sum-=sequence[left];
            left++;
        }else if(sum>k){
            sum-=sequence[left];
            left++;
        }else if(sum<k){
            right++;
            if(right<n)sum+=sequence[right];
        }
    }
    answer.push_back(start);
    answer.push_back(end);
    return answer;
    
}