<h1>File encoder</h1>

*Created by S. Marousek (maroust1) | 2021/06/17*

<h2>Compile:</h2>

Type `gcc decrypt.c -o decrypt` and `gcc encrypt.c -o encrypt` in terminal.

Examples:

*    `./encrypt original-file coded-file password`

*    `./decrypt coded-file password`

<h2>Tips:</h2>

*    long password or big file = long encrypting and decoding

*    decrypt file creates decoded file with same name as the original file (it can overwrite original file if you run this command in the same directory)

Example how encryption works:

![alt text](https://github.com/1000101cz/file_encoder/blob/main/encryption_sheet.png?raw=true "graph")



tested on :computer: Manjaro | x86_64    |   written in :atom: Atom
