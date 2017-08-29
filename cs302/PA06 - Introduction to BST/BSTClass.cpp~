// Program Information ////////////////////////////////////////////////////////
/**
 * @file BSTClass.h
 *
 * @brief Definition file for BSTClass
 * 
 * @details Specifies all member methods of the BSTClass
 *
 * @version 1.10
 *          Michael Leverington (27 February 2016)
 *          Updated for use with new assignment
 * 
 *          1.00 
 *          Michael Leverington (30 August 2015)
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

using namespace std;

template <typename DataType>
BSTNode<DataType>::BSTNode( const DataType &nodeData, BSTNode *leftPtr, BSTNode *rightPtr )
: dataItem( nodeData ), left( leftPtr ), right( rightPtr )
{
    //constructed in the initializer.
}

template <typename DataType>
BSTClass<DataType>::BSTClass()
: rootNode( NULL )
{
    //constructed in the initializer.
}

template <typename DataType>
BSTClass<DataType>::BSTClass( const BSTClass<DataType> &copied )
: rootNode( NULL )
{
    if( !copied.isEmpty( ) )
    {
        copyTree( this->rootNode, copied.rootNode );
    }
}

template <typename DataType>
BSTClass<DataType>::~BSTClass()
{
    clear();
}

template <typename DataType>
const BSTClass& BSTClass<DataType>::operator = (const BSTClass<DataType> &rhData )
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

template <typename DataType>
void BSTClass<DataType>::clear()
{
    BSTNode<DataType>* workingPtr = rootNode;
    clearHelper( workingPtr );
}
template <typename DataType>
void BSTClass<DataType>::insert( const DataType &newData )
{
    BSTNode<DataType>* workingPtr = rootPtr; 
    insertHelper( workingPtr, newData );
}
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
template <typename DataType>
bool BSTClass<DataType>::remove( const DataType &dataItem )
{
    BSTNode<DataType>* workingPtr = rootNode;
    if( isEmpty( ) )
    {
        return false;
    }
    else 
    {
        removeHelper( workingPtr, dataItem );        

        return true;
    }
}
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
template <typename DataType>
void BSTClass<DataType>::preOrderTraversal() const
{

    BSTNode<DataType>* workingPtr = rootNode;
 
    preOrderTraversalHelper( workingPtr ); 

}

template <typename DataType> 
void BSTClass<DataType>::inOrderTraversal() const
{

    BSTNode<DataType>* workingPtr = rootNode; 
    
    inOrderTraversalHelper( workingPtr );

}

template <typename DataType>  
void BSTClass<DataType>::postOrderTraversal() const
{

    BSTNode<DataType>* workingPtr = rootNode; 

    postOrderTraversal( workingPtr );
}
//recursion functions from here on 
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
template <typename DataType>
void BSTClass<DataType>::clearHelper( BSTNode<DataType> *workingPtr )
{
    clearHelper( workingPtr->left );
     
    clearHelper( workingPtr->right );
    
    delete workingPtr;
 
    workingPtr = NULL;

}
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
template <typename DataType>
bool BSTClass<DataType>::findHelper( BSTNode<DataType> *workingPtr, 
                                 DataType &searchDataItem ) const
{
    if( isEmpty() )
    {
        return false;
    }
    else if( searchDataItem == workingPtr->dataItem )
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

template <typename DataType>
bool BSTClass<DataType>::removeHelper( BSTNode<DataType> *&workingPtr, 
                                       const DataType &removeDataItem )
{
    //second nested-if, still need to implement the first if
    if( ( workingPtr->left == NULL ) && ( workingPtr->right == NULL ) )
    {
        removeDataItem = workingPtr->dataItem; 

        delete workingPtr;

        workingPtr = NULL;
    }
    else if( ( workingPtr->left || workingPtr->right ) == NULL )
    {
        if( workingPtr->left == NULL )
        {
            removeDataItem = workingPtr->dataItem; 
            
            workingPtr->dataItem = workingPtr->right->dataItem;
    
            delete workingPtr->right; 
         
        }
        else if( workingPtr->right == NULL )
        {
            removeDataItem = workingPtr->dataItem;

            workingPtr->dataItem = workingPtr->left->dataItem;
   
            delete workingPtr->left;

        }
    }
    else if( ( workingPtr->left != NULL ) && ( workingPtr->right != NULL ) )
    {
        
    }
}
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
          
#endif	// define BST_CLASS_CPP

