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

---
## AI Tool Usage

ChatGPT and Claude AI was used as a supporting tool for documentation review, clarification of embedded systems concepts, and discussion of implementation approaches during development.

Specifically, it was used to:

* Review and improve the structure and presentation of the design document and README.
* Discuss ESP32 TWAI (CAN) communication concepts and simulation limitations in Wokwi.
* Explain filtering techniques such as Exponential Moving Average (EMA) and their design trade-offs.
All implementation decisions, code, and project deliverables were reviewed, understood, and validated before submission.


----


