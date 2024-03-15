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
 *      - comments made and code finished
 */




#ifndef PROJ5_BUATHLETES_PROJ5_BUATHLETELIST_HPP
#define PROJ5_BUATHLETES_PROJ5_BUATHLETELIST_HPP
#include "proj5-BUAthlete.hpp"

class BUAthleteList {
protected:
    BUAthlete *list;
    int capacity;
    int size;

    void resizeArray();

public:
    /**
     * BUAthleteList()
     *
     * default constructor
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    BUAthleteList();

    /**
     * BUAthleteList
     *
     * copy constructor
     *
     * Parameters: const BUAthleteList&
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    ~BUAthleteList();

    /**
     * ~BUAthleteList
     *
     * destructor
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    BUAthleteList(BUAthleteList &);

    /**
     * BUAthleteList& operator=
     *
     * overloads equals operator
     *
     * Parameters: const BUAthleteList&
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    BUAthleteList &operator=(BUAthleteList &);

    /**
     * addNCAAAthlete
     *
     * adds a player to array
     *
     * Parameters: integer, string, string, string
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void addNCAAAthlete(int ID, string name, string LOI, string school);

    /**
     * setBUInfo
     *
     * sets BUInfo of player object
     *
     * Parameters: integer, Position, integer
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void setBUInfo(int index, Position pos, int eval);

    /**
     * findById
     *
     * finds player by their ID using binary search
     *
     * Parameters: integer
     *
     * Output:
     *      return: integer ID
     *      reference parameters: none
     *      stream: none
     */
    int findById(int id);

    /**
     * sortByID
     *
     * sorts players by their ID using Quicksort
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void sortByID();

    /**
     * sortByPosition
     *
     * sorts players by their Position using bubblesort
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void sortByPosition();

    /**
     * sortByEvaluation
     *
     * sorts players by their Evaluation using Quicksort
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void sortByEvaluation();

    /**
     * operator[]
     *
     * overloads [] operator
     *
     * Parameters: integer
     *
     * Output:
     *      return: value and integer index
     *      reference parameters: none
     *      stream: none
     */
    BUAthlete &operator[](int);

    /**
     * toString
     *
     * prints the top 2 from each class
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

/**
 * QuicksortForID
 *
 * creates Quicksort function to sort ID
 *
 * Parameters: BUAthlete*, integer, integer
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: none
 */
void QuicksortForID(BUAthlete* list, int i, int k);

/**
 * PartitionForID
 *
 * creates the partition for the Quicksort of ID
 *
 * Parameters: BUAthlete*, integer, integer
 *
 * Output:
 *      return: integer
 *      reference parameters: none
 *      stream: none
 */
int PartitionForID(BUAthlete* list, int i, int k);

/**
 * QuicksortForEvaluation
 *
 * creates Quicksort function to sort evaluation
 *
 * Parameters: BUAthlete*, integer, integer
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: none
 */
void QuicksortForEvaluation(BUAthlete* list, int i, int k);

/**
 * PartitionForEvaluation
 *
 * creates the partition for the binary sort of evaluation
 *
 * Parameters: BUAthlete*, integer, integer
 *
 * Output:
 *      return: integer
 *      reference parameters: none
 *      stream: none
 */
int PartitionForEvaluation(BUAthlete* list, int i, int k);

#endif


