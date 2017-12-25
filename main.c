#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "funcs.h"


#define TEST_FILE "E:\\Development\\c\\files\\file.txt"



void addToTextFileTest() {

    char path[] = "E:\\Development\\c\\files\\file.txt";
    char content[] = "This content was added by C program.";

    if (addToTextFile(path, content, strlen(content)) == 0) {
        printf("Content was successfully added to file.");
    } else {
        printf("Failed to open file.");
    }

}


void copyFileTest() {

    char inputPath[] = "E:\\Development\\c\\files\\heyizhi.mp4";
    char outputPath[] = "E:\\Development\\c\\files\\heyizhi_copy.mp4";

    printf("%s\n", "Copying file...");

    if (copyFile(inputPath, outputPath) == 0) {
        printf("%s\n", "File is successfully copied.");
    } else {
        printf("%s\n", "Failed to copy file.");
    }

}


void readTextFileTest() {

    printf("Reading text file...\n");

    char path[] = "E:\\Development\\c\\files\\file2.txt";
    char content[1024];
    char *content2 = (char*)malloc(sizeof(char) * 5000);
    int result = readTextFile(path, content2, 5000);

    if (result == 0) {

        printf("File was successfully opened.\n");
        printf("%s\n", content2);

    } else if (result == -1) {

        printf("Failed to open file!\n");

    } else if (result == -2) {

        printf("File content is longer than output content!\n");

    }

    free(content2);

}


void replaceStrTest() {

    //char str[] = "It seems that Denise likes me.  Denise is a pretty girl.  And Denise worked with me.  I wish someday I could adfasdfaasdfasdaaaaaaaaaaaaaaaa Denise";
    char str[] = "Denise Denise Denise";
    char subStr1[] = "Denise";
    char subStr2[] = "Christina";
    char result[1024];
    int resultLen;
    int status = replaceStr(str, subStr1, subStr2, result, 1024, &resultLen, 1);
    printf("%d\n", status);

    if (status == 0) {

        printf("String was successfully processed!\n");
        printf("%s\nString length: %d", result, strlen(result));

    } else if (status == -1) {

        printf("No replaced string matched!\n");

    } else if (status == -2) {

        printf("Result string is not long enough!\n");

    }

}


void general() {



}


int main() {

    //general();
    //readTextFileTest();
    //addToTextFileTest();
    //copyFileTest();
    replaceStrTest();

    return 0;

}
