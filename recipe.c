#include<stdio.h>
#include<stdlib.h>

int count_lines(FILE *fp){
    int lines;   // 行数
    char c;      // 改行判定用の文字
    while((c = getc(fp)) != EOF) {
        if(c == '\n') lines++;
    }
    return 0;
}


int main(void){
    FILE *recipe_fp;
    char recipe_string[256];

    recipe_fp = fopen("./recipe-data.txt", "r");
    if(recipe_fp == NULL) {
        puts("file open error.");
        exit(EXIT_FAILURE);
    }
    int lines = count_lines(recipe_fp);
    printf("レシピファイルの行数 = %d\n", lines);

    // int id = 1; // レシピのID
    // while(fgets(recipe_string, sizeof(recipe_string), recipe_fp) != NULL) {
    //     printf("%d: ", id++);
    //     printf("%s", recipe_string);
    // }


    fclose(recipe_fp);
    return 0;
}
