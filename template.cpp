using namespace::std;
#include "test_env.h" 
#include "test_env.cpp" 

//Your basic problem information like return/parameter type and testcases file name filled here.
#define ANSWER_TYPE return_type
#define PARA_TYPE parameters_type
#define SOLUTION solution_function_name
#define FILENAME "filename.txt"

#define INPUT_LISTNODE 0
#define INPUT_VECTOR_INT 0

#define RET_LISTNODE 0

//Your solution function here
class Solution{
public:/*
    static ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return NULL;
        ListNode* fast = head->next->next;
        ListNode* slow = head->next;
        while(fast != slow){
            if(fast->next == NULL || fast->next->next == NULL) return NULL;
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = head;
        
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }*/
};

template<typename ANS, typename PARA>
PARA tester<ANS, PARA>::test_resolver(string& testname){
	resolvers* res = new resolvers();
#if INPUT_LISTNODE == 1
	return res->ListNode_resolver(testname);
#elif INPUT_VECTOR_INT == 1
	return res->vector_int_resolver(testname);
#endif
	//your code here
}

template<typename ANS, typename PARA>
ANS tester<ANS, PARA>::ans_resolver(string& ansname, PARA para){
	resolvers* res = new resolvers();
#if INPUT_LISTNODE == 1 && RET_LISTNODE == 1
	return res->ListNode_ListNode_resolver(ansname, para);
#endif
	//your code here
}

template<typename ANS, typename PARA>
ANS solution_temp<ANS, PARA>::solve(PARA parameter){
	return Solution::SOLUTION(parameter);
}

int main(){
	tester<ANSWER_TYPE, PARA_TYPE> *t = new tester<ANSWER_TYPE, PARA_TYPE>();
	string filename = FILENAME;
	t->test(filename);
}
