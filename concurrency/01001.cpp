#include <iostream> 
#include <thread>

using namespace std; 

void hello()
{
	std::cout << "Hello World!\n";
}

class background_task{
public: 
	void operator()() const{
		cout << "Hello from background\n" ; 
	}
};

int main()
{
	thread t(hello); 
	t.join(); 

	background_task f; 
	thread my_thread(f); 

	my_thread.join(); 

	return 0; 
}
