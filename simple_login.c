#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void go_shell() {
	printf("Login success! The secret is !@#$!\n");
	system("/bin/sh");
}

int authorize() {
	char password[64];
	char input[64];
	FILE *file;
	file = fopen("password", "r");
	fgets(password, 30, file);
	password[strlen(password)-1] = '\0';
	printf("Enter Password: \n");
	gets(input);
	input[63] = '\0';
	if (!strcmp(input, password))
		return 1;
	return 0;
}

int main() {
	if (authorize()) {
		go_shell();
	}
	else {
		printf("Wrong password!\n");
	}
	return 0;
}
