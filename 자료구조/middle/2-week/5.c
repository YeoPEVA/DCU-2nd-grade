#include <stdio.h>
#include <string.h>

char str[100];

void reverse(int c, int i, char newstr[100]){
    if (c < 0){
        return;
    }
    newstr[i] = str[c];
    reverse(c-1, i+1, newstr);
}

int main(int argc, char*argv[]){
    char new_str[100];
    scanf("%s", str);

    // 문자열 길이, 0, 문자열 전달
    reverse(strlen(str)-1, 0, new_str);

    printf("%s", new_str);
}