#include <iostream>
#include "Date.h"
#include <fstream>
#include "Product.h"
#include "Shop.h"
#include "Time.h"

int main()
{
    /*Date d1;
    Date d2(2000, 1, 1);
    Date d3(2024, 2, 28);*/

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
    /*cout << d1 << " " << d2 << " " << d3 << endl;
    cout << d1++ << " " << d2++ << " " << d3++ << endl;
    cout << ++d1 << " " << ++d2 << " " << ++d3 << endl;
    cout << "/==================================================\n";
    cout << d1 + 5<<" "<<5+d1 << endl;
    cout << d1 - 5<<" "<<5-d1 << endl;


    ofstream file("test.txt");
    if (file.is_open()) {
        file << d1 << " " << d2 << " " << d3 << endl;
        file.close();
    }*/

    /*Product p1;
    cin >> p1;
    cout << "<================================>";
    cout << endl << p1;*/

    /*Shop posad;
    posad.addProduct(Product("cheesecake", 200, Date(), 3));
    posad.showInfo();
    cout << "=======================================\n";
    posad.updateDiscountProducts();
    cout << posad["cheesecake"];
    cout << "=======================================\n";
    float sum = posad.calcExpiredProducts();
    cout << "Sum: " << sum << ".\n";
    cout << "=======================================\n";
    posad.delExpiredProducts();*/

        Time_ t1(14, 30, 45, true);
        Time_ t2(2, 30, 45, false);

        t1.showTime();
        t2.showTime();

        cout << "=======adding 80 seconds=======" << endl;
        t1 += 80;
        t1.showTime();

        cout << "=======adding 1.5 minutes=======" << endl;
        t2 += 1.5f;
        t2.showTime();

        t1.tickTime();
        t1.showTime();

        if (t1 > t2) {
            cout << "t1 > t2\n";
        }
        else {
            cout << "t1 < t2\n";
        }

        return 0;
}
