# Laboration 4

## Environment & Tools
windows 10 Operating system, CLion 2019.3.3 IDE, Microsoft 
C++ (MSVC) compiler, CMake version: 3.15.6, Git version: 2.25.0.windows.1
## Purpose
The purpose of this lab is to practice on the implementation of exception 
handling in combination with Templates and I0-streams.

## Procedures
A program is written to read values stored on the file and filtered for 
errors from values outside specified range and values with non numeric characters,
The program makes use of two classes. The DataFileReader class reads values 
from the given file and filter values for values with non numeric characters.
The DataFilter class filters values read by the DataFileReader class and 
return an exception when the value lies outside a specified range.
The program then prints out data on; Number of values read, Number of values out of range,
Sum of values read and Average of values read.

## Discussion
I have met the goal of this lab since I have written a working program with the
expected results using the various principles stated in the purpose. In my solution 
I used exception handling in DataFilter class by throwing a exception when a wrong 
value is read which is later caught and stored in the errorFile. I also used exception handling 
in the DataFileReader class by using std::ios_base::failure -exceptions (eofbit, failbit and badbit)
to control for errors when reading file. I also used throw runtime_error exception to control for errors with opening my files.
Both classes was writen in Template format. ifstream and ofstream was used to read from file and write 
to file. Overall, I think the material and intructions were clear enough and adequate to enable me to do the lab.