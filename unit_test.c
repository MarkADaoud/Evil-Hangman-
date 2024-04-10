#include <stdio.h>
#include "unit_test.h"

int main(int argc, char* argv[])
{
 Status (*tests[])(char*, int) =
 {
  test_init_default_returns_nonNULL, 
  test_get_size_on_init_default_returns_0, 
  test_mdaoud_test_init_c_string_returns_nonNULL,
  test_mdaoud_test_get_size_after_init_c_string_returns_strlen,
  test_mdaoud_get_capacity_on_init_default_returns_8,
  test_mdaoud_string_compare_identical_strings_returns_0,
  test_mdaoud_string_compare_identical_strings_returns_greater_than_0,
  test_mdaoud_string_compare_identical_strings_returns_less_than_0,
  test_mdaoud_my_string_c_str_valid_input, 
  test_mdaoud_get_capacity_after_resize_returns_16,
  test_mdaoud_my_string_insertion_valid_input,
  test_mdaoud_my_string_push_back_valid_input,
  test_mdaoud_my_string_pop_back_valid_input,
  test_mdaoud_my_string_at_valid_input,
  test_mdaoud_my_string_at_out_of_bounds,
  test_mdaoud_my_string_at_modify_value,
  test_mdaoud_my_string_concat_valid_input,
  test_mdaoud_my_string_empty_returns_true,
  test_mdaoud_my_string_empty_returns_false,
  test_mdaoud_my_string_destroy_returns_NULL,
  test_mdaoud_get_capacity_after_resize_returns_16,
  test_mdaoud_my_string_pop_back_empty_string_returns_FAILURE,
  test_mdaoud_my_string_get_size_after_pop_back_reduces_by_1,
  test_mdaoud_my_string_concat_with_empty_string_returns_original_string,
  test_mdaoud_my_string_concat__NULL_string_returns_FAILURE
 };
 int number_of_functions = sizeof(tests) / sizeof(tests[0]);
 int i;
 char buffer[500];
 int success_count = 0;
 int failure_count = 0;
 for(i=0; i<number_of_functions; i++)
 {
 if(tests[i](buffer, 500) == FAILURE)
 {
 printf("FAILED: Test %d failed miserably\n", i);
 printf("\t%s\n", buffer);
 failure_count++;
 }
 else
 {
// printf("PASS: Test %d passed\n", i);
// printf("\t%s\n", buffer);
 success_count++;
 }
 }
 printf("Total number of tests: %d\n", number_of_functions);
 printf("%d/%d Pass, %d/%d Failure\n", success_count,
 number_of_functions, failure_count, number_of_functions);
 return 0;
}
