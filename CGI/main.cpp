/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: perlesvaus
 *
 * Created on 24 / de maig / 2017, 20:17
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    char *data;
    
    printf("Content-type: text/html;charset=utf-8\n\n"); // S'ha d'enviar aquesta capçalera
    
    data = getenv("QUERY_STRING");
    
    printf("Hello CGI");
    
    printf("<br><br>");
    
    printf("%s <br><br>", data);
    
    printf("Press Any Key to Continue\n");  
    //getchar(); 

    return 0;
}

