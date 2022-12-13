#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 100
#define ITEMS_NUM 10

struct item {
	char code[4];
	char name[20];
	int price;
	int discount;

};

void get_menu_from_file() {
	/*FILE* data_file;
	char str[LEN];
	struct item items[ITEMS_NUM];

	data_file = fopen("data.txt", "r");
	for (int i = 0; i < ITEMS_NUM; i++) {
		int cur_code[4];
		char cur_name[20];
		char cur_price[4];
		char cur_discount[2];
		int j = 0;

		fgets(str, LEN, data_file);
		printf("%s%d", str, i);

		while (str[j] != '|') {
			cur_code[j] = (int)str[j];
			j++;
		}

		j++;

		while (str[j] != '|') {
			cur_name[j] = str[j];
			j++;
		};

		j++;

		while (str[j] != '|') {
			cur_price[j] = str[j];
			j++;
		};

		j++;

		while (str[j] != '|') {
			cur_discount[j] = str[j];
			j++;
		};

		for (int k = 0; k < 4; k++) {
			items[i].code[k] = cur_code[k];
		}

		for (int l = 0; l < 20; l++) {
			items[i].name[l] = cur_name[l];
		}

		items[i].price = (int)atof(cur_price);
		items[i].discount = (int)atof(cur_discount);
	}


	fclose(data_file);*/
}

void menu_init() {
	char str[LEN];
	struct item items[ITEMS_NUM] = { "1111", "Baton", 40, 10,
									 "1112", "Rye bread", 23, 10,
									 "1113", "Borodinskiy bread", 50, 15,
									 "1114", "Curd", 33, 20,
									 "1115", "Dumpling", 25, 5,
									 "1116", "Bagel", 42, 15,
									 "1117", "Shallow dumpling", 8, 20,
									 "1118", "Crumbs", 12, 5,
									 "1119", "Bread in dough", 450, 50,
									 "1121", "Baguette", 90, 35};

}


int main() {
	menu_init();
	return 0;

}