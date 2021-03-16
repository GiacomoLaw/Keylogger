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
When nohup command use with ‘&’ then it doesn’t return to shell command prompt after running the command in the background. 
```
$~/Keylogger/linux$ nohup python3 keylogger.py &
[1] 12529 //this is the keylogger's PID (process ID)
$:~/Keylogger/linux$ fg

```

The Keylogger is now running! It will log your strokes to a file .
Stop it by typing the command `fg` then hitting `CTRL+C`
or
`kill {PID}` for example `kill 12529`

Keylogger has several options that can be used to change output log file and change its cancel key:

* `python3 --log-file output.og ` # File path to use as the log file.  Default is current directory.
* `python3 --cancel-key  `        # The key that uses as the cancel key, default is 'backtick( ` )' 
* `python3 --clean-log  `         #clean the log file first, default is No.

---

