#include "Shop.h"


Shop::Shop() {
    arr.push_back(Product("apple", 50, Date(), 30));
    arr.push_back(Product("milk", 70, Date() - 20, 10));
    arr.push_back(Product("pie", 250, Date() - 10, 50));
}

Product Shop::operator[](string title) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].getTitle() == title) {
            return arr[i];
        }
    }
    return Product();
}

Product& Shop::operator[](int n) {
    return arr[n];
}

void Shop::addProduct(Product p) {
    arr.push_back(p);
}

float Shop::calcExpiredProducts() const {
    float sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].isExpired()) {
            sum += arr[i].getPrice();
        }
    }
    return sum;
}

void Shop::updateDiscountProducts() {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].getmadeDate() + arr[i].getTerm() <= Date() + 7) {
            arr[i].setPrice(arr[i].getPrice() * 0.75);
        }
    }
}

void Shop::delExpiredProducts() {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].isExpired()) {
            cout << "Expired: " << arr[i].getTitle() << endl;
            arr.erase(arr.begin() + i);
            i--;
        }
    }
}

void Shop::showInfo() const {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
    }
}