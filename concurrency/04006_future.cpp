#include <future>
#include <iostream>

using namespace std; 

int find_the_answer_to_ltuae(){
	return 100;
}

void do_other_stuff(){
	int i=0;
    while (i++<20) cout << i << " ";
    cout << endl; 
}


int main()

{
    std::future<int> the_answer=std::async(find_the_answer_to_ltuae);
    

	std::cout<<"The answer is "<<the_answer.get()<<std::endl;
}