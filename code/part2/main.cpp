#include <iostream>
#include "DynamicArrays.h"
#include "Linkedlist.h"
using namespace std;
int main(){
    /*
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
    */
    Linklist<int>* list = new Linklist<int>;
    for(int i=0;i<6;i++){
        list->insert(i, i);
    }
    for(int i=0;i<6;i++){
        cout << list->Find_ByIndex(i+1)->GetData() << " ";
    }
    cout << "\n";
    cout << "FIndByValue: " << list->Find_ByValue(3)->GetData() << "\n";
    cout << "Isempty: " << list->isempty();
    return 0; 
}