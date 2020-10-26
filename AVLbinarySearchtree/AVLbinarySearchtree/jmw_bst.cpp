#include <iostream>
#include <cstdlib>

using namespace std;

struct node {                   //builds the sturcture for a node
    int data;
    int height;
    node* left;
    node* right;
};


class binarySearchTree {
public:
    node* root;

    bool isEmpty() {                 //checks to see if the tree is empty by checking if there is a root
        if (root == NULL)
            return true;

        else {
            return false;
        }
    }

    void inorderTraversal() {       //starts the inordertraversal
        inoTrav(root);
        cout << endl;
    }

    void inoTrav(node* N) {          //actually does the inorder traversal
        if (N == NULL)              //ensures the tree is not empty
            return;

        inoTrav(N->left);           //outputs L N R
        cout << N->data << " ";
        inoTrav(N->right);
    }

    void preorderTraversal() {      //starts the preordertaversal
        preTrav(root);
        cout << endl;
    }

    void preTrav(node* N) {          //actually does preorder traversal
        if (N == NULL)              //ensures the tree is not empty
            return;

        cout << N->data << " ";     //outputs N L R
        preTrav(N->left);
        preTrav(N->right);
    }

    void postorderTraversal() {     //starts the postorder traversal
        postTrav(root);
        cout << endl;
    }
    void postTrav(node* N) {         //actually does postorder traversal
        if (N == NULL)              //ensures the tree is not empty
            return;

        postTrav(N->left);          //outputs L R N
        postTrav(N->right);
        cout << N->data << " ";
    }

    int treeHeight(node* N) {        //tells longest route from root to a leaf giving the height
        if (N == NULL)
            return 0;
        int leftHeight = treeHeight(N->left);       
        int rightHeight = treeHeight(N->right);
        if (leftHeight > rightHeight) {               //picks the longer route of the two.
            N->height = 1 + leftHeight;
            return (N->height);
        }
        else {
            N->height = 1 + rightHeight;
            return (1 + rightHeight);
        }
    }

    int treeNodeCount(node* N) {     //tells how many nodes are in the tree
        if (N == NULL)
            return 0;
        else {
            return (1 + treeNodeCount(N->left) + treeNodeCount(N->right));
        }
    }

    int treeLeavesCount(node* N) {   //tells how many leafs on the tree by checking which nodes have two empty pointers
        if (N == NULL)
            return 0;
        else if (N->left == NULL && N->right == NULL)
            return 1;
        else { 
            return (treeLeavesCount(N->left) + treeLeavesCount(N->right));
        }
    }

    int balFac(node* N) {                           //finds the balance factor
        if (N->left != NULL && N->right != NULL) {      //If balFac > 0: left scew. If balFac < 0: right scew. If balFac == 0, balanced. 
            return N->left->height - N->right->height;
        }
        else if (N->left && N->right == NULL) {         //Positive balance factor for left
            return N->left->height;
        }
        else if (N->left == NULL && N->right) {         //Negative balance factor for right
            return -N->right->height;
        }
        else if (N->left == NULL && N->right == NULL)   //if leaf balFac is 0.
            return 0;
    }

    void destroyTree(node* N) {      //deletes tree
        if (N == NULL)
            return;
        destroyTree(N->left);
        destroyTree(N->right);
        free(N);
        root = NULL;
    }

    void rightRotation(node*& N) {
        struct node* temp;
        struct node* temp2;
        temp = N;
        temp2 = N->left->right;

        N = N->left;
        N->right = temp;
        N->right->left = temp2;
    }

    void  leftRotation(node*& N) {
        struct node* temp;
        struct node* temp2;
        temp = N;
        temp2 = N->right->left;

        N = N->right;
        N->left = temp;
        N->left->right = temp2;
    }

    void leftRightRotation(node*& N) {
        leftRotation(N->left);
        rightRotation(N);
    }

    void rightLeftRotation(node*& N) {
        rightRotation(N->right);
        leftRotation(N);
    }

    bool search(int num, node* N) {  //returns true if the value exists in the tree and false if it does not
        bool found = false;
        if (N == NULL)
            return false;
        if (N->data == num)
            return true;
        else if (num < N->data)
            found = search(num, N->left);
        else
            found = search(num, N->right);
        return found;
    }

    void insert(int num, node* N) {          //inserts value into tree
        if (root == NULL) {               //makes root if root is NULL
            root = new node;
            root->data = num;
            root->right = NULL;
            root->left = NULL;
            N = root;
        }

        if (num < N->data) {              //if less goes left

            if (N->left != NULL) {
                insert(num, N->left);
            }
            else {
                N->left = new node;
                N->left->data = num;
                N->left->left = NULL;
                N->left->right = NULL;
                N = root;
            }
            
        }
        else if (num > N->data) {         //if greater goes right
            if (N->right != NULL) {
                insert(num, N->right);
            }
            else {
                N->right = new node;
                N->right->data = num;
                N->right->left = NULL;
                N->right->right = NULL;
                N = root;
            }
        }
        
  
        if (balFac(N) == 2 && balFac(N->left) == 1){
            rightRotation(N);
                }
        else if (balFac(N) == 2 && balFac(N->left) == -1) {
            leftRightRotation(N);
        }
        else if (balFac(N) == -2 && balFac(N->right) == -1) {
            leftRotation(N);
        }
        else if (balFac(N) == -2 && balFac(N->right) == 1) {
            rightLeftRotation(N);
        }
    }

    binarySearchTree(int arr[], int arrLeng) {       //constructor
        root = NULL;
        for (int i = 0; i < arrLeng; i++) {
            insert(arr[i], root);
        }

        cout << "BUILT!!" << endl;
    }

    binarySearchTree() {             //default constructor    
        root = NULL;
    }
};


int main() {

    const int arrLeng = 3;
 /*   int arr[arrLeng];
    cout << "Array Entered: ";
    for (int i = 0; i < arrLeng; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " , ";
    }
    cout << endl;
*/

    int arr[arrLeng];
    arr[2] = 61;
    arr[1] = 57;
    arr[0] = 12;
    binarySearchTree bsTree = binarySearchTree(arr, arrLeng);
    cout << "Pre rotation traversal" << endl;
    bsTree.preorderTraversal();
    
    bsTree.leftRotation(bsTree.root);
    
    cout << "Post rotation traversal " << endl;
    bsTree.preorderTraversal();

    bsTree.destroyTree(bsTree.root);
    
    /*   cout << "preorder traversal" << endl;
    bsTree.preorderTraversal();
    cout << "inorder traversal" << endl;
    bsTree.inorderTraversal();
    cout << "postorderTraversal" << endl;
    bsTree.postorderTraversal();
    cout << "insert 41 then inorder traversal" << endl;
    bsTree.insert(41, bsTree.root);
    bsTree.inorderTraversal();
    cout << "Search Function for 65" << endl;
    cout << "results: " << bsTree.search(65, bsTree.root) << endl;
    cout << "Search Function for 93" << endl;
    cout << "results: " << bsTree.search(93, bsTree.root) << endl;
    cout << "Tree height = " << bsTree.treeHeight(bsTree.root) << endl;
    cout << "Number of tree leaves = " << bsTree.treeLeavesCount(bsTree.root) << endl;
    cout << "Number of nodes = " << bsTree.treeNodeCount(bsTree.root) << endl;
    cout << "is empty test " << endl;
    cout << "results: " << bsTree.isEmpty() << endl;
    cout << "delete function" << endl;
    bsTree.destroyTree(bsTree.root);
    cout << "see if empty results: " << bsTree.isEmpty() << endl;
*/
    return 0;
}