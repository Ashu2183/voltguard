#ifndef PACKET_H
#define PACKET_H

#include <cstdint>
#include <vector>

struct Packet
{
    uint16_t transactionId;
    uint16_t protocolId;
    uint16_t length;
    uint8_t unitId;

    uint8_t functionCode;

    std::vector<uint8_t> data;
};

#endif