import serial
import struct
import json
import socketio
#import time

# WARNING - INITIALIZE PROPERLY
sio = socketio.Client()
ard1 = serial.Serial('COM10', 9600)

# let it initialize
#time.sleep(2)

def fetchData(): 
    data = ard1.readline()[:-2] #the last bit gets rid of the new-line chars
    data = str(data)
    data = data[2:-1]
    x = list(map(str, data.split(" ")))

    ride_rot = {
        "rideOne" : x[0],
        "rideTwo" : x[1],
        "rideThree" : x[2],
        "rideFour" : x[3],
        "rideFive" : x[4],
        "rideSix" : x[5],
        "rotary" : x[6]
    }

    ride_rot_json = json.dumps(ride_rot)
    #print(x)
    return ride_rot_json
 
if __name__ == "__main__":
    sio.connect('http://localhost:3000')
    while True:
        sio.emit('ride_rot', fetchData())