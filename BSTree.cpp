#include "BSTree.h"

template <typename DataType, class KeyType>
BSTree<DataType, KeyType>::BSTree ()  {                         // Default constructor
    root = NULL;
    counter = 0;
	cursor = NULL;
}


template <typename DataType, class KeyType>
BSTree<DataType, KeyType>::BSTree ( const BSTree<DataType,KeyType>& other )  {   // Copy constructor
	*this = other; 
}

template <typename DataType, class KeyType>
BSTree<DataType, KeyType>& BSTree<DataType, KeyType>::operator= ( const BSTree<DataType,KeyType>& other )  {
	if (this != other)  {
		clear();
		root = assignHelper(root);
	}     
	return *this;
}

template <typename DataType, class KeyType>
typename BSTree<DataType,KeyType>::BSTreeNode* BSTree<DataType, KeyType>::assignHelper(BSTreeNode* copy)  {
	BSTreeNode* pointer;
	if (copy != NULL)  {
		pointer = new BSTreeNode(copy.dataItem, copy->left, copy->right);
	}
	else  {
		pointer = NULL;
	}
	return pointer;
}

    // Destructor
template <typename DataType, class KeyType>
BSTree<DataType, KeyType>::~BSTree ()  {
   clear();
   root = NULL;   
   counter = 0;              
}

	//searches the tree
template <typename DataType, class KeyType>
char BSTree<DataType, KeyType>::search(KeyType data){
	char direction;
	if(data < cursor->dataItem.getKey() && cursor->left != NULL){
		cursor = cursor->left;
		direction = search(data);
	}
	else if(data > cursor->dataItem.getKey() && cursor->right !=NULL){
		cursor = cursor->right;
		direction = search(data);
	}
	else{
		if(data == cursor->dataItem.getKey())
			direction = 'n';
		else if(data < cursor->dataItem.getKey())
			direction = 'l';
		else if(data > cursor->dataItem.getKey())
			direction = 'r';
	}
	return direction;
}

    // Binary search tree manipulation operations
template <typename DataType, class KeyType>
void BSTree<DataType, KeyType>::insert ( const DataType& newDataItem )  {  // Insert data item
    if (isEmpty())  {
       root = new BSTreeNode(newDataItem, NULL, NULL);
       counter++;
    }
    else  {
       //need to sort into correct node position within tree
	   cursor = root;
	   char direction = search( newDataItem.getKey());
	   if(direction == 'l')
			cursor->left = new BSTreeNode(newDataItem, NULL, NULL);
	   else if(direction == 'r')
			cursor->right = new BSTreeNode(newDataItem, NULL, NULL);
	   else  
			cout << "Cannot insert duplicates of the same item!\n\n";
       counter++;
    }
	cursor = root;
}

template <typename DataType, class KeyType>  //Retrieve data item
bool BSTree<DataType, KeyType>::retrieve ( const KeyType& searchKey, DataType& searchDataItem )   {
	cursor = root;
	char direction = search(searchKey);
    if (direction == 'n')  {
		searchDataItem = cursor->dataItem;
		return true;
	}
	else  {
		return false;
	}
}

//---------------------------------------------------------
template <typename DataType, class KeyType>                                                  
bool BSTree<DataType, KeyType>::remove ( const KeyType& deleteKey)  {            // Remove data item
    if (isEmpty())  {
       return false;
       cout << "Tree is empty!  Cannot remove." << endl;
    } 
    /*else  {
       return removeHelper(deleteKey, root);
    }*/
}

/*template <typename DataType, class KeyType>
bool BSTree<DataType, KeyType>::removeHelper(KeyType deleteKey, BSTreeNode* lostNode)  { 
     if (lostNode == NULL)  {
        return;
     }
     if (deleteKey < lostNode->dataItem.getKey())  {
        removeHelper(deleteKey, lostNode->left);     
        return true;         
     }
     else if(lostNode->dataItem.getKey() < deleteKey)  {
        removeHelper(deleteKey, lostNode->right);  
        return true;   
     }
     else if (lostNode->left != NULL && lostNode->right != NULL)  {
          lostNode->dataItem = findMin(lostNode->right)->dataItem.getKey();
          removeHelper(lostNode->dataItem, lostNode->right);   
          return true;  
     }
     else  {
          BSTreeNode *oldNode = lostNode;
          lostNode = (lostNode->left != NULL) ? lostNode->left : lostNode->right;
          delete oldNode;     
          return true; 
     }
}*/

/*template <typename DataType, class KeyType>
typename BSTree<DataType,KeyType>::BSTreeNode* BSTree<DataType, KeyType>::findMin(BSTreeNode* node)  {
         if (node == NULL)  {
            return NULL;        
         }
         if (node->left == NULL)  {
            return node;
         }
         return findMin(node->left);
}*/

template <typename DataType, class KeyType>
void BSTree<DataType, KeyType>::writeKeys () const  {                     // Output keys
     if (isEmpty())  {
        cout << "Empty tree!" << endl;                
     }
     else  {
        writeKeysHelper(root);
     }
}

template <typename DataType, class KeyType>
void BSTree<DataType, KeyType>::writeKeysHelper(BSTreeNode *node) const  {
     if (node != NULL)  {    
        writeKeysHelper(node->left);
        cout << node->dataItem.getKey() << endl;
        writeKeysHelper(node->right);
     }
}

template <typename DataType, class KeyType>
void BSTree<DataType, KeyType>::clear ()  {                                // Clear tree
     if (root == NULL && counter == 0)  {
        cout << "Tree is already empty!" << endl;
     }
     else  {
        helpClear(root);
        root = NULL;
        counter = 0;
     }
}

template <typename DataType, class KeyType>
void BSTree<DataType, KeyType>::helpClear(BSTreeNode* gone)  {
     if (gone != NULL)  {
        helpClear(gone->left);
        helpClear(gone->right);
        delete gone;
     }
     gone = NULL;
     counter = 0;
}


    // Binary search tree status operations
template <typename DataType, class KeyType>
bool BSTree<DataType, KeyType>::isEmpty () const  {                       // Tree is empty
    // !! isFull() has been retired. Not very useful in a linked structure.
    if (root == NULL && counter == 0)  {
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
int BSTree<DataType, KeyType>::getHeight ()  {                      // Height of tree
    int height;
    if (isEmpty())  {
       height = 0;
    }
    else  {
       height = heightHelper(root);
    }
    return height;
}

template <typename DataType, class KeyType>
int BSTree<DataType, KeyType>::heightHelper(BSTreeNode* heightNode)  {
    if (heightNode != NULL)  {
        return (max(heightHelper(heightNode->left), heightHelper(heightNode->right))+1);                    
    }
	else  {
		return 0;
	}
}

template <typename DataType, class KeyType>
int BSTree<DataType, KeyType>::getCount () const  {			  // Number of nodes in tree
    return counter;
}

//---------------------------------------------------------------
template <typename DataType, class KeyType>
void BSTree<DataType, KeyType>::writeLessThan ( const KeyType& searchKey )   { // Output keys < searchKey
     if (isEmpty())  {
        cout << "Tree is empty!" << endl;                
     }
     else  {
           writeLessHelper(root, searchKey);
     }
}

//--------------------------------------------------------------------
template <typename DataType, class KeyType>
void BSTree<DataType, KeyType>::writeLessHelper(BSTreeNode* pointer, KeyType searchKey)  {
     if (pointer == NULL)  {
         return;
     }
     else  {if (pointer->dataItem.getKey() >= searchKey)  {
             writeLessHelper(pointer->left, searchKey);
         }
         else  {
             pointer = pointer->left;
             cout << pointer->dataItem.getKey() << endl;
             writeLessHelper(pointer->right, searchKey);
         }   
     }
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

