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
Message::Message() : m_target(""), m_source(""), m_message(""), 
					 m_special(""), m_rawMessage(""), m_type(UNKNOWN), 
					 m_interpreted(false) {
	
}

/**
 * @brief Input constructor that creates a message from the given values.
 * 
 * @param 
 * 
 */
Message::Message(MessageType type, const string &source, 
				 const string &target, const string &message, const string &special) : 
				 m_target(target),  m_source(source), m_message(message),
				 m_special(special), m_type(type), m_interpreted(false) {
	construct();
	
}

/**
 * @brief Input constructor that interprets a given message.
 * 
 */
Message::Message(const string &rawMessage) : m_target(""), m_source(""),
											 m_message(""), m_special(""),
											 m_rawMessage(rawMessage), 
											 m_type(UNKNOWN),
											 m_interpreted(true) {
	analyze();
	
	
}

/**
 * @brief Destuctor
 * 
 */
Message::~Message() {
	
	
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
 */
string Message::getSource(void) const {
	return m_source;
}

/**
 * 
 * 
 * 
 */
string Message::getTarget(void) const {
	return m_target;
}

/**
 * 
 * 
 */
string Message::getMessage(void) const {
	return m_message;	
}

/**
 * 
 * 
 * 
 */
string Message::getSpecial(void) const {
	return m_special;
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
	if(m_rawMessage.back() == '\n') {
		m_rawMessage.pop_back();
		if(m_rawMessage.back() == '\r') {
			m_rawMessage.pop_back();
		}
	}
	
	// Catch some special message types
	// Ping: standard format "PING :message"
	if(m_rawMessage.compare(0, 4, "PING") == 0) {
		m_type = PING;
		m_message = m_rawMessage.substr(6); // copy the message
		return;
	}
	
	if(m_rawMessage.compare(0, 4, "USER") == 0) {
		std::cout << "Hallo" << std::endl;
		m_type = USER;
		
		int first_space = m_rawMessage.find(" ", 5);
		int colon = m_rawMessage.find(":");
		
		m_source = m_rawMessage.substr(5, first_space-5);
		m_special = m_rawMessage.substr(first_space+1, colon-first_space-2); 
		m_message = m_rawMessage.substr(colon+1);
		
		return;
	}
	
	// Lines starting with a colon
	//  PRIVMSG, NOTICE, JOIN, PART, KICK, 
	if(m_rawMessage.compare(0, 1, ":") == 0) {
		m_rawMessage.pop_back(); // remove this colon
		
		int first_space = m_rawMessage.find(" ");
		int first_colon = m_rawMessage.find(":");
		
		
		
	}
}
