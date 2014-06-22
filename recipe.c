#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_RECIPE_LETTERS 256

// レシピを標準出力する関数
// 指定IDが存在しないとき，何も出力されない
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

// ユーザー名を標準出力する関数
void print_user_name(char user[]) {
	printf("ユーザー名: %s\n", user);
}
int check_user_name(char user[]) {
	// ユーザー名が長すぎる場合は偽の値を返す
	if(strlen(user) > 10) {
		return 0;
	}
	return 1;
}


int main(int argc, char *argv[]){
    FILE *recipe_fp;
    char recipe_string[256];
	char user_name[10];
	int received_recipe_id = 0;

    recipe_fp = fopen("./recipe-data.txt", "r");
    if(recipe_fp == NULL) {
        puts("file open error.");
        exit(EXIT_FAILURE);
    }

	// ユーザー名を標準入力
	printf("input user name: ");
	scanf("%s", user_name);

	// ユーザー名が正しいかチェック
	if(check_user_name(user_name)) {
		// 正しければ何もしない
	} else {
		printf("Invalid User Name\n");
		return 1;
	}

	// IDを指定されたとき
	if(argc > 1) {
		received_recipe_id = atoi(argv[1]);
		print_user_name(user_name);
		print_recipes(recipe_string, recipe_fp, received_recipe_id);
	}
	// IDが指定されなかったとき
	else {
		print_user_name(user_name);
		print_recipes(recipe_string, recipe_fp, received_recipe_id);
    }

    fclose(recipe_fp);
    return 0;
}
