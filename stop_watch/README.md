# Stopwatch Project for TM4C123GH6PM TivaC
## Table of Contents

- [Project Overview](#project-overview)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Project Features](#project-features)
- [Usage](#usage)
- [Author](#author)

## Project Overview

The Stopwatch Project is designed to run on the TM4C123GH6PM TivaC microcontroller. It provides a simple and user-friendly stopwatch functionality using the SysTick timer. The project allows users to start and stop the stopwatch using external buttons. While the stopwatch is running, users can capture up to three laps, and if the stopwatch is in the stop state, pressing a button will reset it.

### Lap Overwriting Behavior

One unique feature of this stopwatch project is that the lap feature continues to overwrite the first lap after displaying three laps. This behavior allows users to cycle through their lap times without the need to clear the display, ensuring a seamless experience.

## Hardware Requirements

To run this project, you will need the following hardware components:

- TM4C123GH6PM TivaC microcontroller board or equivalent.
- A suitable power supply for the microcontroller.
- Two push buttons/buttons on the board (Button1 for start/stop and Button2 for lap/reset).
- An LCD display to show the stopwatch time.

## Software Requirements

- Development environment for TM4C123GH6PM (e.g., TivaWare, Code Composer Studio).
- C/C++ Compiler.
- Appropriate communication interface (e.g., UART, USB) for loading the project onto the microcontroller.

## Project Features

- Start and stop the stopwatch using SW1 on TivaC board (Button1).
- Capture up to three laps while the stopwatch is running using SW2 on TivaC board (Button2).
- The lap feature continues to overwrite on the first lap after displaying three laps, cycling through them.
- Reset the stopwatch to zero when it's in the stop state by pressing Button2.
- User-friendly LCD interface to display the stopwatch time.

## Usage

1. Connect the TM4C123GH6PM TivaC microcontroller to the hardware components (push buttons in case you don't want to use tivaC buttons and LCD display).

2. Compile and load the Stopwatch Project onto the microcontroller.

3. Power on the microcontroller.

4. The LCD display will show the project title and author information.

5. Press Button1 to start or stop the stopwatch. The stopwatch will start counting when you press it for the first time and stop when pressed again.

6. While the stopwatch is running, press Button2 to capture a lap. Up to three laps can be captured.

7. If the stopwatch is in the stop state, press Button2 to reset it to zero.

8. Enjoy using your user-friendly stopwatch!

## Author

- Momen Mohamed Mostafa
- momenayyad64@gmail.com

