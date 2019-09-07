# Semi-auto Leetcode Tester

## Mention
This a c++ tester, which **can only uesed in C++**. I will update some common transfer functions ~~if I have time~~.

## Tutorial
Clone/Download the repo and open the file ``template.cpp``, then change the MACRO to the information of the problem you want to test.
```cpp
//Your basic problem information like return/parameter type and testcases file name filled here.
#define ANSWER_TYPE return_type
#define PARA_TYPE parameters_type
#define SOLUTION solution_function_name
#define FILENAME "filename.txt"
```

There are some **default** resolver functions, set the corresponding MACRO into 1 instead of 0.
```cpp
//For example, if your test input is ListNode*, set this into 1.
#define INPUT_LISTNODE 0
#define INPUT_VECTOR_INT 0
//Similarly, if your return value is ListNode*, set this into 1.
#define RET_LISTNODE 0
```
The supported **test type** including
+ ListNode*
+ vector<int>
The supported **answer type(test type, return type)** including
+ ListNode*, ListNode*
**Mention that if the type is the address of object like STL container, put the type without address identifier here.**

And there are two functions need to be coded yourself. ``test_resolver(string& testname)`` is to tranform your testcase string into a initialization of cpp and ``ans_resolver(string& ansname)`` is to transform your test correct answer into a cpp type.
```cpp
template<typename ANS, typename PARA>
PARA tester<ANS, PARA>::test_resolver(string& testname){
  //Your code here.
}

template<typename ANS, typename PARA>
ANS tester<ANS, PARA>::ans_resolver(string& ansname, PARA para){
  //Your code here.
}
```

I know it's not so convenient but I'm a newbie in cpp and tried my best to do this. If you have some better idea, feel free to PR. If there is anything wrong or confusing, please issue the problem or contact me by email.
