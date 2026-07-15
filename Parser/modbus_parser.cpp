#include "modbus_parser.h"

#include <iostream>
#include <iomanip>

ModbusParser::ModbusParser()
{
}

const char* ModbusParser::getFunctionName(uint8_t functionCode)
{
    switch (functionCode)
    {
        case 0x01:
            return "Read Coils";

        case 0x02:
            return "Read Discrete Inputs";

        case 0x03:
            return "Read Holding Registers";

        case 0x04:
            return "Read Input Registers";

        case 0x05:
            return "Write Single Coil";

        case 0x06:
            return "Write Single Register";

        case 0x10:
            return "Write Multiple Registers";

        default:
            return "Unknown Function";
    }
}

void ModbusParser::parsePacket(const Packet& packet)
{
    std::cout << "\n========== Modbus TCP Packet ==========\n";

    std::cout << "Transaction ID : " << packet.transactionId << std::endl;
    std::cout << "Protocol ID    : " << packet.protocolId << std::endl;
    std::cout << "Length         : " << packet.length << std::endl;
    std::cout << "Unit ID        : " << static_cast<int>(packet.unitId) << std::endl;

    std::cout << "Function Code  : 0x"
              << std::hex
              << std::uppercase
              << static_cast<int>(packet.functionCode)
              << " (" << getFunctionName(packet.functionCode) << ")"
              << std::dec
              << std::endl;

    std::cout << "Payload Data   : ";

    if (packet.data.empty())
    {
        std::cout << "No Data";
    }
    else
    {
        for (uint8_t byte : packet.data)
        {
            std::cout
                << std::hex
                << std::uppercase
                << std::setw(2)
                << std::setfill('0')
                << static_cast<int>(byte)
                << " ";
        }

        std::cout << std::dec;
    }

    std::cout << "\n=======================================\n";
}