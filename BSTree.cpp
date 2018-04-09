#include "BSTree.h"
#include "Node.h"
// Constructor
BSTree::BSTree() {
    root = nullptr;
}

// Destructor
BSTree::~BSTree() {
    if (root !=nullptr)
        freeNode(root);
}

// Free the node
void BSTree::freeNode(Node* leaf)
{
    if ( this->Root() == leaf)
    {
        
    }
    else if ( leaf != nullptr )
   
        {
        freeNode(leaf->Left());
        freeNode(leaf->Right());
        delete leaf;
        }
    
}

// Add a node
void BSTree::addNode(Node* a_set)
{
    // No elements. Add the root
    if ( this->Root() != nullptr )
    {
        addNode(this->Root(), a_set);
    }
    else
    {
        this->setRoot(a_set);
    }
}

// Add a node (private)
void BSTree::addNode(Node* leaf, Node* a_set)
{
    
    if ( leaf->Key() >= a_set->Key() )
    {
        if ( leaf->Left() != nullptr )
            addNode(leaf->Left(), a_set);
        else 
        {
            leaf->setLeft(a_set);
            a_set->setParent(leaf);
        }
    }
    else if ( leaf->Key() < a_set->Key() )
    {
        if ( leaf->Right() != nullptr )
            addNode(leaf->Right(), a_set);
        else
        {
            leaf->setRight(a_set);
            a_set->setParent(leaf);
        }
    }
}

// Find a node
Node* BSTree::findNode(double key, Node* node)
{
    Node* hold;
    if(node->Key() > key)
    {
        if(node->Left() != nullptr)
            findNode(key, node->Left());
        else
            cout << "node not found\n";
    }
    else if(key > node->Key())
    {
        if(node->Right() != nullptr)
            findNode(key, node->Right());
        else
            cout << "node not found\n";
    }
    else if(node == nullptr)
    {
        cout << key << " node was not found" << endl;
        hold = node;
    }
    else {
        cout << "the desired item was found" << endl;
        hold = node;
    }
    
    return hold;
}

// Print the BSTree
void BSTree::printPreorder(Node* node)
{
    
}
void BSTree::printInorder(Node* node)
{

    
}

void BSTree::printPostorder(Node* node)
{
    if ( node != nullptr)
    {
        
            }
}

// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
Node* BSTree::min(Node* node)
{
    Node* tempNode = node;
    if ( node == nullptr )
        tempNode = nullptr;
    else if ( node->Left() )
    {
        tempNode = min(node->Left());
    }
    else
        tempNode = node;
    
    return tempNode;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
Node* BSTree::max(Node* node)
{
    Node * tempNode = node;
    if ( node == nullptr )
        tempNode = nullptr;
    else if ( node->Right() )
        tempNode = max(node->Right());
    else
        tempNode = node;
    
    return tempNode;
}

// Find successor to a node
// Find the node, get the node with max value
// for the right sub-BSTree to get the successor
Node* BSTree::successor(double key, Node *node)
{
    

    Node *successor = nullptr;
    Node *current  = root;
    if(root == nullptr)
        return NULL;
    
    while(current->Key() != key){
        /* If node value is greater than the node which are looking for, then go to left sub tree
         Also when we move left, update the successor pointer to keep track of lst left turn */
        
        if(current->Key() >key){
            successor = current;
            current= current->Left();
        }
        /* Else take right turn and no need to update successor pointer */
        else
            current = current->Right();
    }
    /*Once we reached at the node for which inorder successor is to be found, check if it has right sub tree, if yes then find the minimum in that right sub tree and return that node
     
     Else last left turn taken node is already stored in successor pointer and will be returned*/
    if(current && current->Right()){
        successor = min(current->Right());
    }
    
    return successor;
}

// Find predecessor to a node
// Find the node, get the node with max value
// for the left sub-BSTree to get the predecessor
Node* BSTree::predecessor(double key, Node *node)
{
    
    Node* current = findNode(key, node);

    if (current == nullptr)
        { return nullptr; }
    
    if (current->Left() !=nullptr)
    {
        return max(current->Left());
    } else
    
    {
        Node *tempParent = current->Parent();
        while (tempParent !=nullptr) {
            if (current == tempParent->Right() ){
                break;
            }
            current = tempParent;
            tempParent = current->Parent();
        }
        return tempParent;
    }
}


void BSTree::deleteNode(double key)
{
    if (deleteNode(Root(), key) == nullptr)
        setRoot(nullptr);
}

//deleteNode (Private)
Node* BSTree::deleteNode(Node* root, double key)
{
   
    /* Given a binary search tree and a key, this function deletes the key
     and returns the new root */

    
        if(root == nullptr) return root;
        else if(key < root->Key())
            root->setLeft( deleteNode(root->Left(),key));
        else if(key > root->Key())
            root->setRight( deleteNode(root->Right(), key) );
        else {
            // Case 1: No Child
            if(root->Left() == nullptr && root->Right() == nullptr){
                delete root;
                root = nullptr;
                // Case 2: one child
            } else if(root->Left() == nullptr){
                Node *temp = root;
                root = root->Right();
                delete temp;
            } else if(root->Right() == nullptr){
                Node *temp = root;
                root = root->Left();
                delete temp;
            } else{
                Node *temp = min(root->Right());
                root->setKey(temp->Key() );
                root->setRight(  deleteNode(root->Right(), temp->Key() ) );
            }
        }
        return root;
    
}
