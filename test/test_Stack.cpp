#include "Stack.h"

#include <gtest.h>

TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack<int> v(13));
}

TEST(Stack, can_create_stack_with_zero_size)
{
    ASSERT_NO_THROW(Stack<int> v(0));
}

TEST(Stack, throws_when_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(Stack<int> v(-13));
}

TEST(Stack, IsFull)
{
	Stack<int>q(1);
	int t = 2;
	q.push(t);
	EXPECT_EQ(q.IsFull(), 1);
}

TEST(Stack, IsEmpty)
{
	Stack<int>q(1);
	int t = 2;
	q.push(t);
	q.pop();
	EXPECT_EQ(q.IsEmpty(), 1);
}

TEST(Stack, can_create_copied_Stack)
{
 Stack<int> v(7);

  ASSERT_NO_THROW(Stack<int> v1(v));
}

TEST(Stack, can_get_size)
{
  Stack<int> v(12);

  EXPECT_EQ(v.GetSize(), 12);
}

TEST(Stack, can_push_and_pop)
{
	Stack<int> A(7);
	int q = 7;
	A.push(q);
	EXPECT_EQ(A.pop(), 7);
}

TEST(Stack, can_pop_with_any_size)
{
	Stack<int> A;
	ASSERT_ANY_THROW(A.pop());
}

TEST(Stack, can_not_pop_out_of_size)
{
	Stack<int> A(13);
	ASSERT_ANY_THROW(A.pop());
}