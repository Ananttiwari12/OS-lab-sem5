#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

void main(){
    char buff;
    printf("Enter the name of source file\n");
    char source[50], destination[50];
    scanf("%s",&source);
    int fd_one=open("source_file.txt", O_RDONLY);
    if(fd_one==-1){
        printf("Error\n");
        close(fd_one);
        return;
    }
    printf("Enter the name of destination");
    scanf("%s", &destination);
    int fd_two= open(destination, O_WRONLY|O_CREAT|S_IRGRP|S_INUSR|S_IROTH);
    while (read(fd_one,&buff,1)){
        write(fd_two, &buff,1);
    }
    printf("\n Successfully copy");
    close(fd_one);
    close(fd_two);
}