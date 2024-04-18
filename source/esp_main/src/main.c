#include <stdio.h>

int main(int argc, char* argv[]) 
{
	int res = 0;
	// Open the JSON file
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL){
		fprintf(stderr, "Error opening JSON file\n");
		return 1;
	}

	// Create a buffer to store the JSON data
	char buffer[1024];
	size_t bytes_read = fread(buffer, 1, sizeof(buffer), fp);
	if (bytes_read == 0) {
		fprintf(stderr, "Error reading JSON file\n");
		fclose(fp);
		return 1;
	}

	// Close the JSON file
	fclose(fp);

	return 0;
}

