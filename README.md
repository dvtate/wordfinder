# WordFinder
- Given the puzzel and the words, this program will highlight the answers. 
- Unfortionatly this only supports the ASCII charset, anyone willing to add support 
- The obvious next step is to make a word-find generator which I can pipe the output to

# Build and Run
Pretty basic build and run. If someone who knows how to do makefiles would help, that sould be great.
```
$ git clone https://github.com/dvtate/wordfinder/
$ cd wordfinder
---- unix-based ----
$ gcc *.c -Wall -Wextra -o wordfinder #build
$ ./wordfinder # run
---- windows ----
> gcc *.c -Wall -Wextra -o wordfinder.exe # build
> wordfinder.exe # run
```
