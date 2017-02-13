#ifndef RAM_LAB_COM_H
#define RAM_LAB_COM_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sstream>
#include <iomanip>
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"
#include <cpprest/ws_client.h>
#include <cpprest/filestream.h>
#include <fstream>

using namespace std;
using namespace utility;
using namespace web;
using namespace web::websockets::client;
using namespace concurrency;
using namespace concurrency::streams;
using namespace rapidjson;


void webSocketSendText(websocket_client client, const char* str);
void webSocketSendText(websocket_client client, Document &docu_state_imu);
string webSocketReceiveText(websocket_client client);
void docuAddPayload(const int payloadlength, Document &docu_state_imu);
//void docureceiveCreate(Document &docu_state_fused, string &data_receive, const int payloadlength_2);
double getCurrentTime();
void string2CharArray(char * c, string s);
string doubleConverToString(double d);
//string ltos(long l);

extern char json_state[];
extern char json_feature_camera[];
extern char json_payload[];

#endif
