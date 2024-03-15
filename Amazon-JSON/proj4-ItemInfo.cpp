/**
 * file: proj4-ItemInfo.cpp
 * author: Harrison Hassler
 * course: CSI 1440
 * assignment: project 4
 * due date: 2/27/2023
 *
 * date modified:  2/25/2023
 *    - file created
 *    - functions made
 *
 * date modified:  2/26/2023
 *    - main was created
 *
 *
 * Implemented in main and test main
 */


#include "proj4-ItemInfo.hpp"

void ItemInfo::setItemId(const char* num){
    this->itemId = 0;
    for(int i = 0; num[i] != '\0'; i++){
        this->itemId *= 10;
        this->itemId += num[i] - '0';

    }
}

void ItemInfo::setDescription(const char *cstr){
    int i;
    for(i = 0; cstr[i] != '\0'; i++){
        this->description[i] = cstr[i];
    }
    this->description[i] = '\0';
}

void ItemInfo::setManCost(const char *num){
    this->manCost = stuCstrToDbl(num);
}

void ItemInfo::setSellPrice(const char *num){
    this->sellPrice = stuCstrToDbl(num);
}


int ItemInfo::getItemId() {
    return this->itemId;
}
const char* ItemInfo::getDescription() {
    return this->description;
}

double ItemInfo::getManCost() {
    return this->manCost;
}

double ItemInfo::getSellPrice(){
    return this->sellPrice;
}

//Prints items in JSON format
void ItemInfo::toAmazonJSON(ostream& out) {
    printCString(out, "\t\t\"itemId\": ");
    char *itemId = new char[10];
    stuDblToCstr(itemId, this->itemId);
    printCString(out, itemId);
    printCString(out,",\n");
    delete[] itemId;

    printCString(out, "\t\t\"description\": ");
    char *description = new char[40];
    stuCstrCpy(description, this->description);
    printCString(out, description);
    printCString(out, ",\n");
    delete[] description;

    printCString(out, "\t\t\"manPrice\": ");
    char *manCost = new char[10];
    stuDblToCstr(manCost, this->manCost);
    printCString(out, manCost);
    printCString(out, ",\n");
    delete[] manCost;

    printCString(out, "\t\t\"sellPrice\": ");
    char *sellPrice = new char[10];
    stuDblToCstr(sellPrice, this->sellPrice);
    printCString(out, sellPrice);
    out.put('\n');
    delete[] sellPrice;
}

//Prints items in displayItem format
void ItemInfo::displayItemInfo(ostream& out) {
    printCString(out, "itemId: ");
    char *itemId = new char[10];
    stuDblToCstr(itemId, this->itemId);
    printCString(out, itemId);
    out.put('\n');
    delete[] itemId;

    printCString(out, "description: ");
    char *description = new char[40];
    stuCstrCpy(description, this->description);
    printCString(out, description);
    out.put('\n');
    delete[] description;

    printCString(out, "manCost: ");
    char *manCost = new char[10];
    stuDblToCstr(manCost, this->manCost);
    printCString(out, manCost);
    out.put('\n');
    delete[] manCost;

    printCString(out, "sellPrice: ");
    char *sellPrice = new char[10];
    stuDblToCstr(sellPrice, this->sellPrice);
    printCString(out, sellPrice);
    out.put('\n');
    delete[] sellPrice;

    printCString(out, "calculatedProfit: ");
    char *calculatedProfit = new char[10];
    stuDblToCstr(calculatedProfit, calcProfit());
    printCString(out, calculatedProfit);
    out.put('\n');
    delete[] calculatedProfit;
}


double ItemInfo::calcProfit(){
    return this->sellPrice - this->manCost;
}

double stuCstrToDbl(const char *num){
    double returnVal = 0;
    double neg = 1;
    int count = 0;
    //checks if it is negative
    if(*num == '-'){
        neg = -1;
        num++;
    }
    //reads until a . or \0
    while(*num != '\0' && *num != '.'){
        if(count != 0){
            returnVal *= 10;
        }
        returnVal += *num - '0';
        num++;
        count++;
    }
    int i = 0;
    //reads the decimal part
    while(*num != '\0'){
        if(i == 0){
            ++num;
            returnVal += 0.1 * (*num - '0');
        }
        else {
            returnVal += 0.01 * (*num - '0');
        }
        num++;
        ++i;
    }

    return returnVal * neg;
}



void stuDblToCstr(char *cstr, double num){
    int ndx = 0;
    int count = 0;
    int num2, neg = 0;
    char swap;
    double num3;
    //checks for negative number
    if(num < 0){
        cstr[ndx] = '-';
        ndx++;
        num *= -1;
        neg = 1;
        ++count;
    }
    num2 = num;
    while(num2 > 0){
        cstr[ndx] = char(num2%10 + '0');
        num2 /= 10;
        ndx++;
        count++;
    }
    //reverses order
    for(int i = 0; i < count / 2; ++i){
        swap = cstr[i + neg];
        cstr[i + neg] = cstr[count - i - 1];
        cstr[count - i - 1] = swap;
    }
    num3 = num - static_cast<int>(num);
    //calculates decimal part
    if(num3 > 0){
        cstr[ndx] = '.';
        ndx++;
        for(int i = 0; i < 2; ++i){
            num3 *= 10;
            cstr[ndx] = char(int(num3) + '0');
            num3 = num3 - static_cast<int>(num3);
            ndx++;
        }
    }
    cstr[ndx] = '\0';
}

void stuCstrCpy(char *dest, const char *src){
    int i = 0;
    if(src != dest){
        for(i = 0; src[i] != '\0'; i++){
            dest[i] = src[i];
        }
        dest[i] = '\0';
    }
}

int stuCstrLen(const char *src){
    int i = 0;
    while(src[i] != '\0'){
        i++;
    }
    return i;
}

ostream& printCString(ostream &out, const char *src){
    for(int i = 0; src[i] != '\0'; i++){
        out.put(src[i]);
    }
    return out;

}



























