/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};


TEST(PasswordTest, no_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, single_letter_lower_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, single_letter_upper_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, multi_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZZZ");
	ASSERT_EQ(4, actual);
}

TEST(PasswordTest, upper_and_lower_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaaAAAaAA");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, number_test_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("1234321");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, longer_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("7777777656777");
	ASSERT_EQ(7, actual);
}

TEST(PasswordTest, multi_number_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("33322333");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, three_leading_space_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("   threespaces");
	ASSERT_EQ(3, actual);
}

