#include <network/mco/MCOParser.hpp>
#include <json/json.h>

void MCOParser::parseErrorMessage(const std::string& a2, std::string& reason, int32_t& error) {
	Json::Value v8;
	Json::Reader v11;
	v11.parse(a2, v8, 1);
	error = v8.get("error", Json::Value()).asInt();
	reason = v8.get("reason", Json::Value()).asString();
}
void MCOParser::parseJoinWorld(const std::string&, std::string&, uint16_t&, std::string&);
LoginInformation MCOParser::parseMCOAccountValidSessionReturnValue(const std::string&);
std::unordered_map<int64_t, MCOServerListItem> MCOParser::parseServerList(const std::string&);
void MCOParser::parseStatus(const std::string& a2, bool& buyServerEnabled, bool& createServersEnabled, bool& serviceEnabled) {
	Json::Value v8;
	Json::Reader v11;
	v11.parse(a2, v8, 1);
	buyServerEnabled = v8.get("buyServerEnabled", Json::Value()).asBool();
	createServersEnabled = v8.get("createServerEnabled", Json::Value()).asBool();
	serviceEnabled = v8.get("serviceEnabled", Json::Value()).asBool();
}
