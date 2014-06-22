#include<stdio.h>
#include<stdlib.h>
#define MAX_DATA_SIZE 256

int count_lines(FILE *fp){
    int lines = 0;   // 行数
    char c;      // 改行判定用の文字
    while((c = getc(fp)) != EOF) {
        if(c == '\n') lines++;
    }
    return lines;
}


int main(int argc, char **argv){
    FILE *recipe_fp;
    char recipe_name[MAX_DATA_SIZE]; // 各行
    int selected_recipe_id;

    if(argc == 0) {
        puts("レシピのIDを入力してください");
        scanf("%d", &selected_recipe_id);
    } else {
        selected_recipe_id = atoi(argv[0]);
    }

    recipe_fp = fopen("./recipe-data.txt", "r");
    if(recipe_fp == NULL) {
        puts("file open error.");
        exit(EXIT_FAILURE);
    }

    int num_recipes = count_lines(recipe_fp); // レシピの個数
    char recipes[num_recipes][MAX_DATA_SIZE]; // 各レシピ
    int id = 0; // レシピのID
    while(fgets(recipe_name, sizeof(recipe_name), recipe_fp) != NULL) {
        recipes[id] = recipe_name;
        id++;
        // printf("%d: ", id++);
        // printf("%s", recipe_string);
    }
    printf("レシピファイルの行数 = %d\n", num_recipes);



    fclose(recipe_fp);
    return 0;
}
