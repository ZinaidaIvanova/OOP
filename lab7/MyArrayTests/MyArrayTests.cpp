#include "stdafx.h"
#include "../MyArray/MyArray.h"

struct ArrayItem
{
	ArrayItem(int value = 0)
		: value(value)
	{
	}
	int value;
};


TEST_CASE("Empty arrray has zero size and zero capacity")
{
	CMyArray<ArrayItem> arr;
	CHECK(arr.GetSize() == 0);
	CHECK(arr.GetCapacity() == 0);
};

TEST_CASE("Сan add elements to the end of the array")
{
	CMyArray<ArrayItem> arr;
	ArrayItem el(-1);
	arr.Append(1);
	CHECK(arr.GetSize() == 1);
	CHECK(arr.GetCapacity() == 1);
	arr.Append(el);
	CHECK(arr.GetSize() == 2);
	CHECK(arr.GetCapacity() == 2);
	arr.Append(el);
	CHECK(arr.GetSize() == 3);
	CHECK(arr.GetCapacity() == 4);
	arr.Append(el);
	CHECK(arr.GetSize() == 4);
	CHECK(arr.GetCapacity() == 4);
	arr.Append(el);
	CHECK(arr.GetSize() == 5);
	CHECK(arr.GetCapacity() == 8);
}

TEST_CASE("Can get and change array element by []-operator from the available range")
{
	CMyArray<float> numArray;
	numArray.Append(1.0f);
	numArray.Append(-2.4f);
	numArray.Append(3.0f);
	
	CHECK(numArray[0] == 1.0f);
	CHECK(numArray[1] == -2.4f);
	CHECK(numArray[2] == 3.0f);

	numArray[1] = 4.0f;
	CHECK(numArray[1] == 4.0f);

	CMyArray<std::string> strArray;
	strArray.Append("one");
	strArray.Append("two");
	strArray.Append("three");

	CHECK(strArray[0] == "one");
	CHECK(strArray[1] == "two");
	CHECK(strArray[2] == "three");

	strArray[0] = "four";
	CHECK(strArray[0] == "four");
}


TEST_CASE("When index is out of array range can get exception ")
{ 
	CMyArray<float> numArray;
	numArray.Append(1.0f);
	numArray.Append(-2.4f);
	numArray.Append(3.0f);

	CHECK_THROWS_AS(numArray[3], std::out_of_range);

	CMyArray<std::string> strArray;
	strArray.Append("one");
	strArray.Append("two");
	strArray.Append("three");

	CHECK_THROWS_AS(strArray[3], std::out_of_range);
}


TEST_CASE("Can resize array")
{
	CMyArray<ArrayItem> arr;
	ArrayItem el1(-1), el2(2);
	arr.Append(el1);
	arr.Append(el2);
	arr.Append(el1);

	//arr.Resize(1);
	//CHECK(arr.GetSize() == 1);
	//CHECK(arr.GetCapacity() == 4);
}

TEST_CASE("Can clear array")
{
	CMyArray<ArrayItem> arr;
	ArrayItem el1(-1), el2(2);
	arr.Append(el1);
	arr.Append(el2);
	arr.Append(el1);
	arr.Clear();
	CHECK(arr.GetSize() == 0);
	CHECK(arr.GetCapacity() == 4);
}

TEST_CASE("Can move array")
{
	CMyArray<int> arr;
	arr.Append(1);
	arr.Append(2);
	arr.Append(-1);
	arr.Append(-1);
	arr.Append(-1);

	CMyArray<int> arrCopy(std::move(arr));
	CHECK(arrCopy.GetSize() == 5);
	CHECK(arrCopy.GetCapacity() == 8);
	CHECK(arr.GetSize() == 0);
	CHECK(arr.GetCapacity() == 0);
}

TEST_CASE("Exist assignment operator for array")
{
	CMyArray<int> arr;
	arr.Append(1);
	arr.Append(2);
	arr.Append(2);

	CMyArray<int> arrCopy;
	arrCopy = arr;
	CHECK(arrCopy.GetSize() == arr.GetSize());
	CHECK(arrCopy.GetCapacity() == arr.GetCapacity());
}

