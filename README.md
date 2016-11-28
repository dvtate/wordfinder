# WordFinder
- Given the puzzel and the words, this program will highlight the answers. 
- Unfortionatly this only supports the ASCII charset, anyone willing to add support is welcome to do so. :)
- The obvious next step is to make a word-find generator which I can pipe the output to.
- perhaps in the distant future I will add a GUI-frontend for this program using QT/GTK. but for now it's CLI.
- *NOTE:* This project does not represent good C programming practices, and I can understand it being hard to read and not scalable. Performance is my main priority, so if you see any improovements, please feel free to send a pull-request.

# Build and Run
Pretty basic build and run. If someone who knows how to do makefiles would help, that would be great.
```
$ git clone https://github.com/dvtate/wordfinder/
$ cd wordfinder
---- unix-like ----
$ gcc *.c -Wall -Wextra -o wordfinder # build
$ ./wordfinder # run
---- windows ---- 
> gcc *.c -Wall -Wextra -o wordfinder.exe # build
> wordfinder.exe # run
```
