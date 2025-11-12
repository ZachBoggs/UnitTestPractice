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




TEST(PasswordTest, mixed_case_empty)
{
	Password my_password;
	bool result = my_password.has_mixed_case("");
	ASSERT_FALSE(result);
}

TEST(PasswordTest, mixed_case_lower_then_upper)
{
	Password my_password;
	bool result = my_password.has_mixed_case("aA");
	ASSERT_TRUE(result);
}

TEST(PasswordTest, mixed_case_upper_then_lower)
{
	Password my_password;
	bool result = my_password.has_mixed_case("Aa");
	ASSERT_TRUE(result);
}

TEST(PasswordTest, mixed_case_long_lower_then_upper)
{
	Password my_password;
	bool result = my_password.has_mixed_case("aaaaaA");
	ASSERT_TRUE(result);
}

TEST(PasswordTest, mixed_case_long_upper_then_lower)
{
	Password my_password;
	bool result = my_password.has_mixed_case("AAAAAa");
	ASSERT_TRUE(result);
}

TEST(PasswordTest, mixed_case_mix_letters_lower_then_upper)
{
	Password my_password;
	bool result = my_password.has_mixed_case("abcABC");
	ASSERT_TRUE(result);
}

TEST(PasswordTest, mixed_case_short_all_lower)
{
	Password my_password;
	bool result = my_password.has_mixed_case("aa");
	ASSERT_FALSE(result);
}

TEST(PasswordTest, mixed_case_short_all_upper)
{
	Password my_password;
	bool result = my_password.has_mixed_case("AA");
	ASSERT_FALSE(result);
}

TEST(PasswordTest, mixed_case_mixed_all_lower)
{
	Password my_password;
	bool result = my_password.has_mixed_case("abcabc");
	ASSERT_FALSE(result);
}

TEST(PasswordTest, mixed_case_char_under_A_then_lower)
{
	Password my_password;
	bool result = my_password.has_mixed_case("@a");
	ASSERT_FALSE(result);
}

TEST(PasswordTest, mixed_case_char_above_Z_then_lower)
{
	Password my_password;
	bool result = my_password.has_mixed_case("[a");
	ASSERT_FALSE(result);
}

TEST(PasswordTest, mixed_case_upper_then_char_under_a)
{
	Password my_password;
	bool result = my_password.has_mixed_case("A`");
	ASSERT_FALSE(result);
}

TEST(PasswordTest, mixed_case_upper_then_char_above_z)
{
	Password my_password;
	bool result = my_password.has_mixed_case("A{");
	ASSERT_FALSE(result);
}

TEST(PasswordTest, mixed_case_lower_then_space)
{
	Password my_password;
	bool result = my_password.has_mixed_case("a ");
	ASSERT_FALSE(result);
}

TEST(PasswordTest, mixed_case_spaces)
{
	Password my_password;
	bool result = my_password.has_mixed_case("a A");
	ASSERT_TRUE(result);
}
