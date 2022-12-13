#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 50
#define ITEMS_NUM 10

struct item {
	char code[4];
	char name[20];
	int price;
	int discount;
};

struct receipt_item {
	char code[4];
	char name[20];

	int price;
	int price_r;
	int quant;
	int discount_r;
	int cost_r;
};

int get_info(char c[4], struct item items[ITEMS_NUM], struct receipt_item receipt[ITEMS_NUM]) {
	float cost;
	for (int i=0; i < ITEMS_NUM; i++) {
		if ((items[i].code[0] == c[0]) && (items[i].code[1] == c[1]) && (items[i].code[2] == c[2]) && (items[i].code[3] == c[3])) {
			cost = items[i].price - items[i].price * ((float)items[i].discount / 100);
			printf("%s | price: %d rubl | discount: %d percent | overall cost : %d\n", items[i].name, items[i].price, items[i].discount, (int)cost);

			if (receipt[i].quant == 0) {
				strcpy(receipt[i].code, c);
				strcpy(receipt[i].name, items[i].name);
				receipt[i].price = items[i].price;
				receipt[i].quant = 1;
				receipt[i].discount_r = items[i].price - (int)cost;
				receipt[i].cost_r = (int)cost;
			}
			else {
				receipt[i].quant++;
				receipt[i].cost_r += (int)cost;
			}

			return 0;
		}
	}
	printf("There's no item with this code\n");
}

int get_receipt(struct receipt_item receipt[ITEMS_NUM]) {
	int pre_sum = 0;
	int disc = 0;
	int sum = 0;
	for (int i = 0; i < ITEMS_NUM; i++) {
		if (receipt[i].quant!=0) {
			printf("%21s | %4d rub per one | %2d pcs. | = %3d rub\n", receipt[i].name, receipt[i].price, receipt[i].quant, receipt[i].cost_r);
			pre_sum += receipt[i].price * receipt[i].quant;
			disc += receipt[i].price * receipt[i].quant - receipt[i].cost_r;
			sum += receipt[i].cost_r;
		}
	}
	printf("     --------------------------------------------------------------\n");
	printf("         Price:  %4d |  Discount:  %4d |    =>   | Total:  %d rub \n", pre_sum, disc, sum);
}

int main() {
	char code[5];
	struct receipt_item receipt[ITEMS_NUM];
	struct item menu[ITEMS_NUM] = { "1111", "Baton", 40, 10,
									"1112", "Rye bread", 23, 10,
									"1113", "Borodinskiy bread", 50, 15,
									"1114", "Curd", 33, 20,
									"1115", "Dumpling", 25, 5,
									"1116", "Bagel", 42, 15,
									"1117", "Shallow dumpling", 8, 20,
									"1118", "Crumbs", 12, 5,
									"1119", "Bread in dough", 450, 50,
									"1121", "Baguette", 90, 35 };
	for (int i = 0; i < ITEMS_NUM; i++) {
		receipt[i].quant = 0;
	}


	printf("<< Welcome to our store >>\n");
	printf("(Type 4 numbers to get an item in your cart and type '=' to check out)\n");
	while (1) {
		scanf("%s", &code);
		if (code[0] != '=') {
			get_info(code, menu, receipt);
		}
		else {
			get_receipt(receipt);
			return 0;
		}
	}
	printf("<< Come again >>\n");
}