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


//========================================
//== test cases for count leading chars ==
//========================================
TEST(PasswordTest, count_leading_no_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, count_leading_single_letter_lower_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, count_leading_single_letter_upper_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, count_leading_multi_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZZZ");
	ASSERT_EQ(4, actual);
}

TEST(PasswordTest, count_leading_upper_and_lower_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaaAAAaAA");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, count_leading_number_test_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("1234321");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, count_leading_longer_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("7777777656777");
	ASSERT_EQ(7, actual);
}

TEST(PasswordTest, count_leading_multi_number_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("33322333");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, count_leading_three_leading_space_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("   threespaces");
	ASSERT_EQ(3, actual);
}


//========================================
//== test cases for unique characters   ==
//========================================
TEST(PasswordTest, unique_characters_empty)
{
	Password my_password;
	unsigned int result = my_password.unique_characters("");
	ASSERT_EQ(result,0);
}

TEST(PasswordTest, unique_characters_single_letter)
{
	Password my_password;
	unsigned int result = my_password.unique_characters("a");
	ASSERT_EQ(result,1);
}

TEST(PasswordTest, unique_characters_single_space)
{
	Password my_password;
	unsigned int result = my_password.unique_characters(" ");
	ASSERT_EQ(result,1);
}

TEST(PasswordTest, unique_characters_multi_single_character)
{
	Password my_password;
	unsigned int result = my_password.unique_characters("aaaaa");
	ASSERT_EQ(result,1);
}

TEST(PasswordTest, unique_characters_lower_upper_same_character_short)
{
	Password my_password;
	unsigned int result = my_password.unique_characters("aA");
	ASSERT_EQ(result,2);
}

TEST(PasswordTest, unique_characters_upper_lower_same_character_short)
{
	Password my_password;
	unsigned int result = my_password.unique_characters("Aa");
	ASSERT_EQ(result,2);
}

TEST(PasswordTest, unique_characters_lower_upper_same_character_longer)
{
	Password my_password;
	unsigned int result = my_password.unique_characters("aaaaaAAAAA");
	ASSERT_EQ(result,2);
}

TEST(PasswordTest, unique_characters_upper_lower_same_character_longer)
{
	Password my_password;
	unsigned int result = my_password.unique_characters("AAAAAaaaaa");
	ASSERT_EQ(result,2);
}

TEST(PasswordTest, unique_characters_mixed_lower)
{
	Password my_password;
	unsigned int result = my_password.unique_characters("abcdabcd");
	ASSERT_EQ(result,4);
}

TEST(PasswordTest, unique_characters_mixed_lower_then_upper)
{
	Password my_password;
	unsigned int result = my_password.unique_characters("abcdABCD");
	ASSERT_EQ(result,8);
}

TEST(PasswordTest, unique_characters_multi_space)
{
	Password my_password;
	unsigned int result = my_password.unique_characters("     ");
	ASSERT_EQ(result,1);
}


//========================================
//== test cases for mixed case          ==
//========================================
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
