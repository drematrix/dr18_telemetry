import serial
import socketio
import json
import struct

# WARNING - INITIALIZE PROPERLY
# Make sure the corresponsing code is uploaded in arduino
sio = socketio.Client()
ard2 = serial.Serial('COM17', 9600)

@sio.on('connect')
def on_connect():
    print('connection established')

def fetchData(): 
    
    data = ard2.readline()[:-2] #the last bit gets rid of the new-line chars
    data = str(data)
    data = data[2:-1]
    x = list(map(str, data.split(" ")))
    
    lp = {
        "fLeft" : x[0],
        "fRight" : x[1],
        "rLeft" : x[2],
        "rRight" : x[3]
    }
    
    lp_json = json.dumps(lp)
    #print(lp)
    return lp_json

if __name__ == "__main__":
    sio.connect('http://localhost:3000')
    while True:
        sio.emit('linearPots', fetchData())
    
