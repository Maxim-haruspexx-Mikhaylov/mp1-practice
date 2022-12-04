#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 10
#define NUM 10

struct item {
	int code[4];
	char name[20];
	int price;
	int discount;

};

void menu_init() {
	char str[LEN]; 
	struct item items[10];
	FILE *data_file;
	data_file = fopen("data.txt", "r");
	fgets(str, LEN, data_file);
	for (int i = 1; i < 100; i++) {
		printf(str[i]);
	}
}


int main() {
	menu_init();
	return 0;

}