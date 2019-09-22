#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#include <conio.h>
#include "ChiliString.h"
#include "Stack.h"
#include <iostream>
#include <vector>
//#include <forward_list>
#include <list>
//#include <iterator>

void test1()
{
	Stack s;
	s.Push( 5 );
	s.Push( 3 );
	if( s.Pop() == 3 && s.Pop() == 5 && s.Empty() )
	{
		chili::print( "    Test 1 passed!\n" );
	}
	else
	{
		chili::print( "*** Test 1 failed!\n" );
	}
}

void test2()
{
	Stack s;
	s.Push( 5 );
	s.Push( 3 );
	s.Push( 3 );
	s.Push( 3 );
	if( s.Size() == 4  )
	{
		chili::print( "    Test 2 passed!\n" );
	}
	else
	{
		chili::print( "*** Test 2 failed!\n" );
	}
}

void test3()
{
	Stack s;
	s.Push( 5 );
	s.Push( 3 );
	s.Pop();
	s.Push( 69 );
	s.Push( 69 );
	s.Push( 69 );
	s.Push( 69 );
	s.Pop();
	s.Pop();
	s.Pop();
	if( s.Size() == 2 )
	{
		chili::print( "    Test 3 passed!\n" );
	}
	else
	{
		chili::print( "*** Test 3 failed!\n" );
	}
}

void test4()
{
	Stack s;
	s.Push( 5 );
	s.Push( 3 );
	s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();
	if( s.Size() == 0 )
	{
		chili::print( "    Test 4 passed!\n" );
	}
	else
	{
		chili::print( "*** Test 4 failed!\n" );
	}
}

void test5()
{
	Stack s;
	s.Push( 5 );
	s.Push( 3 );

	Stack s2 = s;
	s2.Pop();

	if( s.Size() == 2 && s2.Pop() == 5 )
	{
		chili::print( "    Test 5 passed!\n" );
	}
	else
	{
		chili::print( "*** Test 5 failed!\n" );
	}
}

void test6()
{
	Stack s;
	s.Push( 5 );
	s.Push( 3 );

	{
		Stack s2 = s;
		s2.Pop();
	}

	if( s.Size() == 2 && s.Pop() == 3 )
	{
		chili::print( "    Test 6 passed!\n" );
	}
	else
	{
		chili::print( "*** Test 6 failed!\n" );
	}
}

void test7()
{
	Stack s;
	s.Push( 5 );
	s.Push( 3 );

	Stack s2;
	s2 = s;
	s2.Pop();

	if( s.Size() == 2 && s2.Pop() == 5 )
	{
		chili::print( "    Test 7 passed!\n" );
	}
	else
	{
		chili::print( "*** Test 7 failed!\n" );
	}
}

void test8()
{
	Stack s;
	s.Push( 5 );
	s.Push( 3 );

	{
		Stack s2;
		s2 = s;
		s2.Pop();
	}

	if( s.Size() == 2 && s.Pop() == 3 )
	{
		chili::print( "    Test 8 passed!\n" );
	}
	else
	{
		chili::print( "*** Test 8 failed!\n" );
	}
}

void test9()
{
	Stack s;
	s.Push( 5 );
	s.Push( 3 );

	{
		Stack s2;
		s2.Push( 828374 );
		s2.Push( 3454 );
		s2 = s;
		s2.Pop();
	}

	if( s.Size() == 2 && s.Pop() == 3 )
	{
		chili::print( "    Test 9 passed!\n" );
	}
	else
	{
		chili::print( "*** Test 9 failed!\n" );
	}
}
void test10()
{
	Stack s;
	s.Push( 5 );
	s.Push( 3 );

	s = s;

	{
		Stack s2;
		s2.Push( 828374 );
		s2.Push( 3454 );
		s2 = s;
		s2.Pop();
	}

	if( s.Size() == 2 && s.Pop() == 3 )
	{
		chili::print( "    Test 10 passed!\n" );
	}
	else
	{
		chili::print( "*** Test 10 failed!\n" );
	}
}

template<typename Iter1, typename Iter2, typename Iter3>
void sum(Iter1 in1, Iter1 end1, Iter2 in2, Iter3 out)
{
	for (; in1 != end1; ++in1, ++in2, ++out)
	{
		*out = *in1 + *in2;
	}
}

int main()
{
	_CrtSetReportMode( _CRT_WARN,_CRTDBG_MODE_FILE );
	_CrtSetReportFile( _CRT_WARN,_CRTDBG_FILE_STDERR );
	_CrtSetReportMode( _CRT_ERROR,_CRTDBG_MODE_FILE );
	_CrtSetReportFile( _CRT_ERROR,_CRTDBG_FILE_STDERR );
	_CrtSetReportMode( _CRT_ASSERT,_CRTDBG_MODE_FILE );
	_CrtSetReportFile( _CRT_ASSERT,_CRTDBG_FILE_STDERR );
	
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();

	/////////////////////////////////////////////////////////////////////
	// I15 homework stuff!!
	/////////////////////////////////////////////////////////////////////
	// level 1
	{
		std::vector<int> vi{ 0,1,2,3,4,5,6,7 };
		std::vector<float> vf{ 0.0f,0.1f,0.2f,0.3f,0.4f,0.5f,0.6f,0.7f };

		sum( vi.begin(), vi.end(), vf.begin(), std::ostream_iterator<float>(std::cout, ", ") );
		std::cout << std::endl;

		std::list<float> lf;
		//lf.resize(8);
		//sum(vi.begin(), vi.end(), vf.begin(), lf.begin() );
		sum(vi.begin(), vi.end(), vf.begin(), std::back_insert_iterator<std::list<float>>(lf) );

		for (float v : lf)
		{
			std::cout << v << ", ";
		}
		/*
		Stack s;
		s.Push( 520 );
		s.Push( 79 );
		s.Push( 8168118 );
		s.Push( 6311369 );

		// multiply all elements by 10
		for( auto& n : s )
		{
			n *= 10;
		}
		for (auto n : s)
		{
			std::cout << n << ", ";
		}
		std::cout << std::endl;
		
		std::reverse(s.begin(), s.end());

		//print out all elements
		for( auto n : s )
		{
			std::cout << n << ", ";
		}
		std::cout << std::endl;
	*/
	}
	

	//// level 2 (uncomment to challenge)
	//{
	//	Stack s;
	//	s.Push( 520 );
	//	s.Push( 79 );
	//	s.Push( 8168118 );
	//	s.Push( 6311369 );

	//	const Stack& cs = s;
	//	for( auto& n : cs )
	//	{
	//		std::cout << n << ", ";
	//	}
	//	std::cout << std::endl;
	//}

	/////////////////////////////////////////////////////////////////////

	_CrtDumpMemoryLeaks();
	while( !_kbhit() );
	return 0;
}