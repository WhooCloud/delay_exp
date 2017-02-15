#include "ramlab_client.h"

RobotJson::RobotJson()
{
	m_json_doc.SetObject();
	assert(m_json_doc.IsObject()); 
	setString(" {\"NO\" : 1452657.360343, \"timestamp\" : 1452657.360343}  ");
	//cout<<m_json_str.length()<<endl;
	char json_char_arry[BASELENGTH + PAYLOADLENGTH];
	stringToCharArray(json_char_arry, m_json_str);
	m_json_doc.Parse(json_char_arry);

}

RobotJson::~RobotJson()
{
}

void RobotJson::docToString()
{
    StringBuffer str_buf;
	assert(m_json_doc.IsObject()); 
    PrettyWriter<StringBuffer> writer(str_buf);
    m_json_doc.Accept(writer);
    m_json_str = str_buf.GetString();

    return;
}


void RobotJson::stringToDoc(const int &string_length)
{
	assert(m_json_doc.IsObject()); 
	char json_char_arry[string_length];
	stringToCharArray(json_char_arry, m_json_str);
	m_json_doc.Parse(json_char_arry);
	return;
}

void RobotJson::stringToCharArray(char * c, string s)
{
    int i;
    for( i=0; i<s.length(); i++)
        c[i] = s[i];

    c[i] = '\0';
    return;
}

string RobotJson::getString()
{
	assert(m_json_doc.IsObject()); 
	docToString();
	return m_json_str;
}

void RobotJson::setString(const string &json_str)
{
	m_json_str = json_str;
}

void RobotJson::addValueCharArray(char *payload_char, const int payload_size)
{
	Value payload;
    payload.SetString(payload_char, static_cast<SizeType>(payload_size), m_json_doc.GetAllocator());
    m_json_doc.AddMember("payload", payload, m_json_doc.GetAllocator());
    return;
}
/*
Document RobotJson::getDoc()
{
	assert(m_json_doc.IsObject()); 
	stringToDoc(STRINGLENGTH + PAYLOADLENGTH);
	return m_json_doc;
}
*/