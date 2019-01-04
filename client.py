from socketIO_client_nexus import SocketIO
from socketIO_client_nexus import LoggingNamespace
import logging
import time
 
i = 0
with SocketIO('localhost', 1234, LoggingNamespace) as socketio:
    while True:
        data = i
        socketio.emit('source',{'source':data})
        print "sent"
        time.sleep(2)
        i=i+1