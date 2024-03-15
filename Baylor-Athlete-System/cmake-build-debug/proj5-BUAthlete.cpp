/**
 * file: proj5-BUAthlete.cpp
 * author: Harrison Hassler
 * course: CSI 1440
 * assignment: project 5
 * due date: 3/20/2023
 *
 * date modified: 3/15/2023
 *      - file created
 * date modified: 3/16/2023
 *      Functions Implemented:
 *      - setEvaluation
 *      - setPosition
 *      - getPosition
 *      - getEvaluation
 *      - toString
 */

#include "proj5-BUAthlete.hpp"
#include <sstream>
void BUAthlete::setEvaluation(int eval) {
    this->evaluation = eval;
}
void BUAthlete::setPosition(Position pos){
    this->bestFit = pos;
}
int BUAthlete::getEvaluation() {
    return this->evaluation;
}
Position BUAthlete:: getPosition(){
    return this->bestFit;
}
string BUAthlete::toString() {
ostringstream out;

/*uses NCAAAthlete's toString to print out the NCAA
   info on the Athlete
 */
out << NCAAAthlete::toString();

//prints out Aranda's info
out<< "Evaluation: " << this->evaluation << endl;
out << "Position: ";
switch(this->bestFit){
    case 0:
        out << "OL";
        break;

    case 1:
        out << "QB";
        break;

    case 2:
        out << "RB";
        break;

    case 3:
        out << "WR";
        break;

    case 4:
        out << "TE";
        break;

    case 5:
        out << "DL";
        break;

    case 6:
        out << "DE";
        break;

    case 7:
        out << "LB";
        break;

    case 8:
        out << "CB";
        break;

    case 9:
        out << "S";
        break;

    case 10:
        out << "K";
        break;
}
    out << endl;

    return out.str();
}




