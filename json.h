#pragma once
#include <sstream>
#include <vector>
#include "SimbaScheme.h"

std::string toJson(MDFlagsSet flags);

std::string toJson(MDFlags2Set flags);

std::string toJson(FlagsSet flags);

std::string toJson(MsgFlagsSet flags);

std::string toJson(const Decimal5& decimal);

std::string toJson(const Decimal5NULL& decimal);

std::string toJson(MDUpdateAction action);

std::string toJson(MDEntryType entryType);

std::string toJson(const OrderUpdate* orderUpdate);

std::string toJson(const OrderExecution* orderExe);

std::string toJson(const MarketDataPacketHeader* marketHeader);

std::string toJson(const IncrementalPacketHeader* incrHeader);

std::string toJson(const SBEHeader* incrHeader);

std::string toJson(const OrderBookSnapshotEntry* ordBookEntry);

std::string toJson(const OrderBookSnapshot* ordBook, const std::vector<const OrderBookSnapshotEntry*>& entries);

std::string toJson(const GroupSize* group);
