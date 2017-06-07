/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: perlesvaus
 *
 * Created on 1 / de juny / 2017, 16:30
 */

#include <stdio.h>
#include <stdlib.h>

#include "mazfilesystem.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    //char folder[] = "C:/Intel";
    //scandir(folder);
    
    //char path[] = "C:/Intel/test.txt", contents[] = "El meu contingut lalala...";
    //file_put_contents(path, contents);
    
    char path[] = "C:/Intel/test.txt";
    printf("contents: %s.\n", file_get_contents(path));
    
    //char path[] = "C:/Intel/test.txt";
    //printf("size: %d.\n", filesize(path));
    
    return 0;
}

