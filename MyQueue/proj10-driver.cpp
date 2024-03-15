/**
*  File: proj10-driver.cpp
*  Author: Harrison Hassler
*  Course: CSI 1440
*  Assignment: Project 10
*  Due Date: 05/1/2023
*
*  Date Modified: 04/30/2023
*    - Project goal completed
*
*/

#include "proj10-Queue1.h"
#include "proj10-Queue2.h"
#include "proj10-Queue3.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
    Queue1<int> q1;
    Queue2<int> q2;
    Queue3<int> q3;
    time_t time1, time2, time3;
    int temp;
    srand(time(NULL));

    for(int i = 0; i < 100; ++i){
        q1.enqueue(rand() % 100);
    }

    for(int i = 0; i < 100; ++i){
        q2.enqueue(rand() % 100);
    }

    for(int i = 0; i < 100; ++i){
        q3.enqueue(rand() % 100);
    }

    time1 = clock();
    for(int i = 0; i < 100; ++i){
        q1.dequeue(temp);
    }
    time1 = clock() - time1;

    time2 = clock();
    for(int i = 0; i < 100; ++i){
        q2.dequeue(temp);
    }
    time2 = clock() - time2;

    time3 = clock();
    for(int i = 0; i < 100; ++i){
        q3.dequeue(temp);
    }
    time3 = clock() - time3;

    cout << "Queue1 Time: " << time1 << endl;
    cout << "Queue2 Time: " << time2 << endl;
    cout << "Queue3 Time: " << time3 << endl;

    return 0;
}