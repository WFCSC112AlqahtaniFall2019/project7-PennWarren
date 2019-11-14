//
// Created by Benjamin Raiford on 11/13/19.
//

#include "Data.h"
using namespace std;

//Default Constructor
Data::Data() {
    date = Day(-1,-1,-1);
    threeMonth = -1;
    twoYear = -1;
    tenYear = -1;
    setDerivedData();
}
//CSV constructor
Data::Data(std::string s, double threeMo, double twoYr, double tenYr) {
    date = Day(s);
    threeMonth = threeMo;
    twoYear = twoYr;
    tenYear = tenYr;
    setDerivedData();
}

//Output stream operator
ostream &operator<<(ostream &os, const Data &d) {
    os << d.date.outputDate() << endl;

    if(d.holiday){
        os << "This day is a holiday, no treasuries are issued on holidays" << endl;
    }
    else{
        os << "Three month constant maturity rate: " << d.threeMonth << endl;
        os << "Two year constant maturity rate: " << d.twoYear << endl;
        os << "Ten year constant maturity rate: " << d.tenYear << endl << endl;
        os << "Three month and ten year Spread: " << d.TenYr_ThreeMo_Spread << endl;
        os << "Two and ten spread: " << d.TenYr_TwoYr_Spread << endl << endl;
    }

    return os;
}
//Comparison operators sort based on the three month, ten year spread
bool Data::operator<(const Data &rhs) {
    return this->TenYr_ThreeMo_Spread < rhs.TenYr_ThreeMo_Spread;
}
bool Data::operator>(const Data &rhs) {
    return this->TenYr_ThreeMo_Spread > rhs.TenYr_ThreeMo_Spread;
}

//Set derived member variables for spreads and holiday
void Data::setDerivedData() {
    holiday = checkHoliday();
    TenYr_ThreeMo_Spread = tenYear - threeMonth;
    TenYr_TwoYr_Spread = tenYear - twoYear;
}
//Check if the date is a holiday
bool Data::checkHoliday() {
    return (threeMonth == 0 && twoYear == 0 && tenYear == 0);
}
//Prints data to screen
void Data::printDataScreen() {
    cout << date.outputDate() << endl;

    if(holiday){
        cout << "This day is a holiday, no treasuries are issued on holidays" << endl;
    }
    else{
        cout << "Three month constant maturity rate: " << threeMonth << endl;
        cout << "Two year constant maturity rate: " << twoYear << endl;
        cout << "Ten year constant maturity rate: " << tenYear << endl << endl;
        cout << "Three month and ten year Spread: " << TenYr_ThreeMo_Spread << endl;
        cout << "Two and ten spread: " << TenYr_TwoYr_Spread << endl << endl;
    }
}