import socketio
import ahrs
import json

# WARNING - INITIALIZE PROPERLY - IP Address
sio = socketio.Client()

@sio.on('connect')
def on_connect():
    print('connection established')

@sio.on('lap_change')
def lap_change():
    print("Lap Change")
    lap = lap + 1
    y = "Lap" + str(lap)
    writeData(y)
    writeData(fetchData)

def fetchData():

    rpy = {
        "roll" : ahrs.roll(),
        "pitch" : ahrs.pitch(),
        "yaw" : ahrs.yaw(),
        "yaw_vel" : ahrs.yaw_parameters()[0],
        "yaw_accel" : ahrs.yaw_parameters()[1],
        "accelX" : ahrs.accelerometer()[0],
        "accelY" : ahrs.accelerometer()[1] - ahrs.yaw_parameters()[1]*ahrs.radius,
        "accelZ" : ahrs.accelerometer()[2]
    }

    rpy_json = json.dumps(rpy)
    #print(rpy_json)
    return rpy_json

if __name__ == "__main__":
    sio.connect('http://localhost:3000')
    while True:
        sio.emit('imu', fetchData())
    