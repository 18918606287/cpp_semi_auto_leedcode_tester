#include "test_env.h" 
using namespace std;

template<typename ANS, typename PARA>
tester<ANS, PARA>::tester(){
	this->correct_answer = "";
	this->testcase = "";
}

template<typename ANS, typename PARA>
double tester<ANS, PARA>::test(string& filename){
	double acc = 0;
    int sum = 0;
	
	this->testcases.open(filename,ios::in);
	solution_temp<ANS, PARA>* solver = new solution_temp<ANS, PARA>();
	
	while(!this->testcases.eof()){
		getline(this->testcases, this->testcase);
        while(this->testcase == "" && !this->testcases.eof()) getline(this->testcases, this->testcase);
        if(this->testcases.eof()) break;
        sum++;
        cout<<testcase<<endl;
        getline(this->testcases, this->correct_answer);
        while(this->correct_answer == "" && !this->testcases.eof()) getline(this->testcases, this->correct_answer);
        if(this->testcases.eof() && this->correct_answer == "") break;
        cout<<correct_answer<<endl;
        PARA para = this->test_resolver(this->testcase);
        ANS ans = this->ans_resolver(this->correct_answer, para);
        ANS your_answer = solver->solve(para);
        if(ans == your_answer){
        	cout<<"Accepted!"<<endl;
        	acc++;
		} 
        else cout<<"Wrong Answer! The correct Answer is "<<ans<<" but your answer is "<<your_answer<<"."<<endl;;
	}
	acc = 1.0*acc/sum;
	
	cout<<"The accuracy of your solution in this testcase set of "<< sum << " tests is "<<(acc*100)<<"% ."<<endl;
	return acc;
}

resolvers::resolvers(){}

ListNode* resolvers::ListNode_resolver(string& testname){
	ListNode* head = new ListNode(0);
	ListNode* cur = head;
	int i = 0, j = 0;
	//find '['
	while(testname[i] != '[') i++;
	i++;
	j = i;
	while(j < testname.length()){
		while(testname[j] == ' ') j++;
		if(!isdigit(testname[j])){
			while(i < j && !isdigit(testname[i])) i++;
			if(i == j) break;
			int sub = stoi(testname.substr(i, j-i));
			cur->next = new ListNode(sub);
			cur = cur->next;
			i = j+1;
			if(testname[j] == ']') break;
		}
		j++;
	}
	int pos = stoi(testname.substr(j+1));
	if(head->next == NULL || pos == -1) return head->next;
	ListNode* end = cur; 
	cur = head->next;
	for(int i = 0; i < pos; i++) cur = cur->next;
	end->next = cur;
	cur = head;
	return head->next;
}

vector<int> resolvers::vector_int_resolver(string& testname){
	vector<int> container;
	int i = 0, j = 0;
	//find '['
	while(testname[i] != '[') i++;
	i++;
	j = i;
	while(j < testname.length()){
		while(testname[j] == ' ') j++;
		if(!isdigit(testname[j])){
			while(i < j && !isdigit(testname[i])) i++;
			if(i == j) break;
			int sub = stoi(testname.substr(i, j-i));
			container.push_back(sub);
			i = j+1;
			if(testname[j] == ']') break;
		}
		j++;
	}
	return container;
}

ListNode* resolvers::ListNode_ListNode_resolver(std::string& ansname, ListNode* para){
	if(!isdigit(ansname[0])) return NULL;
	ListNode* head = para;
	int pos = -1;
	pos = stoi(ansname);
	for(int i = 0 ; i < pos; i++){
		if(head == NULL)
			break;
		head = head->next;
	}
	return head;
}
