# Quixie - RC Delivery Car

Quixie is a small autonomous RC delivery car. The custom PCB handles motor control and sensor expansion; the firmware manages navigation, telemetry, and the locking cargo bay.

> Built by **AlAoTach** for [Fallout](https://fallout.hackclub.com/)

<img width="1587" height="2245" alt="Blue and Pink Modern Film Poster(4)" src="https://github.com/user-attachments/assets/5c156925-4bee-4ae4-8458-a2cd0e61f788" />

---

## Why I Built This

I wanted to steal chips from my nephew.

---

## Key Features

- **Servo locked cargo bay** - lid opens and closes automatically via servo motor
- **Live camera feed** - ESP32-CAM streamed to the web dashboard
- **GPS navigation** - Neo-8M for real-time position tracking
- **Obstacle avoidance** - 3× ultrasonic sensors
- **OLED display** - SSD1306 1.3" on-device status screen
---

## Tech Specs

| Component | Part |
|-----------|------|
| MCU | ESP32 Mini (ESP32-S3) |
| Motors | Dual DC Geared, 12V |
| Driver | BTN7960B (43A) |
| GPS | Neo-6M |
| IMU | BMI270 |
| Sensors | Ultrasonic ×3 |
| Camera | ESP32-CAM |
| Display | SSD1306 OLED (1.11") |
| Battery | 3S Li-ion (11.1V) |
| Comms | WiFi — Web + WebSocket |

---

## System Overview

<img width="1036" height="702" alt="image-Photoroom" src="https://github.com/user-attachments/assets/722206a5-9cf5-466a-ba7c-72d54a304c77" />

---

## What's in This Repo

```
quixie/
├── pcb/                          # KiCad project
│   ├── rc-car.kicad_pcb          # PCB layout
│   ├── rc-car.kicad_sch          # Schematic
│   ├── rc-car.kicad_pro          # Project file
│   ├── rc-car-BOM.csv            # Bill of materials
│   └── fabrication/              # Gerbers + drill files
├── firmware/
│   └── rc-car/
│       ├── include/              # Header files + Config.h
│       └── src/                  # Source files
├── fabrication/
│   └── 3d/
│       ├── rc-car-case.f3d       # Fusion 360 CAD source
│       ├── rc-car-case.stl       # 3D printable case
│       └── pcb-model.stl         # 3D PCB model
└── docs/assets/                  # Images and media
```

---

## PCB

Front and back of the custom PCB:

<img width="1018" height="712" alt="Screenshot 2026-06-10 111952-Photoroom" src="https://github.com/user-attachments/assets/f790e00c-a156-43b5-a4cd-eb13d4456c9f" />

<img width="1017" height="716" alt="Screenshot 2026-06-10 112009-Photoroom" src="https://github.com/user-attachments/assets/98d2909c-9894-481f-b554-26d8a72295c7" />

---

## 3D Case

The case is 3D printable in PLA.

<img width="1920" height="692" alt="rc-car_2026-Jun-09_08-27-36PM-000_CustomizedView2119663068" src="https://github.com/user-attachments/assets/829a8160-93ea-4615-b46d-b355fbbd46de" />
<img width="1920" height="692" alt="rc-car_2026-Jun-09_08-28-37PM-000_CustomizedView30783760963" src="https://github.com/user-attachments/assets/cdd5af57-83ed-455d-b84e-d282fa896424" />
<img width="1920" height="692" alt="450aec4a-f353-46d9-9899-f3d45b1544f4" src="https://github.com/user-attachments/assets/d51c8741-4ac8-4a92-a9a7-4d6e3ef11c2b" />

**Open cargo bay**

<img width="2089" height="753" alt="open-lid" src="https://github.com/user-attachments/assets/89a82c64-3837-4e8c-bbd9-17e5a106cff5" />

---

## Schematic

### Main schema
<img width="2200" height="1700" alt="schema-quixie-1" src="https://github.com/user-attachments/assets/f15118f1-b7cd-45fb-b802-4cb44f64dbd8" />

### Motor schema
<img width="2200" height="1700" alt="schema-quixie-2" src="https://github.com/user-attachments/assets/12c0a425-9748-4532-b076-998283d890a8" />

### Ultrasonic and TOF
<img width="2200" height="1700" alt="schema-quixie-3" src="https://github.com/user-attachments/assets/ae5da451-9dc9-4f46-a04e-94920ff6b742" />

### Servo lock
<img width="2200" height="1700" alt="schema-quixie-4" src="https://github.com/user-attachments/assets/de41d557-a9e6-4d7d-b624-52a1bc6ce074" />

### Voltage divider
<img width="2200" height="1700" alt="schema-quixie-5" src="https://github.com/user-attachments/assets/3787d4a1-fac4-4772-b835-624111fe74b6" />

### Battery and charging
<img width="2200" height="1700" alt="schema-quixie-6" src="https://github.com/user-attachments/assets/c9e3e440-f2ab-42e6-b80c-4239ef02188a" />

---

## Build Guide

### Step 1 - Export Gerbers

Open `pcb/rc-car.kicad_pcb` in KiCad. Generate Gerbers and drill files into `pcb/fabrication/`. Zip all outputs.

### Step 2 - Order the PCB

Upload your Gerber zip to [JLCPCB](https://jlcpcb.com) or your preferred fab.

### Step 3 - Solder & Populate

Solder the required components ( hope you have gotten SMD from jlcpcb )

### Step 4 - Flash Firmware

```bash
cd firmware/rc-car
pio run --target upload
```

Requires [PlatformIO](https://platformio.org/). Main config is in `firmware/rc-car/include/Config.h`.

### Step 5 - 3D Print the Case

- Material: PLA (PETG also works)
- File: `fabrication/3d/rc-car-case.stl`
- No supports needed for most orientations

### Step 6 - Final Assembly

Mount the PCB in the case, wire motors and power, connect sensors. The servo for the lid attaches at the rear hinge point.

---

## Modifying the Firmware

All config parameters live in:

```
firmware/rc-car/include/Config.h
```

Features are split into modules under `firmware/rc-car/src/`.

---

## License

Open source. Do what you want, just don't use it to steal chips from *my* nephew *cough cough*.
