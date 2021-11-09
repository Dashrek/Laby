import Adafruit_BBIO.GPIO as GPIO
import time
GPIO.setup("P8_10", GPIO.OUT)
for i in range(3):
    for j in range(3):
        GPIO.output("P8_10", GPIO.HIGH)
        time.sleep(3 if i%2==1 else 1)
        GPIO.output("P8_10", GPIO.LOW)
        time.sleep(3 if i%2==1 else 1)
