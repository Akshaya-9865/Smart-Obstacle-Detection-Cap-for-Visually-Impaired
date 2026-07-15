# Smart-Obstacle-Detection-Cap-for-Visually-Impaired
ESP32-based smart wearable for visually impaired users that detects obstacles in four directions using ultrasonic sensors and provides real-time voice alerts through a DFPlayer Mini, enabling safer and hands-free navigation.
 🧢 Smart Obstacle Detection Cap for Visually Impaired
An ESP32-based wearable assistive device designed to help visually impaired individuals navigate safely by detecting nearby obstacles using ultrasonic sensors and providing real-time voice alerts through a speaker.
 📖 Project Overview
The Smart Obstacle Detection Cap is a low-cost wearable navigation aid developed using the ESP32 microcontroller. Four ultrasonic sensors continuously monitor the surroundings from the front, left, right, and rear. Based on the detected obstacle distance and direction, the ESP32 plays appropriate pre-recorded voice messages through a DFPlayer Mini MP3 module.
The project aims to improve mobility and environmental awareness for visually impaired users by providing hands-free audio guidance.

✨ Features
- Real-time obstacle detection
- Four-direction obstacle monitoring
- Voice alerts using DFPlayer Mini
- ESP32-based embedded system
- Low-cost and portable design
- Continuous distance monitoring
- Serial Monitor debugging support
  
🛠 Hardware Components
 Component 	                 Quantity 
 ESP32 Development Board 	   1 
 HC-SR04 Ultrasonic Sensor 	 4 
 DFPlayer Mini MP3 Module 	 1 
 Speaker 	                   1 
 MicroSD Card 	             1 
 Jumper Wires 	             As required 
 Power Supply 	             5V 
 
💻 Software Requirements
- Arduino IDE
- ESP32 Board Package
- DFRobotDFPlayerMini Library
- SoftwareSerial Library
  
⚙ Working Principle
1. The ESP32 continuously triggers all four ultrasonic sensors.
2. Each sensor measures the distance to nearby obstacles.
3. The ESP32 compares the measured distances with predefined threshold values.
4. According to the detected direction and distance, a corresponding audio file is selected.
5. The DFPlayer Mini plays the voice alert through the speaker.
6. The process repeats continuously to provide real-time assistance.
System Architecture
 
 🔌 Pin Configuration
 Device 	       ESP32 Pin 
 Front Trigger 	 GPIO 2 
 Front Echo 	   GPIO 4 
 Left Trigger 	 GPIO 5 
 Left Echo 	     GPIO 18 
 Right Trigger 	 GPIO 19 
 Right Echo 	   GPIO 21 
 Back Trigger 	 GPIO 22 
 Back Echo 	     GPIO 23 
 DFPlayer RX  	 GPIO 16 
 DFPlayer TX 	   GPIO 17 

🔊 Voice Alerts
 MP3 File 	 Description 
 0001.mp3 	 Obstacle very close ahead 
 0002.mp3 	 Obstacle ahead 
 0003.mp3 	 Obstacle on the left 
 0004.mp3 	 Obstacle on the right 
 0005.mp3 	 Obstacle behind 
 0009.mp3 	 Path clear 

📌 Current Project Status
✅ Implemented
- ESP32 Controller
- Four Ultrasonic Sensors
- Multi-direction Obstacle Detection
- DFPlayer Mini Integration
- Voice Alert System
- Distance Measurement
🚧 Planned Future Enhancements
- 360° LiDAR Integration
- AI-based Navigation Assistance
- Gyroscope and Accelerometer
- Fall Detection
- Haptic Feedback
- SOS Emergency Button
- Wi-Fi Connectivity
- Mobile Application
- GPS Navigation
- Object Recognition using Computer Vision
🚀 Future Scope
Future versions of this project will integrate additional sensors and artificial intelligence techniques to improve navigation accuracy and user safety. Planned enhancements include LiDAR-based mapping, AI-powered object recognition, fall detection, emergency SOS messaging, haptic feedback, and smartphone connectivity.

