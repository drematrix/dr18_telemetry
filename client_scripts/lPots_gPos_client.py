import serial
import socketio
import json
import struct
import csv

# WARNING - INITIALIZE PROPERLY
# Make sure the corresponsing code is uploaded in arduino
sio = socketio.Client()
ard2 = serial.Serial('COM17', 9600)
fileName = 'lPots.csv'
lap = 1
filName = 'lPots.csv'

@sio.on('connect')
def on_connect():
    print('connection established')

def writeLabel():
    with open(fileName,'a+') as f:
        output = csv.writer(f,dialect='excel')
        labels = {'fleft','fRight','rLeft','rRight'}
        output.writerows([labels])
    f.close()

def writeData(arr=[],*args):
    with open(fileName,'a+') as f:
        output = csv.writer(f,dialect='excel')
        output.writerows([arr])
    f.close()

def fetchData():

    global lap
    data = ard2.readline()[:-2] #the last bit gets rid of the new-line chars
    data = str(data)
    data = data[2:-1]
    x = list(map(str, data.split(" ")))

    if x[5] is 1:
        lap = lap + 1
        y = "Lap" + str(lap)
        writeData(y)
        writeLabel()
    else:
        writeData(x)

    lp = {
        "fLeft" : x[0],
        "fRight" : x[1],
        "rLeft" : x[2],
        "rRight" : x[3],
        "gearPos" : x[4],
        "lap_button" : x[5]
    }
    
    lp_json = json.dumps(lp)
    #print(lp)
    return lp_json

#Lap change socket
@sio.on('lap_change')
def lap_change():
    global lap
    print("Lap Change")
    lap = lap + 1
    y = "Lap" + str(lap)
    writeData(y)
    writeLabel()

if __name__ == "__main__":
    writeLabel()
    sio.connect('http://localhost:3000')
    while True:
        sio.emit('lPots_gPos', fetchData())