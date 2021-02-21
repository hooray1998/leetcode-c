#include <stdio.h>
#include <string.h>

int Contain(char *str, char *subStr){
    int subLen = strlen(subStr);
    for(int i=0;i<subLen;i++){
        if(subStr[i]!=str[i])
            return 0;
    }
    return 1;
}

int main(){
    char a[] = "abc";
    char b[] = "bc";
    printf("%d, ", Contain(a, b));
    return 0;
}
