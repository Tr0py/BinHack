#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void go_shell() {
	printf("Login success!\n");
	system("/bin/sh");
}

int authorize() {
	char check[64];
	char password[64];
	FILE *file;
	file = fopen("password", "r");
	fgets(check, 30, file);
	check[strlen(check)-1] = '\0';
	printf("Enter Password: \n");
	gets(password);
	password[63] = '\0';
	if (!strcmp(password, check))
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
