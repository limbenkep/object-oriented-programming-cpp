# Resources
This folder should be used for general resources, such as data files needed for input and those generated as output. Everything
in this folder, except for...

- ... **``_libs/``** and **``_img/``**
- ... this **README**
- ... **``jukebox.txt``** 
 
... will be ignored from version control as stated in **``.gitignore``**:

````
_Resources/*
!_Resources/_libs/
!_Resources/_img/
!_Resources/README.md
!_Resources/jukebox.txt
````

The folder **``_libs/``** contains some general libraries to support you in the development of solutions. One of these 
libraries is **``memstat.hpp``** which many of you already are familiar with from previous courses. It helps keeping track 
of allocations and deallocations of memory and the library is included by default in each **``main()``** for every assignment.

The reason we use a specified folder for resources is because of how _**working directories**_ are handled by different
environments. In order to avoid the hassle of finding the _**working directory**_ used by a certain IDE (for I/O files), 
we simply state that this folder should be used. For instance, we can do this in code as can be seen in some of the examples:

````
string fileName = "../../_Resources/names.biy";
ofstream inFile(fileName, ios::out|ios::binary);
...
````  

... which will open a stream to the file **``names.biy``** under **``/_Resources/``**. The dot-syntax **``../../``** simply states that 
we need to traverse the folder structure backwards until we find the needed directory, which's placed directly under the 
project root.