#include <iostream>
using namespace std;
int main(){
    int n = 3000;
    while(n--) { // 2*n次
        printf("%d" ,n); //n 次
    }  
    return 0;
}

// T(n) = 3*n     3系数可忽略
// O(n) = n