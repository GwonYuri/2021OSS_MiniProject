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

void saveData(Product *p, int product_count){
  FILE *fp;
  fp = fopen("product.txt", "wt");

  for(int i=0; i<product_count; i++){
    if(p[i].gram == -1) continue;
      fprintf(fp, "%s %d %d %d %d\n", p[i].name, p[i].gram, p[i].price, p[i].grade, p[i].grading_count);
  }
  fclose(fp);
  printf("=> 데이터가 저장됨!\n");
}

int loadData(Product *p){
  int i = 0;
    FILE *fp;
    fp = fopen("product.txt","rt");

    if(fp == NULL) {
      printf("=> 파일 없음\n");
      return 0;
    }

    for(; i<10000; i++){
        fscanf(fp, "%s",p[i].name);
        if(feof(fp)) break;
        fscanf(fp, "%d", &p[i].gram);
        fscanf(fp, "%d", &p[i].price);
        fscanf(fp, "%d", &p[i].grade);
        fscanf(fp, "%d", &p[i].grading_count);
    }
    fclose(fp);
    printf("=> 로딩 성공!\n");
    return i;
}

void searchName(Product *p, int product_count){
  int scnt = 0;
  char search[20];
    
  printf("검색할 제품명은? ");
  scanf("%s", search);

  printf("\nNo|      Name      | gram|  price| grade| grading_count\n");
  printf("========================================================\n");
  for(int i=0; i<product_count; i++){
    if(p[i].gram == -1) continue;
    if(strstr(p[i].name, search)){
      printf("%2d ", i+1);
      readProduct(p[i]);
      scnt++;
    }
  }
  if(scnt == 0) printf("=> 해당 과일은 판매하지 않습니다!");
  printf("\n");
} // 사용자가 원하는 상품(명)이 해당 쇼핑몰에 있는지 검색하는 함수
