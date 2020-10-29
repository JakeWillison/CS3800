#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

ifstream inFile;
ofstream outFile;

struct node {                   //builds the sturcture for a node
    int data;
    int height;
    node* left;
    node* right;
};

class binarySearchTree {
public:
    node* root;
    int numOfRightRotations = 0;
    int numOfLeftRotations = 0;

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
        else if (N->left != NULL && N->right == NULL) {         //Positive balance factor for left
            return N->left->height;
        }
        else if (N->left == NULL && N->right != NULL) {         //Negative balance factor for right
            return -N->right->height;
        }
        else if (N->left == NULL && N->right == NULL)   //if leaf balFac is 0.
            return 0;
    }

    void balanceTree(node*& N) {                    //function balances the tree by checking the balance factor of each node in the tree
        if (N != NULL) {
            if (balFac(N) == 2) {                   //If the tree is leaning left
                if (balFac(N->left) == 1) {
                    rightRotation(N);
                }
                else if (balFac(N->left) == -1) {
                    leftRightRotation(N);
                }
            }
            else if (balFac(N) == -2) {             //if the tree is leaning right
                if (balFac(N->right) == -1) {
                    leftRotation(N);
                }
                else if (balFac(N->right) == 1) {
                    rightLeftRotation(N);
                }
            }
            
            treeHeight(root);                       //Reset the heightos nodes after a potential switch
            balanceTree(N->left);                   //Check the left nodes
            balanceTree(N->right);                  //check the right nodes
        }
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
        temp = N;                       //Sets up temp variables to store data for rotation
        temp2 = N->left->right;

        N = N->left;                    //resets N as the node to the left, N->right becomes N
        N->right = temp;                //lastly the data that was stored in temp2 gets placed in right->left.
        N->right->left = temp2;

        numOfRightRotations++;
    }

    void  leftRotation(node*& N) {
        struct node* temp;              //Sets up temp variables to store data for rotation
        struct node* temp2;
        temp = N;
        temp2 = N->right->left;

        N = N->right;                   //resets N as the node to the right, N->left becomes N
        N->left = temp;                 //lastly temp2 gets stored in N->left->right
        N->left->right = temp2;

        numOfLeftRotations++;
    }

    void leftRightRotation(node*& N) {     //Calls a left rotation then a right rotation
        leftRotation(N->left);
        rightRotation(N);
    }

    void rightLeftRotation(node*& N) {      //calls a right rotation then a left rotation.
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
  
        treeHeight(root);

        balanceTree(root);
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

    inFile.open("ints.txt");
    outFile.open("rotationsDataOut.txt" , fstream::app);

    int currNum;
    int num;
    int numOfN = 0;

    binarySearchTree bsTree = binarySearchTree();

    while (inFile >> currNum) {
        bsTree.insert(currNum, bsTree.root);
        numOfN++;
    }

    bsTree.preorderTraversal();

    outFile << "N = " << numOfN << ". Right Rotations = " << bsTree.numOfRightRotations << ". Left Rotations = " << bsTree.numOfLeftRotations << "." << endl;

    inFile.close();
    outFile.close();
    bsTree.destroyTree(bsTree.root);
    
    return 0;
}