#include <iostream>
#include <vector>

#include "parser.h"
#include "modbus_parser.h"

int main()
{
    try
    {
        // Sample Modbus TCP Packet
        std::vector<uint8_t> rawPacket =
        {
            0x00, 0x01,   // Transaction ID
            0x00, 0x00,   // Protocol ID
            0x00, 0x06,   // Length
            0x01,         // Unit ID
            0x03,         // Function Code (Read Holding Registers)
            0x00, 0x00,   // Starting Address
            0x00, 0x0A    // Quantity of Registers
        };

        Parser parser;
        Packet packet = parser.parse(rawPacket);

        ModbusParser modbusParser;
        modbusParser.parsePacket(packet);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}