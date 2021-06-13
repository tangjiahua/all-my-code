from socket import *
import sys

if len(sys.argv) <= 1:
    print 'Usage : "python ProxyServer.py server_ip"\n[server_ip : It is the IP Address Of Proxy Server'
    sys.exit(2)
# Create a server socket, bind it to a port and start listening
tcpSerSock = socket(AF_INET, SOCK_STREAM)
# Fill in start.
tcpSerSock.bind(('', 6998))
tcpSerSock.listen(5)
# Fill in end.
while 1:
    # Strat receiving data from the client
    print 'Ready to serve...'
    tcpCliSock, addr = tcpSerSock.accept()
    print 'Received a connection from:', addr
    message = tcpCliSock.recv(1024) # Fill in start. # Fill in end.
    # print message
    # Extract the filename from the given message

    # hostn: gaia.cs.umass.edu/wireshark-labs/INTRO-wireshark-file1.html
    # filename: gaia.cs.umass.edu/wireshark-labs/INTRO-wireshark-file1.html
    # filetouse: /gaia.cs.umass.edu/wireshark-labs/INTRO-wireshark-file1.html

    print message.split()[1]
    filename = message.split()[1].partition("//")[2]
    print 'filename: ' + filename
    fileExist = "false"
    savefilename = filename.replace('/', '_')
    try:
        # Check wether the file exist in the cache
        f = open(savefilename, "r")
        outputdata = f.readlines()
        fileExist = "true"
        print 'file exist'
        # ProxyServer finds a cache hit and generates a response message
        # tcpCliSock.send("HTTP/1.0 200 OK\r\n")
        # tcpCliSock.send("Content-Type:text/html\r\n")
        # Fill in start.
        for data in outputdata:
            tcpCliSock.send(data)

        tcpCliSock.close()
        # Fill in end.
        print 'Read from cache'
    # Error handling for file not found in cache
    except IOError:
        if fileExist == "false":
            # Create a socket on the proxyserver
            c = socket(AF_INET, SOCK_STREAM) # Fill in start. # Fill in end.
            hostn = filename.replace("www.", "", 1).split('/')[0]
            print 'hostn: ' + hostn

            try:
                c.connect((hostn, 80))



                filepath = filename.split('/', 1)[1]
                print "filepath: " + filepath
                c.send(message)
                recv = c.recv(4096)
                # print 'recv: ' + recv
                tmpFile = open("./" + savefilename, "w")
                tmpFile.write(recv)
                tmpFile.close()

                tcpCliSock.send(recv)
                tcpCliSock.close()
                c.close()
            # Fill in start.
            # Fill in end.
            except:
                print "Illegal request"
        else:
            # HTTP response message for file not found
            # Fill in start.
            print "file not found"
            # Fill in end.
            # Close the client and the server sockets

        tcpCliSock.close()
        # Fill in start.
        # Fill in end.

