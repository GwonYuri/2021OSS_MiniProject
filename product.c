#include <stdio.h>
#include "product.h" 

int createProduct(Product *p){
  printf("제품명은? ");
  scanf(" %[^\n]s", p->name);
  printf("제품 무게(gram)는? ");
  scanf("%d", &p->gram);
  printf("제품 가격은? ");
  scanf("%d", &p->price);
  printf("제품 별점은?(1~5) ");
  scanf("%d", &p->grade);
  printf("제품 별점개수는? ");
  scanf("%d", &p->grading_count);
  printf("=> 제품이 추가됨!\n");
  return 1;
}

void readProduct(Product p){
  printf("%16s %6d %6d %6d %13d\n",
    p.name, p.gram, p.price, p.grade, p.grading_count);
}
 
void listProduct(Product *p, int product_count){
  int i = 0;
  printf("\nNo|      Name      | gram|  price| grade| grading_count\n");
  printf("========================================================\n");
  for(i= 0; i < product_count; i++){
    if(p[i].gram == -1) continue;
    printf("%2d ", i+1);
    readProduct(p[i]);
  }
}

int updateProduct(Product *p){
    printf("업데이트할 제품명은? ");
    scanf(" %[^\n]s", p->name);
    printf("제품 무게(gram)는? ");
    scanf("%d", &p->gram);
    printf("제품 가격은? ");
    scanf("%d", &p->price);
    printf("제품 별점은?(1~5) ");
    scanf("%d", &p->grade);
    printf("제품 별점개수는? ");
    scanf("%d", &p->grading_count);
    printf("=> 제품이 업데이트됨!\n");
    return 1;
}

int deleteProduct(Product *p){
  p->gram = -1;
  p->price = -1;
  p->grade = -1;
  p->grading_count = -1;
  printf("=> 제품이 삭제됨!\n");
  return 1;
}
