project(IZ-1)

add_library(book STATIC books.c)

add_executable(main main.c)
target_link_libraries(main book)