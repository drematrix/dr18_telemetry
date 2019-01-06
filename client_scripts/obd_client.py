import obd
import socketio
import csv
import json

connection = obd.OBD("COM15",fast=False)

lap = 1
fileName = 'engine.csv'

sio = socketio.Client()

@sio.on('connect')
def on_connect():
    print('connection established')

@sio.on('lap_change')
def lap_change():
	global lap
	print ("Lap Change")
	lap = lap + 1
	y = "Lap" + str(lap)
	writeData(y)
	writeLabel()
	writeData(fetchData)

def writeData(arr=[],*args):
    with open(fileName,'a+') as f:
        output = csv.writer(f,dialect='excel')
        output.writerows([arr])
    f.close()

def writeLabel():
    with open(fileName,'a+') as f:
        output = csv.writer(f,dialect='excel')
        labels = {'RPM','coolantTemp','intakePressure','intakeTemp','throttlePos'}
        output.writerows([labels])
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

			if not response.is_null():
				values = [response.value,response2.value,response3.value,response4.value,response5.value]
				writeData(values)

				obd_data = {
        			"RPM" : values[0],
					"COOLANT_TEMP" : values[1],
					"INTAKE_PRESSURE" : values[2],
					"INTAKE_TEMP" : values[3],
					"THROTTLE_POS" : values[4],
				}

				obd_data_json = json.dumps(obd_data)
				#print(x)
				return obd_data_json
			

if __name__ == "__main__":
	writeLabel()
	while True:
		fetchData()