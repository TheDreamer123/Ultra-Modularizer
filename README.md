# Ultra Modularizer
This is a simple, one file, C application that takes a file in, creates a folder corresponding to that file, inside that folder, creates x new files, each containing a single non-empty line from the original file and then deletes the original.

Do **NOT** run it on a binary file, you will loose most if not all contents.

## How reliable is this?
As reliable as a joke made in one hour can be.

## Why?
Because it is funny.

## Can I download the application or do I have to compile it myself?
If you head over to [releases](https://github.com/TheDreamer123/Ultra-Modularizer/releases/tag/windows-release), you can get an already compiled version of the program.

If you would rather compile it yourself, well... I assume you already know how. Just make sure when compiled, it uses C11 (`-std=c11` on gcc).

## Does it require any libraries?
No, it does not.

## Does it work on X operating system?
I am not sure, it's only been tested on Windows 10 and only been compiled on Windows 10.

## What can I do with the code?
Anything that fits in the MIT license's permissions.

# How do I use it?
Easy! Open your terminal and type the following:

`path/to/UltraModulizer.exe <path/to/file/to.separate>`

A folder with a similar name (`path/to/file/to.separate-M`) should be created on the same directory as the target file.
