// Program Information ////////////////////////////////////////////////////////
/**
 * @file SimpleStack.cpp
 *
 * @brief Implementation file for SimpleStack class
 * 
 * @author Michael Leverington
 * 
 * @details Implements all member methods of the SimpleStack class
 *
 * @version 1.00
 *          Michael Leverington (13 April 2016)
 *          Original Code
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_SIMPLESTACK_CPP
#define CLASS_SIMPLESTACK_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "SimpleList.cpp"
#include "SimpleStack.h"
#include <iostream>
using namespace std;

// Class implementation  //////////////////////////////////////////////////////

// constructors

template <class DataType>
SimpleStack<DataType>::SimpleStack()
: SimpleList<DataType>( INITIAL_CAPACITY ), stackSize( 0 ) 
{
    //Class members initialized using the initializer.
}

template <class DataType>
SimpleStack<DataType>::SimpleStack( const SimpleStack<DataType> &copiedStack )
: stackSize( copiedStack.stackSize ), SimpleList<DataType>( copiedStack )
{
    //Class members initialized using the initializer. 
} 

// destructor
template <class DataType>
SimpleStack<DataType>::~SimpleStack( )
{
    stackSize = 0; 
    //SimpleList<DataType>::~SimpleList( ); 
}

// assignment
template <class DataType>
const SimpleStack<DataType>& SimpleStack<DataType>::operator = 
                                      ( const SimpleStack<DataType> &rhStack )
{
    if( this != &rhStack )
    {
        stackSize = rhStack.stackSize; 
        *this = rhStack; 
    }
    return *this; 
}

// accessors

// reports stack empty
template <class DataType>
bool SimpleStack<DataType>::isEmpty() const
{
    if( stackSize == 0 )
    {
        return true; 
    }
    else 
    {
        return false;
    }
}

// modifiers

// pushes item onto stack
template <class DataType>
void SimpleStack<DataType>::push( const DataType &newData )
{
    this->addItem( newData ); 
    stackSize++; 
}
// removes item from stack
template <class DataType>
bool SimpleStack<DataType>::pop( DataType &poppedData)
{
    if( !isEmpty( ) )
    {
        poppedData = (*this)[ stackSize - 1 ];
  
        this->findData( poppedData, true ); 

        stackSize--;

        return true;
    }
    return false;
}   
// allows access to top without removing
template <class DataType>
bool SimpleStack<DataType>::peekTop( DataType &peekData )
{
    if( !isEmpty( ) )
    {
        peekData = (*this)[ stackSize - 1 ];
        return true; 
    }
    else 
    {
        return false; 
    }
}


// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef CLASS_simpleStack_CPP
