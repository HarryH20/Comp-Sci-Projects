/**
 * file: proj4-testmain.cpp
 * author: Harrison Hassler
 * course: CSI 1440
 * assignment: project 4
 * due date: 2/27/2023
 *
 * date modified:  2/26/2023
 *    - file created
 *    - functions tested
 *
 * date modified:  2/26/2023
 *    - main was created
 */



#include "proj4-ItemInfo.hpp"
#include <iostream>
using namespace std;
int main() {
//testing setDescription
//testing printCstring
//testing getDescription
//testing stuCstrLen
    ItemInfo itemArray1;
    itemArray1.setDescription("HelloWorld\0");
    printCString(cout, "Should be HelloWorld\n\0");
    printCString(cout, "Testing: ");
    printCString(cout, itemArray1.getDescription());
    cout.put('\n');
    cout.put('\n');

    ItemInfo itemArray2;
    itemArray2.setDescription("Harrison Hassler\0");
    printCString(cout, "Should be Harrison Hassler\n\0");
    printCString(cout, "Testing: ");
    printCString(cout, itemArray2.getDescription());
    cout.put('\n');
    cout.put('\n');

    ItemInfo itemArray3;
    itemArray3.setDescription("3345677\0");
    printCString(cout, "Should be 3345677\n\0");
    printCString(cout, "Testing: ");
    printCString(cout, itemArray3.getDescription());
    cout.put('\n');
    cout.put('\n');

    ItemInfo itemArray4;
    itemArray4.setDescription("Kirby\0");
    printCString(cout, "Should be Kirby\n\0");
    printCString(cout, "Testing: ");
    printCString(cout, itemArray4.getDescription());
    cout.put('\n');
    cout.put('\n');

//testing setItemId
//testing getItemId
    itemArray1.setItemId("12345\0");
    printCString(cout, "Should be 12345\n\0");
    printCString(cout, "Testing: ");
    cout << itemArray1.getItemId();
    cout.put('\n');
    cout.put('\n');

    itemArray2.setItemId("54321\0");
    printCString(cout, "Should be 54321\n\0");
    printCString(cout, "Testing: ");
    cout << itemArray2.getItemId();
    cout.put('\n');
    cout.put('\n');

    itemArray3.setItemId("8878765\0");
    printCString(cout, "Should be 8878765\n\0");
    printCString(cout, "Testing: ");
    cout << itemArray3.getItemId();
    cout.put('\n');
    cout.put('\n');

    itemArray4.setItemId("123456789\0");
    printCString(cout, "Should be 123456789\n\0");
    printCString(cout, "Testing: ");
    cout << itemArray4.getItemId();
    cout.put('\n');
    cout.put('\n');

//testing setManCost
//testing getManCost
//testing stuCstrToDbl
    itemArray1.setManCost("17.89\0");
    printCString(cout, "Should be 17.89\n\0");
    printCString(cout, "Testing: ");
    cout << itemArray1.getManCost();
    cout.put('\n');
    cout.put('\n');

    itemArray2.setManCost("-17.89\0");
    printCString(cout, "Should be -17.89\n\0");
    printCString(cout, "Testing: ");
    cout << itemArray2.getManCost();
    cout.put('\n');
    cout.put('\n');

    itemArray3.setManCost("1000.9\0");
    printCString(cout, "Should be 1000.9\n\0");
    printCString(cout, "Testing: ");
    cout << itemArray3.getManCost();
    cout.put('\n');
    cout.put('\n');

    itemArray4.setManCost("0.9\0");
    printCString(cout, "Should be 0.9\n\0");
    printCString(cout, "Testing: ");
    cout << itemArray4.getManCost();
    cout.put('\n');
    cout.put('\n');

//testing getSellPrice
//testing setSellPrice
    itemArray1.setSellPrice("179.89\0");
    printCString(cout, "Should be 179.89\n\0");
    printCString(cout, "Testing: ");
    cout << itemArray1.getSellPrice();
    cout.put('\n');
    cout.put('\n');

    itemArray2.setSellPrice("1079.09\0");
    printCString(cout, "Should be 1079.09\n\0");
    printCString(cout, "Testing: ");
    cout << itemArray2.getSellPrice();
    cout.put('\n');
    cout.put('\n');

    itemArray3.setSellPrice("11234.9\0");
    printCString(cout, "Should be 11234.9\n\0");
    printCString(cout, "Testing: ");
    cout << itemArray3.getSellPrice();
    cout.put('\n');
    cout.put('\n');

    itemArray4.setSellPrice("-11234.9\0");
    printCString(cout, "Should be -11234.9\n\0");
    printCString(cout, "Testing: ");
    cout << itemArray4.getSellPrice();
    cout.put('\n');
    cout.put('\n');

//testing calcProfit
    printCString(cout, "Should be 162\n\0");
    printCString(cout, "Testing: ");
    cout << itemArray1.calcProfit();
    cout.put('\n');
    cout.put('\n');

    printCString(cout, "Should be 1096.98\n\0");
    printCString(cout, "Testing: ");
    cout << itemArray2.calcProfit();
    cout.put('\n');
    cout.put('\n');

    printCString(cout, "Should be 10234\n\0");
    printCString(cout, "Testing: ");
    cout << itemArray3.calcProfit();
    cout.put('\n');
    cout.put('\n');

    printCString(cout, "Should be -11235.8\n\0");
    printCString(cout, "Testing: ");
    cout << itemArray4.calcProfit();
    cout.put('\n');
    cout.put('\n');




//testing stuDblToCstr
    char *array1 = new char[20];
    stuDblToCstr(array1, 20);
    printCString(cout, "Should be 20");
    cout.put('\n');
    printCString(cout, "Testing: ");
    printCString(cout, array1);
    cout.put('\n');
    cout.put('\n');
    delete[] array1;

    char *array2 = new char[20];
    stuDblToCstr(array2, 2099);
    printCString(cout, "Should be 2099");
    cout.put('\n');
    printCString(cout, "Testing: ");
    printCString(cout, array2);
    cout.put('\n');
    cout.put('\n');
    delete[] array2;

    char *array3 = new char[20];
    stuDblToCstr(array3, 2099.88);
    printCString(cout, "Should be 2099.88");
    cout.put('\n');
    printCString(cout, "Testing: ");
    printCString(cout, array3);
    cout.put('\n');
    cout.put('\n');
    delete[] array3;

    char *array4 = new char[20];
    stuDblToCstr(array4, -89.98);
    printCString(cout, "Should be -89.98");
    cout.put('\n');
    printCString(cout, "Testing: ");
    printCString(cout, array4);
    cout.put('\n');
    cout.put('\n');
    delete[] array4;

//testing toAmazonJSON
//testing displayItemInfo
//testing stuCstrCpy
//prints itemArray1's info
    itemArray1.toAmazonJSON(cout);
    itemArray1.displayItemInfo(cout);
//prints itemArray2's info
    itemArray2.toAmazonJSON(cout);
    itemArray2.displayItemInfo(cout);
    return 0;
}


