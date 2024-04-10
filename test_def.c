#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unit_test.h" 

Status test_init_default_returns_nonNULL(char* buffer, int length)
{
   MY_STRING hString = NULL;
   hString = my_string_init_default();

    if(hString == NULL)
    {
        strncpy(buffer, "test_init_default_returns_nonNULL\n"
        "my_string_init_default returns NULL", length);
        return FAILURE;
    }
    else
    {
        my_string_destroy(&hString);
        strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
        return SUCCESS;
    }
}
Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
   MY_STRING hString = NULL;
   Status status;
   hString = my_string_init_default();
    
    if(my_string_get_size(hString) != 0)
    {
        status = FAILURE;
        printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
        "Did not receive 0 from get_size after init_default\n", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
        , length);
    }
    my_string_destroy(&hString);
    return status;
}
Status test_mdaoud_test_init_c_string_returns_nonNULL(char* buffer, int length)
{ 
  MY_STRING hString = NULL;
  const char* test_string = "Hello, World!";
  hString = my_string_init_c_string(test_string);   
  
   
    if (hString == NULL)
    {
        strncpy(buffer, "test_init_c_string_returns_nonNULL\nmy_string_init_c_string returns NULL", length);
        return FAILURE;
    }
    else
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_init_c_string_returns_nonNULL\n", length);
        return SUCCESS;
    }
}
Status test_mdaoud_test_get_size_after_init_c_string_returns_strlen(char* buffer, int length)
{
  MY_STRING hString = NULL;
  const char* test_string = "Hello, World!";
  hString = my_string_init_c_string(test_string); 
  Status status;

    if (my_string_get_size(hString) != strlen(test_string))
    {
        status = FAILURE;
        printf("Expected size %d but got %d\n", (int)strlen(test_string), my_string_get_size(hString));
        strncpy(buffer, "test_get_size_after_init_c_string\nDid not receive correct size after init_c_string\n", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_get_size_after_init_c_string\n", length);
    }
    my_string_destroy(&hString);
    return status;
}
 Status test_mdaoud_get_capacity_on_init_default_returns_8(char* buffer, int length)
 {
  MY_STRING hString = my_string_init_default();
    Status status;
    if (my_string_get_capacity(hString) != 8) // Default capacity is 7 + 1 for null terminator
    {
        status = FAILURE;
        printf("Expected capacity %d but got %d\n", 8, my_string_get_capacity(hString));
        strncpy(buffer, "test_get_capacity_on_init_default\nDid not receive correct capacity after init_default\n", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_get_capacity_on_init_default\n", length);
    }
    my_string_destroy(&hString);
    return status;
 }
 Status test_mdaoud_string_compare_identical_strings_returns_0(char* buffer, int length)
{
    const char* test_string = "Hello, World!";
    MY_STRING hLeft_String = my_string_init_c_string(test_string);
    MY_STRING hRight_String = my_string_init_c_string(test_string);
    Status status;
    if (my_string_compare(hLeft_String, hRight_String) != 0)
    {
        status = FAILURE;
        strncpy(buffer, "test_string_compare_identical_strings\nFailed to compare identical strings correctly\n", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_string_compare_identical_strings\n", length);
    }
    my_string_destroy(&hLeft_String);
    my_string_destroy(&hRight_String);
    return status;
}
Status test_mdaoud_string_compare_identical_strings_returns_greater_than_0(char* buffer, int length)
{
    const char* test_string1 = "Hello, World!";
    const char* test_string2 = "Hello!";
    MY_STRING hLeft_String = my_string_init_c_string(test_string1);
    MY_STRING hRight_String = my_string_init_c_string(test_string2);
    Status status;
    if (my_string_compare(hLeft_String, hRight_String) < 0)
    {
        status = FAILURE;
        strncpy(buffer, "test_string_compare_identical_strings\nFailed to compare identical strings correctly\n", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_string_compare_identical_strings\n", length);
    }
    my_string_destroy(&hLeft_String);
    my_string_destroy(&hRight_String); 
    return status; 
}
Status test_mdaoud_string_compare_identical_strings_returns_less_than_0(char* buffer, int length)
{
  const char* test_string1 = "Hello, World!";
    const char* test_string2 = "Hello!";
    MY_STRING hLeft_String = my_string_init_c_string(test_string2);
    MY_STRING hRight_String = my_string_init_c_string(test_string1);
    Status status;
    if (my_string_compare(hLeft_String, hRight_String) > 0)
    {
        status = FAILURE;
        strncpy(buffer, "test_string_compare_identical_strings\nFailed to compare identical strings correctly\n", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_string_compare_identical_strings\n", length);
    }
    my_string_destroy(&hLeft_String);
    my_string_destroy(&hRight_String); 
    return status;
}
Status test_mdaoud_my_string_c_str_valid_input(char* buffer, int length)
{
    
    MY_STRING hString = my_string_init_c_string("Hello, World!");
    if (hString == NULL)
    {
        strncpy(buffer, "test_my_string_c_str_valid_input\nFailed to initialize string object\n", length);
        return FAILURE;
    }

    const char* expected_string = "Hello, World!";
    char* extracted_string = my_string_c_str(hString);

    if (strcmp(extracted_string, expected_string) != 0)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_my_string_c_str_valid_input\nExtracted string does not match expected\n", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_my_string_c_str_valid_input\n", length);
    return SUCCESS;
}
Status test_mdaoud_string_extraction_valid_input(char* buffer, int length)
{
    FILE* fp = fopen("simple.txt", "r");
    if (fp == NULL)
    {
        strncpy(buffer, "test_string_extraction_valid_input\nFailed to open input file\n", length);
        return FAILURE;
    }

    MY_STRING hString = my_string_init_default();
    if (hString == NULL)
    {
        fclose(fp);
        strncpy(buffer, "test_string_extraction_valid_input\nFailed to initialize string object\n", length);
        return FAILURE;
    }

    Status status = my_string_extraction(hString, fp);

    fclose(fp);

    if (status == FAILURE)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_string_extraction_valid_input\nFailed to extract string from file\n", length);
        return FAILURE;
    }


    const char* expected_string = "The quick brown fox jumped over the lazy dogs.";
    char* extracted_string = my_string_c_str(hString);
    if (strcmp(extracted_string, expected_string) != 0)
    {
        my_string_destroy(&hString);
        printf ("Got string %s but expected %s\n", extracted_string, expected_string);
        strncpy(buffer, "test_string_extraction_valid_input\nExtracted string does not match expected\n", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_string_extraction_valid_input\n", length);
    return SUCCESS;
}
Status test_mdaoud_my_string_insertion_valid_input(char* buffer, int length)
{
    MY_STRING hString = NULL;
    hString = my_string_init_c_string("This is a test string.");
    if (hString == NULL)
    {
        strncpy(buffer, "test_my_string_insertion_valid_input\nFailed to initialize destination string\n", length);
        return FAILURE;
    }

   
    FILE* fp = tmpfile();
    if (fp == NULL)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_my_string_insertion_valid_input\nFailed to create temporary file\n", length);
        return FAILURE;
    }

  
    Status status = my_string_insertion(hString, fp);

   
    fclose(fp);

    
    if (status == FAILURE)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_my_string_insertion_valid_input\nInsertion failed\n", length);
        return FAILURE;
    }

    
    my_string_destroy(&hString);
    strncpy(buffer, "test_my_string_insertion_valid_input\n", length);
    return SUCCESS;
}

Status test_mdaoud_my_string_push_back_valid_input(char* buffer, int length)
{
    MY_STRING hString = NULL;
    hString = my_string_init_c_string("Hello, world!");
    if (hString == NULL)
    {
        strncpy(buffer, "test_my_string_push_back_valid_input\nFailed to initialize string\n", length);
        return FAILURE;
    }

    char ch = '!';
    Status status = my_string_push_back(hString, ch);
    if (status == FAILURE)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_my_string_push_back_valid_input\nFailed to push back character\n", length);
        return FAILURE;
    }

    int size = my_string_get_size(hString);
    if (size != 14) 
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_my_string_push_back_valid_input\nUnexpected size after push back\n", length);
        return FAILURE;
    }

    const char* expected_string = "Hello, world!!";
    char* result_string = my_string_c_str(hString);
    if (strcmp(result_string, expected_string) != 0)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_my_string_push_back_valid_input\nResult string does not match expected\n", length);
        return FAILURE;
    }

    my_string_destroy(&hString); 
    strncpy(buffer, "test_my_string_push_back_valid_input\n", length);
    return SUCCESS;
}

Status test_mdaoud_my_string_pop_back_valid_input(char* buffer, int length)
{
    MY_STRING hString = NULL;
    hString = my_string_init_default(); 
    if (hString == NULL)
    {
        strncpy(buffer, "test_my_string_pop_back_valid_input\nFailed to initialize string object\n", length);
        return FAILURE;
    }

    const char* test_string = "Hello, World!";
    int i;
    for (i = 0; test_string[i] != '\0'; ++i)
    {
        if (my_string_push_back(hString, test_string[i]) == FAILURE)
        {
            my_string_destroy(&hString);
            strncpy(buffer, "test_my_string_pop_back_valid_input\nFailed to push characters into the string\n", length);
            return FAILURE;
        }
    }

    for (i = strlen(test_string) - 1; i >= 0; --i)
    {
        if (my_string_pop_back(hString) == FAILURE)
        {
            my_string_destroy(&hString);
            strncpy(buffer, "test_my_string_pop_back_valid_input\nFailed to pop characters from the string\n", length);
            return FAILURE;
        }
        if (my_string_get_size(hString) != i)
        {
            my_string_destroy(&hString);
            strncpy(buffer, "test_my_string_pop_back_valid_input\nIncorrect size after popping characters\n", length);
            return FAILURE;
        }
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_my_string_pop_back_valid_input\n", length);
    return SUCCESS;
}

Status test_mdaoud_my_string_at_valid_input(char* buffer, int length)
{
    MY_STRING hString = NULL;
    hString = my_string_init_default();
    if (hString == NULL)
    {
        strncpy(buffer, "test_my_string_at_valid_input\nFailed to initialize string object\n", length);
        return FAILURE;
    }

    const char* test_string = "Hello, World!";
    int i;
    for (i = 0; test_string[i] != '\0'; ++i)
    {
        if (my_string_push_back(hString, test_string[i]) == FAILURE)
        {
            my_string_destroy(&hString);
            strncpy(buffer, "test_my_string_at_valid_input\nFailed to push characters into the string\n", length);
            return FAILURE;
        }
    }

    char* character = my_string_at(hString, 7);
    if (character == NULL || *character != 'W')
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_my_string_at_valid_input\nFailed to get the correct character at a valid index\n", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_my_string_at_valid_input\n", length);
    return SUCCESS;
}

Status test_mdaoud_my_string_at_out_of_bounds(char* buffer, int length)
{
    MY_STRING hString = NULL;
    hString = my_string_init_default();
    if (hString == NULL)
    {
        strncpy(buffer, "test_my_string_at_out_of_bounds\nFailed to initialize string object\n", length);
        return FAILURE;
    }

    const char* test_string = "Hello, World!";
    int i;
    for (i = 0; test_string[i] != '\0'; ++i)
    {
        if (my_string_push_back(hString, test_string[i]) == FAILURE)
        {
            my_string_destroy(&hString);
            strncpy(buffer, "test_my_string_at_out_of_bounds\nFailed to push characters into the string\n", length);
            return FAILURE;
        }
    }

    char* out_of_bounds = my_string_at(hString, i);
    if (out_of_bounds != NULL)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_my_string_at_out_of_bounds\nOut-of-bounds access did not return NULL\n", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_my_string_at_out_of_bounds\n", length);
    return SUCCESS;
}

Status test_mdaoud_my_string_at_modify_value(char* buffer, int length)
{
    MY_STRING hString = NULL;
    hString = my_string_init_default();
    if (hString == NULL)
    {
        strncpy(buffer, "test_my_string_at_modify_value\nFailed to initialize string object\n", length);
        return FAILURE;
    }

    const char* test_string = "Hello, World!";
    int i;
    for (i = 0; test_string[i] != '\0'; ++i)
    {
        if (my_string_push_back(hString, test_string[i]) == FAILURE)
        {
            my_string_destroy(&hString);
            strncpy(buffer, "test_my_string_at_modify_value\nFailed to push characters into the string\n", length);
            return FAILURE;
        }
    }

    char* character = my_string_at(hString, 7);
    if (character == NULL)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_my_string_at_modify_value\nFailed to get the character at a valid index\n", length);
        return FAILURE;
    }
    *character = 'Z'; 

    character = my_string_at(hString, 7);
    if (character == NULL || *character != 'Z')
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_my_string_at_modify_value\nFailed to modify the character value at a valid index\n", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_my_string_at_modify_value\n", length);
    return SUCCESS;
}

Status test_mdaoud_my_string_concat_valid_input(char* buffer, int length)
{
    MY_STRING hString1 = NULL;
    MY_STRING hString2 = NULL;
    hString1 = my_string_init_c_string("Hello, ");
    if (hString1 == NULL)
    {
        strncpy(buffer, "test_my_string_concat_valid_input\nFailed to initialize first string object\n", length);
        return FAILURE;
    }

    hString2 = my_string_init_c_string("World!");
    if (hString2 == NULL)
    {
        my_string_destroy(&hString1);
        strncpy(buffer, "test_my_string_concat_valid_input\nFailed to initialize second string object\n", length);
        return FAILURE;
    }

    Status status = my_string_concat(hString1, hString2);
    if (status == FAILURE)
    {
        my_string_destroy(&hString1);
        my_string_destroy(&hString2);
        strncpy(buffer, "test_my_string_concat_valid_input\nFailed to concatenate strings\n", length);
        return FAILURE;
    }

    const char* expected_string = "Hello, World!";
    char* result_string = my_string_c_str(hString1);
    if (strcmp(result_string, expected_string) != 0)
    {
        my_string_destroy(&hString1);
        my_string_destroy(&hString2);
        strncpy(buffer, "test_my_string_concat_valid_input\nConcatenation result does not match expected string\n", length);
        return FAILURE;
    }

    my_string_destroy(&hString1);
    my_string_destroy(&hString2);
    strncpy(buffer, "test_my_string_concat_valid_input\n", length);
    return SUCCESS;
}

Status test_mdaoud_my_string_empty_returns_true(char* buffer, int length)
{
    MY_STRING hString = NULL;
    hString = my_string_init_default();
    if (hString == NULL)
    {
        strncpy(buffer, "test_my_string_empty_true\nFailed to initialize string object\n", length);
        return FAILURE;
    }

    Boolean is_empty = my_string_empty(hString);
    if (is_empty != TRUE)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_my_string_empty_true\nExpected string to be empty\n", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_my_string_empty_true\n", length);
    return SUCCESS;
}

Status test_mdaoud_my_string_empty_returns_false(char* buffer, int length)
{
    MY_STRING hString = NULL;
    hString = my_string_init_default();
    if (hString == NULL)
    {
        strncpy(buffer, "test_my_string_empty_false\nFailed to initialize string object\n", length);
        return FAILURE;
    }

    my_string_push_back(hString, 'A');
    Boolean is_empty = my_string_empty(hString);
    if (is_empty != FALSE)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_my_string_empty_false\nExpected string not to be empty after push back\n", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_my_string_empty_false\n", length);
    return SUCCESS;
}

Status test_mdaoud_my_string_destroy_returns_NULL(char* buffer, int length)
{
    MY_STRING hString = NULL;
    hString = my_string_init_default();
    if (hString == NULL)
    {
        strncpy(buffer, "test_my_string_destroy\nFailed to initialize string object\n", length);
        return FAILURE;
    }

    my_string_destroy(&hString);

    if (hString != NULL)
    {
        strncpy(buffer, "test_my_string_destroy\nFailed to destroy string object\n", length);
        return FAILURE;
    }

    strncpy(buffer, "test_my_string_destroy\n", length);
    return SUCCESS;
}

Status test_mdaoud_get_capacity_after_resize_returns_16(char* buffer, int length)
{
    MY_STRING hString = my_string_init_default();
    for (char c = 'a'; c <= 'p'; ++c) 
    {
        my_string_push_back(hString, c);
    }

    if (my_string_get_capacity(hString) != 16) 
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_get_capacity_after_resize\nCapacity after resize is incorrect\n", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_get_capacity_after_resize\n", length);
    return SUCCESS;
}

Status test_mdaoud_my_string_pop_back_empty_string_returns_FAILURE(char* buffer, int length)
{
    MY_STRING hString = my_string_init_default(); 
    Status status = my_string_pop_back(hString);
    
    if (status != FAILURE) 
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_my_string_pop_back_empty_string\nPop back on empty string should return FAILURE\n", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_my_string_pop_back_empty_string\n", length);
    return SUCCESS;
}

Status test_mdaoud_my_string_get_size_after_pop_back_reduces_by_1(char* buffer, int length)
{
    MY_STRING hString = my_string_init_default();
    my_string_push_back(hString, 'a');
    int size_before_pop = my_string_get_size(hString);
    my_string_pop_back(hString);
    int size_after_pop = my_string_get_size(hString);
    
    if (size_after_pop != size_before_pop - 1) 
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_my_string_get_size_after_pop_back_reduces_by_1\nSize should reduce by 1 after pop back\n", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_my_string_get_size_after_pop_back_reduces_by_1\n", length);
    return SUCCESS;
}

Status test_mdaoud_my_string_concat_with_empty_string_returns_original_string(char* buffer, int length)
{
    MY_STRING hString1 = my_string_init_c_string("Hello");
    MY_STRING hString2 = my_string_init_default();

    Status status = my_string_concat(hString1, hString2);
    if (status != SUCCESS)
    {
        my_string_destroy(&hString1);
        my_string_destroy(&hString2);
        strncpy(buffer, "test_mdaoud_my_string_concat_with_empty_string_returns_original_string\nFailed to concatenate with empty string\n", length);
        return FAILURE;
    }

    const char* expected_string = "Hello";
    char* result_string = my_string_c_str(hString1);
    if (strcmp(result_string, expected_string) != 0)
    {
        my_string_destroy(&hString1);
        my_string_destroy(&hString2);
        strncpy(buffer, "test_mdaoud_my_string_concat_with_empty_string_returns_original_string\nConcatenation result does not match expected string\n", length);
        return FAILURE;
    }

    my_string_destroy(&hString1);
    my_string_destroy(&hString2);
    strncpy(buffer, "test_mdaoud_my_string_concat_with_empty_string_returns_original_string\n", length);
    return SUCCESS;
}

Status test_mdaoud_my_string_concat__NULL_string_returns_FAILURE(char* buffer, int length)
{
    MY_STRING hString1 = my_string_init_c_string("Hello");
    MY_STRING hString2 = NULL;

    Status status = my_string_concat(hString1, hString2);

    if (status != FAILURE)
    {
        my_string_destroy(&hString1);
        strncpy(buffer, "test_mdaoud_my_string_concat_handles_NULL_strings\nConcatenation with NULL string should return FAILURE\n", length);
        return FAILURE;
    }

    my_string_destroy(&hString1);
    strncpy(buffer, "test_mdaoud_my_string_concat_handles_NULL_strings\n", length);
    return SUCCESS;
}





