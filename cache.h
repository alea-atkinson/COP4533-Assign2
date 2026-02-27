#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <functional>
#include <sstream>
void genInput(int k, int m);
void genOutput(int fifo, int lifo, int optff);
std::vector<int> readInput();
int fifo(std::vector<int> requests, int k);
int lru(std::vector<int> requests, int k);
int optff(std::vector<int> requests, int k);