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
        print(fingers)
        #ser.write(fingers)
        if cv2.waitKey(100) > 0:
            break
    cv2.imshow("Sigma rule number 251", img)
    cv2.waitKey(1)
