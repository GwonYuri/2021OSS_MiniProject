#ifndef _PRODUCT_H

#define _PRODUCT_H
typedef struct {
  char name[40]; // 제품명 변수
  int gram; // 중량 변수
  int price; // 가격 변수
  int grade; // 별점 변수 
  int grading_count; // 별점개수 변수
} Product; 

int createProduct(Product *p); // 상품(정보)을 추가하는 함수
void readProduct(Product p); // 상품의 정보를 출력하는 함수
void listProduct(Product *p, int product_count); // 전체 상품 목록을 보여주는 함수
int updateProduct(Product *p); // 상품 정보를 수정해주는 함수
int deleteProduct(Product *p); // 상품을 삭제하는 함수 

#endif
