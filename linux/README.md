# Keylogger

**Keylogger** is simple keylogger for Windows, Linux and Mac.
## Installation

The following instructions will install Keylogger using pip3 .

```
  pip3 install -r requirements.txt
```

## How to run it

By running `python3 keylogger.py` command, it'll start to log your strokes:
```
$ python3 keylogger.py

started:
```

The Keylogger is now running! It will log your strokes to the file you specified. Stop it by hitting the grave key (Thats the one under escape on a standard keyboard). 

Keylogger has several options that can be used to change output log file and change its cancel key:

* `python3 --log-file output.og ` # File path to use as the log file.  Default is current directory.
* `python3 --cancel-key  `        # The key that uses as the cancel key, default is 'backtick( ` )' 
* `python3 --clean-log  `         #clean the log file first, default is No.

---

