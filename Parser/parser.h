#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <cstdint>
#include "packet.h"

class Parser
{
public:
    Parser();

    // Parse raw Modbus TCP packet
    Packet parse(const std::vector<uint8_t>& rawData);

private:
    // Check if packet is valid
    bool isValidPacket(const std::vector<uint8_t>& rawData);
};

#endif // PARSER_H