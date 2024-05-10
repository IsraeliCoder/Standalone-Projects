
#ifndef __USER_CREDENTIAL_H
#define __USER_CREDENTIAL_H

#define MAX_STRING 30

typedef struct userCredential
{
	char* userName;
	int password;
} UserCredential;

UserCredential* CreateUserCredential(char* user, char* password);
void FreeUserCredential(UserCredential* userCredential);

#endif