#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
const int n = 10;
int nums[11];
int vision[20][20] = {0};
void init();
void Paint(int l, int r,int flag);
void Updata(int l,int r);
int main(){
    init();
    for(int i=0;i<n;i++) cout << nums[i] << " ";
    cout << "\n";
    Paint(0, 0, 0);
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
        	system ("cls");
            Paint(j,j+1, 0);
            Sleep(1000);
        	if(nums[j] > nums[j+1]){
        		int temp = nums[j];
        		nums[j] = nums[j+1];
        		nums[j+1] = temp;
        		system ( "cls");
            	Paint(j,j+1, 1);
            	Sleep(1000);
        		Updata(j,j+1);
			}
        	system ("cls");
            Paint(j,j+1,0);
            Sleep(1000);
        }
    }

    
}

void init(){
    srand((int)time(0));  
    for (int i = 0; i < n; i++)
    {
        nums[i] = rand()% 10 + 1;
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            if(i >= (n-nums[j])){
                vision[i][j] = 1;
            }
        }
    }
}

void Paint(int l,int r,int flag){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vision[i][j] == 1) cout << "#" << " ";
            else cout << "  " ;
        }
        cout << "\n";
    }
    cout << "\n\n\n";
    for(int i=0;i<n;i++){
    	if(i==l||i==r) cout << "^ ";
    	else cout << "  ";
	}
	cout << "\n";
    for(int i=0;i<n;i++){
    	if(i==l||i==r) cout << "| ";
    	else cout << "  ";
	}
	cout << "\n";
	if(flag == 1) {
		cout << "½»»»" << "\n";
	}
}

void Updata(int l,int r){
	for(int i=0;i<n;i++){
		int temp = vision[i][l];
		vision[i][l] = vision[i][r];
		vision[i][r] = temp;
	}
}
