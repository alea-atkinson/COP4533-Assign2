# COP4533 Programming Assignment 2  
**To Run:**
1. Clone the repository into a code editor such as vs code
2. To genereate a cache.exe file, run the following command in the terminal: **g++ -o cache cache.cpp**
3. To run the executable, run the following command in the terminal: **./cache k m**. you must provide 2 command line arguments. The first argument k determines the size of the cache, and the second argument m determines the number of requests: ex. ./cache 5 55 runs with a cache of size 5 and 55 request
4. Running the executable will automatically create a randomlly generated input file with the specified input format with integer IDs ranging from 1 to 20. This file is created in the io folder: io/input.txt
5. Running the executable will also create an output file in io: io/output.txt. This file allows you to view the results of each cache policy. Ex. FIFO: 45 indicates that the FIFO policy resulted in 45 misses  
**View Written Questions**
* The written answers can be accessed in the written_component folder
* For question 1, the files in the table correspond to the input and output are located in the written_component/input and written_component/output respectively
* All written answers are located in written_component/written_questions.pdf
