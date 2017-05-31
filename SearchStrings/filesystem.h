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

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

bool is_file(const char* path);
bool is_dir(const char* path);


#ifdef __cplusplus
}
#endif

#endif /* FILESYSTEM_H */

