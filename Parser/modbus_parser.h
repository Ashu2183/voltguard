#ifndef MODBUS_PARSER_H
#define MODBUS_PARSER_H

#include "packet.h"

class ModbusParser
{
public:
    ModbusParser();

    // Parse and display Modbus packet details
    void parsePacket(const Packet& packet);

private:
    // Decode Modbus function code
    const char* getFunctionName(uint8_t functionCode);
};

#endif // MODBUS_PARSER_H