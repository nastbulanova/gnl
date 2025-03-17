<H1><b>get_next_line - 42 school project</b></H1>
<H2>Function Description</H2>
The get_next_line() function reads and returns the next line from a given file descriptor (fd). It allows reading text files line by line, ensuring efficient memory management and proper handling of the buffer.

<H2>How it works</H2>
Reads one line at a time, including the newline character (\n) if present.
Uses a static buffer to optimize performance and minimize read() system calls.
Handles EOF (End of File) properly:
If there is data left in the buffer, it returns it as the last line.
If the buffer is empty, it returns NULL.
Each returned line is allocated dynamically and must be freed by the caller.
At EOF, all allocated memory (except the returned line) is released.

No norminette applied.
