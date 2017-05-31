/* dll.h */
#ifndef __DLL_H__
#define __DLL_H__

#define DLL_EXPORT __declspec(dllexport)

    char * DLL_EXPORT hello(char * user); // returns a string "Hello USER!";
    void DLL_EXPORT helloworld(); //prints out a "Hello World"

#endif // __DLL_H__

