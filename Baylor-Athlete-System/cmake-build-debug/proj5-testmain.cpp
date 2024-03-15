/**
 * file: proj5-testmain.cpp
 * author: Harrison Hassler
 * course: CSI 1440
 * assignment: project 5
 * due date: 3/20/2023
 *
 * date modified: 3/14/2023
 *      - file created
 * date modified: 3/18/2023
 *      - BUAthlete/BUAthleteList functions tested
 */


/*#include <iostream>
#include "proj5-BUAthleteList.hpp"

using namespace std;
int main (){
    //Testing BUAthlete Functions
    BUAthlete BUAthlete1;
    BUAthlete BUAthlete2;

    cout << "Testing setEvaluation and getEvaluation" << endl;
    BUAthlete1.setEvaluation(10);
    BUAthlete2.setEvaluation(2);
    cout << "Should be 10" << endl;
    cout << "Testing: " << BUAthlete1.getEvaluation() << endl;
    cout << "Should be 2" << endl;
    cout << "Testing: " << BUAthlete2.getEvaluation() << endl;
    cout << endl;

    cout << "Testing setPosition and getPosition" << endl;
    BUAthlete1.setPosition(K);
    BUAthlete2.setPosition(WR);
    cout << "Should be 10" << endl;
    cout << "Testing: " << BUAthlete1.getPosition() << endl;
    cout << "Should be 3" << endl;
    cout << "Testing: " << BUAthlete2.getPosition() << endl;
    cout << endl;

    cout << "Testing toString" << endl;
    cout << "Should be everything in BUAthlete1" << endl;
    BUAthlete1.setID(0000);
    BUAthlete1.setName("Harry");
    BUAthlete1.setLOI("yes");
    BUAthlete1.setSchool("Baylor");
    cout << BUAthlete1.toString();
    cout << endl;

    cout << "Should be everything in BUAthlete2" << endl;
    BUAthlete2.setID(9999);
    BUAthlete2.setName("Yolo");
    BUAthlete2.setLOI("yes");
    BUAthlete2.setSchool("Tennessee");
    cout << BUAthlete2.toString();
    cout << endl;

    //Testing BUAthleteList Functions
    BUAthleteList list;
    cout << "Testing addNCAAAthlete" << endl;
    list.addNCAAAthlete(7878,"Harrison","yes","Baylor" );
    list.setBUInfo(0, QB, 6);
    list.addNCAAAthlete(9999, "Joe", "no", "Texas");
    list.setBUInfo(1, RB, 7);
    list.addNCAAAthlete(3090,"HH","yes","Kansas" );
    list.setBUInfo(2, K, 3);
    list.addNCAAAthlete(8888, "Joe2", "no", "SMU");
    list.setBUInfo(3, WR, 4);

    cout << "Should be 7878" << endl;
    cout << "Testing: " << list[0].getID() << endl;
    cout << "Should be Harrison" << endl;
    cout << "Testing: " << list[0].getName() << endl;
    cout << "Should be 1" << endl;
    cout << "Testing: " << list[0].getLOI() << endl;
    cout << "Should be Baylor" << endl;
    cout << "Testing: " << list[0].getSchool() << endl;
    cout << endl;
    cout << "Should be 9999" << endl;
    cout << "Testing: " << list[1].getID() << endl;
    cout << "Should be Joe" << endl;
    cout << "Testing: " << list[1].getName() << endl;
    cout << "Should be 0" << endl;
    cout << "Testing: " << list[1].getLOI() << endl;
    cout << "Should be Texas" << endl;
    cout << "Testing: " << list[1].getSchool() << endl;
    cout << endl;

    cout << "Testing setBUInfo" << endl;
    cout << "Should be 1" << endl;
    cout << "Testing: " << list[0].getPosition() << endl;
    cout << "Should be 6" << endl;
    cout << "Testing: " << list[0].getEvaluation() << endl;
    cout << endl;

    cout << "Testing setBUInfo" << endl;
    cout << "Should be 2" << endl;
    cout << "Testing: " << list[1].getPosition() << endl;
    cout << "Should be 7" << endl;
    cout << "Testing: " << list[1].getEvaluation() << endl;
    cout << endl;

    cout << "Testing sortByID" << endl;
    list.sortByID();
    for(int i = 0; i < 4; i++){
        cout << list[i].getID() << " ";
    }
    cout << endl;
    cout << "Should sort ID's from least to greatest" << endl;
    cout << endl;

    cout << "Testing sortByEvaluation" << endl;
    list.sortByEvaluation();
    for(int i = 0; i < 4; i++){
        cout << list[i].getEvaluation() << " ";
    }
    cout << endl;
    cout << "Should sort by evaluation from least to greatest" << endl;
    cout << endl;

    cout << "Testing sortByPosition" << endl;
    list.sortByPosition();
    for(int i =- 0; i < 4; i++){
        cout << list[i].getPosition() << " ";
    }
    cout << endl;
    cout << "Should sort by position from least to greatest" << endl;
    cout << endl;

    cout << "Testing findByID" << endl;
    int find = list.findById(7878);
    cout << "Should be 0" << endl;
    cout << "Testing: " <<  find << endl;
    find = list.findById(9999);
    cout << "Should be 1" << endl;
    cout  << "Testing: " << find << endl;
    cout << endl;

    list.sortByEvaluation();
    cout << "Should print out sorted by evaluation" << endl;
    cout << "Testing toString" << endl;
    cout << list.toString();
    cout << endl;


}*/

