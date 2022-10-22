#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define n 10
int main() {
	short nums[n];
	short length, bulls, cows, try_count = 0, cur_num;
	int guess;
	char check, check2;
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
	printf("\n");

	printf("I chose the number. Try to guess it! (type '-1' for answer)\n");
	while (1) {
		check2 = '0';
		try_count++;
		bulls = 0;
		cows = 0;

		do {
			printf("What's your guess? \n");
			scanf("%d", &guess);
		} while (!((guess >= pow(10, length - 1) && guess <= pow(10, length) - 1) || guess == -1));

		if (guess == -1) {
			for (short i = 0; i < length; i++) {
				printf("%hd", nums[i]);
			}
			printf("\n");
			try_count--;
		}
		else {
			for (short i = length - 1; i >= 0; i--) {
				cur_num = guess % 10;
				if (cur_num == nums[i]) bulls++;
				else {
					check2 = '0';
					for (short i = 0; i < length; i++) {
						if (cur_num == nums[i]) {
							check2 = '1';
							break;
						}
					}
					if (check2 == '1') cows++;
				}
				guess /= 10;
			}
			if (bulls == length) {
				printf("You're right, mooooo! You've guessed the number in %hd tries. \n", try_count);
				break;
			}
			else {
				printf("No. Bulls - %hd. Cows - %hd. (Tries - %hd) \n", bulls, cows, try_count);
			}
		}
	}
}