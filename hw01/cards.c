/*
cards is a card counting program. Based on user input, it increments
and decrements a count variable to keep track of the highs and lows
left in the deck.
-mike warner
*/

#include <stdio.h>
#include <stdlib.h>

/*
getVal takes the user input and extracts its integer value.

full_face: user input string
*/

int getVal(char full_face[]) {
	
	char face = full_face[0];
	int val = 0;
	
	if (face == 'K' ||  face == 'Q' || face == 'J') 
		val = 10;
	else if (face == 'A')
		val = 11;
	else if (face == 'X')
		val = -1;
	else {
		val = atoi(full_face);
		if ((val < 1) || (val > 10)) {
			puts("I don't understand that value");
			val = -1;
		}
	}
	return val;
}

/*
countIt performs the card counting functions by checking their values 
and modifying the count as necessary.
value: integer value of card
count: tracker of highs and lows in deck
*/

int countIt(int value, int count) {
		
	if ((value > 2) && (value < 7)) 
		count++;
	else if (value == 10)
		count--;
	printf("Current count: %i\n", count);
	return count;

}
/*
main function contains a while loop, terminated only by input of X.
Has a count variable that keeps track of highs and lows left in deck.
card_name: user input string
count: tracker of highs and lows in deck
*/

int main() {
	char card_name[3];
	int count = 0;

	while (card_name[0] != 'X') {
		puts("enter the card name");
		scanf("%2s", card_name);

		int num = getVal(card_name);
		if (num != -1) count = countIt(num, count);
	}
	return 0;
}
	 



 
