/**
*  File: proj9-TestMain.cpp
*  Author: Harrison Hassler
*  Course: CSI 1440
*  Assignment: Project 9
*  Due Date: 04/24/2023
*
*  Date Modified: 04/11/2023
*    - File Created
*
*  Date Modified: 04/12/2023
*    - All functions tested
*
*/



#include <iostream>
#include "proj9-MyList.h"
using namespace std;

/**
 *copyIt
 *
 *This function copies a MyList to test the copy constructor
 *
 *Parameters:
 *    b: MyList<T>
 *
 *Output:
 *    return: size and numbers in linked list
 *    reference parameters: a
 *    stream: none
 */
template <class T>
void copyit(MyList<T> a){
    cout << "Size: ";
    cout << a.getSize() << endl;
    cout << "Numbers: ";
    for(int i = 0; i < a.getSize(); i++){
        cout << a[i] << " ";
    }
    cout << endl;

}

int main (){
    MyList<int> list;

    //Tests pushback(a)
    cout << "Testing pushBack()" << endl;
    cout << "Pushing back values 0-4" << endl;
    for(int i = 0; i < 5; i++){
        list.pushBack(i);
    }

    //Tests [] operator
    cout << "Testing [] operator: ";
    for(int i = 0; i < 5; i++){
        cout << list[i] << " ";
    }
    cout << endl;

    //Tests getSize()
    cout << "Testing getSize()" << endl;
    cout << "Should be 5" << endl;
    cout << "Testing: " << list.getSize() << endl;

    cout << "Testing erase()" << endl;
    list.erase();

    try{
        for(int i = 0; i < 5; i++){
            cout << list[i] << " ";
        }
    }
    catch(BADINDEX){
        cout << "Error because nothing is in vector so erase() works" << endl;
    }

    cout << "List should now be empty" << endl;
    //Tests isEmpty()
    cout << "Testing isEmpty()" << endl;
    if(list.isEmpty()){
        cout << "PASSED list is empty" << endl;
    }
    cout << endl;

    //Testing functions again
    cout << "Testing pushBack() with different numbers" << endl;
    cout << "pushing back 5-9" << endl;
    for(int i = 5; i < 10; i++){
        list.pushBack(i);
    }
    cout << "Testing [] operator: ";
    for(int i = 0; i < 5; i++){
        cout << list[i] << " ";
    }
    cout << endl;

    cout << "Testing getSize()" << endl;
    cout << "Should be 5" << endl;
    cout << "Testing: " << list.getSize() << endl;

    //Tests popFront(a)
    cout << "Testing popFront(a)" << endl;
    cout << "popping all numbers should be 5-9" << endl;
    int a;
    for(int i = 0; i < 5; i++){
        list.popFront(a);
        cout << a << " ";
    }
    cout << endl;

    try{
        list.popFront(a);
    }
    catch(BADINDEX){
        cout << "Should see this because all the numbers are popped" << endl;
    }

    cout << "List should now be empty" << endl;
    cout << "Testing isEmpty()" << endl;
    if(list.isEmpty()){
        cout << "PASSED list is empty" << endl;
    }
    cout << endl;

    //Tests pushFront(a)
    cout << "Testing pushFront(a)" << endl;
    cout << "Pushing front 0-4" << endl;
    for(int i = 0; i < 5; i++){
        list.pushFront(i);
    }
    cout << "Testing [] operator: ";
    for(int i = 0; i < 5; i++){
        cout << list[i] << " ";
    }
    cout << endl;

    //Tests popBack(a)
    cout << "Testing popBack(a)" << endl;
    cout << "Numbers should be from least to greatest " << endl;
    for(int i = 0; i < 5; i++){
        list.popBack(a);
        cout << a << " ";
    }
    cout << endl;
    try{
        list.popBack(a);
    }
    catch(BADINDEX){
        cout << "Should see this because all the numbers are popped" << endl;
    }
    cout << endl;
    cout << "List should now be empty" << endl;
    cout << "Testing getSize()" << endl;
    cout << "Should be 0" << endl;
    cout << "Testing: " << list.getSize() << endl;

    //Checks if BADINDEX is working
    try{
        list.front();
    }
    catch(BADINDEX){
        cout << "Should see this error because nothing is in the list" << endl;
    }
    try{
        list.back();
    }
    catch(BADINDEX){
        cout << "Should see this error because nothing is in the list" << endl;
    }
    try{
        list.popFront(a);
    }
    catch(BADINDEX){
        cout << "Should see this error because nothing is in the list" << endl;
    }
    try{
        list.popBack(a);
    }
    catch(BADINDEX){
        cout << "Should see this error because nothing is in the list" << endl;
    }
    try{
        list[0];
    }
    catch(BADINDEX){
        cout << "Should see this error because nothing is in the list" << endl;
    }
    cout << endl;

    cout << "Pushing back values 0-9" << endl;
    for(int i = 0; i < 10; i++){
        list.pushBack(i);
    }

    //Tests front()
    cout << "Testing front()" << endl;
    cout << "Should be 0" << endl;
    cout << "Testing: ";
    cout << list.front() << endl;
    cout << "Popping front value" << endl;
    list.popFront(a);
    cout << "Front should now be 1" << endl;
    cout << "Testing: ";
    cout << list.front() << endl << endl;

    //Tests back()
    cout << "Testing back()" << endl;
    cout << "Should be 9" << endl;
    cout << "Testing: ";
    cout << list.back() << endl;
    cout << "Popping back value" << endl;
    list.popBack(a);
    cout << "Back should now be 8" << endl;
    cout << "Testing: " << list.back() << endl << endl;

    //Tests copy constructor
    MyList<int> list2;
    cout << "Testing copy constructor" << endl;
    copyit(list);
    cout << endl;

    //Tests = operator
    cout << "Testing = operator" << endl;
    list2 = list;
    copyit(list2);
    cout << endl;

    //Tests erase() again
    cout << "Erasing both functions" << endl;
    list.erase();
    list2.erase();

    if(list.isEmpty() && list2.isEmpty()){
        cout << "Should see this erased worked" << endl;
    }
    return 0;

}