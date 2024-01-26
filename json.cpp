#include "json.h"

std::ostream& operator<<(std::ostream& os, MDFlagsSet flags) {
    os << "[";

    bool isFirst = true;
    auto checkFlag = [&](MDFlagsSet flag, const std::string& name) {
        if (static_cast<uint64_t>(flags) & static_cast<uint64_t>(flag)) {
            if (!isFirst) {
                os << ", ";
            }
            os << "\"" << name << "\"";
            isFirst = false;
        }
    };

    checkFlag(MDFlagsSet::day, "day");
    checkFlag(MDFlagsSet::ioc, "ioc");
    checkFlag(MDFlagsSet::nonQuote, "nonQuote");
    checkFlag(MDFlagsSet::endOfTransaction, "endOfTransaction");
    checkFlag(MDFlagsSet::dueToCrossCancel, "dueToCrossCancel");
    checkFlag(MDFlagsSet::secondLeg, "secondLeg");
    checkFlag(MDFlagsSet::fok, "fok");
    checkFlag(MDFlagsSet::replace, "replace");
    checkFlag(MDFlagsSet::cancel, "cancel");
    checkFlag(MDFlagsSet::massCancel, "massCancel");
    checkFlag(MDFlagsSet::negotiated, "negotiated");
    checkFlag(MDFlagsSet::multiLeg, "multiLeg");
    checkFlag(MDFlagsSet::crossTrade, "crossTrade");
    checkFlag(MDFlagsSet::cod, "cod");
    checkFlag(MDFlagsSet::activeSide, "activeSide");
    checkFlag(MDFlagsSet::passiveSide, "passiveSide");
    checkFlag(MDFlagsSet::synthetic, "synthetic");
    checkFlag(MDFlagsSet::rfs, "rfs");
    checkFlag(MDFlagsSet::syntheticPassive, "syntheticPassive");
    checkFlag(MDFlagsSet::boc, "boc");
    checkFlag(MDFlagsSet::duringDiscreteAuction, "duringDiscreteAuction");

    os << "]";

    return os;
}

std::ostream& operator<<(std::ostream& os, MDFlags2Set flags) {
    os << "[";

    bool isFirst = true;
    auto checkFlag = [&](MDFlags2Set flag, const std::string& name) {
        if (static_cast<uint64_t>(flags) & static_cast<uint64_t>(flag)) {
            if (!isFirst) {
                os << ", ";
            }
            os << "\"" << name << "\"";
            isFirst = false;
        }
    };

    checkFlag(MDFlags2Set::zero, "zero");

    os << "]";
    return os;
}

std::ostream& operator<<(std::ostream& os, FlagsSet flags) {
    os << "[";

    bool isFirst = true;
    auto checkFlag = [&](FlagsSet flag, const std::string& name) {
        if (static_cast<uint64_t>(flags) & static_cast<uint64_t>(flag)) {
            if (!isFirst) {
                os << ", ";
            }
            os << "\"" << name << "\"";
            isFirst = false;
        }
    };

    checkFlag(FlagsSet::eveningOrMorningSession, "eveningOrMorningSession");
    checkFlag(FlagsSet::anonymousTrading, "anonymousTrading");
    checkFlag(FlagsSet::privateTrading, "privateTrading");
    checkFlag(FlagsSet::daySession, "daySession");
    checkFlag(FlagsSet::multiLeg, "multiLeg");
    checkFlag(FlagsSet::collateral, "collateral");
    checkFlag(FlagsSet::intradayExercise, "intradayExercise");

    os << "]";
    return os;
}

std::ostream& operator<<(std::ostream& os, MsgFlagsSet flags) {
    os << "[";

    bool isFirst = true;
    auto checkFlag = [&](MsgFlagsSet flag, const std::string& name) {
        if (static_cast<uint64_t>(flags) & static_cast<uint64_t>(flag)) {
            if (!isFirst) {
                os << ", ";
            }
            os << "\"" << name << "\"";
            isFirst = false;
        }
    };

    checkFlag(MsgFlagsSet::lastFragment, "lastFragment");
    checkFlag(MsgFlagsSet::startOfSnapshot, "startOfSnapshot");
    checkFlag(MsgFlagsSet::endOfSnapshot, "endOfSnapshot");
    checkFlag(MsgFlagsSet::incrementalPacket, "incrementalPacket");
    checkFlag(MsgFlagsSet::possDupFlag, "possDupFlag");

    os << "]";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Decimal5& decimal) {
    os << "{";
    os << "\"mantissa\": " << decimal.mantissa;
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Decimal5NULL& decimal) {
    os << "{";
    os << "\"mantissa\": " << decimal.mantissa;
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, MDUpdateAction action) {
    switch (action) {
    case MDUpdateAction::New: os << "\"New\""; break;
    case MDUpdateAction::Change: os << "\"Change\""; break;
    case MDUpdateAction::Delete: os << "\"Delete\""; break;
    default: os << "\"Unknown\""; break;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, MDEntryType entryType) {
    switch (entryType) {
    case MDEntryType::Bid: os << "\"Bid\""; break;
    case MDEntryType::Offer: os << "\"Offer\""; break;
    case MDEntryType::EmptyBook: os << "\"EmptyBook\""; break;
    default: os << "\"Unknown\""; break;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const OrderUpdate* orderUpdate) {
    os << "{";
    os << "\"mdEntryID\": " << orderUpdate->mdEntryID << ", ";
    os << "\"mdEntryPx\": " << orderUpdate->mdEntryPx << ", ";
    os << "\"mdEntrySize\": " << orderUpdate->mdEntrySize << ", ";
    os << "\"mdFlags\": " << orderUpdate->mdFlags << ", ";
    os << "\"mdFlags2\": " << orderUpdate->mdFlags2 << ", ";
    os << "\"securityID\": " << orderUpdate->securityID << ", ";
    os << "\"rptSeq\": " << orderUpdate->rptSeq << ", ";
    os << "\"mdUpdateAction\": " << orderUpdate->mdUpdateAction << ", ";
    os << "\"mdEntryType\": " << orderUpdate->mdEntryType;
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const OrderExecution* orderExe) {
    os << "{";
    os << "\"mdEntryID\": " << orderExe->mdEntryID << ", ";
    os << "\"mdEntryPx\": " << orderExe->mdEntryPx << ", ";
    os << "\"mdEntrySize\": " << orderExe->mdEntrySize << ", ";
    os << "\"lastPx\": " << orderExe->lastPx << ", ";
    os << "\"lastQty\": " << orderExe->lastQty << ", ";
    os << "\"tradeID\": " << orderExe->tradeID << ", ";
    os << "\"mdFlags\": " << orderExe->mdFlags << ", ";
    os << "\"mdFlags2\": " << orderExe->mdFlags2 << ", ";
    os << "\"securityID\": " << orderExe->securityID << ", ";
    os << "\"rptSeq\": " << orderExe->rptSeq << ", ";
    os << "\"mdUpdateAction\": " << orderExe->mdUpdateAction << ", ";
    os << "\"mdEntryType\": " << orderExe->mdEntryType;
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const MarketDataPacketHeader* marketHeader) {
    os << "{";
    os << "\"msgSeqNum\": " << marketHeader->msgSeqNum << ", ";
    os << "\"msgSize\": " << marketHeader->msgSize << ", ";
    os << "\"msgFlags\": " << marketHeader->msgFlags << ", ";
    os << "\"sendingTime\": " << marketHeader->sendingTime;
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const IncrementalPacketHeader* incrHeader) {
    os << "{";
    os << "\"transactTime\": " << incrHeader->transactTime << ", ";
    os << "\"exchangeTradingSessionID\": " << incrHeader->exchangeTradingSessionID;
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const SBEHeader* incrHeader) {
    os << "{";
    os << "\"blockLength\": " << incrHeader->blockLength << ", ";
    os << "\"templateID\": " << incrHeader->templateID << ", ";
    os << "\"schemaID\": " << incrHeader->schemaID << ", ";
    os << "\"version\": " << incrHeader->version;
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const OrderBookSnapshotEntry* ordBookEntry) {
    os << "{";
    os << "\"MDEntryID\": " << ordBookEntry->MDEntryID << ", ";
    os << "\"TransactTime\": " << ordBookEntry->TransactTime << ", ";
    os << "\"MDEntryPx\": " << ordBookEntry->MDEntryPx << ", ";
    os << "\"MDEntrySize\": " << ordBookEntry->MDEntrySize << ", ";
    os << "\"TradeID\": " << ordBookEntry->TradeID << ", ";
    os << "\"MDFlags\": " << ordBookEntry->MDFlags << ", ";
    os << "\"MDFlags2\": " << ordBookEntry->MDFlags2 << ", ";
    os << "\"MDEntryType\": " << ordBookEntry->MDEntryType;
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<const OrderBookSnapshotEntry*>& entries) {
    if (entries.size() > 0) {
        os << ", \"NoMDEntries\": [";
        for (size_t i = 0; i < entries.size(); ++i) {
            os << (i > 0 ? ", " : "") << entries[i];
        }
        os << "]";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const OrderBookSnapshot* ordBook) {
    os << "{";
    os << "\"securityID\": " << ordBook->securityID << ", ";
    os << "\"lastMsgSeqNumProcessed\": " << ordBook->lastMsgSeqNumProcessed << ", ";
    os << "\"rptSeq\": " << ordBook->rptSeq << ", ";
    os << "\"exchangeTradingSessionID\": " << ordBook->exchangeTradingSessionID;
    return os;
}

std::ostream& operator<<(std::ostream& os, const GroupSize* group) {
    os << "{";
    os << "\"blockLength\": " << group->blockLength << ", ";
    os << "\"numInGroup\": " << group->numInGroup;
    os << "}";
    return os;
}
