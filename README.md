# Global shifting using Multi-threading

Description :- 
  This task main aim is to achive multi threading using pthreads in which 3 threads simultaneously read 3 lines, line by line of a text file and print histogram of characters with their frequencies for every line.
This code has been coded in accordance with putty cluster in csx given by Oklahoma state university but it's working is universal.

Steps to run:-
  1)First all the linux commands will be handy here,if not linux you should load your own text file and change in the code, name of your input text file in main function in one of the paramaters in fopen.
  2)After loading of text file compiling must be done by using Linux commands or in accordance with your compiler.
  3) After compiling if Linux beside ./a.out you should mention your required thread numbers to process.
  4) Program will be executed and hashmap of every character as a key with frequency count will be given as out put depending upon number of threads you had given in command line.

Basic idea:-
  Globally shifting filepointer and reading file line fuction passing as parameter in pthread function.
  
Conclusion:-
  Multi threading can be  effectively achieved if all theads are joined and created properly.
