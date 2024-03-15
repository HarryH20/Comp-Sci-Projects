/**
 * file: proj5-BUAthlete.hpp
 * author: Harrison Hassler
 * course: CSI 1440
 * assignment: project 5
 * due date: 3/20/2023
 *
 * date modified: 3/15/2023
 *      - file created
 * date modified: 3/19/2023
 *      - comments made
 */

#ifndef PROJ5_BUATHLETES_PROJ5_BUATHLETE_HPP
#define PROJ5_BUATHLETES_PROJ5_BUATHLETE_HPP

#include "proj5-NCAAAthlete.hpp"

enum Position {OL, QB, RB, WR, TE, DL, DE, LB, CB, S, K};
class BUAthlete: public NCAAAthlete{
protected:
    int evaluation;
    Position bestFit;

public:
    /**
     * setEvaluation
     *
     * sets evaluation of player
     *
     * Parameters: integer
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void setEvaluation(int eval);

    /**
     * setPosition
     *
     * sets the position of player
     *
     * Parameters: Position
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void setPosition(Position pos);

    /**
     * getEvaluation
     *
     * returns integer evaluation
     *
     * Parameters: none
     *
     * Output:
     *      return: integer
     *      reference parameters: none
     *      stream: none
     */
    int getEvaluation();

    /**
     * getPosition
     *
     * returns enum of Position
     *
     * Parameters: none
     *
     * Output:
     *      return: one of the values in enum Position
     *      reference parameters: none
     *      stream: none
     */
    Position getPosition();

    /**
     * toString
     *
     * converts an instance of a NCAAAthlete into a string representation
     *
     * Parameters: none
     *
     * Output:
     *      return: a string representation of the object
     *      reference parameters: none
     *      stream: none
     */
    string toString();
};
#endif