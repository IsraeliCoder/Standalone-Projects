#include "UserCredential.h"

#include <stdlib.h>
#include <string.h>

#include "Hashing.h"

UserCredential* CreateUserCredential(char* user, char* password)
{
	UserCredential* toReturn = (UserCredential*)malloc(sizeof(UserCredential));
	toReturn->userName = (char*)malloc(sizeof(char) * MAX_STRING);
	strcpy_s(toReturn->userName, MAX_STRING, user);
	toReturn->password = hashing(password);
	return toReturn;
}

void FreeUserCredential(UserCredential* userCredential)
{
	free(userCredential->userName);
	free(userCredential);
}
