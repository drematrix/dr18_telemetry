# Hardware components required: 
# 1. Wheel Speed Sensors x4

# Warnings:
# 1. COM Ports are subject to change

##################################################################################################
##################################################################################################

import serial
import struct
import json
import csv
import socketio
#import time
sio = socketio.Client()
lap = 1
fileName = 'wheelSpeed.csv'

def writeLabel():
    with open(fileName,'a+') as f:
        output = csv.writer(f,dialect='excel')
        labels = {'wheelSpeed'}
        output.writerows([labels])
    f.close()

@sio.on('lap_change')
def lap_change():
    global lap
    print ("Lap Change")
    lap = lap + 1
    y = "Lap" + str(lap)
    writeData(y)
    writeLabel()
    writeData(fetchData)

ard1 = serial.Serial('COM10', 9600)

# let it initialize
#time.sleep(2)

def writeData(arr=[],*args):
    with open(fileName,'a+') as f:
        output = csv.writer(f,dialect='excel')
        output.writerows([arr])
    f.close()

 
def fetchData():  
    data = ard1.readline()[:-2]     #the last bit gets rid of the new-line chars 
    data = str(data)    
    data = data[2:-1] # removing the initial byte markers 
    x = list(map(str, data.split(" ")))  # convert the whole into a list of strings 
    print(x)
    writeData(x)
    
    # Code for converting this data and then sending the data needs to be written here. 

    # json creation below
    wheelSpeed = {
        "wheel_speed" : x[0],
    }

    wheelSpeed_json = json.dumps(wheelSpeed)
    #print(x)
    return wheelSpeed_json
###############################################################################

if __name__ == "__main__":
	writeLabel()
	while True:
		fetchData()