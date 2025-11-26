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
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void inOrder(Node* root){
    if (!root) return;

    inOrder(root->right);
    cout << root->data << " ";
    inOrder(root->left);
}

Node* trees(){

    int x;
    cin >> x;

    Node* root = new Node(x);
    root->left = trees();
    root->right = trees();

    return root;
}

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        while(size--){
            Node* temp =  q.front();
            q.pop();

            cout << temp->data << " ";

            if (root->left) q.push(root->left);
            if (root->right) q.push(root->right);
        }

        cout << endl;
    }
}


void AVL(){

};

int main(){



    cout << "Hello World" << endl;
}