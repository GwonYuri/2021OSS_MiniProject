#ifndef _MANAGER_H

#define _MANAGER_H
#include "product.h" 
int selectMenu(); 
int selectDataNo(Product p[], int product_count);
void saveData(Product *p, int product_count);
int loadData(Product *p);

#endif
