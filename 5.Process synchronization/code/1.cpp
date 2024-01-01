#include <iostream>
#include <thread>
#include <chrono> // Include for std::this_thread and std::chrono

int in{};
int out{};
int count{};
const int Buffersize{10};
int arr[Buffersize]{};
void Producer() {
	int i{};
	while(1)
	{
		std::cout<<__FUNCTION__<<std::endl;
		while(count==Buffersize);   
		arr[in] = i;
		i+=10;
		in = (in+1)%Buffersize;
		count ++;
		if(i == 100)
		i = 0;
		std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
	}
}

void Consumer() {
	int tmp{};
	while(1)
	{
		std::cout<<__FUNCTION__<<std::endl;
		while(count==0);  
		tmp =  arr[out];
		std::cout<<"Element "<<out<<" is "<<tmp<<std::endl;
		out= (out+1)%Buffersize;
		count --;
		std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
	}
}

int main() {


    std::thread t1(Producer);
    std::thread t2(Consumer);


    t1.join();
    t2.join();
    


    return 0;
}
