#include <gtest/gtest.h>
#include <memory>
#include "json.h"

TEST(OrderUpdateTest, toJson) {
    OrderUpdate orderUpd;
    orderUpd.mdEntryID = 684651487496;
    orderUpd.mdEntryPx = Decimal5(16846541657);
    orderUpd.mdEntrySize = 256;
    orderUpd.mdFlags = static_cast<decltype(orderUpd.mdFlags)>(MDFlagsSet::day | MDFlagsSet::cod | MDFlagsSet::duringDiscreteAuction);
    orderUpd.mdFlags2 = MDFlags2Set::zero;
    orderUpd.securityID = 456;
    orderUpd.rptSeq = 564846;
    orderUpd.mdUpdateAction = MDUpdateAction::New;
    orderUpd.mdEntryType = MDEntryType::Offer;

    const auto& json = toJson(&orderUpd);
    const auto& jsonReference = R"({"mdEntryID": 684651487496, "mdEntryPx": {"mantissa": 16846541657}, "mdEntrySize": 256, "mdFlags": ["day", "cod", "duringDiscreteAuction"], "mdFlags2": ["zero"], "securityID": 456, "rptSeq": 564846, "mdUpdateAction": "New", "mdEntryType": "Offer"})";

    EXPECT_EQ(jsonReference, json);
}

TEST(OrderExecutionTest, toJson) {
    OrderExecution orderExec;
    orderExec.mdEntryID = 684651487496;
    orderExec.mdEntryPx = Decimal5NULL(16846541657);
    orderExec.mdEntrySize = 256;
    orderExec.lastPx = Decimal5(684);
    orderExec.lastQty = 135;
    orderExec.tradeID = 1368768546874;
    orderExec.mdFlags = static_cast<decltype(orderExec.mdFlags)>(MDFlagsSet::boc | MDFlagsSet::cancel | MDFlagsSet::endOfTransaction | MDFlagsSet::fok);
    orderExec.mdFlags2 = MDFlags2Set::zero;
    orderExec.securityID = 486;
    orderExec.rptSeq = 564846;
    orderExec.mdUpdateAction = MDUpdateAction::Change;
    orderExec.mdEntryType = MDEntryType::Bid;

    const auto& json = toJson(&orderExec);
    const auto& jsonReference = R"({"mdEntryID": 684651487496, "mdEntryPx": {"mantissa": 16846541657}, "mdEntrySize": 256, "lastPx": {"mantissa": 684}, "lastQty": 135, "tradeID": 1368768546874, "mdFlags": ["endOfTransaction", "fok", "cancel", "boc"], "mdFlags2": ["zero"], "securityID": 486, "rptSeq": 564846, "mdUpdateAction": "Change", "mdEntryType": "Bid"})";

    EXPECT_EQ(jsonReference, json);
}

TEST(OrderBookSnapshotEntryTest, toJson) {
    OrderBookSnapshotEntry entry;
    entry.MDEntryID = 168796846768;
    entry.MDEntryPx = Decimal5NULL(16874687);
    entry.MDEntrySize = 256;
    entry.TradeID = 1368768546874;
    entry.MDFlags = static_cast<decltype(entry.MDFlags)>(MDFlagsSet::crossTrade | MDFlagsSet::fok);
    entry.MDFlags2 = MDFlags2Set::zero;
    entry.MDEntryType = MDEntryType::Bid;

    const auto& json = toJson(&entry);
    const auto& jsonReference = R"({"MDEntryID": 168796846768, "TransactTime": 14757395258967641292, "MDEntryPx": {"mantissa": 16874687}, "MDEntrySize": 256, "TradeID": 1368768546874, "MDFlags": ["fok", "crossTrade"], "MDFlags2": ["zero"], "MDEntryType": "Bid"})";

    EXPECT_EQ(jsonReference, json);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
