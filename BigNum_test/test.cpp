#include "pch.h"
#include "D:\BuiAnhKent_Add2Num_VS\BigNum_test\BigNum\BigNum.h"

MyBigNumber myBigNumber;


TEST(StringAddition, BaseTest) {
	EXPECT_EQ("9197990", myBigNumber.sum("0000000001", "9197989"));
}
TEST(StringAddition, EmptyStrings) {
	EXPECT_EQ("", myBigNumber.sum("", ""));
}

TEST(StringAddition, FirstStringEmpty) {
	EXPECT_EQ("123", myBigNumber.sum("", "123"));
}

TEST(StringAddition, SecondStringEmpty) {
	EXPECT_EQ("456", myBigNumber.sum("456", ""));
}

TEST(StringAddition, SameLengthStrings) {
	EXPECT_EQ("579", myBigNumber.sum("123", "456"));
}

TEST(StringAddition, DifferentLengthStrings1) {
	EXPECT_EQ("1245", myBigNumber.sum("123", "1122"));
}

TEST(StringAddition, DifferentLengthStrings2) {
	EXPECT_EQ("1010", myBigNumber.sum("99", "911"));
}

TEST(StringAddition, LargeNumbers1) {
	EXPECT_EQ("123457800", myBigNumber.sum("123456789", "1011"));
}

TEST(StringAddition, LargeNumbers2) {
	EXPECT_EQ("10000000000000000000000000000000000000000000000000000000000000000000000000000000",
		myBigNumber.sum("9999999999999999999999999999999999999999999999999999999999999999999999999999999",
			"1"));
}
TEST(StringAddition, LeadingZeros) {
	EXPECT_EQ("300", myBigNumber.sum("000150", "150"));
}

