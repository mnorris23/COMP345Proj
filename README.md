# COMP345Proj
Advanced C++ Project

Installation Instruction

This project currently need to be compiled by Visual Studio. 
FLTK also need to be installed on the computer.

Step 1. Download FLTK 1.3.3 at http://www.fltk.org/software.php?VERSION=1.3.3&FILE=fltk/1.3.3/fltk-1.3.3-source.tar.gz

Step 2. GoTo fltk-1.3.3\ide\VisualC2015 and double-click on fltk.sln.  It opens a large MSVC++ solution.

Step 3. Go to Visual Studio menu -> Build > Configuration Manager... and switch active configuration to Release 

Step 4. Then Build -> Rebuild Solution

Step 5. Exit Visual Studio

Step 6. Once built, FLTK can be added to Visual Studio development environment. To begin, locate Visual C++ installation folder on your local machine. In most cases it is

    On 32-bit machine: C:\Program Files\Microsoft Visual Studio 15.0\VC

    On 64-bit machine: C:\Program Files (x86)\Microsoft Visual Studio 15.0\VC

There are two steps:

    Copy FL and GL folders, for example,


        C:\Users\yourname\Downloads\fltk-1.3.3\FL
        C:\Users\yourname\Downloads\fltk-1.3.3\GL

    to the include folder of Visual Studio:


        On 32-bit machine: C:\Program Files\Microsoft Visual Studio 15.0\VC\include

        On 64-bit machine: C:\Program Files (x86)\Microsoft Visual Studio 15.0\VC\include

    Copy all files from the lib folder,


        C:\Users\yourname\Downloads\fltk-1.3.3\lib

    to the lib folder of Visual Studio:


        On 32-bit machine: C:\Program Files\Microsoft Visual Studio 15.0\VC\lib

        On 64-bit machine: C:\Program Files (x86)\Microsoft Visual Studio 15.0\VC\lib
		
		
Step 7. Start Visual Studio again, then File -> New -> Project From Existing Code... Browse the PowerGrid file location and create the project.

Step 8. In the solution explorer, right-click on the name of the project(not Solution) and select Properties.

Step 9. You need to make the following three changes:

 Configuration Properties
        C/C++
            Code Generation
                Runtime Library
                    <<Edit..>>
                        and set it to Multi-threaded DLL (/MD)
        Linker
            Input
                Additional Dependencies
                    <<Edit..>>
                        and enter fltk.lib fltkjpeg.lib fltkimages.lib

                Ignore Specific Default Libraries
                    <<Edit..>>
                        and enter libcd.lib

Step 10. Build -> Rebuild Solution and it should compile.

If it did not work:

    Compiler error stating a .lib file could not be found: Your problem is most likely in the installation section. Pay attention to step 6, which involves putting the link libraries (.lib) files where your compiler can easily find them.
    Compiler error stating a .h file could not be opened: Your problem is most likely in the installation section. Pay attention to step 6, which involves putting the header (.h) files where your compiler can easily find them.
    Linker error involving unresolved external symbols: Your problem is most likely in the project section.
