#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums={2,3,3,3};
    int result = 0;

    for(int i=0 ;i<=32;i++){
        int sum =0;
        for(int num : nums){
            if (num & (1<<i)){
                sum++;
            }
        }
        if(sum%3){
            result |= (1<<i);
        } 
    }  
    cout << "Result: " << result << endl;
    return 0;
}
    