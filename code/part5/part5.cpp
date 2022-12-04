#include <iostream>
#include <time.h>
#include <queue>
using namespace std;
const int N = 100, n = 15;
int k = 0;
int nums[N];
struct node{
	int value;
	node * l;
	node * r;
	node(int value=' ',node * l = NULL,node * r=NULL):value(value),l(l),r(r) {}
};
queue<node*> q;
void buildtree(int &t){
    int m = 1;
    while(!q.empty()){ 
        q.front()->value = nums[t];
        //cout << q.front()->value << "\n";
        t = t + 1;
        if(m < n){
            q.front()->l = new node();
            q.front()->r = new node();
            q.push(q.front()->l);
            q.push(q.front()->r);
            m = m + 2;
        }
        q.pop();
    }
}
void Precedence(node * root){
    if(root!=NULL){
        printf("%d ",root->value);
		Precedence(root->l);
		Precedence(root->r);
	}
}

void MiddleOrder(node * root){
    if(root!=NULL){
		MiddleOrder(root->l);
        printf("%d ",root->value);
		MiddleOrder(root->r);
	}
}

void PostOrder(node * root){
    if(root!=NULL){
		PostOrder(root->l);      
		PostOrder(root->r);
		printf("%d ",root->value);
	}
}

int main(){
	//srand((int)time(0));  
    for (int i = 0; i < n; i++)
    {
        nums[i] = i + 1;
        cout << nums[i] << " ";
    }
    cout << "\n";
    
    node * root = new node();
    int t = 0;
    q.push(root);
	/* 根据层序遍历建树*/
    buildtree(t);
    /* 先序遍历 */
    Precedence(root);
    cout << "\n";
    /* 中序遍历 */
    MiddleOrder(root);
    cout << "\n";
    /* 后序遍历 */
    PostOrder(root);
    cout << "\n";
	return 0;
} 