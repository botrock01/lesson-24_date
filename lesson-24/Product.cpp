#include "Product.h"

Product::Product()
{
    title = "undefined";
    price = 0;
    termSave = 0;
}

Product::Product(string title, float price, Date madeDate, int termSave)
{
    this->title = title;
    this->price = price;
    this->madeDate = madeDate;
    this->termSave = termSave;
}

void Product::setTitle(string title)
{
    if (title.length() >= 2) {
        this->title = title;
    }
}

string Product::getTitle() const
{
    return this->title;
}

void Product::setPrice(float price)
{
    if (price >= 0) {
        this->price=price;
    }
}

float Product::getPrice() const
{
    return price;
}

int Product::getTerm() const
{
    return this->termSave;
}

Date Product::getmadeDate() const
{
    return this->madeDate;
}

bool Product::isExpired() const
{
    if(madeDate+termSave<=Date())
    return true;
    else { return false; }
}

ostream& operator<<(ostream& out, const Product& obj)
{
    out << "Title: " << obj.title << endl;
    out << "Price: " << obj.price << endl;
    out << "Date: " << obj.madeDate << endl;
    out << "Term: " << obj.termSave << endl;
    out << "Finish date: " << obj.termSave+obj.madeDate << endl;
    if (obj.isExpired()) {
        out << "EXPIRED PRODUCT!!!BE AWARE" << endl;
    }
    out << endl;
    return out;
}

istream& operator>>(istream& in, Product& obj)
{
    cout << "input title: ";
    getline(in, obj.title);
    cout << "Input price: ";
    in >> obj.price;
    cout << "Input production date: ";
    in >> obj.madeDate;
    cout << "Input expire date: ";
    in >> obj.termSave;
    return in;
}
