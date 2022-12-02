#include <iostream>
#include <time.h>
using namespace std;
const int nums = 15;
int a[100];
int tong[1000010] = {0};
void BubblingSorting(int a[], int n);
void SelectSort(int a[], int n);
void InsertSort(int a[],int n);
void mSort(int a[], int l, int r);
int main(){
    srand((int)time(0));  
    for (int i = 0; i < nums; i++)
    {
        a[i] = rand()%100;
    }
    //BubblingSorting(a, nums);
    //SelectSort(a,nums);
    //InsertSort(a, nums);
    //mSort(a, 0, 14);
    //桶排序
    for(int i=0;i<nums;i++){
        tong[a[i]] ++;
        
    }
    int i = 0, count = 0;
    while(count < nums){
        if(tong[i] != 0) {
            count += tong[i];
            while(tong[i]--) cout << i << " ";
        }
        i++;
    }
    cout << "\n";
    return 0;
}


void BubblingSorting(int a[], int n){
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void SelectSort(int a[], int n){
    for(int i=n;i>0;i--){
        int nmax = a[0],index = 0;
        for(int j=0;j<i;j++){
            if(a[j] > nmax){
                nmax = a[j];
                index = j;
            }
        }
        a[index] = a[i-1];
        a[i-1] = nmax;
    }
}

void InsertSort(int a[],int n){
    for(int i=1;i<n;i++){
        int j = i-1;
        int temp = a[i];
        while(a[i] < a[j] && j >= 0) j--;
        for(int k=i;k>j+1;k--) a[k] = a[k-1];
        a[j+1] = temp;
    }
}

void mSort(int a[], int l, int r){
    if(l >= r) return ;
    int x = a[l];
    int i = l, j = r;
    while(i < j){
        while(i < j && a[j] > x){
            j--;
        }
        if(i < j) a[i++] = a[j];
        
        while(i < j && a[i] < x){
            i++;
        }
        if(i < j) a[j--] = a[i];
    }
    a[i] = x;
    mSort(a, l, i-1);
    mSort(a, i+1,r);
}