# Quixie

## Project Overview
Quixie is a a small RC delivery car, the pcb board handles motor control and sensor expansion, while the firmware manages navigation and telemetry.

## Why I Built This
I wanted to steal chips from my nephew.

<img width="1587" height="2245" alt="quixie-zine" src="https://github.com/user-attachments/assets/b236df10-8bf9-4805-842d-9b7c5c97aa7d" />

---

<img width="1477" height="1065" alt="PCB-Info" src="https://github.com/user-attachments/assets/6d4a1d5e-4a79-4eee-a3e1-453b37cab4f3" />

## What's Inside This Folder
**PCB & Hardware Files:**
- `pcb/` - KiCad project files, schematics, symbols, footprints, and BOM.
- `pcb/rc-car.kicad_pcb` - The main PCB layout file.
- `pcb/rc-car.kicad_sch` - The main schematic.
- `pcb/rc-car.kicad_pro` - KiCad project file for editing.
- `fabrication/pcb/` - Gerbers and drill files for manufacturing.
- `fabrication/3d/pcb-model.stl` - 3D model of the PCB.

**Firmware:**
- `firmware/rc-car/` - All firmware source code.
- `firmware/rc-car/include/` - Header files.
- `firmware/rc-car/src/` - Implementation files.

**3D Case Files:**
- `fabrication/3d/rc-car-case.f3d` - CAD source for the case.
- `fabrication/3d/rc-car-case.stl` - 3D printable case.

**Misc Files:**
- `pcb/rc-car-BOM.csv` - BOM.
- `docs/assets/` - Project images and media.

## The Files You Actually Need
**To Manufacture the PCB:**
1. `pcb/rc-car.kicad_pcb`
2. `fabrication/pcb/` - Gerbers and drill files.
3. `pcb/rc-car.kicad_sch`

**To Print the Case:**
1. `fabrication/3d/rc-car-case.stl`
2. `fabrication/3d/rc-car-case.f3d`

---

## Build Guide

### Step 1 - Export Gerbers from KiCad
Open `pcb/rc-car.kicad_pcb` in KiCad, generate Gerbers and drill files, and export them into `fabrication/pcb/`. Zip all outputs together.

---

### Step 2 - Order the PCB
Upload your Gerber zip to JLCPCB.

---

### Step 3 - Solder and Populate
Populate the core components, motor driver, connectors, and sensor headers.

---

### Step 4 - Flash the Firmware
Use PlatformIO in `firmware/rc-car/` to build and flash the firmware.

---

### Step 5 - 3D Print
- **Material:** PLA works well.
- Use `fabrication/3d/rc-car-case.stl`.

---

### Step 6 - Final Assembly
Mount the PCB in the case, wire the motors and power, and connect sensors.

---

### Modifying the Firmware
- Main config lives in `firmware/rc-car/include/Config.h`.
- Features are organized under `firmware/rc-car/src/`.
