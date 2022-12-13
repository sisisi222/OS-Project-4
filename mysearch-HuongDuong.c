/* 
Name: Huong Duong
Project 4 - File System Utilities
Recursive Search: Write a program that prints out the names of each file and directory in 
the file system tree, starting at a given point in the tree.  For example, when run without 
arguments,  the  program  should  start  with  the  current  working  directory  and  print  its 
contents, as well as the contents of any sub-directories, etc., until the entire tree, root at the 
CWD, is printed. If given a single argument (of a directory name), use that as the root of 
the tree instead.   
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

void search(char *pdir) {

    //file information
    struct dirent *drt;
    struct stat file_info;
    DIR *dir;
    dir = opendir(pdir);
    
    //we print the current path
    printf("Current Path %s\n", pdir);

    while ((drt = readdir(dir)) != NULL) {
        if (strcmp(drt->d_name, ".") != 0 && strcmp(drt->d_name, "..") != 0) {
            printf("File name: %s\n", drt->d_name);

            //sub-directories
            char path[1000];
            if (S_ISDIR(file_info.st_mode)) {
                strcpy(path, pdir);
                strcat(path, "/");
                strcat(path, drt->d_name);
                search(path); //recursion call
            }
        }
    }
}

int main(int argc, char *argv[]) {
    char buffer[1000];

    //current directory
    if (argc == 1) {
        search(getcwd(buffer, sizeof(buffer)));
    }

    else if (argc == 2) {
        search(argv[1]);
    }

    printf("Search has finished!");
    return 0;
}
