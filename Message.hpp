/**
 *
 */
 

#include <string>
#include <iostream>

using namespace std;

typedef enum MessageType { PRIVMSG, JOIN, PING, NOTICE, USER, PART, QUIT, UNKNOWN } MessageType;

class Message {
public:
	Message();
	Message(const string& rawMessage);
	Message(MessageType type, const string &source, const string &target, const string &message);
	
	MessageType getMessageType(void) const;
	void setMessageType(MessageType type);
	
	string getRawMessage(void);
	string getSource(void) const;
	string getTarget(void) const;
	string getMessage(void) const;
	
	~Message();
	
private:
	
	string m_target;
	string m_source;
	string m_message;
	string m_rawMessage;
	MessageType m_type;
	
	bool m_interpreted;
	
	void construct();
	
};
