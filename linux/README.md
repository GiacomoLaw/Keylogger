# Keylogger

**Keylogger** is simple keylogger for Windows, Linux and Mac.
## Installation

The following instructions will install Keylogger using pip3 .

```
  pip3 install -r requirements.txt
```
or 
```
  pip3 install pyxhook
```

## How to run it

By running `nohup python3 keylogger.py &` command, it'll start to log your strokes:
The meaning of nohup is ‘no hangup‘.
When nohup command use with ‘&’ then it doesn’t return to shell command prompt after running the command in the background. But if you want you can return to shell command prompt by typing ‘fg’
```
$~/Keylogger/linux$ nohup python3 keylogger.py &
[1] 12529
$~/Keylogger/linux$ nohup: ignoring input and appending output to 'nohup.out'
$:~/Keylogger/linux$ fg

```

The Keylogger is now running! It will log your strokes to the file you specified. Stop it by hitting the grave key (Thats the one under escape on a standard keyboard). 

Keylogger has several options that can be used to change output log file and change its cancel key:

* `python3 --log-file output.og ` # File path to use as the log file.  Default is current directory.
* `python3 --cancel-key  `        # The key that uses as the cancel key, default is 'backtick( ` )' 
* `python3 --clean-log  `         #clean the log file first, default is No.

---

