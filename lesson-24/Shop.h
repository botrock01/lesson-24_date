#pragma once
#include<vector>
#include <stdio.h>
#include "Product.h"
class Shop {
	vector<Product> arr;
public:
	Shop();
	~Shop();

	Product operator[](string title);
	Product& operator[](int n);

	void addProduct(Product p);
	float calcExpiredProducts() const;
	void updateDiscountProducts();
	void delExpiredProducts();

	void showInfo()const;
};
