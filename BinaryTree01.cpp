#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;
// learning to build , traverse and printing of a binary tree through breath first search 

class Node{

    public:
        Node *left;
        Node *right;
        int data;

    
        Node(int data){
            this->data=data;
            this->left = NULL;
            this->right = NULL;
        }     
};

Node* buildTree(){
        int x;
        cin >> x;

        if(x == -1) return NULL; // base case 

        Node* root = new Node(x);  // making the root node
        root->left = buildTree();  // recursive call for right
        root->right = buildTree(); // recursive call for left

        return root;  // returns the entire tree 
    }



void preorder(Node* root){
    if(!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* root){
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void inorder(Node* root){
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void levelOrder(Node* root){
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();   // Number of nodes in the current level

        while (size--) {       // Process exactly 'size' nodes
            Node* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }


        // OR "Look at the while loop"
        // while (size > 0) {       // Process exactly 'size' nodes
        //     size = size-1;
        //     Node* temp = q.front();
        //     q.pop();

        //     cout << temp->data << " ";

        //     if (temp->left) q.push(temp->left);
        //     if (temp->right) q.push(temp->right);
        // }

        cout << endl;  // Move to next line after one level
    }
    
}

// Counting nodes
int countNode (Node* root){
    if (root == NULL) return 0;

    int left = countNode(root->left);
    int right = countNode(root->right);

    return left+right+1;

}

// Finding maximum height of tree
int heightTree (Node* root){
    if(root == NULL) return 0;

    int leftHeight  = heightTree(root->left); 
    int rightHeight  = heightTree(root->right);
    
    return 1+ max(leftHeight ,rightHeight);
    // return 1 + max(height(root->left), height(root->right));   we can optimize the code
}


// Counting leaf nodes 
int countLeafNode (Node* root) {
    if (root == NULL) return 0;

    // If node is leaf
    if (root->left == NULL && root->right == NULL)
        return 1;

    int left = countLeafNode(root->left);
    int right = countLeafNode(root->right);

    return left + right;
}


// Counting nodes of degree one 
int countDegreeOneNode(Node* root) {
    if (root == NULL) return 0;

    int left = countDegreeOneNode(root->left);
    int right = countDegreeOneNode(root->right);

    // Count if EXACTLY one child exists
    if ( (root->left == NULL && root->right != NULL) ||
         (root->left != NULL && root->right == NULL) )
        return left + right + 1;

    return left + right;
}

// Counting internal nodes 
int countInternalNodes(Node* root){
    if (root == NULL) return 0;

    int leftInternal = countInternalNodes(root->left);
    int rightInternal = countInternalNodes(root->right);

    // Internal node = has at least 1 child (not a leaf)
    if (root->left != NULL || root->right != NULL)
        return leftInternal + rightInternal + 1;

    return leftInternal + rightInternal;
}


 
int main(){

    cout << "hello world" << endl;


    cout << "Enter tree values (-1 for NULL): ";
    
    Node* root = buildTree();   // Build the tree
    
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    
    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    cout << "Level Order: " << endl;
    levelOrder(root);
    

    cout << "Total Nodes: "  << countNode(root) << endl;


    cout << "Total Height: "  << heightTree(root) << endl;


    cout << "Total Leaf Nodes: "  << countLeafNode(root) << endl;
   
    cout << "Total Degree One Nodes: "  << countDegreeOneNode(root) << endl;
   
    cout << "Total Internal Nodes: "  << countInternalNodes(root) << endl;




    
}

// 1 2 4 8 -1 -1 9 -1 -1 5 -1 10 -1 -1 3 6 -1 11 -1 -1 7 12 -1 -1 13 -1 -1