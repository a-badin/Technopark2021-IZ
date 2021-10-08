#include "books.h"
#include <stdio.h>
#include <malloc.h>

int static count_readers(t_library* library) {
    int count = 0;
    t_reader* tmp = library->reader_head;
    while (tmp != NULL) {
        ++count;
        tmp = tmp->next;
    }
    return count;
}

void books_on_hands(t_library* library) {
    if (library->reader_head == NULL || library->book_head == NULL) {
        printf("%d\n", 0);
        return;
    }
    printf("Count of readers: %d\n", count_readers(library));
    printf("Codes of the books taken:\n");
    t_reader* tmp = library->reader_head;
    while (tmp != NULL) {
        printf("%d\n", tmp->book_code);
        tmp = tmp->next;
    }
}

t_library* create_library() {
    t_library* library = (t_library*) calloc(1, sizeof(t_library));
    library->book_head = NULL;
    library->reader_head = NULL;
    return library;
}

void push_book(t_library* library, int code) {
    if (library->book_head == NULL) {
        t_book* node = (t_book*) calloc(1, sizeof(t_book));
        node->code = code;
        node->next = NULL;
        library->book_head = node;
        return;
    }
    t_book* tmp = library->book_head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    t_book* node = (t_book*) calloc(1, sizeof(t_book));
    node->code = code;
    node->next = NULL;
    tmp->next = node;
}

void push_reader(t_library* library, int code) {
    if (library->reader_head == NULL) {
        t_reader* node = (t_reader*) calloc(1, sizeof(t_reader));
        node->book_code = code;
        node->next = NULL;
        library->reader_head = node;
        return;
    }
    t_reader* tmp = library->reader_head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    t_reader* node = (t_reader*) calloc(1, sizeof(t_reader));
    node->book_code = code;
    node->next = NULL;
    tmp->next = node;
}

void pop_book(t_library* library) {
    if (library->book_head == NULL)
        return;
    t_book* tmp = library->book_head;
    library->book_head = library->book_head->next;
    free(tmp);
}

void pop_reader(t_library* library) {
    if (library->reader_head == NULL)
        return;
    t_reader* tmp = library->reader_head;
    library->reader_head = library->reader_head->next;
    free(tmp);
}

void free_library(t_library* library) {
    while (library->reader_head != NULL)
        pop_reader(library);
    while (library->book_head != NULL)
        pop_book(library);
}