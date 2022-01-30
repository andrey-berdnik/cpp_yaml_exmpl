# DeLorean_Team
Source project automotive BASECAMP


## Build
```
cd build
cmake ../
make
```

## Run
``` 
./main
```

## Before commit   

### Make sure your code matches the Google C++ Style Guide.  
For automatic format of all code you can use command: 
```
find src/ -iname *.hpp -o -iname *.cpp | xargs clang-format -i -style=Google
```

or for one file 
```
clang-format -i -style=Google src/main.cpp
```
(Warning, will modify code in place without any notice)

### Check that tests passed 
```
cd build
cmake ../
make
./tests
```