#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    char word[50];
    char meaning[100];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

int isNumber(const char *str) {
    if (*str == '\0') return 0;
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}


struct Node* createNode(const char *word, const char *meaning) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->prev = newNode->next = NULL;
    return newNode;
}


void insertWord(const char *word, const char *meaning) {
    struct Node *newNode = createNode(word, meaning);

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        struct Node *last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }
    printf("Inserted: %s -> %s\n", word, meaning);
}


void deleteWord(const char *word) {
    if (head == NULL) {
        printf("Dictionary empty!\n");
        return;
    }

    struct Node *current = head;
    do {
        if (strcmp(current->word, word) == 0) {
            if (current->next == current) {
                head = NULL;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                if (current == head) head = current->next;
            }
            free(current);
            printf("Deleted: %s\n", word);
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Word not found!\n");
}


void updateWord(const char *word, const char *newMeaning) {
    if (head == NULL) {
        printf("Dictionary empty!\n");
        return;
    }

    struct Node *current = head;
    do {
        if (strcmp(current->word, word) == 0) {
            strcpy(current->meaning, newMeaning);
            printf("Updated: %s -> %s\n", word, newMeaning);
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Word not found!\n");
}


void displayDictionary() {
    if (head == NULL) {
        printf("Dictionary empty!\n");
        return;
    }

    struct Node *current = head;
    printf("\nDictionary:\n");
    do {
        printf("%s -> %s\n", current->word, current->meaning);
        current = current->next;
    } while (current != head);
}

int main() {
    char input[100];
    int choice;
    char word[50], meaning[100];

    while (1) {
        printf("\n========== DICTIONARY MENU ==========\n");
        printf("1. Insert Word\n");
        printf("2. Delete Word\n");
        printf("3. Update Word\n");
        printf("4. Display Dictionary\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        if (!fgets(input, sizeof(input), stdin)) continue;
        input[strcspn(input, "\n")] = '\0';

        if (!isNumber(input)) {
            printf("Invalid input! Digits only.\n");
            continue;
        }

        choice = atoi(input);

        switch (choice) {
            case 1:
                printf("Enter word: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = '\0';

                printf("Enter meaning: ");
                fgets(meaning, sizeof(meaning), stdin);
                meaning[strcspn(meaning, "\n")] = '\0';

                insertWord(word, meaning);
                break;

            case 2:
                printf("Enter word to delete: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = '\0';
                deleteWord(word);
                break;

            case 3:
                printf("Enter word to update: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = '\0';

                printf("Enter new meaning: ");
                fgets(meaning, sizeof(meaning), stdin);
                meaning[strcspn(meaning, "\n")] = '\0';

                updateWord(word, meaning);
                break;

            case 4:
                displayDictionary();
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
