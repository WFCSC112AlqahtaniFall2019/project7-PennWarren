#include <iostream>
#include "Data.h"
#include "Stack.h"
#include "Queue.h"
#include "SortedLinkedList.h"

using namespace std;

int main() {
    ifstream spreadsheet;
    ofstream stack;
    ofstream queue;
    ofstream sort;

    cout << "Reading dataset..." << endl;
    spreadsheet.open("../TreasuryYieldsData.csv");
    if(!spreadsheet.is_open()){
        cout << "Could not open file." << endl;
    }
    //code for parsing data
    spreadsheet.close();

    cout << "Writing data inserted at head into stacked.txt" << endl;
    stack.open("../stacked.txt");
    //code for stack
    stack.close();

    cout << "Writing data inserted at tail into queued.txt" << endl;
    queue.open("../queued.txt");
    //code for queue
    queue.close();

    cout << "Writing data sorted by the 10-year 3-month spread into sorted.txt" << endl;
    sort.open("../sorted.txt");
    //code for sort
    sort.close();

    return 0;


}