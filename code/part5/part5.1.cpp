#include <iostream>
#include <time.h>
using namespace std;
const int N = 15;
int nums[N];
struct node {
    int _data;
    int quan;
    int ltreesize;
    node * lnext;
    node * rnext;
    node(int _data = 0,int quan = 0,int ltreesize = 0, node * lnext = nullptr,node * rnext = nullptr):
        _data(_data),
        quan(quan),
        ltreesize(ltreesize),
        lnext(lnext),
        rnext(rnext)
    {

    }

};
void BuildTree(node * root);
void Insert(node * root, int value);
void Delete(node * root, int value);
void Precedence(node * root);
void MiddleOrder(node * root);
void PostOrder(node * root);
int Find_Byvalue(node * root, int value);
int FindByindex(node * now , node * root, int index);

int main(){
    srand((int)time(0));  
    for (int i = 0; i < N; i++)
    {
        nums[i] = rand()%100;
    }
    node * root = new node();
    BuildTree(root);
    MiddleOrder(root);
    cout << "\n";
    int m;
    cout << "FInd ByValue: " ;
    scanf("%d",&m);
    cout << Find_Byvalue(root, m);
    cout << "\n";
    cout << "FInd ByIndex: " ;
    scanf("%d",&m);
    cout << FindByindex(root, root, m);
    cout << "\n";

    
}

void BuildTree(node * root){
    for(int i=0;i<N;i++){
        Insert(root, nums[i]);
    }
}

void Insert(node * root, int value){
    if(root->quan == 0) {
        root->_data = value;
        root->quan ++;
        return ;
    } 
    if(value > root->_data){
        
        if(root->rnext == nullptr) root->rnext = new node();
        Insert(root->rnext, value);
    }
    else if(value < root->_data){
        root->ltreesize ++;
        if(root->lnext == nullptr) root->lnext = new node();
        Insert(root->lnext, value);
    }
    else {
        root->quan ++;
    }
}

void Precedence(node * root){
    if(root!=NULL){
        for(int i=0;i<root->quan;i++)
            printf("%d ",root->_data);
		Precedence(root->lnext);
		Precedence(root->rnext);
	}
}

void MiddleOrder(node * root){
    if(root!=NULL){
		MiddleOrder(root->lnext);
        for(int i=0;i<root->quan;i++)
            printf("%d ",root->_data);
		MiddleOrder(root->rnext);
	}
}

void PostOrder(node * root){
    if(root!=NULL){
		PostOrder(root->lnext);      
		PostOrder(root->rnext);
		for(int i=0;i<root->quan;i++)
            printf("%d ",root->_data);
	}
}

int Find_Byvalue(node * root, int value){
    if(root == nullptr) return -1;
    if(root->_data == value) return root->ltreesize + 1;
    else if(value > root->_data) return Find_Byvalue(root->rnext, value) + root->ltreesize + root->quan;
    else return  Find_Byvalue(root->lnext,value);
}

int FindByindex(node * now , node * root, int index){
    int temp = Find_Byvalue(root, now->_data);
    if(index == temp) return now->_data;
    else if(index > temp){
        return FindByindex(now->rnext, root, index);
    }
    else return FindByindex(now->lnext, root, index);
}

void Delete(node * root, int value){
    if(root->_data == value){
        if(root->quan > 1) {
            root->quan --;
            return ;
        }
        if(root->lnext != nullptr && root->rnext == nullptr){
            root->_data = root->lnext->_data;
            if(root->lnext->quan > 1) root->lnext->quan--;
            else {
                delete root->lnext;
                root->lnext = nullptr;
            }
        }
        else if(root->lnext == nullptr && root->rnext != nullptr){
            root->_data = root->rnext->_data;
            if(root->rnext->quan > 1){
                root->rnext->quan--;
            }
            else{
                root->rnext = nullptr;
                root->rnext = nullptr;
            }
        }
        else if(root->lnext!=nullptr && root->rnext != nullptr){
            
        }
    }

}