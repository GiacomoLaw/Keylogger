# A simple keylogger for Windows, Linux and Mac
[![MIT Licence](https://badges.frapsoft.com/os/mit/mit.png?v=103)](https://opensource.org/licenses/mit-license.php)

[Keylogger wiki](https://github.com/GiacomoLaw/Keylogger/wiki)

Welcome to the simple keylogger repo! A keylogger is a program that records your keystrokes, and this program saves them in a log file on your local computer.

Check out below to learn how to install them. These keyloggers are simple and bare bones, however they work great! Feel free to fork and improve it if you want. Be sure to check out the [pull requests](https://github.com/GiacomoLaw/Keylogger/pulls) to see if your problem has been fixed, or to help out others.

Currently, there are three keylogger programs for the major operating systems; Windows, Mac and Linux.

## Windows
Simply compile into an .exe, and then run. Visual Studio is good for this.

There are two files; klog_visible and klog_invisible. It is pretty simple, but I will expand:

- `klog_invisible` makes the window of the logger disappear, and it also starts up hidden from view. Note that it is still visible in the task manager.
- `klog_visible` is visible, and the window does not close when typing. Great for testing it out.

Both of these save the keystrokes to a .txt file when closed.

## Mac
This is a little more complicated, as its Apple after all! Please note, it does not work for secure areas such as password inputs. I have not found a work around yet.

### Installation
Download the repo. It will install in `/usr/local/bin/keylogger`.

Install it:

`$ git clone https://github.com/GiacomoLaw/Keylogger && cd keylogger`

`$ make && make install`

It will log to `/var/log/keystroke.log`. This may require root access, but you can change that if you want. Set where you want it to log:

`$ keylogger ~/logfile.txt`

`Logging to: /var/log/keystroke.log`

Want to make it start on system startup?

`$ sudo make startup`

That will run it on startup.

### Uninstall
`$ sudo make uninstall`

Will uninstall the program, but not the logs.

---

Thanks to Casey Scarborough for the base program!

> Please note that this logger cannot record keystrokes in protected areas yet.

## Linux
### Installation
You'll need to install python-xlib if you don't have it.

You can install it using `pip`:

`pip install python-xlib`

...or your system package manager:

`sudo apt-get install python-xlib`

Check that you have git installed, and then run this.

`git clone https://github.com/GiacomoLaw/Keylogger`

This will clone this entire repo. Find the linux folder, extract it, and open it. Rename the extracted folder to `linux-logger` Then run this:

`giacomo@vostro:~$ cd linux-logger/`

### Options
There are several options that can be set with environment variables:

- `pylogger_file`: File path to use as the log file.
Default: `~/Desktop/file.log`
- `pylogger_cancel`: The key to use as the cancel key, in character form.
Default: \`
- `pylogger_clean`: Whether to clear the file on startup. This can be set to anything to clear the file.
Default: No (not set)

### Running

You can use Python 2 or 3 to run the logger.

To run it:
```
$ python keylogger.py
<class 'Xlib.protocol.request.QueryExtension'>
<class 'Xlib.protocol.request.QueryExtension'>
RECORD extension version 1.13
```

Or, using the options mentioned above:
```bash
# This tells the logger to use /home/me/myfile.txt,
# clearing the file on startup, and using ! as the
# cancel key.
# You don't have to use all of these options at once, or any at all.
$ pylogger_file="/home/me/myfile.txt" pylogger_clean=1 pylogger_cancel="!" python keylogger.py
```

The keylogger is now running! It will log your strokes to the file you
specified. Stop it by hitting the cancel key (grave or \`, if not set with
`pylogger_cancel`. Thats the one under escape on a standard keyboard.)

You can make it run on startup:

`$ sudo make startup`

---
#### Uses

Some uses of a keylogger are:

- Business Administration: Monitor what employees are doing.
- School/Institutions: Track keystrokes and log banned words in a file.
- Personal Control and File Backup: Make sure no one is using your computer when you are away.
- Parental Control: Track what your children are doing.
- Self analysis

---

Feel free to contribute to fix any problems, or to submit an issue!

Please note, this repo is for educational purposes only. No contributors, major or minor, are to fault for any actions done by this program.

Giacomo Lawrance – [@GiacomoLaw](https://twitter.com/GiacomoLaw) - [My website](https://about.me/giacomolaw)

Distributed under the MIT license. See [LICENSE](https://github.com/GiacomoLaw/Keylogger/blob/master/LICENSE.txt) for more information.
