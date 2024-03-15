/**
 * file: proj5-main.cpp
 * author: Harrison Hassler
 * course: CSI 1440
 * assignment: project 5
 * due date: 3/20/2023
 *
 * date modified: 3/14/2023
 *      - file created
 * date modified: 3/19/2023
 *      - project solution complete
 */

#include "proj5-BUAthleteList.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

int main(){
    BUAthleteList BUAthleteList;
    Position enumPos;
    ifstream inputFile;
    string name;
    string loi;
    string school;
    string strPos;
    int id;
    int eval;
    int count = 0;

    //opens file and checks
    inputFile.open("proj5-NCAAAthlete.csv");

    if(!inputFile){
        cout << "ERROR: Could not open NCAA file" << endl;
        return 1;
    }else{
        //parses data
        while(inputFile >> id){
            inputFile.ignore();
            getline(inputFile, name, ',');
            getline(inputFile, loi, ',');
            getline(inputFile, school);

            BUAthleteList.addNCAAAthlete(id, name, loi, school);
            count++;
        }
    }
    inputFile.close();
    BUAthleteList.sortByID();

    //opens second file
    inputFile.open("proj5-BUAthlete.csv");
    if(!inputFile){
        cout << "ERROR: Could not open Coach's file" << endl;
        return 1;
    }else{
        int i = 0;
        while(inputFile >> id){
            inputFile.ignore();
            getline(inputFile, strPos, ',');
            inputFile >> eval;
            if(strPos == "OL"){
                enumPos = OL;
            }else if (strPos == "QB"){
                enumPos = QB;
            }else if (strPos == "RB"){
                enumPos = RB;
            }else if (strPos == "WR"){
                enumPos = WR;
            }else if (strPos == "TE"){
                enumPos = TE;
            }else if (strPos == "DL"){
                enumPos = DL;
            }else if (strPos == "DE"){
                enumPos = DE;
            }else if (strPos == "LB"){
                enumPos = LB;
            }else if (strPos == "CB"){
                enumPos = CB;
            }else if (strPos == "S"){
                enumPos = S;
            }else if (strPos == "K"){
                enumPos = K;
            }
            BUAthleteList.setBUInfo(i++, enumPos, eval);
        }
    }
    inputFile.close();

    BUAthleteList.sortByPosition();
    BUAthleteList.sortByEvaluation();

    cout << BUAthleteList.toString() << endl;
    return 0;
}