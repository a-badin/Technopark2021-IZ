#include <stdio.h>
#include "books.h"

int main(void) {
    t_library* library = create_library();
    int count_books = 0;
    scanf("%d", &count_books);
    for (int i = 0; i < count_books; ++i) {
        int code = 0;
        scanf("%d", &code);
        push_book(library, code);
    }

    int count_readers = 0;
    scanf("%d", &count_readers);
    for (int i = 0; i < count_readers; ++i) {
        int code = 0;
        scanf("%d", &code);
        push_reader(library, code);
    }

    books_on_hands(library);

    free_library(library);
    return 0;
}