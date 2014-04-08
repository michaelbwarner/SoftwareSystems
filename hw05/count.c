#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

/*count.c takes a text file and counts the number of instances each word occurs.
A word is defined by characters separated by a space. Each word and the number of instances
it appears in a file is printed at the end.
*/

//printInput is called to print each key value pair
void printInput(char *key, int value) {
	printf("Key: %s. Value %d\n", key, value);
}
//printTable takes a hash table and prints its contents
int printTable(GHashTable *table) {
	printf("contents\n");
	g_hash_table_foreach(table, (GHFunc) printInput, NULL);
}

int main (int argc, char** argv) {
	
	FILE *fp;
	fp = fopen("test", "r");
	char *word;
	int i = 0;
	int max = 100;
	word = (char*)malloc(max);
	int c;
	gpointer val;
	GHashTable* hash;
	hash =  g_hash_table_new(g_str_hash, g_str_equal);
	
	if (fp == NULL) { printf("file not read\n"); return 0; }
	
	/*main loop will loop until the end of the file
	iterates though file one character at a time until a space or EOF is reached
	at which point the word is stored in the hashtable
	*/
	while(1) {
		c = fgetc(fp);
		if (c == ' ' || c == EOF) {
			word[i] = '\0';
			i = 0;
			//printf("word: %s\n", word);
			val = g_hash_table_lookup(hash, word);
			gint gval = GPOINTER_TO_INT(val);
			char * temp;
			temp = g_strdup(word);
			if (val == NULL) {
				//first instance of word. value is 1
				int m = 1;
				g_hash_table_insert(hash, temp, GINT_TO_POINTER(m));
			}
			else {
				//word is already present, retrieve value, increment, and store
				int m = (int)gval + 1;
				g_hash_table_replace(hash, temp, GINT_TO_POINTER(m));
			}
			if (c == EOF) { break; }
		}
		else {
			//add character to active word and increment index of word array
			word[i] = (char)c;
			i++;
			if (i >= max) {
				printf("word is too long\n");
			}
		}
	}

	printTable(hash);
	fclose(fp);
	return 0;
}
