#include <iostream>
#include <thread>
#include <chrono> // Include for std::this_thread and std::chrono

int count{};
#define number_of_iteration 1000000
void Producer() {
	for(int i=0;i<number_of_iteration;i++)
	{
		count ++;
	}

}

void Consumer() {

	for(int i=0;i<number_of_iteration;i++)
	{
		count --;
	}

}

int main() {


    std::thread t1(Producer);
    std::thread t2(Consumer);


    t1.join();
    t2.join();
    
    std::cout<<"the final value of count is "<<count<<std::endl;
    if(count == 0)
    {
    	std::cout<<"no race condition occur"<<std::endl;
    }
    else
    {
     	std::cout<<"race condition detect"<<std::endl;   	
    }
    


    return 0;
}
