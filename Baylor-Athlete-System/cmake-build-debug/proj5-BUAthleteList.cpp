/**
 * file: proj5-BUAthlete.cpp
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


#include "proj5-BUAthleteList.hpp"
#include <sstream>
//BIG 4
BUAthleteList::BUAthleteList() {
    this->size = 0;
    this->capacity = 2;
    this->list = new BUAthlete[this->capacity];

}
BUAthleteList::~BUAthleteList() {
    delete[] this->list;
}

BUAthleteList::BUAthleteList(BUAthleteList& that) {
    this->size = that.size;
    this->capacity = that.capacity;
    this->list = new BUAthlete[that.capacity];
    for(int i = 0; i < this->size; i++){
        this->list[i] = that.list[i];
    }

}

BUAthleteList &BUAthleteList::operator=(BUAthleteList &that) {
    if(this != &that){
        delete[] this->list;
        this->size = that.size;
        this->capacity = that.capacity;
        this->list = new BUAthlete[this->capacity];
        for(int i = 0; i < this->size; i++){
            this->list[i] = that.list[i];
        }

    }
    return *this;
}

void BUAthleteList::resizeArray() {
    this->capacity += 2;
    BUAthlete *temp = this->list;
    this->list = new BUAthlete[this->capacity];
    for(int i = 0; i < this->size; i++){
        this->list[i] = temp[i];

    }
    delete[] temp;

}
void BUAthleteList::addNCAAAthlete(int ID,string name,string LOI, string school){
    if(this->size == this->capacity){
        this->resizeArray();
    }
    this->list[this->size].setID(ID);
    this->list[this->size].setName(name);
    this->list[this->size].setLOI(LOI);
    this->list[this->size].setSchool(school);
    this->size++;
}

void BUAthleteList::setBUInfo(int index, Position pos, int eval){
    (this->list + index)->setPosition(pos);
    (this->list + index)->setEvaluation(eval);
}

int BUAthleteList::findById(int id) {
    int mid;
    int low = 0;
    int high = this->size - 1;

    while (high >= low) {
        mid = (high + low) / 2;
        if (list[mid].getID() > id) {
            high = mid -1;
        } else if (list[mid].getID() < id) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

void BUAthleteList::sortByID(){
    QuicksortForID(this->list, 0, this->size -1);
}

void BUAthleteList::sortByPosition() {
    for(int i = 0; i < this->size -1; i++){
        for(int j = 0; j < this->size -1 -i; j++){
            if(this->list[j].getPosition() > this->list[j+1].getPosition()){
                swap(this->list[j],this->list[j+1]);
            }
        }

    }
}

void BUAthleteList::sortByEvaluation(){
    QuicksortForEvaluation(this->list,0,this->size -1);
}

BUAthlete& BUAthleteList::operator[](int ndx){
    return this->list[ndx];
}

string BUAthleteList::toString() {
    ostringstream out;
    for(int i = 0; i < this->size; i++){
        out << "[" << i << "]" << endl;
        out << (this->list + i)->toString();

    }
    return out.str();
}








//Quicksort Functions
void QuicksortForID(BUAthlete *list, int i, int k){
    int j;
    if(i >= k){
        return;

    }
    j = PartitionForID(list, i, k);
    QuicksortForID(list, i, j);
    QuicksortForID(list, j + 1, k);


}

void QuicksortForEvaluation(BUAthlete *list, int i, int k){
int j;
if(i >= k){
return;

}
j = PartitionForEvaluation(list, i, k);
QuicksortForEvaluation(list, i, j);
QuicksortForEvaluation(list, j + 1, k);


}

int PartitionForID(BUAthlete *list, int i, int k){
    int l;
    int h;
    int midpoint;
    int pivot;
    int temp;
    bool done;

    midpoint = i + (k - i)/2;
    pivot = list[midpoint].getID();

    done = false;
    l = i;
    h = k;

    while(!done){
        while(list[l].getID() < pivot){
            ++l;
        }
        while(pivot < list[h].getID()){
            --h;
        }
        if(l >=h){
            done = true;
        }
        else{
            swap(list[h], list[l]);
            ++l;
            --h;
        }
    }
return h;

}

int PartitionForEvaluation(BUAthlete *list, int i, int k){
    int l;
    int h;
    int midpoint;
    int pivot;
    int temp;
    bool done;

    midpoint = i + (k - i)/2;
    pivot = list[midpoint].getEvaluation();

    done = false;
    l = i;
    h = k;

    while(!done){
        while(list[l].getEvaluation() < pivot){
            ++l;
        }
        while(pivot < list[h].getEvaluation()){
            --h;
        }
        if(l >=h){
            done = true;
        }
        else{
            swap(list[h], list[l]);
            ++l;
            --h;
        }
    }
    return h;

}
























