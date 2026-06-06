# ctrlPad firmware

![GitHub stars](https://img.shields.io/github/stars/ctrlPad/firmware?style=for-the-badge&logo=github) ![GitHub issues](https://img.shields.io/github/issues/ctrlPad/firmware?style=for-the-badge&logo=github) ![Last commit](https://img.shields.io/github/last-commit/ctrlPad/firmware?style=for-the-badge&logo=github)

The firmware of the ctrlPad is written in PlatformIO.


## Table of Content

- [Requirements](#requirements)
- [Layout](#layout)
- [Contributing](#contributing)
- [Development Setup](#development-setup)


## Requirements

- A Cheap-Yellow-Display (ESP32)
- PlatformIO (VS-Code plugin or CLI)
- Bluetooth
- USB Cable

## Layout

The layout is configured over a BLE connection. Once connected to 'ctrlPad-BLE', the JSON string can be sent to the ESP. In the future, this process will be handled by an Elgato-like desktop application.

### Example
```
[{"id":0,"name":"Mute","icon":"\uf130"},{"id":1,"name":"Volume increase","icon":"\uf028"},{"id":2,"name":"Volume decrease","icon":"\uf027"},{"id":3,"name":"Open Discord","icon":"\uf392"},{"id":4,"name":"Open Spotify","icon":"\uf1bc"},{"id":5,"name":"Open Bitwarden","icon":"\uf084"}]
```

## Development Setup

To contribute to this project, please ensure you have [devenv](https://deven.sh) installed on your system.

```
# Clone the repository
git clone https://github.com/CtrlPad/firmware.git
cd firmware

# Enter the development environment
devenv shell
```

### Available Scripts

| Command | Description |
| :--- | :--- |
| `pio:build` | Compiles the project source code |
| `pio:upload` | Flashes the compiled firmware to the connected microcontroller |
| `pio:monitor` | Opens the serial device monitor at a baud rate of 115200 in quiet mode |
| `pio:run` | Builds, uploads the firmware, and automatically starts the serial monitor |
| `pio:clean` | Cleans the build environment and removes compiled object files |

## Contributing

1. **Fork** the repository
2. **Clone** your fork: `git clone https://github.com/ctrlPad/firmware.git`
3. **Branch**: `git checkout -b feature/your-feature`
4. **Commit**: `git commit -m 'feat: add some feature'`
5. **Push**: `git push origin feature/your-feature`
6. **Open** a PR

Please follow the existing code style. Thanks!
