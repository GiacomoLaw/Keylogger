# Keylogger

### Prerequisites

You'll need to install python-xlib if you don't have it.

#### To install `python-xlib`:

`pip install python-xlib` or `sudo pip install python-xlib`.


For `ubuntu/debian` package manager:

`sudo apt-get install python-xlib`


### How to install

Clone the repository

`git clone https://github.com/GiacomoLaw/Keylogger`

This will clone this entire repo. Find the linux folder, extract it, and open it. Rename the extracted folder to `linux-logger`.

## How to run it

Set where you want the log to go **before** running this step.

Run this command to start

```
python keylogger.py

<class 'Xlib.protocol.request.QueryExtension'>

<class 'Xlib.protocol.request.QueryExtension'>

RECORD extension version 1.13
```

The keylogger is now running! It will log your strokes to the file you specified. Stop it by hitting the grave key. Thats the one under escape on a standard keyboard.

---

You can make it run on **startup**:

`python /home/giacomo/py-keylogger/keylogger.py`
