/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   filesystem.h
 * Author: perlesvaus
 *
 * Created on 29 / de maig / 2017, 20:25
 */

#ifndef MAZFILESYSTEM_H
#define MAZFILESYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

bool is_file(const char* path);
bool is_dir(const char* path);
void scandir(char* path);
char* file_get_contents(char* path);
int file_put_contents(char* path, char* contents);
int filesize(char* filename);


#ifdef __cplusplus
}
#endif

#endif /* MAZFILESYSTEM_H */

