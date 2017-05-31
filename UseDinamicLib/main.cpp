/* main.c */
#include <stdio.h>
#include <windows.h>

typedef char * (*HelloFunction)(char*);
typedef void (*HelloWorldFunction)();

int main(int argc, char *argv[])
{

   HINSTANCE hinstDLL;
   hinstDLL = LoadLibrary("C:/NetBeansProjects/DLL/dist/Release/MinGW-Windows/libDLL.dll");
 
   if(hinstDLL != 0)
   {
      HelloFunction hello;
      HelloWorldFunction helloworld;
      hello = (HelloFunction) GetProcAddress(hinstDLL, "hello");
      helloworld = (HelloWorldFunction) GetProcAddress(hinstDLL, "helloworld");
 
      printf("%s\n", hello("carr3r"));
      helloworld();
 
      FreeLibrary(hinstDLL);
   }
   else
      printf("It was not possible to load DLL. Error #%d", GetLastError());

   return 0;
}