[![academia][academia_badge]](https://www.miun.se/utbildning/kursplaner-och-utbildningsplaner/Sok-kursplan/kursplan/?kursplanid=23981)
[![JetBrains][jetbrains_badge]](https://www.jetbrains.com/student/)
[![cpp][cpp_badge]](https://en.cppreference.com/w/)
[![cmake][cmake_badge]](https://cmake.org/)
[![vcs][git_badge]](https://git-scm.com/)
[![made-with-Markdown][md_badge]](http://commonmark.org)

[academia_badge]: https://img.shields.io/badge/MIUN-DT060G-blue&style=flat?labelColor=black&color=blue
[cpp_badge]: https://img.shields.io/badge/-C++11-blue&style=flat?logo=c&logoWidth=20&labelColor=black&logoColor=white&color=blueviolet
[cmake_badge]: https://img.shields.io/badge/-CMake-blue&style=flat?logo=cmake&logoWidth=20&labelColor=black&logoColor=white&color=blueviolet
[git_badge]: https://img.shields.io/badge/-Git-blue&style=flat?logo=git&logoWidth=20&labelColor=black&logoColor=white&color=blueviolet
[md_badge]: https://img.shields.io/badge/-Markdown-blue&style=flat?logo=markdown&logoWidth=20&labelColor=black&logoColor=white&color=blueviolet
[jetbrains_badge]: https://img.shields.io/badge/-CLion-blue&style=flat?logo=jetbrains&logoWidth=20&labelColor=black&logoColor=white&color=blue

-----------

**Table of contents**  

[TOC]

--------------

## About This Repository
This is your personal student repository which will be used to submit solutions for the course's various assignments, 
both labs and the final project. This repo is completely private, meaning none other than you and the teachers have access to it.
As you've completed a particular assignment and wish to have its solution evaluated, you'll need to perform a formal 
hand-in using the dedicated submission box in Moodle. Nothing should be attached to this submission in Moodle, as the 
current project state will be fetched from this repository, so make sure to synchronize any local changes with **remote origin** 
before submission.

-------------

## General Structure
The file / folder structure of this repo is determined by its initial state and you may not diverge from this structure at any time: 

````
root/
  _Playground/
  _Resources/
  Laboration_1/
  Laboration_2/
  Laboration_3/
  Laboration_4/
  Laboration_5/
  Project/
  .gitignore
  CMakeLists.txt
  README.md
````

- **``_Playground/``** constitute as a sandbox for you to simply experiment and play around. Nothing you add to this directory will be included in versioning. 
Further details can be seen in dedicated [**``README.md``**](./_Playground/README.md).
- **``_Resources/``** constitute as a common place to write and read data stored in files, and is shared by all assignments. 
Further details can be seen in dedicated [**``README.md``**](./_Resources/README.md).
- **``.gitignore``** dictates which content should be excluded from version control, i.e. not included in commits. 
Existing contents of this file should be general enough to cover most circumstances, but feel free to add more as the need arises.

Each assignment subdirectory has an identical file / folder structure:

````
Laboration_x/
  include/
  src/
  CMakeLists.txt
  README.md
````

- **``include/``** needs to contain all header files (``**.h``**) specific for this assignment.
- **``src/``** needs to contain all source files (**``.cpp``**) specific for this assignment.

-------------

#### Build Scripts
You should all already be somewhat familiar with **CMake** and as in previous course(s) we'll continue to rely on its 
cross-platform management of project builds, and just like before you'll be provided with a working structure of existing 
build scripts. Directly under the repo root you'll find the master **``CMakeLists.txt``** which defines some general rulesets 
and delegates build details to various subscripts.

- Minimum required **CMake** is set to **3.2** and this value should only be modified if such a change can properly be justified.
- We're only using **C++** in conformity to standard **C++11**. The value **``CMAKE_CXX_STANDARD 11``** should therefore not be changed.
- Static inclusion of dependencies may be omitted from the build in case of any issues, which could happen on certain Unix systems. 
Simply remove or comment out the following line **``set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")``**.

The remaining parts of the master script simply delegates build details to dedicated subscripts, which can be found in relevant subdirectories:

````
add_subdirectory(Laboration_x)
add_subdirectory(Project)
```` 

This makes the build system very modularized and provides easy management of what needs to be included in each build. During this course 
build time shouldn't raise much of an issue, but delegation in this manner offers scalability where certain parts can easily be 
omitted from the build by simply commenting out relevant inclusion.

-------------

#### README
The **README** documents you'll find under each assignment directory will be used as lab reports where you present the work you've 
conducted. Details regarding _what_ and _how_ information should be presented can be seen in dedicated document in Moodle.

-------------

## About the Author

Please write a short presentation. Suitable content would be... 

- ... who you are.
- ... previous programming experiences.
- ... your expectations regarding this course.

Feel free to use Markdown syntax [^markdown] [^bitbucket_md]

[^markdown]: _Markdown Cheatsheet_ [link](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)
[^bitbucket_md]: _Bitbucket Supported Markdown_ [link](https://bitbucket.org/tutorials/markdowndemo/src/master/)


