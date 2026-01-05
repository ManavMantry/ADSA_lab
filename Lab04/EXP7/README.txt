README — Huffman Coding (Text File Encoding)
============================================

Program Overview
----------------
This program implements the Huffman Coding algorithm in C to encode 
data from a text file (`input.txt`). 

Huffman Coding is a lossless data compression technique that assigns 
shorter binary codes to more frequent characters and longer codes to 
less frequent characters. The result is a compressed representation 
of the text while preserving all original information.


Input and Output Files
----------------------
Input  : input.txt
Output : encoded_output.txt

The input file should contain any text or string to be encoded.

Example Input (input.txt)
--------------------------
YEHDILMAANGEMORE


Example Output (encoded_output.txt)
-----------------------------------
Y: 1101
E: 00
H: 1110
D: 1111
I: 1011
L: 1001
M: 011
A: 010
N: 1000
G: 1010
O: 1100
R: 001

(Note: Codes may vary depending on character frequency.)




Program Output
---------------
1. The program prints the Huffman code for each character to the console.
2. The same codes are also written to "encoded_output.txt".
3. If the input file is missing or empty, an error message is displayed.




Time and Space Complexity
--------------------------
Operation                     Time Complexity     Space Complexity
------------------------------------------------------------------
Building frequency table        O(n)               O(n)
Building Huffman Tree           O(n log n)         O(n)
Generating Huffman Codes        O(n)               O(n)
------------------------------------------------------------------
Overall                         O(n log n)         O(n)

Where n = number of distinct characters in the input text.


Algorithm Properties
---------------------
- Type: Lossless compression
- Data Structure: Binary Tree (Min-Heap)
- Suitable for: Text compression, file compression, and data encoding


Output Interpretation
----------------------
Each line in encoded_output.txt represents:
    <Character>: <Huffman Code>
Example:  A: 01   means character 'A' is encoded as binary "01".


Limitations
------------
- Only encoding is implemented; decoding is not included.
- Works for text data (ASCII range).
- Case-sensitive (treats 'A' and 'a' as different characters).



====================================================================
