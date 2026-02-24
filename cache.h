#include <iostream>
#include <fstream>
#include <vector>
void genInput(int k, int m);
void genOutput(int fifo, int lifo, int optff);
int fifo(std::vector<int> cache);
int lifo(std::vector<int> cache);
int optff(std::vector<int> cache);