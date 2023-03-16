import cv2
import HandTrackingModule as htm
import serial
#ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
cap = cv2.VideoCapture(0)
detector = htm.handDetector(maxHands=1, detectionCon=0.5) #чем больше detectionCon тем больше у него уверенности (и точности)

while True:
    succes, img = cap.read()
    img = detector.findHands(img)
    lmList, bbox = detector.findPosition(img)
    if lmList:
        fingers = detector.fingersUp()
        x, y = round(lmList[8][1]/80), round(lmList[8][2]/60) # get the x and y coordinates of the tip of the index finger (landmark 8)
        print("Hand position - x:", x, " y:", y)
        print(fingers, x, y)
        #ser.write(fingers, x, y)
    cv2.imshow("Sigma rule #251", img)
    cv2.waitKey(1)
