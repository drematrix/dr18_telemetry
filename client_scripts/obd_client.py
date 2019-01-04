import obd
import socketio

sio = socketio.Client()

@sio.on('connect')
def on_connect():
    print('connection established')

connection = obd.OBD("COM15",fast=False) 

if __name__ == "__main__":

	while True:
		if connection.status() == "Car Connected":
			#print("Car Connected"
			cmd = obd.commands.RPM
			response = connection.query(cmd)
			# cmd = obd.commands.COOLANT_TEMP
			# response2 = connection.query(cmd)
			# cmd = obd.commands.INTAKE_PRESSURE
			# response3 = connection.query(cmd)
			# cmd = obd.commands.INTAKE_TEMP
			# response4 = connection.query(cmd)
			cmd = obd.commands.THROTTLE_POS
			response5 = connection.query(cmd)

			if not response.is_null():
				arr = [response.value, response5.value]
				print(arr)
