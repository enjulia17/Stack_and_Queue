#include "Queue.h"

#include <gtest.h>

TEST(Queue, can_create_Queue_with_positive_length)
{
	ASSERT_NO_THROW(Queue<int> v(7));
}

TEST(Queue, can_create_Queue_with_zero_size)
{
	ASSERT_NO_THROW(Queue<int> v(0));
}

TEST(Queue, throws_when_create_Queue_with_negative_length)
{
	ASSERT_ANY_THROW(Queue<int> v(-7));
}

TEST(Queue, IsFull)
{
	Queue<int>q(1);
	int t = 2;
	q.push(t);
	EXPECT_EQ(q.IsFull(), 1);
}

TEST(Queue, IsEmpty)
{
	Queue<int>q(1);
	int m = 2;
	q.push(m);
	q.pop();
	EXPECT_EQ(q.IsEmpty(), 1);
}

TEST(Queue, can_create_copied_Queue)
{
	Queue<int> v(13);

	ASSERT_NO_THROW(Queue<int> v1(v));
}

TEST(Queue, can_get_size)
{
	Queue<int> v(9);

	EXPECT_EQ(v.GetSize(), 9);
}

TEST(Queue, can_push_and_pop)
{
	Queue<int> A(6);
	int q = 6;
	A.push(q);
	EXPECT_EQ(A.pop(), 6);
}

TEST(Queue, can_pop_with_any_size)
{
	Queue<int> A;
	ASSERT_ANY_THROW(A.pop());
}

TEST(Queue, can_not_pop_out_of_size)
{
	Queue<int> A(7);
	ASSERT_ANY_THROW(A.pop());
}


