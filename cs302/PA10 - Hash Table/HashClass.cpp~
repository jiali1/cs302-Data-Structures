// Program Information ////////////////////////////////////////////////////////
/**
 * @file HashClass.cpp
 *
 * @brief Implementation file for HashClass class
 * 
 * @details Implements the constructor method of the HashClass class
 *
 * @version 1.20 
 *          Jia Li (20 April 2016)
 *          Updated with all member functions
 *
 *          1.10 
 *          Michael Leverington (06 April 2016)
 *          Updated with probing
 *
 *          1.00 
 *          Michael Leverington (06 November 2015)
 *          Original code
 *
 * @Note Requires HashClass.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef HASH_CLASS_CPP
#define HASH_CLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "HashClass.h"

using namespace std;

// Class Implementation  //////////////////////////////////////////////////////

/**
 * @brief Implementation of the DataNode constructor
 *
 * @details Assigns all data members a default value
 *          
 * @pre Assumes that the data members are uninitialized.
 *
 * @post All data members are assigned with an default value. 
 *
 * @par Algorithm 
 *      Utilizes the initializer to initialize default values to its 
 *      data members
 * 
 * @exception None
 *
 * @param[in] None
 *
 * @return None
 *
 * @note None
 */
template<typename DataType>
DataNode<DataType>::DataNode
       (
        // no parameters
       )
     : usedState( UNUSED )
   {
    // no action here
   }

/**
 * @brief Implementation of the HashClass default constructor
 *
 * @details Assign all data members with an default value
 *          
 * @pre Assumes all data members are uninitialized.
 *
 * @post All data members are initialized with an default value.
 *
 * @par Algorithm 
 *      Utilizes the initializer to assign default value to all 
 *      data members.
 * 
 * @exception None
 *
 * @param[in] None
 *
 * @return None
 *
 * @note None
 */
template<typename DataType>
HashClass<DataType>::HashClass
       (
        // no parameters
       )
     : tableLength( DEFAULT_HASH_TABLE_LENGTH ), 
       maxProbeAttempts( DEFAULT_PROBE_ATTEMPT_LIMIT ),
       hashLetterCount( DEFAULT_HASH_LETTER_COUNT ),
       hashList( new DataNode<DataType>[ DEFAULT_HASH_TABLE_LENGTH ] )
   {
    // no action here
   }

/**
 * @brief Implementation of the HashClass copy constructor
 *
 * @details Copies from the passed-in object to this object.
 *          
 * @pre Assumes this object is uninitialized. 
 *
 * @post All data members of this object is assigned with value
 *       from the passed-in object.
 *
 * @par Algorithm 
 *      Utilizes the initializer to copy from the right hand object 
 *      to the left hand object. Then calls the copyList function with 
 *      Node pointer from the right hand object. 
 * 
 * @exception None.
 *
 * @param[in] copied
 *
 * @return None
 *
 * @note None
 */        
template<typename DataType>
HashClass<DataType>::HashClass
       ( 
        const HashClass<DataType> &copied 
       )
     : tableLength( copied.tableLength ), 
       maxProbeAttempts( copied.maxProbeAttempts ),
       hashLetterCount( copied.hashLetterCount ),
       hashList( new DataNode<DataType>[ copied.tableLength ] )
   {
    copyList( copied.hashList );
   }

/**
 * @brief Implmentation of the HashClass destructor 
 *
 * @details deletes its hashList
 *          
 * @pre Assumes that there is still value in the hashList
 *
 * @post The values from the hashList is cleared.
 *
 * @par Algorithm 
 *      Utilizes the delete operator to the array of hashList 
 *      Table. 
 * 
 * @exception None
 *
 * @param[in] None
 *
 * @return None
 *
 * @note None
 */
template<typename DataType>
HashClass<DataType>::~HashClass
       (
        // no parameters
       )
   {
    delete [] hashList;
   }

/**
 * @brief Implementation of the HashClass overload assignment operator.  
 *
 * @details  Assigns the right hand object to the left hand object.
 *          
 * @pre Assumes that the right hand object contains value. 
 *
 * @post The left hand object is assigned value from the right hand 
 *       object. 
 *
 * @par Algorithm 
 *      Utilizes the resize function to resize the current object to 
 *      the right hand object length. Then assign maxProbeAttempts and 
 *      hashLetterCount to the value from the right hand object. Then
 *      calls the copyList function.
 * 
 * @exception None
 *
 * @param[in] rhHashTable
 *
 * @return *this
 *
 * @note None
 */
template <typename DataType>
const HashClass<DataType>& HashClass<DataType>:: operator = 
                                              ( const HashClass &rhHashTable )
   {
    int dummyMaxProbes, dummyTotalProbes;

    if( this != &rhHashTable )
       {
        resizeList( rhHashTable.tableLength, CLEAR_LIST, 
                                           dummyMaxProbes, dummyTotalProbes );

        maxProbeAttempts = rhHashTable.maxProbeAttempts;
        
        hashLetterCount = rhHashTable.hashLetterCount;

        copyList( rhHashTable.hashList );
       }

    return *this;
   }

/**
 * @brief Implementation of the setTableLength function
 *
 * @details Set the tableLength with the new tableLength
 *          
 * @pre Assumes the newTableLength is different.
 *
 * @post The newTableLength is assigned.
 *
 * @par Algorithm 
 *      Calls the resizeList function. 
 * 
 * @exception None
 *
 * @param[in] newTableLength, clearListFlag, maxProbes, totalProbes
 *
 * @return True or False
 *
 * @note None
 */
template <typename DataType>
bool HashClass<DataType>::setTableLength
       ( 
        int newTableLength,
        bool clearListFlag,
        int &maxProbes,
        int &totalProbes
       )
   {
    return resizeList( newTableLength, clearListFlag, maxProbes, totalProbes );
   }

/**
 * @brief Implementation of the setHashLetterCount function
 *
 * @details  Sets an new hash letter count value
 *          
 * @pre Assumes that the new letter count value is different
 *
 * @post the new letter count value is assigned
 *
 * @par Algorithm 
 *      Uses the assignment operation to assign the 
 *      data member hashLetterCount with newHashLetterCount
 * 
 * @exception None
 *
 * @param[in] newHashLetterCount
 *
 * @return None
 *
 * @note None
 */
template <typename DataType>
void HashClass<DataType>::setHashLetterCount
       ( 
        int newHashLetterCount
       )
   {
    hashLetterCount = newHashLetterCount;
   }

/**
 * @brief Implementation of the setProbeAttempts function
 *
 * @details  Sets an new max probe attempts value
 *          
 * @pre Assumes that the new max probe attempts value is different
 *
 * @post the new max probe attempts is assigned
 *
 * @par Algorithm 
 *      Uses the assignment operation to assign the 
 *      data member maxProbeAttempts with newNumProbeAttempts
 * 
 * @exception None
 *
 * @param[in] newNumProbeAttempts
 *
 * @return None
 *
 * @note None
 */
template <typename DataType>
void HashClass<DataType>::setProbeAttempts
       ( 
        int newNumProbeAttempts
       )
   {
    maxProbeAttempts = newNumProbeAttempts;
   }

/**
 * @brief Implementation of the addItem function
 *
 * @details adds an item to the hashTable
 *          
 * @pre Assumes that there is still space in the table
 *
 * @post the item is added to the table
 *
 * @par Algorithm 
 *      Calls the addItemHelper function and return 
 *      success or failure.
 * 
 * @exception None
 *
 * @param[in] newData, probeAttempts
 *
 * @return True or False
 *
 * @note None
 */
template <typename DataType>
bool HashClass<DataType>::addItem
       ( 
        const DataType &newData,
        int &probeAttempts
       )
   {
    probeAttempts = addItemHelper( hashList, newData ); 

    if( probeAttempts == FAILED_PROBE_PROCESS )
    {
        return false; 
    }
    return true;
   }

/**
 * @brief Implementation of the findItem function 
 *
 * @details Finds an item in the hash table
 *          
 * @pre Assumes the item exist in the hash table
 *
 * @post The item is found or not found
 *
 * @par Algorithm 
 *      Uses an for loop to find USED nodes and compare
 *      with the value passed and see if it the same. If 
 *      it is the same, it returns the index of the item.
 * 
 * @exception None
 *
 * @param[in] dataItem, probeAttempts
 *
 * @return index of the data or FAILED_PROBE_PROCESS
 *
 * @note None
 */
template <typename DataType>
int HashClass<DataType>::findItem
       ( 
        const DataType &dataItem,
        int &probeAttempts
       ) const
   {
    // implement method
    int index = 0;
 
    if( isEmpty( ) )
    {
        return FAILED_PROBE_PROCESS;
    }
    for( index = 0; index < tableLength; index++ ) 
    {
        if( hashList[index].usedState == USED )
        {
            if( dataItem.compareTo( hashList[index].nodeData ) == 0  ) 
            {
                return index; 
            }
        }
    }
    return FAILED_PROBE_PROCESS;
   }

/**
 * @brief Implementation of the removeItem function 
 *
 * @details removes an item from the hashTable
 *          
 * @pre Assumes that the item exist in the hashTable
 *
 * @post The item is removed or failure to remove.
 *
 * @par Algorithm 
 *      Calls the findItem function, then based on the 
 *      index, remove the item and return true if it exist
 *      or return false if the findItem function fails.
 * 
 * @exception None
 *
 * @param[in] dataItem, probeAttempts
 *
 * @return True or False
 *
 * @note None
 */
template <typename DataType>
bool HashClass<DataType>::removeItem
       ( 
        const DataType &dataItem,
        int &probeAttempts
       )
   {
    int index = findItem( dataItem, probeAttempts );

    if( index == FAILED_PROBE_PROCESS )
    {
        return false; 
    }
    else 
    {
        hashList[index].usedState = UNUSED; 

        return true; 
    }
   }

/**
 * @brief Implementation of the isEmpty function
 *
 * @details check if all indexes are UNUSED
 *          
 * @pre Assumes the object is constructed
 *
 * @post The result of the determination is returned
 *       as an boolean. 
 *
 * @par Algorithm 
 *      Uses an for loop to check all indexes of an 
 *      hashTable. If one index is USED, then return false. 
 *      Otherwise, if all are UNUSED, return true. 
 * 
 * @exception None
 *
 * @param[in] None
 *
 * @return True or False
 *
 * @note None
 */
template<typename DataType>
bool HashClass<DataType>::isEmpty
       ( 
        // no parameters
       ) const
   {
    int index = 0; 

    for( index = 0; index < tableLength; index++ )
    {
        if( hashList[index].usedState == USED )
        {
            return false;
        }
    }
    return true; 
    
   }

/**
 * @brief Implementation of the clearList function
 *
 * @details Set all indexes to UNUSED state. 
 *          
 * @pre Assumes the hashList is not empty.
 *
 * @post All members are cleared.
 *
 * @par Algorithm 
 *      Utilizes an loop mechanism to set all indexes
 *      in the hashList to UNUSED state.
 * 
 * @exception None
 *
 * @param[in] None
 *
 * @return None
 *
 * @note None
 */
template<typename DataType>
void HashClass<DataType>::clearList
       (  
        // no parameters     
       )
   {
    int index = 0; 

    if( !isEmpty( ) )
    {
        for( index = 0; index < tableLength; index++ )
        {
            hashList[index].usedState = UNUSED; 
        }
    }
   }

/**
 * @brief Implementation of the showStructure function
 *
 * @details print the structure of the hashList
 *          
 * @pre Assumes that the object is initialized 
 *
 * @post the structure of the hashList is printed to 
 *       the screen. 
 *
 * @par Algorithm 
 *      Utilizes an for-loop to extract USED data items
 *      out and then print out its associated string to 
 *      the terminal
 * 
 * @exception The Object cannot be empty.
 *
 * @param[in] None
 *
 * @return None
 *
 * @note None
 */
template<typename DataType>
void HashClass<DataType>::showStructure
       (
        // no parameters
       ) const
   {
    int index = 0; 
    DataType workingData;
    char buffer[STD_STR_LEN];

    for( index = 0; index < tableLength; index++ )
    {
        cout << "Index " << index << ": ";

        if( hashList[index].usedState == USED )
        {
            workingData = hashList[index].nodeData;
 
            workingData.toString( buffer ); 

            cout << buffer;
        }
        else
        {
            cout << "UNUSED";
        }
        cout << endl;
    }
    cout << "- End of List -" << endl;
   }

/**
 * @brief Implementation of the hash function 
 *
 * @details gives an data an hash value.
 *          
 * @pre Assumes that the object is constructed. 
 *
 * @post The hash value is returned.
 *
 * @par Algorithm 
 *      Calls the DataType hash function and then
 *      returns the hash value. 
 * 
 * @exception None
 *
 * @param[in] dataItem, workingTableLength
 *
 * @return hashValue
 *
 * @note None
 */
template<typename DataType>
int HashClass<DataType>::hash
       (
        const DataType &dataItem,
        int workingTableLength
       ) const
   {
    DataType workingData = dataItem; 

    int hashValue = workingData.hash( hashLetterCount, workingTableLength ); 

    return hashValue; 
   }

/**
 * @brief Implementation of the addItemHelper function
 *
 * @details adds an item onto the hashList using quadratic probing.
 *          
 * @pre Assumes that the hashList is not full
 *
 * @post the Item is either added or not added to the hashList.
 *
 * @par Algorithm 
 *      Uses an loop mechanism and modular arithmatic together with 
 *      the hash funciton to add an item onto the hashList.
 * 
 * @exception None
 *
 * @param[in] destHashTable, newData
 *
 * @return probe or FAILED_PROBE_PROCESS 
 *
 * @note None
 */
template <typename DataType>
int HashClass<DataType>::addItemHelper
       ( 
        DataNode<DataType> *destHashTable,
        const DataType &newData
       )
   {
    int hashValue = hash( newData, tableLength ); 
    int index = hashValue; 
    int probe = 0; 
    
    for( probe = 0; probe < maxProbeAttempts; probe++ )
    {
        index = ( hashValue + toPower( probe, 2 ) ) % tableLength;

        if( destHashTable[index].usedState == UNUSED ) 
        {
            destHashTable[index].nodeData = newData; 

            destHashTable[index].usedState = USED; 

            return probe; 
        }
    }

    return FAILED_PROBE_PROCESS;
   }

/**
 * @brief Implementation of the resizeList function 
 *
 * @details resizes the hashList
 *          
 * @pre Assumes that the object is constructed
 *
 * @post the hashList is resized.
 *
 * @par Algorithm 
 *      Based on the clearFlag, it will cleared 
 *      the entire hashList with the delete operator
 *      and then allocate new dynamic memory if the 
 *      flag is on. It will return false if the user
 *      attempts to shrink while the flag is off. It 
 *      will use re-hashing to accomplish the need for
 *      an larger size while the flag is off. It will 
 *      return false if the hashList if full.
 * 
 * @exception None
 *
 * @param[in] newSize, clearFlag, maxProbes, totalProbes
 *
 * @return True or False
 *
 * @note None
 */
template<typename DataType>
bool HashClass<DataType>::resizeList
       (       
        int newSize,
        bool clearFlag,
        int &maxProbes,
        int &totalProbes
       )
   {
    DataNode<DataType>* newHashList; 
    int index = 0; 
    int oldTableLength = 0; 
    int probeValue; 

    if( clearFlag == true ) 
    {
        delete[] hashList; 

        hashList = NULL; 

        hashList = new DataNode<DataType>[newSize];
 
        tableLength = newSize; 

        maxProbes = 0;

        totalProbes = 0;

        clearList( ); 

        return true;
    }
    else 
    {
        if( newSize < tableLength ) 
        {
            return false; 
        }
        else if( newSize > tableLength ) 
        {
            newHashList = new DataNode<DataType>[tableLength]; 

            maxProbes = 0;

            for( index = 0; index < tableLength; index++ )
            {
                newHashList[index].usedState = hashList[index].usedState;
 
                newHashList[index].nodeData = hashList[index].nodeData; 
            }
            delete[] hashList; 

            hashList = NULL;

            oldTableLength = tableLength; 
 
            tableLength = newSize;
            
            hashList = new DataNode<DataType>[tableLength]; 

            totalProbes = 0;

            for( index = 0; index < oldTableLength; index++ )
            {
                if( newHashList[index].usedState == USED )
                {
                    probeValue = addItemHelper( hashList, 
                                              newHashList[index].nodeData );
                    if( probeValue == FAILED_PROBE_PROCESS )
                    {
                        return false; 
                    }
                    if( probeValue > maxProbes ) 
                    {
                        maxProbes = probeValue;
                    }
                    totalProbes += probeValue;
                }
                
            }
          
            delete[] newHashList;

            newHashList = NULL;
            
        }
        return true; 
    }
   }

/**
 * @brief Implementation of the copyList function 
 *
 * @details Copies from the right hand pointer to 
 *          the current array object. 
 *          
 * @pre Assumes that the right hand pointer
 *      contains data items.
 *
 * @post All data from the right hand DataNode pointer
 *       is copied to the left hand DataNode pointer.
 *
 * @par Algorithm 
 *      Utilizes an while-loop to extract all data from the 
 *      right hand array and then copied onto the current
 *      dynamic array object. 
 * 
 * @exception None
 *
 * @param[in] copiedList
 *
 * @return None
 *
 * @note None
 */
template<typename DataType>
void HashClass<DataType>::copyList 
       ( 
        const DataNode<DataType> *copiedList
       )
   {
    int index = 0;
    
    while( index < tableLength )
    {
        hashList[index].nodeData = copiedList[index].nodeData;

        hashList[index].usedState = copiedList[index].usedState; 

        index++;
    }

   }

/**
 * @brief Implementation of the toPower function
 *
 * @details Execute the math power function base to the exponent.
 *          
 * @pre Assumes that the exponent is not negative
 *
 * @post The result is returned for usage.
 *
 * @par Algorithm 
 *      Utilizes an while loop to print the result based on the 
 *      exponent that tells us how many times we should multiply 
 *      our base.
 * 
 * @exception None
 *
 * @param[in] base, exponent
 *
 * @return integer
 *
 * @note None
 */
template<typename DataType>
int HashClass<DataType>::toPower
     ( 
      int base, 
      int exponent 
     ) const
   {
    
    int index = 0; 
    int baseTwo = base;

    if( exponent == 0 )
    {
        return 1;
    }
    while( index < exponent - 1 )
    {
        base = base * baseTwo;

        index++;
    }

    return base;
   }

#endif	// define HASH_CLASS_CPP





