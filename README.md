# Strings Sorting by alphabet. It suits for English and Russian alphabet.
This program is the second task of ISP RAS course C/C++ by I. R. Dedinsky
## Info
This program sorts strings by alphabet in two directions: from left to right and from right to left.
Project uses windows-1251 file encoding  for reading Russian language.
To get the correct with Russian result you need to have ```ru_RU.cp1251``` local in your OS.
## How to set up ru_RU.cp1251 local in KUbuntu 18.04
Try to do this command in terminal
```bash 
sudo /usr/share/locales/install-language-pack ru_RU.CP1251
```
Check 
```bash
locale -a | grep ru_RU
```
and use .txt with windows-1251 file encoding 

## Structure
- Main project 
    - src/
- Test project
    - tests/


# Run
To run main program

```bash
cmake .
make
./sort_strings
```

To run tests

```bash
cmake .
make
./tests
```

## Documentation
You can watch documentation by opening
```docs/html/index.html ``` in browser.
## OS
 KUbuntu 18.04
