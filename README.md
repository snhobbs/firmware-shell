# firmware-shell
Shell for embedded systems with argument parsing. Based on the example project from https://interrupt.memfault.com/blog/firmware-shell.
This is useful only for a reliable connection. A reliable connection is one that is guaranteed like USB or TCP or longterm reliability isn't a requirement. Protocols such as Modbus RTU or another framed protocol that has corruption checking and resynchronization should be used otherwise.

Useful Articles
- https://interrupt.memfault.com/blog/firmware-shell
- http://www.dalescott.net/an-embedded-command-line-interface/
- https://adnbr.co.uk/articles/parsing-simple-usart-commands
- https://www.analog.com/media/en/reference-design-documentation/design-notes/smartmesh_ip_embedded_manager_cli_guide.pdf
- https://paguilar.org/?page_id=17
- https://github.com/PumpkinSpace/pshell

Similar Projects
- FreeRTOS CLI: https://www.freertos.org/FreeRTOS-Plus/FreeRTOS_Plus_CLI/FreeRTOS_Plus_Command_Line_Interface.html
- https://github.com/martinhansdk/embedded-commandline
- https://github.com/jeroendoggen/Arduino-serial-messaging
- https://github.com/damogranlabs/serial-tool
- https://github.com/ShareCat/STM32CommandLine
- https://github.com/psychogenic/SerialUI
- https://github.com/gbmhunter/NinjaTerm
- https://github.com/bhimebau/serialT
- https://github.com/bleverett/qst
- https://github.com/filipecalasans/EmbeddedSerialLibrary
- https://github.com/alterapraxisptyltd/serialterm
- https://github.com/fenix0xf/sterm
- https://playground.arduino.cc/Code/CmdMessenger/

Alternatives To CLI
- Modbus RTU
- Firmata: https://github.com/firmata/protocol
- Min: https://github.com/min-protocol/min
- TinyFrame: https://github.com/MightyPork/TinyFrame
- https://github.com/astraw/framed-serial
