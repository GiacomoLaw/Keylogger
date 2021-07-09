# Keylogger

**Keylogger** is simple keylogger for Windows, Linux and Mac.
## Installation

The following instructions will install dependencies using pip .

`
  pip install pynput
`  

or

` 
  pip3 install pynput
`

## How to run it

0- `python3 main.py`

1- Make a proper cron job that calls your script. Cron is a common name for a GNU/Linux daemon that periodically launches scripts according to a schedule you set. You add your script into a crontab or place a symlink to it into a special directory and the daemon handles the job of launching it in the background. There is a variety of different cron daemons, but your GNU/Linux system should have it already installed.

2- Run the script with nohup which ignores the hangup signal. This means that you can close the terminal without stopping the execution. Also, don’t forget to add " & " so the script runs in the background: `nohup python3 main.py &`

3- Screen or GNU Screen is a terminal multiplexer. In other words, it means that you can start a screen session and then open any number of windows (virtual terminals) inside that session. Processes running in Screen will continue to run when their window is not visible even if you get disconnected :

   -To start a screen session, simply type screen in your console: `screen` 
    
   -You can detach from the screen session at any time by typing : `Ctrl+a d` 
    
   -To resume your screen session use the following command: `screen -r`



---
## TODO :

add argparse.
