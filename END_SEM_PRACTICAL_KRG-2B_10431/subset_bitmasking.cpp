#include<iostream>
using namespace std;



int main(){

    int arr[]={1 , 2 ,3};

    //subset using bitmasking

    int n = sizeof(arr)/sizeof(arr[0]);

    int limit = (1<<n); 

    for(int i=0; i<limit; i++){
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }

    return 0;

}
