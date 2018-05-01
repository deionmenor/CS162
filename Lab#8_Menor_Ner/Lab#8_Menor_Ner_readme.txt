This lab shows how to programs can use the same memory through shared memory.

1.) Create a textfile and put a random string of digits and numbers in the first line. This will act as our source.
2.) After compiling the producer file, enter the command ./producer [name of source file] [shared memory size in bytes]
3.) After compiling the consumer file, enter the command ./consumer [name of destination file] [shared memory size in bytes]
4.) The destination file should contain the string inputted in the source file
