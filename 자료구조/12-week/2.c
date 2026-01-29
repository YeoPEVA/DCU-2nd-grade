#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

// 단어들을 저장할 구조체
typedef struct {
    char *word;
} Word;

int compare_words(const void *a, const void *b) {
    Word *word1 = (Word *)a;
    Word *word2 = (Word *)b;
    int len_diff = strlen(word1->word) - strlen(word2->word);
    if (len_diff != 0) return len_diff;
    return strcmp(word1->word, word2->word);
}

int main() {
    int N;
    scanf("%d", &N); // 단어의 개수 입력받기

    Word words[MAX_WORDS];
    char buffer[MAX_WORD_LENGTH + 1];
    int unique_count = 0;

    for (int i = 0; i < N; i++) {
        scanf("%s", buffer);
        int duplicate = 0;

        // 중복 검사
        for (int j = 0; j < unique_count; j++) {
            if (strcmp(words[j].word, buffer) == 0) {
                duplicate = 1;
                break;
            }
        }

        if (!duplicate) {
            words[unique_count].word = (char *)malloc(strlen(buffer) + 1);
            strcpy(words[unique_count].word, buffer);
            unique_count++;
        }
    }

    // 정렬
    qsort(words, unique_count, sizeof(Word), compare_words);

    // 출력
    for (int i = 0; i < unique_count; i++) {
        printf("%s\n", words[i].word);
        free(words[i].word); // 할당된 메모리 해제
    }

    return 0;
}
