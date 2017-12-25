#ifndef FUNCS_H_INCLUDED
#define FUNCS_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>


int readTextFile(char *path, char *content, int contentLen) {

    FILE *file;

    if ((file = fopen(path, "r")) == NULL) return -1;

    fseek(file, 0, SEEK_END);
    int len = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (len > contentLen) {

        fclose(file);
        return -2;

    }

    fread(content, sizeof(char), len, file);
    fclose(file);

    return 0;

}


int addToTextFile(char *path, char *content, int len) {

    FILE *file;

    if ((file = fopen(path, "a+")) == NULL) return -1;

    fwrite(content, sizeof(char), len, file);
    fclose(file);

    return 0;

}


int copyFile(char *inputPath, char *outputPath) {

    FILE *inputFile, *outputFile;
    char word;

    if ((inputFile = fopen(inputPath, "rb")) == NULL) return -1;
    if ((outputFile = fopen(outputPath, "wb")) == NULL) return -2;

    while (!feof(inputFile)) {

        fread(&word, 1, 1, inputFile);
        fwrite(&word, 1, 1, outputFile);

    }

    fclose(outputFile);
    fclose(inputFile);

    return 0;

}


//int replaceStr(char *str, char *subStr1, char *subStr2, char *result, int resultLen1, int *resultLen2, int all) {
//
//    char *pos = strstr(str, subStr1);
//    if (pos == NULL) return -1;
//
//    int newStr1Len = pos - str;
//    char newStr1[newStr1Len];
//    strncpy(newStr1, str, newStr1Len);
//    newStr1[newStr1Len] = '\0';
//
//    int subStr1Len = strlen(subStr1);
//    pos = pos + subStr1Len;
//    int strLen = strlen(str);
//    int newStr2Len = str + strLen - pos + 1;
//    char newStr2[newStr2Len];
//    strncpy(newStr2, pos, newStr2Len);
//    newStr2[newStr2Len] = '\0';
//
//    int subStr2Len = strlen(subStr2);
//    int newStr3Len = newStr1Len + newStr2Len + subStr2Len;
//    *resultLen2 = newStr3Len;
//    if (newStr3Len > resultLen1) return -2;
//
//    char newStr3[newStr3Len];
//    strcpy(newStr3, newStr1);
//    strcat(newStr3, subStr2);
//    strcat(newStr3, newStr2);
//
//    if (all == 1 && strstr(newStr3, subStr1) != NULL) {
//
//        return replaceStr(newStr3, subStr1, subStr2, result, newStr3Len, resultLen2, all);
//
//    } else {
//
//        strcpy(result, newStr3);
//        return 0;
//
//    }
//
//}


int replaceStr(char *str, char *subStr1, char *subStr2, char *result, int resultLen1, int *resultLen2, int all) {

    char *pos = strstr(str, subStr1);
    if (pos == NULL) return -1;

    int newStr1Len = pos - str;
    char *newStr1 = (char*)malloc(newStr1Len);
    strncpy(newStr1, str, newStr1Len);
    *(newStr1 + newStr1Len) = '\0';

    printf("run1\n");

    int subStr1Len = strlen(subStr1);
    pos = pos + subStr1Len;
    int strLen = strlen(str);
    int newStr2Len = str + strLen - pos + 1;
    char *newStr2 = (char*)malloc(newStr2Len);
    strncpy(newStr2, pos, newStr2Len);
    *(newStr2 + newStr2Len) = '\0';

    printf("run2\n");

    int subStr2Len = strlen(subStr2);
    int newStr3Len = newStr1Len + newStr2Len + subStr2Len;

    printf("run2-1\n");

    *resultLen2 = newStr3Len;
    if (newStr3Len > resultLen1) return -2;

    printf("run2-2\n");
    printf("newStr3Len: %d\n", newStr3Len);

    char *newStr3 = (char*)malloc(newStr3Len);

    printf("run2-3\n");

    strcpy(newStr3, newStr1);
    strcat(newStr3, subStr2);
    strcat(newStr3, newStr2);

    printf("run3\n");



    printf("run4\n");

//    if (all == 1 && strstr(newStr3, subStr1) != NULL) {
////
//        int temp = replaceStr(newStr3, subStr1, subStr2, result, newStr3Len, resultLen2, all);
//        free(newStr3);
//
//        return 0;
//
//    } else {
//
//        strcpy(result, newStr3);
//        free(newStr3);
//
//        return 0;
//
//    }

    strcpy(result, newStr3);

    free(newStr1);
    free(newStr2);
    free(newStr3);

    return 0;

}


#endif // FUNCS_H_INCLUDED
