#include <iostream>
#include "DynamicArrays.h"
using namespace std;
int main(){
    DYnamicArrays<int> nums;
    for(int i=0;i<6;i++){
        nums.insert(i, i-1);
    }
    for(int i=0;i<6;i++){
        cout << nums[i] << " ";
    }
    cout << "\n";
    cout << "FIndByValue: " << nums.Find_Byvalue(3) << "\n";
    cout << "FIndByIndex: " << nums.Find_Byindex(1) << "\n";
    cout << "Delete: " << "\n";
    nums.Delete(3);
    for(int i=0;i<nums.length();i++){
        cout << nums[i] << " " ;
    }
    cout << "\n";
    cout << "Isempty: " << nums.isempty();
    return 0; 
}