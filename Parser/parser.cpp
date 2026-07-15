#include "parser.h"
#include <stdexcept>

Parser::Parser()
{
}

bool Parser::isValidPacket(const std::vector<uint8_t>& rawData)
{
    // Minimum Modbus TCP packet size = 8 bytes
    return rawData.size() >= 8;
}

Packet Parser::parse(const std::vector<uint8_t>& rawData)
{
    if (!isValidPacket(rawData))
    {
        throw std::runtime_error("Invalid Modbus TCP Packet");
    }

    Packet packet;

    // MBAP Header
    packet.transactionId = (rawData[0] << 8) | rawData[1];
    packet.protocolId    = (rawData[2] << 8) | rawData[3];
    packet.length        = (rawData[4] << 8) | rawData[5];
    packet.unitId        = rawData[6];

    // PDU
    packet.functionCode = rawData[7];

    // Remaining bytes = Data
    for (size_t i = 8; i < rawData.size(); i++)
    {
        packet.data.push_back(rawData[i]);
    }

    return packet;
}