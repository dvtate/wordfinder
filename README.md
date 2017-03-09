# WordFinder 
- Given the puzzle and the words, this program will highlight the answers in red. 
- Unfortionatly this only supports the ASCII charset, anyone willing to add support for unicode is welcome to do so. :)
- The obvious next step is to make a word-find generator which I can pipe the output to.
- perhaps in the distant future I will add a GUI-frontend for this program using QT/GTK. but for now it's CLI.
- *NOTE:* This project does not represent good C programming practices, and I can understand it being hard to read and not scalable. If you see any performance improvements, please feel free to send a pull-request.

![screenshot](https://raw.githubusercontent.com/dvtate/wordfinder/master/gnome-shell-screenshot-DOU4WY.png "example useage")

# Build and Run [![Build Status](https://travis-ci.org/dvtate/wordfinder.svg?branch=master)](https://travis-ci.org/dvtate/wordfinder)
Pretty basic build and run. If someone who knows how to do makefiles would help, that would be great.
```
$ git clone https://github.com/dvtate/wordfinder/
$ cd wordfinder
$ gcc *.c --std=c99 -Wall -Wextra -o findwords # build
$ ./findwords # run
---- note: windows ----
> gcc *.c --std=c99 -Wall -Wextra -o findwords.exe # build
> findwords.exe # run
```
