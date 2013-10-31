//--------------------------------------------------------------------
//
//  Laboratory 9                                    BSTree.h
//
//  Class declarations for the linked implementation of the Binary
//  Search Tree ADT -- including the recursive helpers of the
//  public member functions
//
//--------------------------------------------------------------------

#ifndef BSTREE_H
#define BSTREE_H

#include <stdexcept>
#include <iostream>

using namespace std;

template < typename DataType, class KeyType >    // DataType : tree data item
class BSTree                                     // KeyType : key field
{
  public:

    // Constructor
    BSTree ();                         // Default constructor
    BSTree ( const BSTree<DataType,KeyType>& other );   // Copy constructor
    BSTree& operator= ( const BSTree<DataType,KeyType>& other );
						  // Overloaded assignment operator

    // Destructor
    ~BSTree ();
	


    // Binary search tree manipulation operations

//	BSTree& traverse();
//	void search(KeyType data, char& direction = 'l');

	char search(KeyType data);
	void insert ( const DataType& newDataItem );  // Insert data item
	//bool retrieve (KeyType searchKey, DataType& searchDataItem ) const;
    bool retrieve ( const KeyType& searchKey, DataType& searchDataItem );
                                                  // Retrieve data item
    bool remove ( const KeyType& deleteKey );            // Remove data item
    void writeKeys () const;                      // Output keys
    void clear ();                                // Clear tree

    // Binary search tree status operations
    bool isEmpty () const;                        // Tree is empty
    // !! isFull() has been retired. Not very useful in a linked structure.

    // Output the tree structure -- used in testing/debugging
    void showStructure () const;

    // In-lab operations
    int getHeight ();                       // Height of tree
    int getCount () const;			  // Number of nodes in tree
    void writeLessThan ( const KeyType& searchKey ); // Output keys < searchKey
    


  protected:

    class BSTreeNode                  // Inner class: facilitator for the BSTree class
    {
      public:
    
        // Constructor
        BSTreeNode ( const DataType &nodeDataItem, BSTreeNode *leftPtr, BSTreeNode *rightPtr );

        // Data members
        DataType dataItem;         // Binary search tree data item
        BSTreeNode *left,    // Pointer to the left child
                   *right;   // Pointer to the right child
    };

    // Recursive helpers for the public member functions -- insert
    // prototypes of these functions here.
    void showHelper      ( BSTreeNode *p, int level ) const;
    //BSTreeNode* findMin(BSTreeNode* node)const;
    void writeKeysHelper(BSTreeNode *node) const;
   	void helpClear(BSTreeNode* gone);	
    int heightHelper(BSTreeNode* heightNode);
	typename BSTree<DataType, KeyType>::BSTreeNode* assignHelper(BSTreeNode* copy);
	void writeLessHelper(BSTreeNode* pointer, KeyType searchkey); 
	//bool removeHelper(KeyType deleteKey, BSTreeNode* lostNode);
	//typename BSTree<DataType,KeyType>::BSTreeNode* findMin(BSTreeNode* node)  {
	
	// Data member
	BSTreeNode *cursor;
    BSTreeNode *root;   // Pointer to the root node
    int counter;   //helper member
};

#endif	// define BSTREE_H



