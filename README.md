# HAB-2 Recovery System
An independent, audible locator beacon for a high-altitude balloon payload, built to keep working even if the main flight computer fails mid-flight... also an Apple AirTag

## Why I Built This - the problem
- HAB-1 used an active buzzer, an Apple AirTag, and an APRS antenna for recovery
- I wanted a recovery system that operates completely independently of the main flight program, with its own power source, so a single point of failure couldn't take down the whole ability to find the payload

## Design Criteria
- Must operate independently of the rest of the flight program (in case the main system breaks or fries)
- Must be independently powered (separate from the Mega)
- Must be audible from the ground
- Can't buzz until roughly 1000 ft on the descent
- Total weight: 150-200g

## Tools Used
### Hardware
- Seeed Studio XIAO ESP32S3
- MOSFET driver module (PWM signal input, 5-36V load output)
- Piezo buzzer (QC passed, 6V DC)
- Push button
- 3.7 V LIPO Battery

### Software
- Arduino IDE
- C++ (Arduino core for ESP32)

## How It Works
- A single battery powers the whole circuit. 
- Pressing the button starts the 145-minute timer (2 hours, 25 minutes)
- After the timer ends, the buzzer beeps repeatedly until... the battery runs out (meant to buzz until the payload is found)



## Battery
3.7V single-cell LiPo 2000mAh - sized with margin WAY above the calculated 7-hour runtime requirement to account for cold-temperature capacity loss at altitude


## Results
- Balloon launched and was recovered in a forest! AirTag started tracking once we got close enough to the balloon

## Future Improvements
- Replace the manual push button with an automatic launch-detect mechanism
- Move from a soldered perfboard to a PCB
- Have an altitude sensor determine when to start buzzing (instead of a timer)
