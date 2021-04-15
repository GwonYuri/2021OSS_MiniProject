#include <stdio.h>
#include "manager.h"

//#define DEBUG

int main(){ 
    Product plist[10000];
    int count = 0, index = 0, menu;
    count = loadData(plist);
    index = count;

#ifdef DEBUG 
    printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);

#endif
    while(1){
        menu = selectMenu();
        if(menu == 0) break;
        if(menu == 1 || menu ==3 || menu == 4)
            if(count == 0) continue;
        if(menu == 1) {
            if (count > 0) listProduct(plist, index);
        }
        else if(menu == 2) {
            count += createProduct(&plist[index++]);
        } 
        else if(menu == 3) {
            int no = selectDataNo(plist, index);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateProduct(&plist[no-1]);
        }
        else if(menu == 4){
            int no = selectDataNo(plist, index);
            if(no > 0){
                int deleteok;
                printf("정말로 삭제하시겠습니까?(삭제:1)");
                scanf("%d", &deleteok);
                if(deleteok == 1){
                    deleteProduct(&plist[no-1]);
                    count--;
                }
            } 
        }
	else if(menu == 5){
            saveData(plist, index);
        }
        else if(menu == 6){
            searchName(plist,index);
        }
        else if(menu == 7){
            searchPrice(plist, index);
        }
        else if(menu == 8){
            searchGrade(plist, index);
        }
    }
    printf("종료됨!\n");
    return 0;
}
