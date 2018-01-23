# get_next_line
Reading a line on a fd is way too tedious

## Summary
The aim of this project is to make a function that reads a file and at every call returns a new line from that file. 

## what is get_next_line

 From a file descriptor _get_next_line(const int fd, char **line)_ will place in a pointer to string _line_ the next line of an input that hasn't been read yet from a certain file descriptor _fd_.
 A line is a strig ended by a '\n' or by a '\0'.
 It returns 1 if has read something, 0 if there are no new line, -1 if there is an error (wrong file descriptor, inexistent original pointer to string).
 The function has to work with any length of new line and has to work with a _BUFF_SIZE_ for reading a file from 1 to 9999.
 As bonus this one has to work with multiple file descriptors at the same time and use only ona static variable and no global variable.
 
## how it works

 The function uses only one static variable to remeber what is left from the last call from read.
 This static memory is a pointer to a pointer. on the first level thre are multiple slot of memory. Each of this slots is unique for each filedescriptor, it will point to a string that will have the remainder buff from the last call to read if the file descriptor has been called.

 The function will check if there is a past buffer left every time it is called and add it to the result line. then it will go read the actual file concatenating what has been read at every loop of read. when it encounters a buffer with a new line it concatenates to the result line only the buffer till the new line and the new buffer will be updated to the sub string after the new line.

## Example

 Here is an image of _the main.c_ function compiled that takes file paths as arguments and writes every line from these files.
 In this sample I used the first few lines of "Commentarii de Bello Gallico".

![instruction image](/how_to.png "how to make and run")
