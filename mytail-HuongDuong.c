/* 
Name: Huong Duong
Project 4 - File System Utilities
Tail: Write a program that prints out the last few lines of a file. The program should be 
efficient, in that it seeks to near the end of the file, reads in a block of data, and then goes 
back until it finds the requested number of lines; at this point, it should print out those lines 
from the beginning to the end of the file. To invoke the program, one should type: mytail 
-n file, where n is the number of lines at the end of the file to print.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error! The argguments have to be exactly 3!");
        return 0;
    }
    
    // file information
    struct stat file_info;
    int input_line = atoi(argv[1]); //string -> int

    //print output
    char *output;

    //variable to help determine the output
    char new_line;
    int count_line = 0; 
    int count_char = 0;
    off_t position;
    int fd_read;

    //read mode
    int fd = open(argv[2], O_RDONLY);

    if (stat(argv[2], &file_info) == -1) {
        perror("stat");
        exit(EXIT_SUCCESS);
    }

    position = file_info.st_size;
    int size = file_info.st_size;
    int i;
    for (i = 0; i < size; i++) {
        fd_read = read(fd, &new_line, 1);
        if (fd_read != -1) {
            lseek(fd, --position, SEEK_SET); //backward
            if (new_line == '\n') {
                int new_count_line = ++count_line;
                if (new_count_line == input_line) { //stop when all lines that are asked for already read
                    break;
                }
                count_char++;
            }
            else {
                count_char++;
            }
        }
    }

    if (count_line == input_line) {
        lseek(fd, 2, SEEK_CUR); //the file offset is set to its current location plus offset bytes
    }
    else {
        lseek(fd, 0, SEEK_SET); //the file offset is set to offset bytes
    }

    //get output
    printf("These are the last %d lines:\n", input_line);
    output = malloc(count_char * sizeof(char));
    read(fd, output, count_char);

    //print output
    for (i = 0; i < count_char; i++) {
        printf("%c", output[i]);
    }
 
}

