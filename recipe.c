#include<stdio.h>
#include<stdlib.h>
#define MAX_RECIPE_LETTERS 256

// レシピを標準出力する関数
void print_recipes(char recipes[], FILE *recipe_fp, int target_id) {
    int id = 1; // レシピのID

    while(fgets(recipes, MAX_RECIPE_LETTERS, recipe_fp) != NULL) {
		// 指定IDのみ標準出力
		if(id == target_id) {
       	    printf("%d: ", id);
           	printf("%s", recipes);
	    } 
		// 指定ID以外を標準出力
		else if(target_id == 0 && id != target_id) {
       	    printf("%d: ", id);
           	printf("%s", recipes);
		}
		id++;
	}
}

int main(int argc, char *argv[]){
    FILE *recipe_fp;
    char recipe_string[256];
	int received_recipe_id = 0;

    recipe_fp = fopen("./recipe-data.txt", "r");
    if(recipe_fp == NULL) {
        puts("file open error.");
        exit(EXIT_FAILURE);
    }

	// IDを指定されたとき
	if(argc > 1) {
		received_recipe_id = atoi(argv[1]);
		print_recipes(recipe_string, recipe_fp, received_recipe_id);
	}
	// IDが指定されなかったとき
	else {
		print_recipes(recipe_string, recipe_fp, received_recipe_id);
    }

    fclose(recipe_fp);
    return 0;
}
