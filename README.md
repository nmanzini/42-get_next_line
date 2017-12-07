# Get next line

from a file descriptor _fd_ will place in a pointer to string the next line of in input that hasn't been read yet.
A new line is defined as the string that is after a \n(ASCII 10) and another \n or a \0(ASCII 0). 
returns 1 if has red something, 0 if there are no new line, -1 if there is an error (vrowng file descriptor, unexistent original pointer to string.

the function has to work with any length of new line and has to work with a _BUFF_SIZE_ for reading a file from 1 to 9999.
As bonus this one has to work with multiple file descritors at the same time and use only ona static variable and no global variable.

## structure of the data.









1. The program allocates a list of length  = to the max file descriptor (_***file_list_).
2. every slot of this list is a pointer to a list of strings (_**line_list_).
3. every string is a list of pointer to the various characthers (_*str_).
 
 
given two  if fd 3 is the english version of the "Commentarii de bello Gallico" and fd 5 is the original one the structure will look like this one

- _file_list[0]_ = NULL
- _file_list[1]_ = NULL
- _file_list[2]_ = NULL
- _file_list[3]_ = Pointer to a malloc of _**line_list_
    - _line_list[0]_ = All Gaul is divided into three parts, one of which the Belgae inhabit, the Aquitani another, those who in their own language are called Celts, in our Gauls, the third.
    - _line_list[1]_ = All these differ from each other in language, customs and laws.
    - _line_list[2]_ = The river Garonne separates the Gauls from the Aquitani, the Marne and the Seine separate them from the Belgae.
    - _line_list[3]_ = Of all these, the Belgae are the bravest, because they are furthest from the civilization and refinement of [our] Province..
    - _line_list[4]_ = ....
    - _line_list[i]_ = NULL
- _file_list[4]_ = NULL
- _file_list[3]_ = Pointer to a malloc of _**line_list_
    - _line_list[0]_ = Gallia est omnis divisa in partes tres, quarum unam incolunt Belgae, aliam Aquitani, tertiam qui ipsorum lingua Celtae, nostra Galli appellantur.
    - _line_list[1]_ = Hi omnes lingua, institutis, legibus inter se differunt.
    - _line_list[2]_ = Gallos ab Aquitanis Garumna flumen, a Belgis Matrona et Sequana dividit.
    - _line_list[3]_ = Horum omnium fortissimi sunt Belgae, propterea quod a cultu atque humanitate provinciae...
    - _line_list[4]_ = ....
    - _line_list[i]_ = NULL
- _file_list[5]_ = NULL
- _file_list[6]_ = NULL
