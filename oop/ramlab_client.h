#ifndef RAMLAB_CLIENT_H
#define RAMLAB_CLIENT_H
#define PAYLOADLENGTH 70*1024
#define BASELENGTH 100
#include <string>
#include <cpprest/ws_client.h>
#include <cpprest/filestream.h>
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"
#include <sys/time.h> //getCurrentTime
#include <iomanip> // setprecision

using namespace std;
using namespace utility;
using namespace web;
using namespace web::websockets::client;
using namespace rapidjson;

class RobotClient
{
private:
	string 			 m_url;
	string 			 m_data_send;
	string 			 m_data_receive;
	websocket_client m_client;

public:
	RobotClient();
	~RobotClient();

	void connect();
	void sendData();
	void setURL(const string &url);
	void receiveData();
	void setDataSend(const string &data_send);
	void close();

	string getDataReceive();
};

class RobotJson 
{
private:
	string 			m_json_str;

	void docToString();
	void stringToCharArray(char * c, string s);

public:
	Document 		m_json_doc;
	RobotJson();
	~RobotJson();

	void setString(const string &json_str);
	void stringToDoc(const int &string_length);
	void addValueCharArray(char *payload_char, const int payload_size);
	//Document getDoc();
	string getString();


};

double getCurrentTime();
void createPayloadCharArray(char *payload_char, const int payload_size);
#endif