#include "cache.h"

//random input
void genInput(int k, int m){
    std::vector<int> requests;
    std::ofstream file("input.txt");
    file<<k<<" "<<m;
    //random IDs from 1 to 20
    for(int i=0; i<m; i++){
          file<<((std::rand() % 20) + 1)<<" ";
    }
}

//format output with #misses for each algorithm
void genOutput(int fifo, int lifo, int optff){
    std::ofstream file("output.txt");
    file<<"FIFO: "<<fifo<<std::endl<<"LIFO: "<<lifo<<std::endl<<"OPTFF: "<<optff<<std::endl;
}

//first in, first out
int fifo(std::vector<int> cache){

}
//last in, first out
int lifo(std::vector<int> cache){

}
//evict request that occurs farthest in the future (or never occurs again).
int optff(std::vector<int> cache){

}

int main(){
    return 0;
}