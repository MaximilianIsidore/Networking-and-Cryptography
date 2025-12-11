import smtplib
from email import encoders
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart

# Connect to Gmail SMTP server
server = smtplib.SMTP('smtp.gmail.com', 587)
server.ehlo()
server.starttls()
server.ehlo()

# Read password securely
with open('password.txt', 'r') as f:
    password = f.read().strip()

server.login('from@gmail.com', password)

# Build email
msg = MIMEMultipart()
msg['From'] = 'from@gmail.com'
msg['To'] = 'to@gmail.com'
msg['Subject'] = 'test mail'

# Message body
with open('message.txt', 'r') as f:
    message = f.read()

msg.attach(MIMEText(message, 'plain'))

# Attachment
filename = 'mushroom.jpg'
with open(filename, 'rb') as attachment:
    p = MIMEBase('application', 'octet-stream')
    p.set_payload(attachment.read())

encoders.encode_base64(p)
p.add_header('Content-Disposition', f'attachment; filename={filename}')
msg.attach(p)

# Send email
text = msg.as_string()
server.sendmail('from@gmail.com', 'to@gmail.com', text)

server.quit()
print("Email sent successfully!")
