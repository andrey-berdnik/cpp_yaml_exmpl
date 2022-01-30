# Course assignment
Create Аpplication which will start processes with different settings. Information about processes
should be parsed from the configuration file in yaml format. Try to find some information about
this format. Here is a short example with flags that should exist in our application.

## Example of yaml format and possible flags:
```
processes:
    - name: test_name
    executable-path: /Desktop/test_folder
    stdout-config:
        file: /var/log/apps/example_app.log
        mode: truncate
    cmd-arguments:
        - option-name: arg1
        - option-name: arg2
    - name: test_name1
    executable-path: /Desktop/test_folder
    stdout-config:
        file: /var/log/apps/example_app1.log
        mode: append
    cmd-arguments:
        - option-name: arg1
        - option-name: arg2
```

## Flags Description

**Processes** Define configuration for applications.   


**name** Process name.  


**executable-path** Absolute path to executable file.  


**stdout-config** Process stdout configuration section. Allow user to redirect application output to dedicated file.  


**file**  Path to log file storing stdout (no log file is created by default, provided path should exist).


**mode** stdout redirect file write mode. append or truncate (default: truncate).  


**cmd-arguments** Process startup option configuration.


**option-name** Option name(e.g. -h, -filename my_file).


## Restrictions:
1. Use C++14.
2. For style follow Google C++ Style Guide
3. You can use any online parser for a more comfortable read yaml format -
https://yaml-online-parser.appspot.com/.
So your application should parse configuration files. According to this information you
have to start all needed processes with all needed arguments.
4. Created Application must be run as daemon at startup.
Hints:
1. You have to understand and create a parser for the yaml format.
2. You have to understand what variants of the creating process are better for our purposes
and why.