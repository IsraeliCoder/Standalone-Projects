

#include <stdio.h>
#include <stdlib.h>

#include "UserCredential.h"
#include "KeyManager.h"

void main()
{

	char userName[MAX_STRING];
	char password[MAX_STRING];

	printf("Welcome to our Key Managment System\n");

	printf("Please insert your UserName:\n");
	scanf_s("%s", userName, sizeof(userName));
	printf("Please insert your Password:\n");
	scanf_s("%s", password, sizeof(password));

	// Create User Credential


}

