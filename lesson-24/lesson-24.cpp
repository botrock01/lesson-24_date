#include <iostream>
#include "Date.h"
#include <fstream>

int main()
{
    Date d1;
    Date d2(2000, 1, 1);
    Date d3(2024, 2, 28);

    /*d2.prevDate();
    d3.nextDate();

    d1.showDate();
    d2.showDate();
    d3.showDate();

    cout << "--------------------" << endl;
    cout << (d2 < d3) << endl;
    cout << (d2 > d3) << endl;
    cout << (d2 <= d3) << endl;
    cout << (d2 >= d3) << endl;
    cout << (d2 == d3) << endl;
    cout << (d2 != d3) << endl;
    cout << "--------------------" << endl;

    d1.showDate();
    cout << "+217 days=";
    d1 += 217;
    d1.showDate();

    cout << "--------------------" << endl;
    d1.showDate();
    cout << "-115 days=";
    d1 -= 115;
    d1.showDate();

    cout << "--------------------" << endl;
    d1.showDate();
    cout << "+15 months=";
    d1 += 15.0f;
    d1.showDate();*/
    cout << d1 << " " << d2 << " " << d3 << endl;
    cout << d1++ << " " << d2++ << " " << d3++ << endl;
    cout << ++d1 << " " << ++d2 << " " << ++d3 << endl;
    cout << "/==================================================\n";
    cout << d1 + 5<<" "<<5+d1 << endl;
    cout << d1 - 5<<" "<<5-d1 << endl;


    ofstream file("test.txt");
    if (file.is_open()) {
        file << d1 << " " << d2 << " " << d3 << endl;
        file.close();
    }
}
