#include"library_management.h"
#include"unity_internals.h"
#include"unity.h"

void setUp(){}

void tearDown(){}


void test_enter_new_record(void){
    TEST_ASSERT_EQUAL(pass,enter_new_record(900, "Wings of freedom"));
}

void test_view_all_records(void){
    TEST_ASSERT_EQUAL(pass,view_all_records());
}

void test_view_a_record(void){
    TEST_ASSERT_EQUAL(fail,view_a_record(-2));
    TEST_ASSERT_EQUAL(pass,view_a_record(900));
}

void test_update_record(void){
    TEST_ASSERT_EQUAL(pass,update_record(900, "issued", "21/01/21", "31/01/31", "Anupam","Gupta", 123));
}

void test_delete_record(void){
    TEST_ASSERT_EQUAL(pass,delete_record(900));
}

int main(){
    UNITY_BEGIN();

    RUN_TEST(test_enter_new_record);
    RUN_TEST(test_view_a_record);
    RUN_TEST(test_update_record);
    RUN_TEST(test_delete_record);
    RUN_TEST(test_view_all_records);
    
    return UNITY_END();
}