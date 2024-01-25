#pragma once
#include <cstdint>
#include <type_traits>

class MsgFlags {
public:
    // Define the flag constants
    const static uint16_t LastFragmentFlag = 0x1;
    const static uint16_t StartOfSnapshotFlag = 0x2;
    const static uint16_t EndOfSnapshotFlag = 0x4;
    const static uint16_t IncrementalPacketFlag = 0x8;
    const static uint16_t PossDupFlag = 0x10;
};

enum class MDFlagsSet : uint64_t {
    day = 1ULL << 0,
    ioc = 1ULL << 1,
    nonQuote = 1ULL << 2,
    endOfTransaction = 1ULL << 12,
    dueToCrossCancel = 1ULL << 13,
    secondLeg = 1ULL << 14,
    fok = 1ULL << 19,
    replace = 1ULL << 20,
    cancel = 1ULL << 21,
    massCancel = 1ULL << 22,
    negotiated = 1ULL << 26,
    multiLeg = 1ULL << 27,
    crossTrade = 1ULL << 29,
    cod = 1ULL << 32,
    activeSide = 1ULL << 41,
    passiveSide = 1ULL << 42,
    synthetic = 1ULL << 45,
    rfs = 1ULL << 46,
    syntheticPassive = 1ULL << 57,
    boc = 1ULL << 60,
    duringDiscreteAuction = 1ULL << 62
};

inline MDFlagsSet operator|(MDFlagsSet a, MDFlagsSet b) {
    return static_cast<MDFlagsSet>(static_cast<std::underlying_type<MDFlagsSet>::type>(a) |
        static_cast<std::underlying_type<MDFlagsSet>::type>(b));
}

enum class MDFlags2Set : uint64_t {
    zero = 1ULL << 0
};

enum class FlagsSet : uint64_t {
    eveningOrMorningSession = 1ULL << 0,
    anonymousTrading = 1ULL << 4,
    privateTrading = 1ULL << 5,
    daySession = 1ULL << 6,
    multiLeg = 1ULL << 8,
    collateral = 1ULL << 18,
    intradayExercise = 1ULL << 19
};

enum class MsgFlagsSet : uint16_t {
    lastFragment = 1 << 0,
    startOfSnapshot = 1 << 1,
    endOfSnapshot = 1 << 2,
    incrementalPacket = 1 << 3,
    possDupFlag = 1 << 4
};

enum class MDUpdateAction : uint8_t {
    New = 0,
    Change = 1,
    Delete = 2
};

enum class MDEntryType : char {
    Bid = '0',
    Offer = '1',
    EmptyBook = 'J'
};


class Decimal5NULL {
public:
    static constexpr int8_t exponent = -5;
    int64_t mantissa;

    Decimal5NULL() : mantissa(9223372036854775807) {}

    explicit Decimal5NULL(int64_t mantissaValue) : mantissa(mantissaValue) {}

    void setNull() {
        mantissa = 9223372036854775807;  // null value
    }

    bool isNull() const {
        return mantissa == 9223372036854775807;
    }
};

struct Decimal5 {
    static constexpr int8_t exponent = -5;
    int64_t mantissa;

    Decimal5() = default;

    explicit Decimal5(int64_t mantissaValue) : mantissa(mantissaValue) {}
};

struct GroupSize {
    static constexpr int8_t size = 3;

    uint16_t blockLength;
    uint8_t numInGroup;
};

struct OrderUpdate {
    static constexpr int8_t size = 50;

    int64_t mdEntryID;
    Decimal5 mdEntryPx;
    int64_t mdEntrySize;
    MDFlagsSet mdFlags;
    MDFlags2Set mdFlags2;
    int32_t securityID;
    uint32_t rptSeq;
    MDUpdateAction mdUpdateAction;
    MDEntryType mdEntryType;

    OrderUpdate() = default;
};

struct OrderExecution {
    static constexpr int8_t size = 74;

    int64_t mdEntryID;
    Decimal5NULL mdEntryPx;
    int64_t mdEntrySize; // Int64NULL
    Decimal5 lastPx;
    int64_t lastQty;
    int64_t tradeID;
    MDFlagsSet mdFlags;
    MDFlags2Set mdFlags2;
    int32_t securityID;
    uint32_t rptSeq;
    MDUpdateAction mdUpdateAction;
    MDEntryType mdEntryType;
};

struct OrderBookSnapshotEntry {
    static constexpr int8_t size = 57;

    int64_t MDEntryID;
    uint64_t TransactTime;
    Decimal5NULL MDEntryPx;
    int64_t MDEntrySize;
    int64_t TradeID;
    MDFlagsSet MDFlags;
    MDFlags2Set MDFlags2;
    MDEntryType MDEntryType;
};

struct OrderBookSnapshot {
    static constexpr int8_t size = 16;

    int32_t securityID;
    uint32_t lastMsgSeqNumProcessed;
    uint32_t rptSeq;
    uint32_t exchangeTradingSessionID;
};

struct SBEHeader {
    static constexpr int8_t size = 8;

    uint16_t blockLength;
    uint16_t templateID;
    uint16_t schemaID;
    uint16_t version;
};

struct IncrementalPacketHeader {
    static constexpr int8_t size = 12;

    uint64_t transactTime;
    uint32_t exchangeTradingSessionID;
};

struct MarketDataPacketHeader {
    static constexpr int8_t size = 16;

    uint32_t msgSeqNum;
    uint16_t msgSize;
    uint16_t msgFlags;
    uint64_t sendingTime;
};