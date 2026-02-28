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
    file.close();
}

//format output with #misses for each algorithm
void genOutput(int fifo, int lru, int optff){
    std::ofstream file("output.txt");
    file<<"FIFO: "<<fifo<<std::endl<<"LRU: "<<lru<<std::endl<<"OPTFF: "<<optff<<std::endl;
    file.close();
}
std::vector<int> readInput(){
    std::vector <int>requests;
    std::ifstream file("input.txt");
    //invalid
    if (!file) {
        return requests;
    }
    std::string line;
    int count=0;
    int firstLine=0;
    while (file >> line) { // Reads one line at a time
        std::stringstream ss(line); //Create a stringstream from the line
        std::string process;
        while (std::getline(ss, process, ' ')) { 
            requests.push_back(stoi(process));
        } 
        if(count==0){
            firstLine=requests.size(); //how many ints are in the first line?
        }
        count++;
    }
    file.close();

    if(requests[0]<1){ //capacity less than 1
        requests.empty();
    }
    else if(count<2){ //only 1 line
        requests.empty();
    }
    else if(firstLine!=2){ //incorrect formatting of first line
        requests.empty();
    }
    else if(requests.size()-2 != requests[1]){ //num of requests doesn't match input
        requests.empty();
    }
    //first two elements are k and m, rest are requests
    return requests;
    
}

//first in, first out
int fifo(std::vector<int> requests, int k)
{
    int misses = 0;
    std::queue<int> cache;
    std::vector<int> requestsInCache;

    for (int req : requests)
    {
        // Hit
        if (std::find(requestsInCache.begin(), requestsInCache.end(), req) != requestsInCache.end())
        {
            continue;
        }
        // Miss
        else
        {
            misses++;
            
            if (cache.size() == k)
            {
                int front = cache.front();
                cache.pop();
                requestsInCache.erase(std::find(requestsInCache.begin(), requestsInCache.end(), front));
            }
            
            cache.push(req);
            requestsInCache.push_back(req);
        }
    }
    
    return misses;
}

//last in, first out
int lru(std::vector<int> requests, int k){

}

//evict request that occurs farthest in the future (or never occurs again).
int optff(std::vector<int> requests, int k){
    
}

int main(){
    std::vector<int> requests= readInput();
    if(requests.size()==0){
        std::cout<<"Invalid file"<<std::endl;
        return -1;
    }
    //populate k and m and remove them from vector
    int k= requests[0];
    int m= requests[1];
    requests.erase(requests.begin() + 0);
    requests.erase(requests.begin() + 1);
    //execute algorithms
    int fifoOut= fifo(requests, k);
    int lruOut= lru(requests, k);
    int optffOut=optff(requests, k);
    //format output
    genOutput(fifoOut, lruOut, optffOut);
    return 0;
}