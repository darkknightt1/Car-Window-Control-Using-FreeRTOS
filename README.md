# Car Window Control with FreeRTOS

## 🚗 Overview

This project simulates a real-world car window control system on a **TM4C123GH6PM** microcontroller using **FreeRTOS**. It manages driver and passenger inputs, supports manual and automatic window movement, detects obstacles, and communicates status via UART.

## ⚙️ Features

- **Driver & Passenger Control** — Separate up/down buttons with auto/manual modes  
- **FreeRTOS Multitasking** — Real-time task management for responsive control  
- **Obstacle Detection** — Auto-reverse when obstruction is sensed (PF1)  
- **Limit Switches** — Stop window at physical bounds (PD6/PD7)  
- **UART Feedback** — Real-time state updates (e.g., 'A' = Auto Up)

## 🧩 Hardware Setup

- **MCU:** TM4C123GH6PM  
- **Motor Pins:** PA2-PA4, PB6, PB7  
- **Inputs:**  
  - Driver: PF0 (Up), PF4 (Down)  
  - Passenger: PF2 (Up), PF3 (Down)  
  - Obstacle Sensor: PF1  
  - Limit Switches: PD6 (Top), PD7 (Bottom)  
- **UART:** Monitor states using a terminal app

## 💻 Software Tasks

| Task         | Function                       |
|--------------|--------------------------------|
| `DriverUp`   | Manual/Auto Up (Driver)        |
| `DriverDown` | Manual/Auto Down (Driver)      |
| `PassengerUp`| Manual/Auto Up (Passenger)     |
| `PassengerDown`| Manual/Auto Down (Passenger) |
| `obstaclee`  | Obstacle detection and response|
| `UART_TASK`  | UART state transmission        |

## 📡 UART State Codes

| Code | Meaning          |
|------|------------------|
| 'A'  | Auto Up (Driver) |
| 'B'  | Manual Up        |
| 'C'  | Auto Down        |
| ...  | (More codes...)  |
