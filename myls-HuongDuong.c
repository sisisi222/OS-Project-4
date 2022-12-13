/* 
Name: Huong Duong
Project 4 - File System Utilities
List Files: Write a program that lists files in the given directory. When called without any 
arguments, the program should just print the file names. When invoked with the -l flag, the 
program should print out information about each file, such as the owner, group, 
permissions,  and  other  information  obtained  from  the  stat()  system  call.  The  program 
should take one additional argument, which is the directory to read, e.g., myls -l directory. 
If no directory is given, the program should just use the current working directory.  
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>


//print infomation about each file
void print_info(struct stat info) {
    
    printf("Owner ID: %d\n", info.st_uid);
    printf("Group ID: %d\n", info.st_gid);
    printf("File Size: %ld Bytes\n", info.st_size);
    printf("Number of Blocks Allocated: %ld\n", info.st_blocks);
    printf("Number of Links: %ld\n", info.st_nlink);
    printf("File permissions: ");
    printf((S_ISDIR(info.st_mode)) ? "d" : "-");

    printf((info.st_mode & S_IRUSR) ? "r" : "-");
    printf((info.st_mode & S_IWUSR) ? "w" : "-");
    printf((info.st_mode & S_IXUSR) ? "x" : "-");

    printf((info.st_mode & S_IRGRP) ? "r" : "-");
    printf((info.st_mode & S_IWGRP) ? "w" : "-");
    printf((info.st_mode & S_IXGRP) ? "x" : "-");
            
    printf((info.st_mode & S_IROTH) ? "r" : "-");
    printf((info.st_mode & S_IWOTH) ? "w" : "-");
    printf((info.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    printf("File Inode: %ld\n", info.st_ino);
}

int main(int argc, char *argv[]) {

    //file information
    struct dirent *drt;
    struct stat file_info;
    DIR *dir;

    //When called without any arguments, print file name only
    if (argc == 1) {
        dir = opendir(".");
        while ((drt = readdir(dir)) != NULL) {
            if (strcmp(drt->d_name, ".") != 0 && strcmp(drt->d_name, "..") != 0) {
                printf("%s\n", drt->d_name);
            }
        }
    }

    //file names and other information obtained from the stat() system call
    
    else if (argc == 2) {
        if (strcmp(argv[1], "-l") == 0) {
            print_info(file_info);
        }
    }

    //file names, obtained information from the stat(), owner, group, permissions 
    else if (argc == 3) {

        while((drt = readdir(dir)) != NULL) {
            if (strcmp(drt->d_name, "." != 0 && strcmp(drt->d_name, ".." != 0))) {
                //information
                printf("File Information of %s\n", drt->d_name);
                print_info(file_info);
            }
        }
    }

    //if there are 4 or more argumants, ask user to enter again and exit
    else {
        printf("Invalid! Please enter again!");
        return 0;
    }
    return 0;
}