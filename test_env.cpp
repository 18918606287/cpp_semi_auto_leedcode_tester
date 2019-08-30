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
