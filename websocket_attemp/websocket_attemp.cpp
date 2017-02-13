#include "ram_lab_com.h"

int main()
{
    char url[] = "ws://localhost/websocket"; //ws_url
    const int payloadlength = 6;
    ofstream out("debug.txt", ios::app);
    websocket_client client;    //
    client.connect(url).wait();

    while(1)
    {
        Document docu_state_imu;
        docu_state_imu.SetObject();
        docu_state_imu.Parse(json_payload);
        //Modify Docu_state_imu
        docuAddPayload(payloadlength, docu_state_imu);
        docu_state_imu["NO"] = getCurrentTime();
        docu_state_imu["timestamp"] = docu_state_imu["NO"].GetDouble();
        //Send
        webSocketSendText(client, docu_state_imu);

        //Receive Json packet
        string data_receive;
        data_receive = webSocketReceiveText(client);
        Document docu_state_fused;
        docu_state_fused.SetObject();
        char data_receive_char[payloadlength+1024];
        string2CharArray(data_receive_char, data_receive);
        docu_state_fused.Parse(data_receive_char);

        //Culculate delay
        double time1_receive, time2_receive, delta_time_receive;
        time2_receive = getCurrentTime();
        time1_receive = docu_state_fused["timestamp"].GetDouble();
        delta_time_receive = time2_receive - time1_receive;

        cout<<data_receive<<endl;
        out<<"bytes: "<< payloadlength;
        out<<setprecision(14)<<" NO: "<<docu_state_fused["NO"].GetDouble()<<\
        setprecision(6)<<" delay2 is: "<<delta_time_receive*1000<<" ms"<<endl;

    }
    client.close().wait();
    out.close();
    return 0;
}


