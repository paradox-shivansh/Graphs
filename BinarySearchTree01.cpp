#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data= data;
        this->left= NULL;
        this->right= NULL;
    }
};

// NORMAL TREES
Node* buildTree(){
    int x;
    cin>>x;

    if(x == -1) return NULL;

    Node* root = new Node(x);
    root->left= buildTree();
    root->right= buildTree();

    return root ;
}

// BST
Node* takeInput( Node* root , int x){

    if ( !root) return new Node(x);

    if( x< root->data){
        root->left = takeInput(root->left , x);
    }else if (x> root->data){
        root->right = takeInput(root->right , x);
    }else{
        return root;
    }

    return root;
}

void inorder(Node* root){
    if (!root ) return ; 
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

void levelOder(Node* root){

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        while(size--){
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl;
    }
}


// SEARCH

bool search(Node* root, int key) {
    if (!root) {
        cout << "KEY IS NOT PRESENT IN THE BST" << endl;
        return false;
    }

    if (key == root->data) {
        cout << "KEY IS PRESENT IN THE BST" << endl;
        return true;
    }
    else if (key < root->data) {
        return search(root->left, key);
    }
    else { // key > root->data
        return search(root->right, key);
    }
}



int main(){

    cout << "hello world " << endl;

    Node* root = NULL;
    cout << "Take input to create BST : " << endl;
    root = takeInput(root , 10);
    root = takeInput(root , 10);
    root = takeInput(root , 9);
    root = takeInput(root , 12);
    root = takeInput(root , 14);

    levelOder(root);
    cout << endl;
    
    search(root , 20);
    search(root , 12);
    search(root , 19);
    
}