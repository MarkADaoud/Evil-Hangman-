#ifndef UNIT_TEST_H
#define UNIT_TEST_H 

#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length); 
Status test_get_size_on_init_default_returns_0(char* buffer, int length); 
Status test_mdaoud_test_init_c_string_returns_nonNULL(char* buffer, int length);
Status test_mdaoud_test_get_size_after_init_c_string_returns_strlen(char* buffer, int length);
Status test_mdaoud_get_capacity_on_init_default_returns_8(char* buffer, int length);
Status test_mdaoud_string_compare_identical_strings_returns_0(char* buffer, int length);
Status test_mdaoud_string_compare_identical_strings_returns_greater_than_0(char* buffer, int length);
Status test_mdaoud_string_compare_identical_strings_returns_less_than_0(char* buffer, int length);
Status test_mdaoud_string_extraction_valid_input(char* buffer, int length);
Status test_mdaoud_my_string_c_str_valid_input(char* buffer, int length);
Status test_mdaoud_my_string_insertion_valid_input(char* buffer, int length); 
Status test_mdaoud_my_string_push_back_valid_input(char* buffer, int length);
Status test_mdaoud_my_string_pop_back_valid_input(char* buffer, int length); 
Status test_mdaoud_my_string_at_valid_input(char* buffer, int length); 
Status test_mdaoud_my_string_at_out_of_bounds(char* buffer, int length); 
Status test_mdaoud_my_string_at_modify_value(char* buffer, int length);
Status test_mdaoud_my_string_concat_valid_input(char* buffer, int length);
Status test_mdaoud_my_string_empty_returns_true(char* buffer, int length);
Status test_mdaoud_my_string_empty_returns_false(char* buffer, int length);
Status test_mdaoud_my_string_destroy_returns_NULL(char* buffer, int length);
Status test_mdaoud_get_capacity_after_resize_returns_16(char* buffer, int length);
Status test_mdaoud_my_string_pop_back_empty_string_returns_FAILURE(char* buffer, int length);
Status test_mdaoud_my_string_get_size_after_pop_back_reduces_by_1(char* buffer, int length);
Status test_mdaoud_my_string_concat_with_empty_string_returns_original_string(char* buffer, int length); 
Status test_mdaoud_my_string_concat__NULL_string_returns_FAILURE(char* buffer, int length); 


#endif 