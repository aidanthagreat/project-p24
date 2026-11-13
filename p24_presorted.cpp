#include <chrono>
#include <iostream>
#include <vector>
#include <utility>



int main() {


    std::vector<int> list;
    std::vector<int> baselist;
    std::vector<short> altbaselist;
    std::vector<int> listp;

    const int max = 1000000;
    int base=5;
    short basenext=2;

    int max_i=0;
    int copy_max_i=0;
    int counter=0;
    int count = 0;
    bool pflag=false;

    auto start = std::chrono::steady_clock::now();//<<<


    for (int i=0;i<max;i+=basenext){
        pflag = true;
        if (base != 0 && base < max / base) {
            list.push_back(base*base);
            baselist.push_back(base);
            altbaselist.push_back(basenext);
        }
        while (list[max_i] == base) {
            pflag = false;
            if (altbaselist[max_i] == 2) {
                list[max_i] = ((baselist[max_i]) * 2) + list[max_i];
                altbaselist[max_i] = 4;
            }
            else {
                list[max_i] = ((baselist[max_i]) * 4) + list[max_i];
                altbaselist[max_i] = 2;
            }

            copy_max_i = max_i;
            while (copy_max_i != list.size() - 1 && list[copy_max_i] > list[copy_max_i + 1]) {
                std::swap(list[copy_max_i], list[copy_max_i + 1]);
                std::swap(baselist[copy_max_i], baselist[copy_max_i + 1]);
                std::swap(altbaselist[copy_max_i], altbaselist[copy_max_i + 1]);
                copy_max_i++;
            }//r
        }//r
        max_i = 0;

        if (pflag) {
            listp.push_back(base);//<<<
        }

        if ((counter & 1) == 0) {
            base += 2;
            basenext = 4;
        }
        else {
            base += 4;
            basenext = 2;
        }
        counter++;

    }//r

    
    auto end = std::chrono::steady_clock::now();//<<<
    std::chrono::duration<double> total = end - start;
    std::cout << "Mem: " << list.size() << " " << baselist.size() << " " << altbaselist.size() << std::endl;
    std::cout << "Time: "<<total.count() << "\n";
    std::cout << "Ran  5 - " << max << std::endl;
    std::cout << "P: " << listp.size() << std::endl;


    return 0;
}



