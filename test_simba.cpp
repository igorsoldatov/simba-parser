#include <gtest/gtest.h>
#include "base64encoder.h"
#include "SimbaDecoder.h"

TEST(OrderBookSnapshotTest, decoder) {
    auto base64str = "rQwAAEoFAAB1lft8v6iMFxAAEQBETQQAaFQuAPkPAAAYAAAA9hoAADkAF/AGAAD2GuAa8UHYDwR8jBegp3ULAAAAAAEAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMfEGAAD2GuAa158QKAR8jBdAEHwLAAAAAAEAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMfUGAAD2GuAat3g3QQR8jBfgeIILAAAAAAEAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMR0HAAD2GuAaKJkKyQR8jBcAJgsLAAAAAAEAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMB8HAAD2GuAah4r3ygR8jBfw/goLAAAAAAEAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMDEHAAD2GuAamfJwKwV8jBdgXCkLAAAAAAoAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMEwHAAD2GuAasRE1ogV8jBfwuyoLAAAAAAEAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMDYJAAD2GuAaZGiETQx8jBegl04LAAAAACgAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMUkJAAD2GuAaTg84XQx8jBdAfysLAAAAAAEAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMHoJAAD2GuAaMBEnqgx8jBcgP/8KAAAAAAEAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMPMJAAD2GuAaaJlHiQ18jBdg6yYLAAAAAAEAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMAsKAAD2GuAa8ShGuw18jBdQFy4LAAAAAAEAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMKcKAAD2GuAadIUZqQ58jBdAfysLAAAAAAEAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMPgKAAD2GuAaKnMIpxB8jBewtRELAAAAAAEAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAML8LAAD2GuAagpE3PRV8jBfg1woLAAAAAAEAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMOoLAAD2GuAa/Ei54hV8jBcwWCsLAAAAAAEAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMFgMAAD2GuAauvphoBd8jBdwEicLAAAAAAEAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMH0MAAD2GuAa9zRZchh8jBew6h0LAAAAAAIAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMKAMAAD2GuAaLVjJ7hl8jBeQUAALAAAAAAEAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMLgMAAD2GuAaJ9WzGBp8jBcw9fwKAAAAAAEAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMLoMAAD2GuAadSAgLhp8jBfgSA0LAAAAAAEAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMOwMAAD2GuAaoHF9Fxx8jBcw2VQLAAAAAAYAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMRwNAAD2GuAa7V74EB18jBcgoi0LAAAAAAIAAAAAAAAAAAAAAAAAAAABEAAAAAAAAAAAAAAAAAAAMA==";
    auto binData = base64Decode(base64str);

    SimbaDecoder decoder("test.txt");
    auto json = decoder.DecodePackageToJson(binData.data(), binData.size());

    auto jsonReference = R"({"msgSeqNum": 3245, "msgSize": 1354, "msgFlags": 0, "sendingTime": 1696916700000916853},{"blockLength": 16, "templateID": 17, "schemaID": 19780, "version": 4}, {"securityID": 3036264, "lastMsgSeqNumProcessed": 4089, "rptSeq": 24, "exchangeTradingSessionID": 6902, "NoMDEntries": [{"MDEntryID": 1936577483633592048, "TransactTime": 1696867516499378673, "MDEntryPx": {"mantissa": 192260000}, "MDEntrySize": 1, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Offer"}, {"MDEntryID": 1936577483633592049, "TransactTime": 1696867516905725911, "MDEntryPx": {"mantissa": 192680000}, "MDEntrySize": 1, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Offer"}, {"MDEntryID": 1936577483633592053, "TransactTime": 1696867517327702199, "MDEntryPx": {"mantissa": 193100000}, "MDEntrySize": 1, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Offer"}, {"MDEntryID": 1936577483633592093, "TransactTime": 1696867519606462760, "MDEntryPx": {"mantissa": 185280000}, "MDEntrySize": 1, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Bid"}, {"MDEntryID": 1936577483633592095, "TransactTime": 1696867519638768263, "MDEntryPx": {"mantissa": 185270000}, "MDEntrySize": 1, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Bid"}, {"MDEntryID": 1936577483633592113, "TransactTime": 1696867521257337497, "MDEntryPx": {"mantissa": 187260000}, "MDEntrySize": 10, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Bid"}, {"MDEntryID": 1936577483633592140, "TransactTime": 1696867523249902001, "MDEntryPx": {"mantissa": 187350000}, "MDEntrySize": 1, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Bid"}, {"MDEntryID": 1936577483633592630, "TransactTime": 1696867551893809252, "MDEntryPx": {"mantissa": 189700000}, "MDEntrySize": 40, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Offer"}, {"MDEntryID": 1936577483633592649, "TransactTime": 1696867552157241166, "MDEntryPx": {"mantissa": 187400000}, "MDEntrySize": 1, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Bid"}, {"MDEntryID": 1936577483633592698, "TransactTime": 1696867553447973168, "MDEntryPx": {"mantissa": 184500000}, "MDEntrySize": 1, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Bid"}, {"MDEntryID": 1936577483633592819, "TransactTime": 1696867557191424360, "MDEntryPx": {"mantissa": 187100000}, "MDEntrySize": 1, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Bid"}, {"MDEntryID": 1936577483633592843, "TransactTime": 1696867558030190833, "MDEntryPx": {"mantissa": 187570000}, "MDEntrySize": 1, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Bid"}, {"MDEntryID": 1936577483633592999, "TransactTime": 1696867562020242804, "MDEntryPx": {"mantissa": 187400000}, "MDEntrySize": 1, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Bid"}, {"MDEntryID": 1936577483633593080, "TransactTime": 1696867570575504170, "MDEntryPx": {"mantissa": 185710000}, "MDEntrySize": 1, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Bid"}, {"MDEntryID": 1936577483633593279, "TransactTime": 1696867590275043714, "MDEntryPx": {"mantissa": 185260000}, "MDEntrySize": 1, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Bid"}, {"MDEntryID": 1936577483633593322, "TransactTime": 1696867593051785468, "MDEntryPx": {"mantissa": 187390000}, "MDEntrySize": 1, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Bid"}, {"MDEntryID": 1936577483633593432, "TransactTime": 1696867600528702138, "MDEntryPx": {"mantissa": 187110000}, "MDEntrySize": 1, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Bid"}, {"MDEntryID": 1936577483633593469, "TransactTime": 1696867604051342583, "MDEntryPx": {"mantissa": 186510000}, "MDEntrySize": 2, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Bid"}, {"MDEntryID": 1936577483633593504, "TransactTime": 1696867610434033709, "MDEntryPx": {"mantissa": 184570000}, "MDEntrySize": 1, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Bid"}, {"MDEntryID": 1936577483633593528, "TransactTime": 1696867611137266983, "MDEntryPx": {"mantissa": 184350000}, "MDEntrySize": 1, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Bid"}, {"MDEntryID": 1936577483633593530, "TransactTime": 1696867611496685685, "MDEntryPx": {"mantissa": 185420000}, "MDEntrySize": 1, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Bid"}, {"MDEntryID": 1936577483633593580, "TransactTime": 1696867619706859936, "MDEntryPx": {"mantissa": 190110000}, "MDEntrySize": 6, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Offer"}, {"MDEntryID": 1936577483633593628, "TransactTime": 1696867623892442861, "MDEntryPx": {"mantissa": 187540000}, "MDEntrySize": 2, "TradeID": 0, "MDFlags": ["day", "endOfTransaction"], "MDFlags2": [], "MDEntryType": "Bid"}]}, )";
    EXPECT_EQ(jsonReference, json);
}

TEST(OrderExecutionTest, decoder) {
    auto base64str = "/xQAADwFCAA1hSMJkamMF71hHAmRqYwX9hoAAEoAEABETQQAp80PAPYaRRrA5PpOAgAAAHMBAAAAAAAAIIApTQIAAAAKAAAAAAAAAPzxAAD2GkUaAgAAAAACAAAAAAAAAAAAANJaJQA/AgAAATBKABAARE0EACnLDwD2GkUaIIApTQIAAAAAAAAAAAAAACCAKU0CAAAACgAAAAAAAAD88QAA9hpFGgEAAAAABAAAAAAAAAAAAADSWiUAQAIAAAIxSgAQAERNBACnzQ8A9hpFGsDk+k4CAAAAbgEAAAAAAAAAFC5NAgAAAAUAAAAAAAAA/fEAAPYaRRoCAAAAAAIAAAAAAAAAAAAA0lolAEECAAABMEoAEABETQQAOJ8PAPYaRRoAFC5NAgAAAAAAAAAAAAAAABQuTQIAAAAFAAAAAAAAAP3xAAD2GkUaAQAAAAAEAAAAAAAAAAAAANJaJQBCAgAAAjFKABAARE0EAKfNDwD2GkUawOT6TgIAAABtAQAAAAAAAEAhMU0CAAAAAQAAAAAAAAD+8QAA9hpFGgIAAAAAAgAAAAAAAAAAAADSWiUAQwIAAAEwSgAQAERNBADGbQ8A9hpFGkAhMU0CAAAAAAAAAAAAAABAITFNAgAAAAEAAAAAAAAA/vEAAPYaRRoBAAAAAAQAAAAAAAAAAAAA0lolAEQCAAACMUoAEABETQQAp80PAPYaRRrA5PpOAgAAAGwBAAAAAAAAgGNATQIAAAABAAAAAAAAAP/xAAD2GkUaAgAAAAACAAAAAAAAAAAAANJaJQBFAgAAATBKABAARE0EAJOVDwD2GkUagGNATQIAAAAAAAAAAAAAAIBjQE0CAAAAAQAAAAAAAAD/8QAA9hpFGgEAAAAABAAAAAAAAAAAAADSWiUARgIAAAIxSgAQAERNBACnzQ8A9hpFGsDk+k4CAAAAawEAAAAAAABglmlNAgAAAAEAAAAAAAAAAPIAAPYaRRoCAAAAAAIAAAAAAAAAAAAA0lolAEcCAAABMEoAEABETQQAsQ4OAPYaRRpglmlNAgAAAAAAAAAAAAAAYJZpTQIAAAABAAAAAAAAAADyAAD2GkUaAQAAAAAEAAAAAAAAAAAAANJaJQBIAgAAAjFKABAARE0EAKfNDwD2GkUawOT6TgIAAABqAQAAAAAAAEAqbk0CAAAAAQAAAAAAAAAB8gAA9hpFGgIAAAAAAgAAAAAAAAAAAADSWiUASQIAAAEwSgAQAERNBADpNw4A9hpFGkAqbk0CAAAAAAAAAAAAAABAKm5NAgAAAAEAAAAAAAAAAfIAAPYaRRoBAAAAAAQAAAAAAAAAAAAA0lolAEoCAAACMUoAEABETQQAp80PAPYaRRrA5PpOAgAAAGUBAAAAAAAA4LBvTQIAAAAFAAAAAAAAAALyAAD2GkUaAgAAAAACAAAAAAAAAAAAANJaJQBLAgAAATBKABAARE0EAEVyDgD2GkUa4LBvTQIAAAAAAAAAAAAAAOCwb00CAAAABQAAAAAAAAAC8gAA9hpFGgEAAAAABAAAAAAAAAAAAADSWiUATAIAAAIxSgAQAERNBACnzQ8A9hpFGsDk+k4CAAAAZAEAAAAAAADgsG9NAgAAAAEAAAAAAAAAA/IAAPYaRRoCAAAAAAIAAAAAAAAAAAAA0lolAE0CAAABMEoAEABETQQATl8PAPYaRRrgsG9NAgAAAAAAAAAAAAAA4LBvTQIAAAABAAAAAAAAAAPyAAD2GkUaAQAAAAAEAAAAAAAAAAAAANJaJQBOAgAAAjE=";
    auto binData = base64Decode(base64str);

    SimbaDecoder decoder("test.txt");
    auto json = decoder.DecodePackageToJson(binData.data(), binData.size());

    auto jsonReference = R"({"msgSeqNum": 5375, "msgSize": 1340, "msgFlags": 8, "sendingTime": 1696917600000509237},{"transactTime": 1696917600000041405, "exchangeTradingSessionID": 6902},{"blockLength": 74, "templateID": 16, "schemaID": 19780, "version": 4}, {"mdEntryID": 1892948862244474279, "mdEntryPx": {"mantissa": 9915000000}, "mdEntrySize": 371, "lastPx": {"mantissa": 9884500000}, "lastQty": 10, "tradeID": 1892948862243500540, "mdFlags": ["ioc", "activeSide"], "mdFlags2": [], "securityID": 2448082, "rptSeq": 575, "mdUpdateAction": "Change", "mdEntryType": "Bid"}, {"blockLength": 74, "templateID": 16, "schemaID": 19780, "version": 4}, {"mdEntryID": 1892948862244473641, "mdEntryPx": {"mantissa": 9884500000}, "mdEntrySize": 0, "lastPx": {"mantissa": 9884500000}, "lastQty": 10, "tradeID": 1892948862243500540, "mdFlags": ["day", "passiveSide"], "mdFlags2": [], "securityID": 2448082, "rptSeq": 576, "mdUpdateAction": "Delete", "mdEntryType": "Offer"}, {"blockLength": 74, "templateID": 16, "schemaID": 19780, "version": 4}, {"mdEntryID": 1892948862244474279, "mdEntryPx": {"mantissa": 9915000000}, "mdEntrySize": 366, "lastPx": {"mantissa": 9884800000}, "lastQty": 5, "tradeID": 1892948862243500541, "mdFlags": ["ioc", "activeSide"], "mdFlags2": [], "securityID": 2448082, "rptSeq": 577, "mdUpdateAction": "Change", "mdEntryType": "Bid"}, {"blockLength": 74, "templateID": 16, "schemaID": 19780, "version": 4}, {"mdEntryID": 1892948862244462392, "mdEntryPx": {"mantissa": 9884800000}, "mdEntrySize": 0, "lastPx": {"mantissa": 9884800000}, "lastQty": 5, "tradeID": 1892948862243500541, "mdFlags": ["day", "passiveSide"], "mdFlags2": [], "securityID": 2448082, "rptSeq": 578, "mdUpdateAction": "Delete", "mdEntryType": "Offer"}, {"blockLength": 74, "templateID": 16, "schemaID": 19780, "version": 4}, {"mdEntryID": 1892948862244474279, "mdEntryPx": {"mantissa": 9915000000}, "mdEntrySize": 365, "lastPx": {"mantissa": 9885000000}, "lastQty": 1, "tradeID": 1892948862243500542, "mdFlags": ["ioc", "activeSide"], "mdFlags2": [], "securityID": 2448082, "rptSeq": 579, "mdUpdateAction": "Change", "mdEntryType": "Bid"}, {"blockLength": 74, "templateID": 16, "schemaID": 19780, "version": 4}, {"mdEntryID": 1892948862244449734, "mdEntryPx": {"mantissa": 9885000000}, "mdEntrySize": 0, "lastPx": {"mantissa": 9885000000}, "lastQty": 1, "tradeID": 1892948862243500542, "mdFlags": ["day", "passiveSide"], "mdFlags2": [], "securityID": 2448082, "rptSeq": 580, "mdUpdateAction": "Delete", "mdEntryType": "Offer"}, {"blockLength": 74, "templateID": 16, "schemaID": 19780, "version": 4}, {"mdEntryID": 1892948862244474279, "mdEntryPx": {"mantissa": 9915000000}, "mdEntrySize": 364, "lastPx": {"mantissa": 9886000000}, "lastQty": 1, "tradeID": 1892948862243500543, "mdFlags": ["ioc", "activeSide"], "mdFlags2": [], "securityID": 2448082, "rptSeq": 581, "mdUpdateAction": "Change", "mdEntryType": "Bid"}, {"blockLength": 74, "templateID": 16, "schemaID": 19780, "version": 4}, {"mdEntryID": 1892948862244459923, "mdEntryPx": {"mantissa": 9886000000}, "mdEntrySize": 0, "lastPx": {"mantissa": 9886000000}, "lastQty": 1, "tradeID": 1892948862243500543, "mdFlags": ["day", "passiveSide"], "mdFlags2": [], "securityID": 2448082, "rptSeq": 582, "mdUpdateAction": "Delete", "mdEntryType": "Offer"}, {"blockLength": 74, "templateID": 16, "schemaID": 19780, "version": 4}, {"mdEntryID": 1892948862244474279, "mdEntryPx": {"mantissa": 9915000000}, "mdEntrySize": 363, "lastPx": {"mantissa": 9888700000}, "lastQty": 1, "tradeID": 1892948862243500544, "mdFlags": ["ioc", "activeSide"], "mdFlags2": [], "securityID": 2448082, "rptSeq": 583, "mdUpdateAction": "Change", "mdEntryType": "Bid"}, {"blockLength": 74, "templateID": 16, "schemaID": 19780, "version": 4}, {"mdEntryID": 1892948862244359857, "mdEntryPx": {"mantissa": 9888700000}, "mdEntrySize": 0, "lastPx": {"mantissa": 9888700000}, "lastQty": 1, "tradeID": 1892948862243500544, "mdFlags": ["day", "passiveSide"], "mdFlags2": [], "securityID": 2448082, "rptSeq": 584, "mdUpdateAction": "Delete", "mdEntryType": "Offer"}, {"blockLength": 74, "templateID": 16, "schemaID": 19780, "version": 4}, {"mdEntryID": 1892948862244474279, "mdEntryPx": {"mantissa": 9915000000}, "mdEntrySize": 362, "lastPx": {"mantissa": 9889000000}, "lastQty": 1, "tradeID": 1892948862243500545, "mdFlags": ["ioc", "activeSide"], "mdFlags2": [], "securityID": 2448082, "rptSeq": 585, "mdUpdateAction": "Change", "mdEntryType": "Bid"}, {"blockLength": 74, "templateID": 16, "schemaID": 19780, "version": 4}, {"mdEntryID": 1892948862244370409, "mdEntryPx": {"mantissa": 9889000000}, "mdEntrySize": 0, "lastPx": {"mantissa": 9889000000}, "lastQty": 1, "tradeID": 1892948862243500545, "mdFlags": ["day", "passiveSide"], "mdFlags2": [], "securityID": 2448082, "rptSeq": 586, "mdUpdateAction": "Delete", "mdEntryType": "Offer"}, {"blockLength": 74, "templateID": 16, "schemaID": 19780, "version": 4}, {"mdEntryID": 1892948862244474279, "mdEntryPx": {"mantissa": 9915000000}, "mdEntrySize": 357, "lastPx": {"mantissa": 9889100000}, "lastQty": 5, "tradeID": 1892948862243500546, "mdFlags": ["ioc", "activeSide"], "mdFlags2": [], "securityID": 2448082, "rptSeq": 587, "mdUpdateAction": "Change", "mdEntryType": "Bid"}, {"blockLength": 74, "templateID": 16, "schemaID": 19780, "version": 4}, {"mdEntryID": 1892948862244385349, "mdEntryPx": {"mantissa": 9889100000}, "mdEntrySize": 0, "lastPx": {"mantissa": 9889100000}, "lastQty": 5, "tradeID": 1892948862243500546, "mdFlags": ["day", "passiveSide"], "mdFlags2": [], "securityID": 2448082, "rptSeq": 588, "mdUpdateAction": "Delete", "mdEntryType": "Offer"}, {"blockLength": 74, "templateID": 16, "schemaID": 19780, "version": 4}, {"mdEntryID": 1892948862244474279, "mdEntryPx": {"mantissa": 9915000000}, "mdEntrySize": 356, "lastPx": {"mantissa": 9889100000}, "lastQty": 1, "tradeID": 1892948862243500547, "mdFlags": ["ioc", "activeSide"], "mdFlags2": [], "securityID": 2448082, "rptSeq": 589, "mdUpdateAction": "Change", "mdEntryType": "Bid"}, {"blockLength": 74, "templateID": 16, "schemaID": 19780, "version": 4}, {"mdEntryID": 1892948862244446030, "mdEntryPx": {"mantissa": 9889100000}, "mdEntrySize": 0, "lastPx": {"mantissa": 9889100000}, "lastQty": 1, "tradeID": 1892948862243500547, "mdFlags": ["day", "passiveSide"], "mdFlags2": [], "securityID": 2448082, "rptSeq": 590, "mdUpdateAction": "Delete", "mdEntryType": "Offer"}, )";
    EXPECT_EQ(jsonReference, json);
}

TEST(OrderUpdateTest, decoder) {
    auto base64str = "+w8AAFYACQD/EI31v6iMFyHujfW/qIwX9hoAADIADwBETQQAZkwAAPYaFxw4sxQAAAAAAAEAAAAAAAAAARAgAAAAAAAAAAAAAAAAAM0xKAATAAAAAjE=";
    auto binData = base64Decode(base64str);

    SimbaDecoder decoder("test.txt");
    auto json = decoder.DecodePackageToJson(binData.data(), binData.size());

    auto jsonReference = R"({"msgSeqNum": 4091, "msgSize": 86, "msgFlags": 9, "sendingTime": 1696916702023717119},{"transactTime": 1696916702023773729, "exchangeTradingSessionID": 6902},{"blockLength": 50, "templateID": 15, "schemaID": 19780, "version": 4}, {"mdEntryID": 2024116201390623846, "mdEntryPx": {"mantissa": 1356600}, "mdEntrySize": 1, "mdFlags": ["day", "endOfTransaction", "cancel"], "mdFlags2": [], "securityID": 2634189, "rptSeq": 19, "mdUpdateAction": "Delete", "mdEntryType": "Offer"}, )";
    EXPECT_EQ(jsonReference, json);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
