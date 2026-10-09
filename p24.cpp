#include <chrono>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> list;
    std::vector<int> baselist;
    std::vector<short> altbaselist;
    std::vector<int> listp;

    const int max=1000000;
    int base=5;
    short basenext=2;

    int max_i2=1;
    int counter=0;
    int count = 0;

    auto start = std::chrono::steady_clock::now();//<<<


    for (int i=0;i<max;i+=basenext){
        if (base*base<max){
            list.push_back(base*base);
            baselist.push_back(base);
            altbaselist.push_back(basenext);
        }
        count = 0;

        for (int i2=0;i2<max_i2;i2++){

            if (list[i2]==base){
                if (max_i2-1==i2){
                    max_i2++;
                }
                count++;

                if (altbaselist[i2]==2) {
                    list[i2] = ((baselist[i2])*2)+list[i2];
                    altbaselist[i2]=4;
                }else{
                    list[i2] = ((baselist[i2])*4)+list[i2];
                    altbaselist[i2]=2;
                }

                
            }
        }

        if(count == 0) {
            listp.push_back(base);//<<<
        }

        if((counter & 1)==0) {
            base+=2;
            basenext=4;
        }else{
            base+=4;
            basenext=2;
        }
        counter++;
    }

    
    auto end = std::chrono::steady_clock::now();//<<<
    std::chrono::duration<double> total = end - start;

    std::cout << "Time: "<<total.count() << "\n";
    std::cout << "Ran  5 - " << max << std::endl;
    std::cout << "P: " << listp.size() << std::endl;


    return 0;
}

