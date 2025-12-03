#include<iostream>
#include<queue>

using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }


};

Node* BST( Node* root , int x){
    if (!root) {
        return new Node(x);
    }

    if(x < root->data){
        root->left = BST(root->left , x);
    }else if(x > root->data){
        root->right = BST(root->right , x);
    }else{
        return root;
    }

    return root;
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