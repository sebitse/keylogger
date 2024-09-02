# Basic keylogger

This project is a simple keylogger for Windows. It captures keypresses and logs them into a text file. The keylogger is designed with C++ and uses basic logging mechanisms.

## Features

- Captures and logs all keypresses.
- Includes a customizable log format.
- Logs are saved to a text file (`keylog.txt`).
- Minimal CPU usage with an efficient event loop.

## Requirements

- **Windows OS**: This project is designed to run on Windows
- **C++17**: The code is written in C++
- **Make**:  To build the project.

## Installation

1. **Clone the Repository**:
    ```
    git clone https://github.com/sebitse/keylogger
    cd keylogger
    ```

2. **Build the Project**:
    ```
    make all
    ```

3. **Run the Executable**:
    ```
    ./keylogger
    ```

## Usage

- The keylogger will start running immediately after execution.
- All keypresses will be logged in the `keylog.txt` file located in the same directory as the `.exe` file.

### Customizing Log Format

Thanks to the use of Strategy Design Pattern you can customize the format of the logged messages by modifying the MACROS definition and the object declaration in the `main.cpp` file. 

## Notes
- This keylogger is a demonstration and should be used responsibly. Unauthorized use of keyloggers is illegal and unethical.
- The code is intended for educational purposes only (with the great power comes great responsibility).
