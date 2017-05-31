/* dllmain.c */
#include "dll.h"
#include <windows.h>


char * DLL_EXPORT hello(char * user) // // returns a string "Hello USER!";
{
	char * greeting = malloc( strlen(user) + 7); // + "Hello!" characters
	sprintf(greeting, "Hello %s!", user);
	return greeting;
}

void DLL_EXPORT helloworld()
{
	printf("Hello World\n");
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
	switch(fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			break;
		}
		case DLL_THREAD_ATTACH:
		{
			break;
		}
		case DLL_THREAD_DETACH:
		{
			break;
		}
	}
	
	/* Return TRUE on success, FALSE on failure */
	return TRUE;
}

