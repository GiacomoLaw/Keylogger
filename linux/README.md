##Installation
You'll need to install python-xlib if you don't have it.

`pip install python-xlib`    
or `sudo pip install python-xlib` to install `python-xlib` globally.

or use `ubuntu/debian` package manager:
`sudo apt-get install python-xlib`

Check that you have git installed, and then run this.

`git clone https://github.com/GiacomoLaw/Keylogger`

This will clone this entire repo. Find the linux folder, extract it, and open it. Rename the extracted folder to `linux-logger` Then run this:

`giacomo@vostro:~$ cd linux-logger/`

Set where you want the log to go **before** running this step.

```
giacomo@vostro:~/linux-logger$ python keylogger.py

<class 'Xlib.protocol.request.QueryExtension'>

<class 'Xlib.protocol.request.QueryExtension'>

RECORD extension version 1.13
```

The keylogger is now running! It will log your strokes to the file you specified. Stop it by hitting the grave key. Thats the one under escape on a standard keyboard.

---

You can make it run on startup:

`python /home/giacomo/py-keylogger/keylogger.py`
