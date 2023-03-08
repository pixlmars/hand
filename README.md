# hand
bruh that's a school project

Installation
------------
Install Python 3.10 (or 3.11 if you are on Linux) and Visual Studio Code
python.org
code.visualstudio.com

Given Installation guide is for Linux
In windows change python3 to python and pip3 to pip 

Create Python Virtual Environment
```
mkdir hnd 
python3 -m venv hnd
source hnd/bin/activate
```
then, in VS Code open this environment (there should be notification about that in VS Code)

Install dependencies
Check pip libraries
```
pip3 list
```

The result should be something like:
```
Package Version
------------- -------
pip 20.3.4
pkg-resources 0.0.0
setuptools 44.1.1
```
in VS Code's terminal open project folder with virtual environment and in terminal:
```
pip3 install opencv-python
pip3 install mediapipe
pip3 install serial
```
Move HandTrackingModule.py and main.py in hnd folder and launch main.py 

That's all for now
