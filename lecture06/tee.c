#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	char ch;
	char *filename = "";

	while ((ch = getopt(argc, argv, "a:i")) !=EOF) {

		if (ch == 'a') {
			filename = optarg;
			printf("argument a\n");
		}
		else if (ch == 'i') {
			printf("ignoring argument i\n");
		}
		//argc -= optind;
		//argv += optind;
	}
	
	printf("filename: %s\n",filename);

	

	return 0;
}

	
