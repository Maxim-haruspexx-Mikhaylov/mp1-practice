#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 10
int main() {
	short nums[n];
	short length;
	char check;
	srand((unsigned int)time(NULL));

	do {
		printf("Insert number length (2-5) \n");
		scanf("%hd", &length);
	} while (length < 2 || length > 5);

	for (short i = 0; i < length; i++) {
		do {
			nums[i] = rand() % 10;
			check = '0';
			if (nums[0] == 0) check = '1';
			else {
				for (short j = 0; j < i; j++) {
					if (nums[j] == nums[i]) {
						check = '1';
						break;
					}
				}
			}
		} while (check != '0');
	}

	for (short i = 0; i < length; i++) {
		printf("%hd", nums[i]);
	}
}