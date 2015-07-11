# Compressor-Decompressor
Text Compressor built with Visual C++

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
                                                          
                                                          
Encoded 'a' would be  
