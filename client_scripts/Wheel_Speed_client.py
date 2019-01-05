# Hardware components required: 
# 1. Wheel Speed Sensors x4

# Warnings:
# 1. COM Ports are subject to change

##################################################################################################
##################################################################################################

import serial
import struct
#import time

ard1 = serial.Serial('COM10', 9600)

# let it initialize
#time.sleep(2)
 
while True:
  
    data = ard1.readline()[:-2]     #the last bit gets rid of the new-line chars 
    data = str(data)    
    data = data[2:-1] # removing the initial byte markers 
    x = list(map(str, data.split(" ")))  # convert the whole into a list of strings 
    print(x)
    # Code for converting this data and then sending the data needs to be written here. 

###############################################################################