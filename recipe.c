#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE *recipe_fp;
    char recipe_string[256];

    recipe_fp = fopen("./recipe-data.txt", "r");
    if(recipe_fp == NULL) {
        puts("file open error.");
        exit(EXIT_FAILURE);
    }

    int id = 1; // レシピのID
    while(fgets(recipe_string, sizeof(recipe_string), recipe_fp) != NULL) {
        printf("%d: ", id++);
        printf("%s", recipe_string);
    }

    fclose(recipe_fp);
    return 0;
}
