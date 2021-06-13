from socket import *

msg = "\r\n I love computer networks!"
endmsg = "\r\n.\r\n"
# Choose a mail server (e.g. Google mail server) and call it mailserver
mailserver = 'smtp.bit.edu.cn' # Fill in start   #Fill in end
# Create socket called clientSocket and establish a TCP connection with mailserver
# Fill in start
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((mailserver, 25))
# Fill in end
recv = clientSocket.recv(1024)

print recv
if recv[:3] != '220':
    print '220 reply not received from server.'

# Send HELO command and print server response.
heloCommand = 'HELO qq.com\r\n'
clientSocket.send(heloCommand)
recv1 = clientSocket.recv(1024)
print recv1
if recv1[:3] != '250':
    print '250 reply not received from server.'

# Send MAIL FROM command and print server response.
# Fill in start
mailfromCommand = 'MAIL FROM: <ponyma@smtp.qq.com>\r\n'
clientSocket.send(mailfromCommand)
recv2 = clientSocket.recv(1024)
print recv2
if recv2[:3] != '250':
    print '250 sender ok failed'
# Fill in end

# Send RCPT TO command and print server response.
# Fill in start
rcptCommand = 'RCPT TO: <1120171494@bit.edu.cn>\r\n'
clientSocket.send(rcptCommand)
recv3 = clientSocket.recv(1024)
print recv3
if recv2[:3] != '250':
    print '250 recipient not ok'
# Fill in end

# Send DATA command and print server response.
# Fill in start
dataCommand = 'DATA\r\n'
clientSocket.send(dataCommand)
recv4 = clientSocket.recv(1024)
print recv4
if recv4[:3] != '354':
    print '354 enter mail failed'
# Fill in end

# Send message data.
# Fill in start
clientSocket.send(msg)
clientSocket.send(endmsg)
recv5 = clientSocket.recv(1024)
print recv5
if recv5[:3] != '250':
    print '250 message accept failed'
# Fill in end

# Message ends with a single period.
# Fill in start

# Fill in end

# Send QUIT command and get server response.
# Fill in start
clientSocket.send('QUIT\r\n')
recv6 = clientSocket.recv(1024)
print recv6
if recv6[:3] != '221':
    print '221 message accept failed'
# Fill in end

