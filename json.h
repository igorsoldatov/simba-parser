#pragma once
#include <sstream>
#include <vector>
#include "SimbaScheme.h"

std::ostream& operator<<(std::ostream& os, MDFlagsSet flags);

std::ostream& operator<<(std::ostream& os, MDFlags2Set flags);

std::ostream& operator<<(std::ostream& os, FlagsSet flags);

std::ostream& operator<<(std::ostream& os, MsgFlagsSet flags);

std::ostream& operator<<(std::ostream& os, const Decimal5& decimal);

std::ostream& operator<<(std::ostream& os, const Decimal5NULL& decimal);

std::ostream& operator<<(std::ostream& os, MDUpdateAction action);

std::ostream& operator<<(std::ostream& os, MDEntryType entryType);

std::ostream& operator<<(std::ostream& os, const OrderUpdate* orderUpdate);

std::ostream& operator<<(std::ostream& os, const OrderExecution* orderExe);

std::ostream& operator<<(std::ostream& os, const MarketDataPacketHeader* marketHeader);

std::ostream& operator<<(std::ostream& os, const IncrementalPacketHeader* incrHeader);

std::ostream& operator<<(std::ostream& os, const SBEHeader* incrHeader);

std::ostream& operator<<(std::ostream& os, const OrderBookSnapshotEntry* ordBookEntry);

std::ostream& operator<<(std::ostream& os, const std::vector<const OrderBookSnapshotEntry*>& entries);

std::ostream& operator<<(std::ostream& os, const OrderBookSnapshot* ordBook);

std::ostream& operator<<(std::ostream& os, const GroupSize* group);
