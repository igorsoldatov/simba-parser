#include "json.h"

std::string toJson(MDFlagsSet flags) {
    std::stringstream json;
    json << "[";

    bool isFirst = true;
    auto checkFlag = [&](MDFlagsSet flag, const std::string& name) {
        if (static_cast<uint64_t>(flags) & static_cast<uint64_t>(flag)) {
            if (!isFirst) {
                json << ", ";
            }
            json << "\"" << name << "\"";
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

    json << "]";
    return json.str();
}

std::string toJson(MDFlags2Set flags) {
    std::stringstream json;
    json << "[";

    bool isFirst = true;
    auto checkFlag = [&](MDFlags2Set flag, const std::string& name) {
        if (static_cast<uint64_t>(flags) & static_cast<uint64_t>(flag)) {
            if (!isFirst) {
                json << ", ";
            }
            json << "\"" << name << "\"";
            isFirst = false;
        }
    };

    checkFlag(MDFlags2Set::zero, "zero");

    json << "]";
    return json.str();
}

std::string toJson(FlagsSet flags) {
    std::stringstream json;
    json << "[";

    bool isFirst = true;
    auto checkFlag = [&](FlagsSet flag, const std::string& name) {
        if (static_cast<uint64_t>(flags) & static_cast<uint64_t>(flag)) {
            if (!isFirst) {
                json << ", ";
            }
            json << "\"" << name << "\"";
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

    json << "]";
    return json.str();
}

std::string toJson(MsgFlagsSet flags) {
    std::stringstream json;
    json << "[";

    bool isFirst = true;
    auto checkFlag = [&](MsgFlagsSet flag, const std::string& name) {
        if (static_cast<uint64_t>(flags) & static_cast<uint64_t>(flag)) {
            if (!isFirst) {
                json << ", ";
            }
            json << "\"" << name << "\"";
            isFirst = false;
        }
    };

    checkFlag(MsgFlagsSet::lastFragment, "lastFragment");
    checkFlag(MsgFlagsSet::startOfSnapshot, "startOfSnapshot");
    checkFlag(MsgFlagsSet::endOfSnapshot, "endOfSnapshot");
    checkFlag(MsgFlagsSet::incrementalPacket, "incrementalPacket");
    checkFlag(MsgFlagsSet::possDupFlag, "possDupFlag");

    json << "]";
    return json.str();
}

std::string toJson(const Decimal5& decimal) {
    std::stringstream json;
    json << "{";
    json << "\"mantissa\": " << decimal.mantissa;
    json << "}";
    return json.str();
}

std::string toJson(const Decimal5NULL& decimal) {
    std::stringstream json;
    json << "{";
    json << "\"mantissa\": " << decimal.mantissa;
    json << "}";
    return json.str();
}

std::string toJson(MDUpdateAction action) {
    switch (action) {
    case MDUpdateAction::New: return "\"New\"";
    case MDUpdateAction::Change: return "\"Change\"";
    case MDUpdateAction::Delete: return "\"Delete\"";
    default: return "\"Unknown\"";
    }
}

std::string toJson(MDEntryType entryType) {
    switch (entryType) {
    case MDEntryType::Bid: return "\"Bid\"";
    case MDEntryType::Offer: return "\"Offer\"";
    case MDEntryType::EmptyBook: return "\"EmptyBook\"";
    default: return "\"Unknown\"";
    }
}

std::string toJson(const OrderUpdate* orderUpdate) {
    std::stringstream json;
    json << "{";
    json << "\"mdEntryID\": " << orderUpdate->mdEntryID << ", ";
    json << "\"mdEntryPx\": " << toJson(orderUpdate->mdEntryPx) << ", ";
    json << "\"mdEntrySize\": " << orderUpdate->mdEntrySize << ", ";
    json << "\"mdFlags\": " << toJson(orderUpdate->mdFlags) << ", ";
    json << "\"mdFlags2\": " << toJson(orderUpdate->mdFlags2) << ", ";
    json << "\"securityID\": " << orderUpdate->securityID << ", ";
    json << "\"rptSeq\": " << orderUpdate->rptSeq << ", ";
    json << "\"mdUpdateAction\": " << toJson(orderUpdate->mdUpdateAction) << ", ";
    json << "\"mdEntryType\": " << toJson(orderUpdate->mdEntryType);
    json << "}";
    return json.str();
}

std::string toJson(const OrderExecution* orderExe) {
    std::stringstream json;
    json << "{";
    json << "\"mdEntryID\": " << orderExe->mdEntryID << ", ";
    json << "\"mdEntryPx\": " << toJson(orderExe->mdEntryPx) << ", ";
    json << "\"mdEntrySize\": " << orderExe->mdEntrySize << ", ";
    json << "\"lastPx\": " << toJson(orderExe->lastPx) << ", ";
    json << "\"lastQty\": " << orderExe->lastQty << ", ";
    json << "\"tradeID\": " << orderExe->tradeID << ", ";
    json << "\"mdFlags\": " << toJson(orderExe->mdFlags) << ", ";
    json << "\"mdFlags2\": " << toJson(orderExe->mdFlags2) << ", ";
    json << "\"securityID\": " << orderExe->securityID << ", ";
    json << "\"rptSeq\": " << orderExe->rptSeq << ", ";
    json << "\"mdUpdateAction\": " << toJson(orderExe->mdUpdateAction) << ", ";
    json << "\"mdEntryType\": " << toJson(orderExe->mdEntryType);
    json << "}";
    return json.str();
}

std::string toJson(const MarketDataPacketHeader* marketHeader) {
    std::stringstream json;
    json << "{";
    json << "\"msgSeqNum\": " << marketHeader->msgSeqNum << ", ";
    json << "\"msgSize\": " << marketHeader->msgSize << ", ";
    json << "\"msgFlags\": " << marketHeader->msgFlags << ", ";
    json << "\"sendingTime\": " << marketHeader->sendingTime;
    json << "}";
    return json.str();
}

std::string toJson(const IncrementalPacketHeader* incrHeader) {
    std::stringstream json;
    json << "{";
    json << "\"transactTime\": " << incrHeader->transactTime << ", ";
    json << "\"exchangeTradingSessionID\": " << incrHeader->exchangeTradingSessionID;
    json << "}";
    return json.str();
}

std::string toJson(const SBEHeader* incrHeader) {
    std::stringstream json;
    json << "{";
    json << "\"blockLength\": " << incrHeader->blockLength << ", ";
    json << "\"templateID\": " << incrHeader->templateID << ", ";
    json << "\"schemaID\": " << incrHeader->schemaID << ", ";
    json << "\"version\": " << incrHeader->version;
    json << "}";
    return json.str();
}

std::string toJson(const OrderBookSnapshotEntry* ordBookEntry) {
    std::stringstream json;
    json << "{";
    json << "\"MDEntryID\": " << ordBookEntry->MDEntryID << ", ";
    json << "\"TransactTime\": " << ordBookEntry->TransactTime << ", ";
    json << "\"MDEntryPx\": " << toJson(ordBookEntry->MDEntryPx) << ", ";
    json << "\"MDEntrySize\": " << ordBookEntry->MDEntrySize << ", ";
    json << "\"TradeID\": " << ordBookEntry->TradeID << ", ";
    json << "\"MDFlags\": " << toJson(ordBookEntry->MDFlags) << ", ";
    json << "\"MDFlags2\": " << toJson(ordBookEntry->MDFlags2) << ", ";
    json << "\"MDEntryType\": " << toJson(ordBookEntry->MDEntryType);
    json << "}";
    return json.str();
}

std::string toJson(const OrderBookSnapshot* ordBook, const std::vector<const OrderBookSnapshotEntry*>& entries) {
    std::stringstream json;
    json << "{";
    json << "\"securityID\": " << ordBook->securityID << ", ";
    json << "\"lastMsgSeqNumProcessed\": " << ordBook->lastMsgSeqNumProcessed << ", ";
    json << "\"rptSeq\": " << ordBook->rptSeq << ", ";
    json << "\"exchangeTradingSessionID\": " << ordBook->exchangeTradingSessionID;
    if (entries.size() > 0) {
        json << ", \"NoMDEntries\": [";
        for (size_t i = 0; i < entries.size(); ++i) {
            json << (i > 0 ? ", " : "") << toJson(entries[i]);
        }
        json << "]";
    }
    json << "}";
    return json.str();
}

std::string toJson(const GroupSize* group) {
    std::stringstream json;
    json << "{";
    json << "\"blockLength\": " << group->blockLength << ", ";
    json << "\"numInGroup\": " << group->numInGroup;
    json << "}";
    return json.str();
}
