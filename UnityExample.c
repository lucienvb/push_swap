//
// Created by Lucien Van Bussel on 1/18/23.
//

#include "./unity/src/unity.h"
#include "push_swap.h"

void setUp(void) {
	// set stuff up here
}

void tearDown(void) {
	// clean stuff up here
}

void test_function_should_doBlahAndBlah(void) {
//	int 	argc = 1;
//	char	*argv[1];
//
//	argv[0] = "push_swap";
//	TEST_ASSERT_EQUAL(push_swap(argc, argv), NULL);
}

void test_function_should_doAlsoDoBlah(void) {
	//more test stuff
}

//typedef struct node
//{
//	int				content;
//	int				index;
//	int				size;
//	struct node		*next;
//}					t_node;

void test_already_sorted_true() {
	t_node *stack_1;
	t_node *stack_2;

	stack_1 = (t_node *) malloc(sizeof(t_node));
	stack_2 = (t_node *) malloc(sizeof(t_node));
	stack_2->content = 2;
	stack_2->next = NULL;
	stack_1->content = 1;
	stack_1->next = stack_2;

	t_node *stack_3;
	t_node *stack_4;

	stack_3 = (t_node *) malloc(sizeof(t_node));
	stack_4 = (t_node *) malloc(sizeof(t_node));
	stack_4->content = 1;
	stack_4->next = NULL;
	stack_3->content = 2;
	stack_3->next = stack_4;

	TEST_ASSERT_EQUAL(0, reversed_sorted(stack_1));
	TEST_ASSERT_EQUAL(1, reversed_sorted(stack_3));

}

// not needed when using generate_test_runner.rb
int main(void) {
	UNITY_BEGIN();
//	RUN_TEST(test_function_should_doBlahAndBlah);
//	RUN_TEST(test_function_should_doAlsoDoBlah);
	RUN_TEST(test_already_sorted_true);
	return UNITY_END();
}