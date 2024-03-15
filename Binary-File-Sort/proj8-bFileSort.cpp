/**
 * File: proj8-bFileSort.cpp
 * Author: Harrison Hassler
 * Course: CSI 1440
 * Assignment: Project 8
 * Due Date: 4/10/2023
 * Date Modified: 4/9/2023
 *      - file created and code written
 */

#include <iostream>
#include <fstream>
using namespace std;

int main () {
    //variable declaration
    fstream inStream;
    int userInts;
    int numInts;
    int x;
    bool posFound = false;

    //opens binary file and checks for bad file
    inStream.open("sortedInts", ios::in | ios::out | ios::binary);
    if ( !inStream ) {
        cerr << "Bad filename" << endl;
        return 1;
    }

    //prints integers to screen
    //seekg moves file pointer to the end of the file
    inStream.seekg(0, ios::end);
    //calculates number of ints in stream by dividing by 4 because
    //each integer takes up 4 bytes
    numInts = inStream.tellg() / sizeof(int);
    cout << "Integers in the file:" << endl;
    if (inStream.tellg() > 0) {
        //moves file pointer back to the beginning
        inStream.seekg(0, ios::beg);
        for (int i = 0; i < numInts; i++) {
            //reads from the file and prints the int
            inStream.read((char*)&x, sizeof(int));
            cout << x << "\t";
        }
    }
    cout << endl;

    //asks user to enter a number
    //moves file pointer to the end of the file
    inStream.seekg(0, ios::end);
    cout << "Enter a number: " << endl;
    //user inputs number
    cin >> userInts;

    //inputs user number into file
    if (inStream.tellg() > 0) {
        int i = 0;


        //goes until the stream is ended or position is found
        while (i < numInts && !posFound) {
            //moves file pointer back one each time from the current pos
            //moves it back 4 bytes each time
            inStream.seekg(-sizeof(int), ios::cur);
            //reads it from stream into x
            inStream.read((char *) &x, sizeof(int));
            //writes x to the output stream
            inStream.write((char *) &x, sizeof(int));
            inStream.seekg(-1 * sizeof(int), ios::cur);
            //searches until x is in the right order
            if (x < userInts) {
                inStream.write((char *) &userInts, sizeof(int));
                posFound = true;
            } else {
                inStream.seekg(-sizeof(int), ios::cur);
            }
            i++;
        }

        //if the integer is the lowest puts it at beginning of file
        if (!posFound) {
            inStream.write((char*)&userInts, sizeof(int));
        }
    }
    else {
        inStream.write((char*)&userInts, sizeof(int));
    }

    //closes stream
    inStream.close();

    return 0;

}

