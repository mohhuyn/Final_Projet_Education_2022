#getting the essential libreries for this project…
import cv2
from time import time
from picamera import PiCamera
import time
#Setting the camera    
Width=640
Height=480
cam=cv2.VideoCapture(0,cv2.CAP_DSHOW)
cam=PiCamera()
cam.set(cv2.CAP_PROP_FRAME_WIDTH, Width)
cam.set(cv2.CAP_PROP_FRAME_HEIGHT,Height)
cam.set(cv2.CAP_PROP_FPS, 30)
cam.set(cv2.CAP_PROP_FOURCC,cv2.VideoWriter_fourcc(*'MJPG'))
#The file which contains the model haar of frontal face detection 
Face_O=cv2.CascadeClassifier(haar/haarcascade_frontalface_default.xml')
Count=0
TimeN=time.time()
time.sleep(2)
while True:
    TimeM=time.time()-TimeN
    TimeN=time.time()
    T=int(1/TimeM)
    print(T)
    ignore,  frame = cam.read()
    framG=cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    faces=Face_O.detectMultiScale(framG,1.3,5)
    cv2.putText(frame,str(T)+'fps',(25,25),cv2.FONT_HERSHEY_COMPLEX,1,(0,255,0),1) 
    for face in faces:
        x,y,z,k=face
        print(x,y,z,k)
        cv2.rectangle(frame,(x,y),(z+x,k+y),(0,255,0))
        cv2.imshow('my WEBcam', frame)
        cv2.moveWindow('my WEBcam',0,0)
        file='raspberry/home/Desktop/Patients_File/Patient'+str(count)+'.jpg'
        cv2.imwrite(file, frame)   
        count=count+1
    if cv2.waitKey(1) & 0xff ==ord('q'):
        break
cam.release()
cv2.destroyWindow
