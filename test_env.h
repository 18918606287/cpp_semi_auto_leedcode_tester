#ifndef TEST_H
#define TEST_H

#include<stdio.h>
#include<iostream>
#include <fstream>
#include<string>
#include<ctype.h>
#include<stdlib.h>
#include<string>
#include<fstream>

template <typename ANS, typename PARA>
class tester{
	private:
		std::fstream testcases;
		std::string testcase;
		std::string correct_answer;
		ANS solutiion_answer;
	public:
		tester();
		~tester();
		double test(std::string& filename);
		PARA test_resolver(std::string& testname);
		ANS ans_resolver(std::string& ansname, PARA para);
};

template <typename ANS, typename PARA>
class solution_temp{
	public:
		ANS solve(PARA parameter);
};
#endif
