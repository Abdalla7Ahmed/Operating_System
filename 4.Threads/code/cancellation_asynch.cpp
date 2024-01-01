#include <iostream>
#include <thread>
#include <chrono> // Include for std::this_thread and std::chrono
bool cancellation_flag = false;
void printprogress() {
    for (int i = 10; i <=100; i+=10) {
    	if(cancellation_flag == false)
    	{
        	std::cout << "copying files {" <<i<<"} % completed"<<std::endl;
        	std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Sleep for 500 milliseconds
        }
        else
        {
        	std::cout<<"Deleting copied files "<<std::endl;
        	std::cout<<"---------- copied cancelled sucessfully"<<std::endl;
        	return;
        }
    }
    std::cout<<"---------- copying files done sucessfully"<<std::endl;
}

int main() {


    std::thread t1(printprogress);



    t1.detach();
    std::this_thread::sleep_for(std::chrono::milliseconds(1500)); // Sleep for 1500 milliseconds   
    cancellation_flag  = true;
 
    int a;
    std::cin>>a;
    return 0;
}
