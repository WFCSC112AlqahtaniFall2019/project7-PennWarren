#include <iostream>
#include <sstream>
#include <vector>
#include "Data.h"
#include "Stack.h"
#include "Queue.h"
#include "SortedLinkedList.h"

using namespace std;

int main() {
    //stream files
    ifstream spreadsheet;
    ofstream stackFile;
    ofstream queueFile;
    ofstream sortFile;


    //parsing data
    cout << "Reading dataset..." << endl;
    spreadsheet.open("../TreasuryYieldsData.csv");
    if(!spreadsheet.is_open()){
        cout << "Could not open file." << endl;
    }

    //declare three lists
    Stack stackedYields;
    Queue queuedYields;
    SortedLinkedList sortedYields;

    while(!spreadsheet.eof()){
        //put each line into a stringstream for parsing
        string line;
        getline(spreadsheet, line);
        stringstream s(line);

        //parse data into string variables
        string tempDate, strThreeMonth, strTwoYear, strTenYear;
        getline(s, tempDate, ',');
        getline(s, strThreeMonth, ',');
        getline(s, strTwoYear, ',');
        getline(s,strTenYear,',');

        //convert variables to correct type and create a temp Data object to add to each list
        Data temp(tempDate, stod(strThreeMonth), stod(strTwoYear), stod(strTenYear));
        stackedYields.push_head(temp);
        queuedYields.enqueue_tail(temp);
        sortedYields.insertSorted(temp);
    }
    spreadsheet.close();


    //Write to stackFile
    cout << "Writing data inserted at head into stacked.txt" << endl;
    stackFile.open("../stacked.txt");
    //code for stack
    do{
        stackedYields.print(stackFile);
    }while(stackedYields.pop_head());
    stackFile.close();

    //Write to queueFile
    cout << "Writing data inserted at tail into queued.txt" << endl;
    queueFile.open("../queued.txt");
    do{
        queuedYields.print(queueFile);
    }while(queuedYields.dequeue_head());
    queueFile.close();

    //Write to sortFile
    cout << "Writing data sorted by the 10-year 3-month spread (most negative first) into sorted.txt" << endl;
    sortFile.open("../sorted.txt");
    sortedYields.print(sortFile);
    sortFile.close();

    return 0;


}