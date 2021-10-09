#include <stdio.h>
#include <malloc.h>
#include "books.h"

int main(void) {
    t_library* library = create_library();
    int c_books = 0;
    printf("Enter count of books:\n");
    scanf("%d", &c_books);
    printf("Enter codes of books:\n");
    for (int i = 0; i < c_books; ++i) {
        int code = 0;
        scanf("%d", &code);
        push_book(library, code);
    }

    int c_readers = 0;
    printf("Enter count of readers:\n");
    scanf("%d", &c_readers);
    printf("Enter code of book for readers:\n");
    for (int i = 0; i < c_readers; ++i) {
        int code = 0;
        scanf("%d", &code);
        int res = push_reader(library, code);
        if (res == 0) {
            printf("Please, repeat\n");
            --i;
        }
    }

    c_readers = count_readers(library);
    printf("Count of readers: %d\n", c_readers);
    int* reader_books = books_on_hands(library);
    if (reader_books != NULL) {
        printf("Codes of the books taken:\n");
        for (int i = 0; i < c_readers; ++i) {
            printf("%d\n", reader_books[i]);
        }
    }

    free(reader_books);
    free_library(library);
    return 0;
}