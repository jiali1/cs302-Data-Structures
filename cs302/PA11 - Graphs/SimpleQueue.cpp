// Program Information ////////////////////////////////////////////////////////
/**
 * @file SimpleQueue.cpp
 *
 * @brief Implementation file for SimpleQueue class
 * 
 * @author Jia Li
 * 
 * @details Implements all member methods of the SimpleQueue class
 *
 * @version 1.00
 *          Michael Leverington (13 April 2016)
 *          Original Code
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_SIMPLEQUEUE_CPP
#define CLASS_SIMPLEQUEUE_CPP

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#include "SimpleList.cpp"
#include "SimpleQueue.h"

// Class implementation  //////////////////////////////////////////////////////

// constructors
template <class DataType>
SimpleQueue<DataType>::SimpleQueue()
: queueSize( 0 ), SimpleList<DataType>( INITIAL_CAPACITY )
{
    //Class members initialized using the initializer.
}

template <class DataType>
SimpleQueue<DataType>::SimpleQueue( const SimpleQueue<DataType> &copiedQueue )
: queueSize( copiedQueue.queueSize ), SimpleList<DataType>( copiedQueue ) 
{
    //Class members initialized using the initializer.
}

// destructor
template <class DataType>
SimpleQueue<DataType>::~SimpleQueue( )
{
    queueSize = 0;

    ~SimpleList<DataType>( ); 
}

// assignment
template <class DataType>
const SimpleQueue<DataType>& SimpleQueue<DataType>::operator = 
                                      ( const SimpleQueue<DataType> &rhQueue )
{
    if( this != &rhQueue )
    {
        queueSize = rhQueue.queueSize; 
 
        *this = rhQueue;
    }
    return *this;
}
// accessors

// reports empty queue
template <class DataType>
bool SimpleQueue<DataType>::isEmpty() const
{
    if( queueSize == 0 )
    {
        return true; 
    }
    else 
    {
        return false; 
    }
}
// modifiers

// enqueues data
template <class DataType>
void SimpleQueue<DataType>::enqueue( const DataType &enqueueData )
{
    addItem( enqueueData );
 
    queueSize++; 
}
// dequeues data
template <class DataType>
bool SimpleQueue<DataType>::dequeue( DataType &dequeueData)
{
    if( !isEmpty() )
    {
        dequeueData = (*this)[ 0 ]; 

        findData( dequeueData, true );

        queueSize--;

        return true;
    }
    return false; 
}
// allows access to front without removal
template <class DataType>
bool SimpleQueue<DataType>::peekFront( DataType &peekData )
{
    if( !isEmpty( ) )
    {
        peekData = (*this)[ 0 ];
 
        return true; 
    }
    return false;
}


// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef CLASS_SIMPLEQUEUE_CPP
