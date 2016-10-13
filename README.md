# Compressor-Decompressor
Text Compressor , can be built on Windows, and Linux. Not sure about OSX

Text is encoded with a Huffman tree.

The tree is built where the most frequent characters have the shortest path from the root of the tree.

An example is:

                                                  abcd 20
                                                  /      \
                                                a 10     bcd 10
                                                        /     \
                                                      d 5     bc 5
                                                              /   \
                                                            b 3     c 2
                                                          
                                                          
To encode each character to simply traverse the tree where left is a binary 0 and right is a 1

    a   0
    d   10
    b   110
    c   111


## To build
- `make`

## To run
- Compress a file
  - `./bzip -c the_file`
- Decompress a file
  - `./bzip -d the_file.bzip`

to do:
compressor needs to take a buffer rather than an input file
