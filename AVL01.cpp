#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

class Node{

    public:
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        height = 1;
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

int height(Node * n){
    if (n==NULL) return 0;
    return n->height;
}

int getBalance(Node* n){
    if(n == NULL) return 0;
    return height(n->left)-height(n->right);
}

Node* leftRotate(Node* z) {
    Node* y = z->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = z;
    z->right = T2;

    // Update heights
    z->height = 1 + max(height(z->left), height(z->right));
    y->height = 1 + max(height(y->left), height(y->right));

    // Return new root
    return y;
}


// --------------------------------------
// Right Rotation (LL Case)
// --------------------------------------
Node* rightRotate(Node* z) {
    Node* y = z->left;
    Node* T3 = y->right;

    // Perform rotation
    y->right = z;
    z->left = T3;

    // Update heights
    z->height = 1 + max(height(z->left), height(z->right));
    y->height = 1 + max(height(y->left), height(y->right));

    // Return new root
    return y;
}

Node* AVL(Node* root , int key){

    if (!root) return new Node(key);

    if(key < root->data) root->left= AVL(root->left , key);
    else if (key > root->data) root->right= AVL(root->right , key);
    else return root;  // duplicate node


    // Upadating height
    root->height = 1+max(height(root->left) , height(root->right));

    // Balance Factor
    int bf = getBalance(root);


    //LL case
    if(bf> 1 && key < root->left->data) return rightRotate(root-);
    if(bf< -1 && key > root->right->data){
       root->right = rightRotate(root->right); 
       return leftRotate(root);  
    } 

    //RL Case
    if (bf<-1 && key < root->right->data){
        root->right = rightRotate(root->right);
    }

    return root;


};

int main(){



    cout << "Hello World" << endl;
}