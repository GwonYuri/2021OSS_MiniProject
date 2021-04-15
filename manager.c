#include <stdio.h> 
#include "manager.h"

int selectMenu(){
  int menu;
  printf("\n*** 과일 쇼핑몰 관리 프로그램 ***\n");
  printf("1. 조회\n");
  printf("2. 추가\n");
  printf("3. 수정\n");
  printf("4. 삭제\n");
  printf("5. 파일저장\n");
  printf("6. 제품명 검색\n");
  printf("7. 원하는 가격대의 제품 검색\n");
  printf("8. 원하는 별점대의 제품 검색\n");
  printf("0. 종료\n\n");
  printf("=> 원하는 메뉴는? ");
  scanf("%d", &menu);
  return menu;
}

int selectDataNo(Product p[], int product_count){
  int no;
  listProduct(p, product_count);
  printf("번호는? (취소:0)? ");
  scanf("%d", &no);
  return no;
}
