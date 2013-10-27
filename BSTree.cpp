#include "BSTree.h"

template <typename DataType, class KeyType>
BSTree<DataType, KeyType>::BSTree ()  {                         // Default constructor
    root = NULL;
    counter = 0;
}

template <typename DataType, class KeyType>
BSTree<DataType, KeyType>::BSTree ( const BSTree<DataType,KeyType>& other )  {   // Copy constructor
    
}
    
template <typename DataType, class KeyType>
BSTree<DataType, KeyType>& BSTree<DataType, KeyType>::operator= ( const BSTree<DataType,KeyType>& other )  {

}

    // Destructor
template <typename DataType, class KeyType>
BSTree<DataType, KeyType>::~BSTree ()  {
   clear();
   root = 0;                 
}

    // Binary search tree manipulation operations
template <typename DataType, class KeyType>
void BSTree<DataType, KeyType>::insert ( const DataType& newDataItem )  {  // Insert data item
    if (isEmpty())  {
       BSTreeNode* temp = root;
       root = new BSTreeNode(newDataItem, NULL, NULL);
       counter++;
    }
    else  {
       //need to sort into correct node position within tree
       counter++;
    }
}

template <typename DataType, class KeyType>  //Retrieve data item
bool BSTree<DataType, KeyType>::retrieve ( const KeyType& searchKey, DataType& searchDataItem ) const  {

}

template <typename DataType, class KeyType>                                                  
bool BSTree<DataType, KeyType>::remove ( const KeyType& deleteKey )  {            // Remove data item
    
}

template <typename DataType, class KeyType>
void BSTree<DataType, KeyType>::writeKeys () const  {                     // Output keys

}

template <typename DataType, class KeyType>
void BSTree<DataType, KeyType>::clear ()  {                                // Clear tree
     if (root == NULL && counter == 0)  {
        cout << "List is already empty!" << endl;
     }
     else  {
        //helper functions to clear left and right nodes of tree?
     }
}

    // Binary search tree status operations
template <typename DataType, class KeyType>
bool BSTree<DataType, KeyType>::isEmpty () const  {                       // Tree is empty
    // !! isFull() has been retired. Not very useful in a linked structure.
    if (root == NULL)  {
       return true;
    }
    else  {
       return false;
    }
}

    // Output the tree structure -- used in testing/debugging
template < typename DataType, typename KeyType >
void BSTree<DataType,KeyType>:: showStructure () const

// Outputs the keys in a binary search tree. The tree is output
// rotated counterclockwise 90 degrees from its conventional
// orientation using a "reverse" inorder traversal. This operation is
// intended for testing and debugging purposes only.

{
    if ( root == 0 )
       cout << "Empty tree" << endl;
    else
    {
       cout << endl;
       showHelper(root,1);
       cout << endl;
    }
}

    // In-lab operations
template <typename DataType, class KeyType>
int BSTree<DataType, KeyType>::getHeight () const  {                      // Height of tree

}

template <typename DataType, class KeyType>
int BSTree<DataType, KeyType>::getCount () const  {			  // Number of nodes in tree
    return counter;
}

template <typename DataType, class KeyType>
void BSTree<DataType, KeyType>::writeLessThan ( const KeyType& searchKey ) const  { // Output keys < searchKey


}
    
        // Constructor
template <typename DataType, class KeyType>
BSTree<DataType, KeyType>::BSTreeNode::BSTreeNode( const DataType &nodeDataItem, BSTreeNode *leftPtr, BSTreeNode *rightPtr )  {
    dataItem = nodeDataItem;
    left = leftPtr;
    right = rightPtr;                 
}

    // Recursive helpers for the public member functions -- insert
    // prototypes of these functions here.
    
    
template <typename DataType, class KeyType>
void BSTree<DataType,KeyType>:: showHelper ( BSTreeNode *p, int level) const

// Recursive helper for showStructure. 
// Outputs the subtree whose root node is pointed to by p. 
// Parameter level is the level of this node within the tree.

{
     int j;   // Loop counter

     if ( p != 0 )
     {
        showHelper(p->right,level+1);         // Output right subtree
        for ( j = 0 ; j < level ; j++ )    // Tab over to level
            cout << "\t";
        cout << " " << p->dataItem.getKey();   // Output key
        if ( ( p->left != 0 ) &&           // Output "connector"
             ( p->right != 0 ) )
           cout << "<";
        else if ( p->right != 0 )
           cout << "/";
        else if ( p->left != 0 )
           cout << "\\";
        cout << endl;
        showHelper(p->left,level+1);          // Output left subtree
    }
}

