//Name: Huong Duong
/*
Stat: Write your own version of the command line program  stat, which simply calls the 
stat() system call on a given file or directory. Print out file size, number of blocks allocated, 
reference (link) count, file permissions, and file inode.  
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error! Please try again!");
        return 0;
    }
    else {
        struct stat file_info;
        stat(argv[1], &file_info);
        printf("File information of %s\n", argv[1]);
        printf("File Size: %ld Bytes\n", file_info.st_size);
        printf("Number of Blocks Allocated: %ld\n", file_info.st_blocks);
        printf("Number of Links: %ld\n", file_info.st_nlink);
        printf("File permissions: ");
        printf((S_ISDIR(file_info.st_mode)) ? "d" : "-");

        printf((file_info.st_mode & S_IRUSR) ? "r" : "-");
        printf((file_info.st_mode & S_IWUSR) ? "w" : "-");
        printf((file_info.st_mode & S_IXUSR) ? "x" : "-");

        printf((file_info.st_mode & S_IRGRP) ? "r" : "-");
        printf((file_info.st_mode & S_IWGRP) ? "w" : "-");
        printf((file_info.st_mode & S_IXGRP) ? "x" : "-");
                
        printf((file_info.st_mode & S_IROTH) ? "r" : "-");
        printf((file_info.st_mode & S_IWOTH) ? "w" : "-");
        printf((file_info.st_mode & S_IXOTH) ? "x" : "-");
        printf("\n");

        printf("File Inode: %ld\n", file_info.st_ino);
    }
}