# A simple keylogger for Windows, Linux and Mac
[![MIT Licence](https://badges.frapsoft.com/os/mit/mit.png?v=103)](https://opensource.org/licenses/mit-license.php)

[Website](https://simple-keylogger.github.io) - [Keylogger wiki](https://github.com/GiacomoLaw/Keylogger/wiki)

Welcome to the simple keylogger repo! A keylogger is a program that records your keystrokes, and this program saves them in a log file on your local computer.

Check out below to learn how to install them. These keyloggers are simple and bare bones, however they work great! Feel free to fork and improve it if you want. Be sure to check out the [pull requests](https://github.com/GiacomoLaw/Keylogger/pulls) to see if your problem has been fixed, or to help out others.

Currently, there are three keylogger programs for the major operating systems; Windows, Mac and Linux.

> Looking to make a fix or change on the website? You can find the website repo [here](https://github.com/simple-keylogger/simple-keylogger.github.io).

## Contents
- [Windows installation guide](https://simple-keylogger.github.io/windows.html)
- [Mac installation guide](https://simple-keylogger.github.io/mac.html)
- [Linux installation guide](https://simple-keylogger.github.io/linux.html)
- [Check out the site for more information](https://simple-keylogger.github.io/)

## Windows
To change visibility of the window set the `#define` in line 9 to `visible` or `invisible`.

Simply compile into an .exe, and then run. Visual Studio is good for this.

- `invisible` makes the window of the logger disappear, and it also starts up hidden from view. Note that it is still visible in the task manager.
- `visible` is visible, and the window does not close when typing. Great for testing it out.

Both of these save the keystrokes to a .txt file when closed.

> Note that sometimes your compiler may through up errors. If it does, keep compiling - the program still works. As always, please create an issue if you have a problem.

## Mac
This is a little more complicated. Please note, it does not work for secure areas such as password inputs. I have not found a work around yet.

### Installation
Download the repo. It will install in `/usr/local/bin/keylogger`.

Install it:

`$ git clone https://github.com/GiacomoLaw/Keylogger && cd keylogger/mac`

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

Thanks to [Casey Scarborough](https://github.com/caseyscarborough/keylogger) for the base program!

> Please note that this logger cannot record keystrokes in protected areas yet.

## Linux
### Installation

First, install the keylogger:

`pip install keylogger`

and there are several options that can be set with environment variables:

* `--log-file output.og`: File path to use as the log file.  Default is current directory.
* `--cancel-key`: The key that uses as the cancel key, default is '`'.
* `--clean-log`: clean the log file first, default is No.

### How to run it?

To run it just type `keylogger` and it'll run:
```
keylogger --log-file keylogger.log 
RECORD extension version 1.13
```

The keylogger is now running! It will log your strokes to the file you
specified. Stop it by hitting the cancel key (grave or \`, if not set with
`--cancel-key`. That's the one under escape on a standard keyboard.)

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

Don't really understand licenses or tl;dr? Check out the [MIT license summary](https://tldrlegal.com/license/mit-license).

Distributed under the MIT license. See [LICENSE](https://github.com/GiacomoLaw/Keylogger/blob/master/LICENSE.txt) for more information.

Giacomo Lawrance – [@GiacomoLaw](https://twitter.com/GiacomoLaw) - [Website](https://giacomolaw.github.io)

Help support the project:

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=FWTUUC2C3G9BL&source=url)
