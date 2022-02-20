#pragma once

/*
* -----------------------------------------------------------------------------
* General message structure:
* [IDCMDRRRRCC]
* Where:
* [ - Message start character
* ID - Message ID
* CMD - Command bits (Length depends on message id)
* RRRR - 4 bits reserved for future use
* CC - Checksum
* ] - Message end character
* -----------------------------------------------------------------------------
*/

// Serial
#define BAUD_RATE  115200
#define PORT_NAME "COM1"

// Dbus Processes
#define DBUS_TEST "Test"
#define DBUS_SERIAL "Serial"
#define DBUS_DASHBOARD "Dashboard"
#define DBUS_TLDETECTOR "TLDetector"
