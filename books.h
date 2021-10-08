#pragma once

typedef struct t_book {
    int code;
    char name[30];
    int year_publishing;
    int count;
    struct t_book* next;
} t_book;

typedef struct t_reader {
    int book_code;
    int date;
    char surname[30];
    struct t_reader* next;
} t_reader;

typedef struct t_library {
    t_book* book_head;
    t_reader* reader_head;
} t_library;

void books_on_hands(t_library* library);

t_library* create_library();
void push_book(t_library* library, int code);
void push_reader(t_library* library, int code);

void pop_book(t_library* library);
void pop_reader(t_library* library);
void free_library(t_library* library);