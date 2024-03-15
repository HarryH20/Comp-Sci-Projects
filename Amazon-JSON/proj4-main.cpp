/**
 * file: proj4-main.cpp
 * author: Harrison Hassler
 * course: CSI 1440
 * assignment: project 4
 * due date: 2/27/2023
 *
 * date modified:  2/26/2023
 *    - file created
 *    - project task completed
 */

/*#include "proj4-ItemInfo.hpp"
#include <fstream>

using namespace std;
// Function to resize the itemArray
void resizeArray(ItemInfo *&itemArray, int &capacity, int newCapacity) {
    // Create a temporary pointer to the old itemArray
    ItemInfo *temp = itemArray;
    // Allocate memory for the new itemArray
    itemArray = new ItemInfo[newCapacity];
    // Copy the items from the old array to the new array
    for (int i = 0; i < capacity; ++i) {
        itemArray[i] = temp[i];
    }
    // Update the capacity of the array
    capacity = newCapacity;
    // Deallocate memory for the old itemArray
    delete[] temp;
}

// Function to sort the itemArray by most profitable items
void priceSort(ItemInfo *arr, int n) {
    // Sort the array using bubble sort
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < n - i - 1; ++j){
            if(arr[j].calcProfit() < arr[j+1].calcProfit()){
                ItemInfo temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
//Function to print JSON
void sortAndPrint(ItemInfo *that) {
    printCString(cout, "\"H shop\": [\n");
    cout.put('\t');
    printCString(cout, "\"firstItem\": {\n");
    that[0].toAmazonJSON(cout);
    printCString(cout,"\t},");
    cout.put('\n');
    cout.put('\t');
    printCString(cout, "\"secondItem\": {\n");
    that[1].toAmazonJSON(cout);
    printCString(cout,"\t},");
    cout.put('\n');
    cout.put('\t');
    printCString(cout, "\"thirdItem\": {\n");
    that[2].toAmazonJSON(cout);
    printCString(cout,"\t},");
    cout.put('\n');
    cout.put('\t');
    printCString(cout, "\"fourthItem\": {\n");
    that[3].toAmazonJSON(cout);
    printCString(cout,"\t},");
    cout.put('\n');
    cout.put('\t');
    printCString(cout, "\"fifthItem\": {\n");
    that[4].toAmazonJSON(cout);
    printCString(cout,"\t}");
    cout.put('\n');
    printCString(cout, "]");
}

int main() {
    char buffer[500];
    int capacity = 2;
    int itemNum = 0;
    ItemInfo *itemArray = new ItemInfo[capacity];
    int count = 0;
    int type = 0;
    ifstream inputFile;

    //Checks if file opens
    inputFile.open("proj4-productServices.csv");
    if (!inputFile) {
        //Prints error message if file doesn't open
        printCString(cout, "inputFile not found");
        cout.put('\n');
    }
    else {
        //Reads in data from file
        while (inputFile.get(buffer[count])) {
            if (itemNum == capacity) {
                resizeArray(itemArray, capacity, capacity + 2);
            }
            if (buffer[count] == ',' || buffer[count] == '\n') {
                buffer[count] = '\0';
                if (type == 0) {
                    type++;
                    count = 0;
                    itemArray[itemNum].setItemId(buffer);
                } else if (type == 1) {
                    type++;
                    count = 0;
                    itemArray[itemNum].setDescription(buffer);
                } else if (type == 2) {
                    type++;
                    count = 0;
                    itemArray[itemNum].setManCost(buffer);
                } else {
                    type = 0;
                    count = 0;
                    itemArray[itemNum].setSellPrice(buffer);
                    itemNum++;
                }
            }
            else {
                count++;
            }
        }
        priceSort(itemArray, itemNum);
        sortAndPrint(itemArray);
    }

    //closes file and deallocates memory
    inputFile.close();
    delete[] itemArray;
}

*/

