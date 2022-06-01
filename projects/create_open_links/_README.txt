Target: take all "id numbers" from a source file (source.txt), and create a text file (links.txt) containing a direct web link for each id found.
Then, open every link from the "links.txt" in a web browser.

Rules: 
- on the SOURCE file, the first 6 characteres of a line will form an id number
- when a non-decimal character is found between the 6 first digits of a line, the whole line is discarted
- on the LINKS file, each links must be separated by a line-break character

About the .c file: as fgetc() is being used, there is an alternative* version of the code, you can alternate it by changing the first function called on main for v1 or v2
v1: take the id number as an int array
v2: take the id number as an int
*nothing much different, just an ternative way to interact with fgetc()