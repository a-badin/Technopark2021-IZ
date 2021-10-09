#include <gtest/gtest.h>

extern "C" {
    #include "books.h"
    #include <malloc.h>
}

TEST(test_book, assert_1){
    t_library* library = create_library();
    if (library == NULL) {
        return;
    }
    push_book(library, 1);
    push_reader(library, 1);
    int* res = books_on_hands(library);
    EXPECT_EQ(res[0], 1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}