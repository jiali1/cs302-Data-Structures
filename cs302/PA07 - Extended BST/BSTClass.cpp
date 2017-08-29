// Program Information ////////////////////////////////////////////////////////
/**
 * @file BSTClass.cpp
 *
 * @brief Implementation file for BSTClass
 * 
 * @details Specifies all member methods of the BSTClass
 *
 * @version 1.10
 *          Jia Li (10 March 2016)
 *          Updated with new conditions for remove
 * 
 *          1.00 
 *          Jia Li (5 March 2015)
 *          Original code
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef BST_CLASS_CPP
#define BST_CLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>
#include "BSTClass.h"
#include <cmath>

using namespace std;

// Class Implementation////////////////////////////////////////////////////////

/**
 * @brief Implementation of the BSTNode class
 *
 * @details Initialize all members in the class
 *          
 * @pre Assumes that the members are uninitialized
 *
 * @post members are initialized with values.
 *
 * @par Algorithm 
 *      Utilizes the initializer to assign values to members.
 * 
 * @exception None
 *
 * @param[in] nodeData
 *
 * @param[in] leftPtr
 *
 * @param[in] rightPtr
 *
 * @return None
 *
 * @note None
 */
template <typename DataType>
BSTNode<DataType>::BSTNode( const DataType &nodeData, BSTNode *leftPtr, BSTNode *rightPtr )
: dataItem( nodeData ), left( leftPtr ), right( rightPtr )
{
    //constructed in the initializer.
}

/**
 * @brief Implementation of the BSTClass
 *
 * @details Initialize all members of the class
 *          
 * @pre assumes that the member is uninitialized
 *
 * @post member is initialized
 *
 * @par Algorithm 
 *      Utilizes the initializer to assign values
 * 
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
template <typename DataType>
BSTClass<DataType>::BSTClass()
: rootNode( NULL )
{
    //constructed in the initializer.
}

/**
 * @brief Implementation of the copy constructor for BSTClass
 *
 * @details Copies all data from right hand obj to left hand
 *          
 * @pre Assumes that the current object is empty
 *
 * @post current object is assign with data from right hand.
 *
 * @par Algorithm 
 *      Calls the initializer and then call the copyTree 
 *      functions.
 * 
 * @exception None
 *
 * @param[in] copied 
 *
 * @return None
 *
 * @note None
 */
template <typename DataType>
BSTClass<DataType>::BSTClass( const BSTClass<DataType> &copied )
: rootNode( NULL )
{
    if( !copied.isEmpty( ) )
    {
        copyTree( this->rootNode, copied.rootNode );
    }
}

/**
 * @brief Implementation of the BSTClass destructor
 *
 * @details clears all data of the object.
 *          
 * @pre Assumes there are values in the object.
 *
 * @post data is cleared
 *
 * @par Algorithm 
 *      calls the clear function
 * 
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
template <typename DataType>
BSTClass<DataType>::~BSTClass()
{
    clear();
}

/**
 * @brief Implementation of the overload assignment operator for BSTClass
 *
 * @details Copies all data from right hand obj to left hand
 *          
 * @pre Assumes that the current object is empty
 *
 * @post current object is assign with data from right hand.
 *
 * @par Algorithm 
 *      Calls the initializer and then call the copyTree 
 *      functions.
 * 
 * @exception None
 *
 * @param[in] rhData 
 *
 * @return *this
 *
 * @note None
 */
template <typename DataType>
const BSTClass<DataType>& BSTClass<DataType>::operator = (const BSTClass<DataType> &rhData )
{
    if( this != &rhData )
    {
        clear( );
        copyTree( this->rootNode, rhData.rootNode );
        return *this;
    }
    else if( rhData.isEmpty() )
    {
        clear( );
        return *this;
    }
    return *this;
}

/**
 * @brief Implementation of the clear method in BSTClass
 *
 * @details clear all data in the object.
 *          
 * @pre Assumes that there are still data in the object.
 *
 * @post all data is cleared.
 *
 * @par Algorithm 
 *      calls the clearHelper function
 * 
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::clear()
{
    clearHelper( rootNode );
    rootNode = NULL;
}

/**
 * @brief Implementation of the insert function in BSTClass
 *
 * @details insert a value into the tree
 *          
 * @pre assumes the object is initialized
 *
 * @post data is added onto the tree
 *
 * @par Algorithm 
 *      calls the insertHelper function
 * 
 * @exception None
 *
 * @param[in] newData
 *
 * @return None
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::insert( const DataType &newData )
{
    insertHelper( rootNode, newData );
}

/**
 * @brief Implementation of find method for BSTClass
 *
 * @details Find an specific item in the tree
 *          
 * @pre Assumes that the item exist in the tree
 *
 * @post item is either found or not found
 *
 * @par Algorithm 
 *      calls the findHelper funtion
 * 
 * @exception None
 *
 * @param[in] searchDataItem
 *
 * @return True or False
 *
 * @note None
 */
template <typename DataType>
bool BSTClass<DataType>::find( DataType &searchDataItem ) const
{
    BSTNode<DataType>* workingPtr = rootNode;

    if( isEmpty( ) )
    {
        return false;
    }
    else
    {

        findHelper( workingPtr, searchDataItem );         

        return true;
    }
}

/**
 * @brief Implementation of the remove method in BSTClass
 *
 * @details remove an data from the tree
 *          
 * @pre Assumes that the data item exist in the tree
 *
 * @post the data item is remove
 *
 * @par Algorithm 
 *      Calls the removeHelper function
 * 
 * @exception None
 *
 * @param[in] dataItem
 *
 * @return True or False
 *
 * @note None
 */
template <typename DataType>
bool BSTClass<DataType>::remove( const DataType &dataItem )
{

    if( isEmpty( ) )
    {
        return false;
    }
    else 
    {
        removeHelper( rootNode, dataItem );        

        return true;
    }
}

/**
 * @brief Implementation of the isEmpty function for BSTClass
 *
 * @details Determines if the obj is empty or not.
 *          
 * @pre Assumes that object is initialized.
 *
 * @post Determines whether the obj is empty
 *
 * @par Algorithm 
 *      Determines whether the rootNode is NULL.
 * 
 * @exception None
 *
 * @param None
 *
 * @return True or False
 *
 * @note None
 */
template <typename DataType>
bool BSTClass<DataType>::isEmpty() const
{
    if( rootNode == NULL )
    {
        return true; 
    }
    else 
    {
        return false; 
    }
}

/**
 * @brief Implementation of the preOrderTraversal function for BSTClass
 *
 * @details Moves through the tree preOrderly
 *          
 * @pre Assumes the tree exist with values.
 *
 * @post The tree is traverse through a preOrderly fashion
 *
 * @par Algorithm 
 *      Calls the preOrderTraversalHelper function
 * 
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::preOrderTraversal() const
{

    if( !isEmpty( ) )
    {
        preOrderTraversalHelper( rootNode ); 
 
        cout << endl;
    }
    else
    {
        cout << "Tree is empty" << endl;
    }

}

/**
 * @brief Implementation of the inOrderTraversal function for BSTClass
 *
 * @details Moves through the tree inOrderly
 *          
 * @pre Assumes the tree exist with values.
 *
 * @post The tree is traverse through a inOrderly fashion
 *
 * @par Algorithm 
 *      Calls the inOrderTraversalHelper function
 * 
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
template <typename DataType> 
void BSTClass<DataType>::inOrderTraversal() const
{

    if( !isEmpty( ) )
    {
        inOrderTraversalHelper( rootNode ); 

        cout << endl;
    }
    else
    {
        cout << "Tree is empty" << endl;
    }

}

/**
 * @brief Implementation of the postOrderTraversal function for BSTClass
 *
 * @details Moves through the tree postOrderly
 *          
 * @pre Assumes the tree exist with values.
 *
 * @post The tree is traverse through a postOrderly fashion
 *
 * @par Algorithm 
 *      Calls the postOrderTraversalHelper function
 * 
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
template <typename DataType>  
void BSTClass<DataType>::postOrderTraversal() const
{
    if( !isEmpty( ) )
    {
        postOrderTraversalHelper( rootNode ); 

        cout << endl;
    }
    else
    {
        cout << "Tree is empty" << endl;
    }

}

/**
 * @brief Implementation of the copyTree method 
 *
 * @details Copies from the right hand obj to the left hand
 *          
 * @pre Assumes the right hand obj is not empty
 *
 * @post left hand obj is copied with data from the right hand
 *
 * @par Algorithm 
 *      Utilizes the preOrder algorithm to copy the data
 * 
 * @exception None
 *
 * @param[in] workingPtr, sourcePtr
 *
 * @return None
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::copyTree( BSTNode<DataType> *&workingPtr, 
                                   const BSTNode<DataType> *sourcePtr )
{

    if( sourcePtr != NULL )
    {
        workingPtr = new BSTNode<DataType>( sourcePtr->dataItem, 
                                         NULL, NULL );
        
        copyTree( workingPtr->left, sourcePtr->left ); 

        copyTree( workingPtr->right, sourcePtr->right );
 
    }
}

/**
 * @brief Implementation of the clearHelper function
 *
 * @details Clears all data using recursion
 *          
 * @pre Assumes that there are data in the tree
 *
 * @post All data is cleared
 *
 * @par Algorithm 
 *      use the postOrder algorithm to delete nodes
 * 
 * @exception None
 *
 * @param[in] workingPtr
 *
 * @return None
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::clearHelper( BSTNode<DataType> *workingPtr )
{
    if( workingPtr != NULL )
    { 
  
        clearHelper( workingPtr->left );
     
        clearHelper( workingPtr->right );
    
        delete workingPtr;

        workingPtr->left = NULL;

        workingPtr->right = NULL;

        workingPtr = NULL;
    }

}

/**
 * @brief Implementation of the insertHelper function
 *
 * @details Inserts an data onto the tree
 *          
 * @pre Assumes the tree obj is constructed
 *
 * @post Data item is added onto the tree
 *
 * @par Algorithm 
 *      Uses the search algorithm to add data item
 *      onto the tree
 * 
 * @exception None
 *
 * @param[in] workingPtr, newData
 *
 * @return None
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::insertHelper( BSTNode<DataType> *&workingPtr, 
                                              const DataType &newData )
{
    if( workingPtr == NULL )
    {
        workingPtr = new BSTNode<DataType>( newData, NULL, NULL ); 
    }
    else if( newData.compareTo( workingPtr->dataItem ) < 0 )
    {
        insertHelper( workingPtr->left, newData ); 
    }
    else if( newData.compareTo( workingPtr->dataItem ) >= 0 )
    {
        insertHelper( workingPtr->right, newData ); 
    }
}

/**
 * @brief Implementation of the findHelper method
 *
 * @details search for the desired item
 *          
 * @pre Assumes that the tree is not empty
 *
 * @post the desired item is either found or not
 *
 * @par Algorithm 
 *      Utilizes the search algorithm to find the item. 
 * 
 * @exception None
 *
 * @param[in] workingPtr, searchDataItem
 *
 * @return True or False
 *
 * @note None
 */
template <typename DataType>
bool BSTClass<DataType>::findHelper( BSTNode<DataType> *workingPtr, 
                                 DataType &searchDataItem ) const
{
    if( isEmpty() )
    {
        return false;
    }
    else if( searchDataItem.compareTo( workingPtr->dataItem ) == 0 )
    {
        return true;
    }
    else if( searchDataItem.compareTo( workingPtr->dataItem ) < 0 )
    {
        return findHelper( workingPtr->left, searchDataItem );
    }
    else if( searchDataItem.compareTo( workingPtr->dataItem ) > 0 )
    {
        return findHelper( workingPtr->right, searchDataItem ); 
    }
    return false; 
}

/**
 * @brief Implementation of the removeHelper function
 *
 * @details remove an item recursively through the tree.
 *          
 * @pre Assumes that the tree exists.
 *
 * @post The desired item is removed.
 *
 * @par Algorithm 
 *      Utilizes the search algorithm to remove the desired item.
 * 
 * @exception None
 *
 * @param[in] workingPtr, removeDataItem
 *
 * @return True or False
 *
 * @note None
 */
template <typename DataType>
bool BSTClass<DataType>::removeHelper( BSTNode<DataType> *&workingPtr, 
                                       const DataType &removeDataItem )
{
    BSTNode<DataType>* temp;

    if( removeDataItem.compareTo( workingPtr->dataItem ) == 0 )
    {
        if( ( workingPtr->left == NULL ) && ( workingPtr->right == NULL ) )
        {

            delete workingPtr;

            workingPtr = NULL;
        }
        else if( ( workingPtr->left == NULL ) || ( workingPtr->right == NULL ) )
        {
            if( workingPtr->left == NULL )
            {
                temp = workingPtr->right;
  
                delete workingPtr; 
       
                workingPtr = temp;
         
            }
            else if( workingPtr->right == NULL )
            {
                temp = workingPtr->left;
  
                delete workingPtr; 
       
                workingPtr = temp;

            }
        }
        else if( ( workingPtr->left != NULL ) && ( workingPtr->right != NULL ) )
        {
            temp = workingPtr;

            temp = temp->left;

            while( temp->right != NULL )
            {
                temp = temp->right; 
            }
            while( temp->left != NULL )
            {
                temp = temp->left;
            }
        
            workingPtr->dataItem = temp->dataItem;

            delete temp;
            
        }
        
        temp = temp->left = temp->right = NULL;
        
        workingPtr->left = NULL;

        return true;
    }
    else if( removeDataItem.compareTo( workingPtr->dataItem ) < 0 )
    {
        return removeHelper( workingPtr->left, removeDataItem );
    }
    else if( removeDataItem.compareTo( workingPtr->dataItem ) > 0 )
    {
        return removeHelper( workingPtr->right, removeDataItem );
    }
    return false; 
}

/**
 * @brief Implementation of the preOrderTraversalHelper function 
 *
 * @details Moves through the tree in preOrderly fashion
 *          
 * @pre Assumes that the tree exists.
 *
 * @post The tree is trasverse in an preOrderly fashion
 *
 * @par Algorithm 
 *      Utilize recursion to print the tree, then transverse
 *      the function left and right.
 * 
 * @exception None
 *
 * @param[in] workingPtr
 *
 * @return None
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::preOrderTraversalHelper( BSTNode<DataType> 
                                                     *workingPtr) const
{
    char buffer[MAX_DATA_LEN];
    DataType container;
    if( workingPtr != NULL )
    {
        container = workingPtr->dataItem; 
   
        container.toString( buffer ); 
        
        cout << buffer << endl;   

        preOrderTraversalHelper( workingPtr->left ); 
          
        preOrderTraversalHelper( workingPtr->right );
    }

}

/**
 * @brief Implementation of the inOrderTraversalHelper function 
 *
 * @details Moves through the tree in inOrderly fashion
 *          
 * @pre Assumes that the tree exists.
 *
 * @post The tree is trasverse in an inOrderly fashion
 *
 * @par Algorithm 
 *      Utilize recursion to transverse the tree to the left, then 
 *      print the value, and then transverse to the right until the 
 *      recursion is exhausted
 * 
 * @exception None
 *
 * @param[in] workingPtr
 *
 * @return None
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::inOrderTraversalHelper( BSTNode<DataType> 
                                                     *workingPtr) const
{
    char buffer[MAX_DATA_LEN];
    DataType container;
    if( workingPtr != NULL )
    {
        inOrderTraversalHelper( workingPtr->left ); 
          
        container = workingPtr->dataItem; 
   
        container.toString( buffer ); 
        
        cout << buffer << endl;   

        inOrderTraversalHelper( workingPtr->right );
    }

}

/**
 * @brief Implementation of the postOrderTraversalHelper function 
 *
 * @details Moves through the tree in postOrderly fashion
 *          
 * @pre Assumes that the tree exists.
 *
 * @post The tree is trasverse in an postOrderly fashion
 *
 * @par Algorithm 
 *      Utilize recursion to transverse the tree to the left, then 
 *      to the right until they are exhausted to print the data item.
 * 
 * @exception None
 *
 * @param[in] workingPtr
 *
 * @return None
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::postOrderTraversalHelper( BSTNode<DataType> 
                                                     *workingPtr) const
{
    char buffer[MAX_DATA_LEN];
    DataType container;
    if( workingPtr != NULL )
    {
        postOrderTraversalHelper( workingPtr->left ); 

        postOrderTraversalHelper( workingPtr->right );         
 
        container = workingPtr->dataItem; 
   
        container.toString( buffer ); 
        
        cout << buffer << endl;   

    }

}

template <typename DataType>
int BSTClass<DataType>::getHeight( ) const
{
    return getHeightHelper( rootNode ); 
}

template <typename DataType>
int BSTClass<DataType>::getHeightHelper( BSTNode<DataType> 
                                             *workingPtr ) const
{
    int leftHeight;
    int rightHeight; 

    if( workingPtr == NULL )
    {
        return 0; 
    }
    else 
    {
        leftHeight = getHeightHelper( workingPtr->left );
        rightHeight = getHeightHelper( workingPtr->right ); 
        if( leftHeight > rightHeight ) 
        {
            return leftHeight + 1; 
        } 
        else 
        {
            return rightHeight + 1; 
        }
    }
}
 
template <typename DataType>      
void BSTClass<DataType>::showBSTStructure( char id )
{
    int height = getHeight( ); 
    
    int index; 
   
    bool flag = true; 

    cout << "BST ID " << id << endl; 
   
    for( index = height; index > 0; index-- )
    {
        showBSTStructureHelper( rootNode, index, flag ); 
        cout << endl; 
        flag = true;
    }   
}

template <typename DataType>
void BSTClass<DataType>::showBSTStructureHelper( BSTNode<DataType> *workingPtr, int height, bool& flag ) 
{
    DataType container;

    char buffer[MAX_DATA_LEN];

    int spaces; 

    if( workingPtr != NULL )
    {
        if( height == getHeightHelper( workingPtr ) )
        {
            if( flag )
            {
                spaces = power( 2, height ) - 1;
                displayChars( spaces );
            }
            else 
            {
                spaces = power( 2, height + 1 ) - 3;
                displayChars( spaces ); 
            }
            container = workingPtr->dataItem;

            container.toString( buffer );
 
            cout << buffer;  
            
            flag = false;
            
        }
 
        showBSTStructureHelper( workingPtr->left, height, flag );
        
        showBSTStructureHelper( workingPtr->right, height, flag );
    }
     
}

template <typename DataType>
void BSTClass<DataType>::displayChars( int spaces )
{
    int index = 0; 

    for( index = 0; index < spaces; index++ )
    {
        cout << " ";
    }
}

template <typename DataType>
int BSTClass<DataType>::power( int base, int exponent )
{
    int index = 0; 
    int baseTwo = base;
    while( index < exponent - 1 )
    {
        base = base * baseTwo;
        index++;
    }
    return base;
}
#endif	// define BST_CLASS_CPP

