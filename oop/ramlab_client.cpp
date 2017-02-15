#include "ramlab_client.h"

using namespace std;
int main()
{
	while(1)
	{
		try
		{
			RobotClient client;
			client.setURL("ws://52.78.100.238/websocket");
			client.connect();
			try
			{
				while(1)
				{
					RobotJson json_send;
					json_send.m_json_doc["NO"] = getCurrentTime();
					json_send.m_json_doc["timestamp"] = json_send.m_json_doc["NO"].GetDouble();
					char payload_char[PAYLOADLENGTH];
					createPayloadCharArray(payload_char, PAYLOADLENGTH);
					json_send.addValueCharArray(payload_char, PAYLOADLENGTH);

					client.setDataSend(json_send.getString());
					client.sendData();

					client.receiveData();
					//cout<<client.getDataReceive()<<endl;

					RobotJson json_receive;
					json_receive.setString(client.getDataReceive());
					json_receive.stringToDoc(BASELENGTH+PAYLOADLENGTH);
					
				    double time1_receive, time2_receive, delta_time_receive;
				    time2_receive = getCurrentTime();
				    time1_receive = json_receive.m_json_doc["timestamp"].GetDouble();
				    delta_time_receive = time2_receive - time1_receive;

				    cout<<"bytes: "<< PAYLOADLENGTH\
				    	<<setprecision(14)<<" NO: "<<json_receive.m_json_doc["NO"].GetDouble()\
				    	<<setprecision(6)<<" delay2 is: "<<delta_time_receive*1000<<" ms"<<endl;	
				}
			}
			catch(...)
			{
	            cout<<"bytes: "<< PAYLOADLENGTH;
	            cout<<"ERROR: DATALOSS"<<endl;
	            continue;
			}
			client.close();
		}
		catch(...)
		{
            cout<<"bytes: "<< PAYLOADLENGTH;
            cout<<"ERROR: OPENINGSHAKEHANDSLOSS"<<endl;			
			continue;
		}

	}
	return 0;

}