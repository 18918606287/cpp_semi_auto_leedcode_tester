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
#include<vector>

//Difinition of LinkedList node.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

class resolvers{
	public:
		resolvers();
		~resolvers();
		ListNode* ListNode_resolver(std::string& testname);
		ListNode* ListNode_ListNode_resolver(std::string& ansname, ListNode* para);
		vector<int> vector_int_resolver(std::string& testname);
};

template <typename ANS, typename PARA>
class solution_temp{
	public:
		ANS solve(PARA parameter);
};
#endif
