import socket
from socket import *
import datetime

clientSocket = socket(AF_INET, SOCK_DGRAM)

for i in range(1, 10):
    try:
        begintime = datetime.datetime.now()
        clientSocket.settimeout(1.0)
        clientSocket.sendto('test', ('localhost', 12000))
        message = clientSocket.recv(1024)
        if message == 'TEST':
            endtime = datetime.datetime.now()
            rtt = endtime - begintime
            print ('Ping ' + str(i) + ' ' + str(rtt))
        else:
            print 'ping message wrong'


    except timeout:
        print 'timeout'

