#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmpfunc (const void *a, const void *b){
    return ( *(int *)a - *(int *)b );
}

int cmpForString (const void *a, const void *b){
    return strcmp(*(char **)a, *(char **)b);
}

int cmpByReverse (const void *a, const void *b){
    return strcmp(*(char **)a, *(char **)b);
    /* abc abe  */
    /* abc abcd */
    /* abc abcd abe */
    char *aStr = *(char **)a, *bStr = *(char **)b;
    int alen = strlen(aStr);
    int blen = strlen(bStr);
    int len = (alen<blen)?alen:blen;
    for(int i=0;i<len;i++){
        if(aStr[alen-1-i] != bStr[blen-1-i])
            return aStr[alen-1-i] > bStr[blen-1-i];
    }
    return alen > blen;


}

int Contain(char *str, char *subStr){
    int subLen = strlen(subStr);
    int strLen = strlen(str);
    if(strLen<subLen) return 0;
    for(int i=0;i<subLen;i++){
        if(subStr[i]!=str[i])
            return 0;
    }
    return 1;
}

int minimumLengthEncoding(char **words, int wordsSize){
    for(int i=0;i<wordsSize; i++){

        /* reverse(words[i]); */
        printf("%s\n", words[i]);
    }

    printf("==========");
    qsort(words, wordsSize, sizeof(char *), cmpByReverse);
    for(int i=0;i<wordsSize; i++){
        printf("%s\n", words[i]);
    }


}

int main(){

    int n;
    int values[] = { 88, 56, 100, 2, 25 };

    char str[] = "abc";
    /* *str的话后面的就是常量， 而str[]则是初始化数据。所以一个可以修改一个不可以修改 */
    reverse(str);
    printf("swap:%s", str);

    char *words[6] = {"ba", "ecbb", "a", "dba", "cdba", "cba"};
    minimumLengthEncoding(words, 6);


    printf("in front of sorted");
    for( n=0 ; n < 5; n++ ){
        printf("%d ", values[n]);
    }

    qsort(values, 5, sizeof(int), cmpfunc);

    printf("\nin back of sorted");
    for( n=0; n<5; n++ ){
        printf("%d ", values[n]);
    }

    return 0;
}
