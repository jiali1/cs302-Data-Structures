// Program Information ////////////////////////////////////////////////////////
/**
 * @file PA08.cpp
 *
 * @brief Driver program to implement the recursive backtracking operation
 * 
 * @details None
 *
 * @version 1.10
 *          Michael Leverington (11 March 2016)
 *          Updated for use with recursive backtracking
 * 
 *          1.00 
 *          Michael Leverington (07 September 2015)
 *          Original code
 *
 * @Note Requires SimpleVector.cpp, SimpleTimer.h, ClassType.h, RoomType.h
 *                iostream, cstring
 */

// Precompiler directives /////////////////////////////////////////////////////

   // none

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "SimpleTimer.h"
#include "ClassType.h"
#include "RoomType.h"
#include "SimpleVector.cpp"

using namespace std;

// Global constant definitioans  //////////////////////////////////////////////

enum FILE_DATA_CODES { STRING_CAPTURED, START_CLASSROOMS, END_CLASSROOMS, 
                                    START_CLASS_REQUESTS, END_CLASS_REQUESTS };
const int MAX_STR_LEN = 100;
const int STD_STR_LEN = 50;
const int MAX_NUM_ROOMS = 25;

const bool SHOW_INPUT = false;
const bool SHOW_TIMER = false;
const bool VERBOSE = true;

const char ENDLINE_CHAR = '\n';
const char CARRIAGE_RETURN_CHAR = '\r';
const char NULL_CHAR = '\0';
const char SPACE = ' ';
const char COMMA = ',';
const char SEMI_COLON = ';';

// Free function prototypes  //////////////////////////////////////////////////

int getALine( istream &consoleIn, char *inString, 
                                        char delimiterChar = SEMI_COLON );

bool getANumber( istream &consoleIn, int &number );

void displayList( const SimpleVector<RoomType> &roomList, 
                                   const SimpleVector<ClassType> &classList );

bool fitClassRooms( SimpleVector<RoomType> &roomList,
                          SimpleVector<ClassType> &classList, 
                                           int roomLevel, bool showAttempts );

bool classListAvailable( SimpleVector<ClassType> &classList );

void printSpaces( int numSpaces );

// Main function implementation  //////////////////////////////////////////////

int main()
   {
    // initialize main
    SimpleVector<RoomType> RoomTypeList( MAX_NUM_ROOMS );
    SimpleVector<ClassType> ClassTypeList( MAX_NUM_ROOMS );
    SimpleTimer timer;
    RoomType roomTypeData;
    ClassType classTypeData;
    char dummy[ MAX_STR_LEN ];
    char name[ STD_STR_LEN ];
    int roomNum, roomCap, classSize;
    int firstRoom = 0;

    // load classrooms

       // capture start line for room data
       getALine( cin, dummy );

       // loop through room data - capture name data
       while( getALine( cin, name, COMMA ) != END_CLASSROOMS )
          {
           // input room number
           getANumber( cin, roomNum );

           // input room capacity
           getANumber( cin, roomCap );

           if( SHOW_INPUT )
              {
               cout << "Room Data: " << name << ", " << roomNum 
                    << ", " << roomCap << endl;
              }
           // set room data
           roomTypeData.setRoomData( name, roomNum, roomCap );

           // add room data to vector
           RoomTypeList.setAtIndex( RoomTypeList.getSize(), roomTypeData );
           RoomTypeList.incrementSize();
          }
       // end loop

    // load class requests

       // capture start line for class data
       getALine( cin, dummy );

       // loop through class request data
       while( getALine( cin, name, COMMA ) != END_CLASS_REQUESTS )
          {
           // get class size request
           getANumber( cin, classSize );

           if( SHOW_INPUT )
              {
               cout << "Class Data: " << name << ", " << classSize << endl;
              }

           // set class request data
           classTypeData.setClassData( name, classSize );

           // add room to vector
           ClassTypeList.setAtIndex( ClassTypeList.getSize(), classTypeData );
           ClassTypeList.incrementSize();
          }           
       // end loop

    // check for equal numbers of data sets
    if( RoomTypeList.getSize() == ClassTypeList.getSize() )
       {
        // start timer
        timer.start();

        // search for solution - check for success
        if( fitClassRooms( RoomTypeList, 
                                    ClassTypeList, firstRoom, VERBOSE ) )
           {
            // stop timer before display
            timer.stop();

            // display classrooms with classes
            displayList( RoomTypeList, ClassTypeList );

            // show time, as needed
            if( SHOW_TIMER )
               {
                timer.getElapsedTime( dummy );

                cout << endl << "Elapsed Time: " << dummy << endl << endl;
               }
           }

        // otherwise, assume failure
        else
           {
            // stop, reset timer
            timer.stop();

            // display failed attempt
            cout << endl
                 << "Solution not found for classroom/class request fit."
                 << endl << endl;

            // show time, as needed
            if( SHOW_TIMER )
               {
                timer.getElapsedTime( dummy );

                cout << endl << "Elapsed Time: " << dummy << endl << endl;
               }
           }
       }

    // otherwise, assume incorrect data input
    else
       {
        cout << "Unequal number of room and class request sets"
             << " - Program Aborted." << endl;
       }

    return 0;
   }

// Free function implementation  //////////////////////////////////////////////

bool fitClassRooms
       ( 
        SimpleVector<RoomType> &roomList,
        SimpleVector<ClassType> &classList,
        int roomLevel, 
        bool showAttempts
       )
   {
    int index = 0; 
    RoomType tempRoom;
    ClassType tempClass;
    int classListSize = classList.getSize( ); 
    int classSize;
    int roomCapacity;
    bool classAvailability;
    bool success;

    if( classListAvailable( classList ) )
    {
        return true; 
    }
    else 
    {
        tempRoom = roomList.getAtIndex( roomLevel ); 

        roomCapacity = tempRoom.getRoomCapacity( ); 

        while( index < classListSize )
        {
            tempClass = classList.getAtIndex( index ); 

            classSize = tempClass.getSizeRequest( );

            classAvailability = tempClass.classIsAvailable( );
 
            if( classAvailability && ( roomCapacity >= classSize ) )
            {
                tempRoom.setAssociatedIndex( index ); 

                roomList.setAtIndex( roomLevel, tempRoom ); 

                tempClass.setClassAvailable( false );

                classList.setAtIndex( index, tempClass );

                success = fitClassRooms( roomList, classList, roomLevel + 1, showAttempts );

                if( success )
                { 
                    return success;
                }
                else
                {
                  
                    tempClass.setClassAvailable( true );

                    classList.setAtIndex( index, tempClass );
                }
                
            }
            index++; 
          
        }
        return false;
    }

   }

bool classListAvailable( SimpleVector<ClassType> &classList )
{
    int index;
    int size = classList.getSize( );
    ClassType storageVar;
    bool flag;

    for( index = 0; index < size; index++)
    {
        storageVar = classList.getAtIndex( index );
        flag = storageVar.classIsAvailable( ); 
        if( flag == true )
        {
            return false; 
        }
    }
    return true;
}

void displayList( const SimpleVector<RoomType> &roomList, 
                                   const SimpleVector<ClassType> &classList )
   {
    SimpleVector<RoomType> workingRoomList( roomList );
    SimpleVector<ClassType> workingClassList( classList );
    RoomType roomData;
    ClassType classData;
    int roomIndex, classIndex;
    char roomStr[ MAX_STR_LEN ], classStr[ MAX_STR_LEN ];

    cout << endl << "Classroom/Class Request Fit List" << endl;
    cout <<  "================================" << endl << endl;

    for( roomIndex = 0; roomIndex < workingRoomList.getSize(); roomIndex++ )
       {
        roomData = workingRoomList.getAtIndex( roomIndex );
        roomData.toString( roomStr );

        classIndex = roomData.getAssociatedIndex();         
        classData = workingClassList.getAtIndex( classIndex );
        classData.toString( classStr );

        cout << roomStr << " - " << classStr << endl;
       }
   }

int getALine( istream &consoleIn, char *inString, char delimiterChar )
   {
    char inChar;
    int index = 0;

    inString[ 0 ] = NULL_CHAR;

    consoleIn.get( inChar );

    while( index < MAX_STR_LEN - 1 && inChar != delimiterChar )
       {
        if( inChar != ENDLINE_CHAR && inChar != CARRIAGE_RETURN_CHAR )
           {
           inString[ index ] = inChar;

           index++;
 
           inString[ index ] = NULL_CHAR;

           if( strcmp( inString, "Start Room Data;" ) == 0 )
              {
               return START_CLASSROOMS;
              }

           else if( strcmp( inString, "End Room Data;" ) == 0 )
              {
               return END_CLASSROOMS;
              }

           else if( strcmp( inString, "Start Class Data;" ) == 0 )
              {
               return START_CLASS_REQUESTS;
              }

           else if( strcmp( inString, "End Class Data;" ) == 0 )
              {
               return END_CLASS_REQUESTS;
              }
           }
        
        consoleIn.get( inChar );
       }
       
    return STRING_CAPTURED;
   }

bool getANumber( istream &consoleIn, int &number )
   {
    char dummyChar;

    consoleIn >> number;
    consoleIn >> dummyChar;

    return ( dummyChar == SEMI_COLON );
   }

void printSpaces( int numSpaces )
   {
    while( numSpaces > 0 )
       {
        cout << SPACE;

        numSpaces--;
       }
   }












