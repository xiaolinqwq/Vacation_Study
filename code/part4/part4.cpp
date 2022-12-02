#include <iostream>
#include "mqueue.h"
#include "mstack.h"
using namespace std;
int main(){
    /*
    Mqueue<int> q(100);
    for(int i=0;i<100;i++){
        q.push_back(i);
    }
    for(int i=0;i<100;i++){
        cout << q.top() << " ";
        q.pop();
    }
    cout << "\n" << q.isempty() << "\n";
    for(int i=0;i<100;i++){
        q.push_back(i);
    }
    for(int i=0;i<100;i++){
        cout << q.top() << " ";
        q.pop();
    }
    cout << "\n" << q.isempty() << "\n";
    */
    mStack<int> s(100);
    for(int i=0;i<100;i++){
        s.push(i);
    }  
    for(int i=0;i<100;i++){
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n" << s.isempty() << "\n";
    return 0;
}