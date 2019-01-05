import obd
import socketio
import csv

connection = obd.OBD("COM15",fast=False)

lap = 1
fileName = 'engine.csv'
fetchData = []

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

def writeData(arr=[],*args):
    with open(fileName,'a+') as f:
        output = csv.writer(f,dialect='excel')
        output.writerows([arr])
    f.close()

def fetchData():
	if connection.status() == "Car Connected":
			#print("Car Connected")
			cmd = obd.commands.RPM
			response = connection.query(cmd)
			cmd = obd.commands.COOLANT_TEMP
			response2 = connection.query(cmd)
			cmd = obd.commands.INTAKE_PRESSURE
			response3 = connection.query(cmd)
			cmd = obd.commands.INTAKE_TEMP
			response4 = connection.query(cmd)
			cmd = obd.commands.THROTTLE_POS
			response5 = connection.query(cmd)

			if response.is_null():
				values = [response.value,response2.value,response3.value,response4.value,response5.value]

			writeData(values)
			

if __name__ == "__main__":
	 
	while True:
		fetchData()