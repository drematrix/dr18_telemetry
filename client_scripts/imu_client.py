import socketio
import ahrs
import json

# WARNING - INITIALIZE PROPERLY - IP Address
sio = socketio.Client()

@sio.on('connect')
def on_connect():
    print('connection established')

@sio.on('my message')
def on_message(data):
    print('message received with ', data)
    sio.emit('hello', 'New Python Client')

@sio.on('disconnect')
def on_disconnect():
    print('disconnected from server')


def fetchData():

    rpy = {
        "roll" : ahrs.roll(),
        "pitch" : ahrs.pitch(),
        "yaw" : ahrs.yaw(),
        "accelX" : ahrs.accelerometer()[0],
        "accelY" : ahrs.accelerometer()[1],
        "accelZ" : ahrs.accelerometer()[2]
    }

    rpy_json = json.dumps(rpy)
    #print(rpy_json)
    return rpy_json

if __name__ == "__main__":
    sio.connect('http://localhost:3000')
    while True:
        sio.emit('imu', fetchData())
    