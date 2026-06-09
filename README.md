# EV Charger Edge Node Firmware

## Overview

This project implements firmware for an EV Charger Edge Node using ESP32. The firmware simulates voltage and current measurements, applies EMA filtering, calculates power, detects fault conditions, generates CAN payload data, logs faults through UART, and handles sensor and communication failures.

---

## Platform Choice

### Platform

* ESP32

### Programming Language

* C/C++ (Arduino Framework)

### Simulation Environment

* Wokwi

### Reason for Selection

ESP32 was selected because it supports UART communication and CAN (TWAI) communication. Wokwi provides a simple environment for firmware simulation without requiring physical hardware.

---

## Repository Contents

* Part A Design Document (PDF)
* Firmware Source Code (`EV_Charger_FirmwareCode.ino`)
* Wokwi Simulation Configuration (`diagram.json`)
* README

---

## Setup Instructions

1. Open the project in Wokwi.
2. Load the firmware source code.
3. Start the simulation.
4. Open the Serial Monitor.

---

## Running the Simulation

1. Click the Run button in Wokwi.
2. The firmware will:

   * Simulate voltage and current readings
   * Apply EMA filtering
   * Calculate power
   * Detect fault conditions
   * Generate CAN payload data
   * Log status messages through UART

---

## Observing UART Output

UART output is displayed in the Wokwi Serial Monitor.

The Serial Monitor displays:

* Voltage readings
* Current readings
* Power calculations
* CAN frame contents
* Fault messages
* Error messages

Example:

FAULT: OVER VOLTAGE | Value: 485V | Threshold: 480V

ERROR: Sensor Read Failed. Using Last Known Good Value.

---

## Wokwi Simulation

The repository includes the `diagram.json` file required to run the simulation in Wokwi.
Wokwi Project Link:
https://wokwi.com/projects/466357819558615041
---

## Limitations

The CAN payload structure, frame packing logic, and fault flag encoding were implemented and verified through UART output.

Attempts were made to verify ESP32 TWAI communication using simulation environments including Wokwi and PlatformIO. However, full CAN/TWAI communication testing requires either:

* A simulator with complete CAN/TWAI support and a second CAN node, or
* Physical CAN hardware (ESP32 with a CAN transceiver module and a second CAN device).

As the project was completed using simulation only and no external CAN hardware was available, actual bus-level CAN transmission and reception could not be fully verified.
The implementation therefore focuses on CAN message generation, payload packing, fault reporting, and communication logic, which can be integrated with physical CAN hardware for complete validation.

---

## AI Tool Usage

ChatGPT and Claude AI was used as a supporting tool for documentation review, clarification of embedded systems concepts, and discussion of implementation approaches during development.

Specifically, it was used to:

* Review and improve the structure and presentation of the design document and README.
* Discuss ESP32 TWAI (CAN) communication concepts and simulation limitations in Wokwi.
* Explain filtering techniques such as Exponential Moving Average (EMA) and their design trade-offs.
  
All implementation decisions, code, and project deliverables were reviewed, understood, and validated before submission.


----


