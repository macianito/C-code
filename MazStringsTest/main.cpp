/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: perlesvaus
 *
 * Created on 1 / de juny / 2017, 15:39
 */

#include <cstdlib>
#include <cstdio>

#include "mazstrings.h"


/*
 * 
 */
int main(int argc, char** argv) {
    
    //char* straux;
    //straux = concat_strings(3, "str1rr", "str2", "str3g");
    //printf("%s", straux);
    
    char** straux;
    int arrlen, i;
    char strexplode[] = "Aquesta es string a partir";
    straux = explode(' ', strexplode);
    /*arrlen = array_strings_size(straux);
    //printf("%s", straux);
     */
    //for (i = 0; i < arrlen; i++) {
    //  printf("%s", straux[i]);
    //}
    
    return 0;
}

