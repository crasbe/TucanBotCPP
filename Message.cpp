/** @file Message.cpp
 * 
 * 
 * 
 * 
 * @date 10.08.2017
 * @author crasbe <crasbe@gmail.com>
 */
 
#include "Message.hpp"

/**
 * @brief Default constructor that initializes the member variables with
 * empty values
 * 
 */
Message::Message() : m_target(""), m_source(""), 
					 m_type(UNKNOWN), m_interpreted(false) {
	
}

/**
 * @brief Input constructor that creates a message from the given values.
 * 
 * @param 
 * 
 */
Message::Message(MessageType type, const string &source, 
				 const string &target, const string &message) : 
				 m_target(target),  m_source(source), m_message(message),
				 m_type(type), m_interpreted(false) {
	construct();
	
}

/**
 * @brief Input constructor that interprets a given message.
 * 
 */
Message::Message(const string &rawMessage) : m_target(""), m_source(""),
											 m_message(""), 
											 m_rawMessage(rawMessage), 
											 m_type(UNKNOWN),
											 m_interpreted(true) {
	analyze();
	
	
}

/**
 * @brief Getter function for m_rawMessage.
 * 
 * If the member variable m_rawMessage is empty, try to construct it
 * from the given member variables.
 * 
 * @return Constant reference to m_rawMessage;
 */
string Message::getRawMessage(void) {
	if(m_rawMessage == "")
		construct();
	return m_rawMessage;
	
}

/**
 * @brief Getter function for the message type.
 * 
 * @return MessageType from MessageType enum.
 */
MessageType Message::getMessageType(void) const {
	return m_type;
}

/**
 * @brief Setter function for the message type.
 * 
 * Setting the message type m_type is only permitted, when the
 * message is constructed and not interpreted.
 * 
 * @param type Message type to set.
 */
void Message::setMessageType(MessageType type) {
	if(m_interpreted == true)
		throw logic_error("Cannot set the Message Type in a constructed message!");
	else
		m_type = type;
}


/**
 * 
 * 
 * 
 */
void Message::construct(void) {
	
}

/**
 * 
 * 
 * 
 */
void Message::analyze(void) {
	
	// Trim return and newline from the back of the raw string
	if(m_rawMessage.back() == "\n") {
		m_rawMessage.pop_back();
		if(m_rawMessage.back() == "\r") {
			m_rawMessage.pop_back();
		}
	}
	
	// Catch some special message types
	// Ping: standard format "PING :message"
	if(m_rawMessage.compare(0, 4, "PING") {
		m_type = PING;
		m_message = m_rawMessage.substr(6); // copy the message
		return;
	} else if(m_rawMessage.compare(0, 4, "USER") {
		m_type = USER;
		m_source = m_rawMessage.substr(5, biszumSternchen);
	}
}
