/* file: proj7-TestMain.cpp
 * author: Harrison Hassler
 * course: CSI 1440
 * assignment: Project 7
 * due date: 4/3/2023
 * date modified: 3/29/2023
 *     -file created
 * date modified: 3/30/2023
 *     -file finished and code written
 */

#include <iostream>
#include "proj7-MyVector.h"

using namespace std;

template <class T>
/*
 *copyIt
 *
 *This function copies a vector to test the copy constructor
 *
 *Parameters:
 *    b: MyVector<T>
 *
 *Output:
 *    return: size and numbers of array
 *    reference parameters: b
 *    stream: none
 */
void copyIt(MyVector<T> b) {
    cout << "Size: " << b.getSize() << endl;
    cout << "Numbers: ";
    for(int i = 0; i < b.getSize(); i++){
        cout << b[i] << " ";

    }
    cout << endl;
}
int main() {
    MyVector<int> intV;
    MyVector<int> intV2;
    int a;

    cout << "Testing default constructor with getSize should be 0" << endl;
    cout << "Testing: " << intV.getSize() << endl << endl;

    cout << "Testing pushBack function with [] operator and grow function" << endl;
    intV.pushBack(1);
    intV.pushBack(2);
    intV.pushBack(3);
    intV.pushBack(4);
    cout << "Size should be 4" << endl;
    cout << "Testing: " << intV.getSize() << endl;
    cout << "Should have 1 2 3 4" << endl;
    cout << "Testing: ";
    for(int i = 0; i < intV.getSize(); i++){
        cout << intV[i] << " ";

    }
    cout << endl << endl;

    cout << "Testing copy constructor" << endl;
    copyIt(intV);
    cout << endl;

    cout << "Pushing back more numbers" << endl;
    intV.pushBack(5);
    intV.pushBack(6);
    intV.pushBack(7);
    intV.pushBack(8);
    intV.pushBack(9);
    intV.pushBack(10);
    intV.pushBack(11);
    cout << "Size should be 11" << endl;
    cout << "Testing: ";
    cout << intV.getSize() << endl;
    cout << "Should be 1 2 3 4 5 6 7 8 9 10 11" << endl;
    cout << "Testing: ";
    for(int i = 0; i < intV.getSize(); i++){
        cout << intV[i] << " ";

    }
    cout << endl << endl;

    cout << "Testing back" << endl;
    cout << "Should say 11" << endl;
    cout << "Testing: " << intV.back() << endl;
    cout << "Testing popBack" << endl;
    cout << "Should be 11 10 9 8" << endl;
    cout << "Testing: ";
    for(int i = 0; i < 4; i++){
        intV.popBack(a);
        cout << a << " ";

    }
    cout << endl;
    cout << "Size should be 7" << endl;
    cout << "Testing: " << intV.getSize() << endl;
    cout << "Back should now be 7" << endl;
    cout << "Testing: " << intV.back() << endl << endl;

    cout << "Testing copy constructor" << endl;
    copyIt(intV);
    cout << endl;

    cout << "Testing pushFront with shiftRight and grow" << endl;
    intV.pushFront(20);
    intV.pushFront(21);
    intV.pushFront(22);
    intV.pushFront(23);
    cout << "Size should be 11" << endl;
    cout << "Testing: " << intV.getSize() << endl;
    cout << "Should be 23 22 21 20 1 2 3 4 5 6 7" << endl;
    cout << "Testing: ";
    for(int i = 0; i < intV.getSize(); i++){
        cout << intV[i] << " ";

    }
    cout << endl << endl;

    cout << "Testing overloading assignment operator" << endl;
    cout << "intV2 is:" << endl;
    copyIt(intV2);
    intV2 = intV;
    cout << "intV2 is now:" << endl;
    copyIt(intV2);
    cout << endl;

    cout << "Testing popFront and front with shiftLeft" << endl;
    cout << "Should say 23 is in the front" << endl;
    cout << "Testing: " << intV.front() << endl;
    cout << "Popping front value should say 23" << endl;
    intV.popFront(a);
    cout << "Testing: " << a << endl;
    cout << "Front value should now be 22" << endl;
    cout << "Testing: " << intV.front() << endl;
    cout << "Popping 22" << endl;
    intV.popFront(a);
    cout << "Front should now be 21" << endl;
    cout << "Testing: " << intV.front() << endl;
    cout << "Size of intV should now be 9" << endl;
    cout << "Testing: " << intV.getSize() << endl << endl;

    cout << "Testing erase and isEmpty" << endl;
    intV.erase();
    cout << "Should say Test passed because intV was erased" << endl;
    if(intV.isEmpty()){
        cout << "Test passed" << endl;
    }
    else{
        cout << "Test failed" << endl;
    }
    cout << "Should say Test failed because intV2 isn't empty" << endl;
    if(intV2.isEmpty()){
        cout << "Test passed" << endl;
    }
    else{
        cout << "Test failed" << endl;
    }
    cout << endl;

    try {
        intV.popFront(a);
        cout << "Should not see this message" << endl;
    }
    catch(BADINDEX){
        cout << "Should see this message because it caught the error" << endl;

    }
    try {
        intV.popBack(a);
        cout << "Should not see this message" << endl;
    }
    catch(BADINDEX){
        cout << "Should see this message because it caught the error" << endl;

    }
    try {
        intV.front();
        cout << "Should not see this message" << endl;
    }
    catch(BADINDEX){
        cout << "Should see this message because it caught the error" << endl;

    }
    try {
        intV.back();
        cout << "Should not see this message" << endl;
    }
    catch(BADINDEX){
        cout << "Should see this message because it caught the error" << endl;

    }
}



