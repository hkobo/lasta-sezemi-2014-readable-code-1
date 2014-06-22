#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE *recipe_fp;

    recipe_fp = fopen("./recipe-data.txt", "r");
    if(recipe_fp == NULL) {
        puts("file open error.");
        exit(EXIT_FAILURE);
    } else {
        puts("file has been opened.");
    }

    return 0;
}
