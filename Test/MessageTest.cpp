/** @file MessageTest.cpp
 * 
 * 
 * 
 */

#include "gtest/gtest.h"

#include "../Message.hpp"

/**
 * @brief Test if the default constructor works properly
 * 
 * 
 * 
 */
TEST(MessageTest, EmptyObject) {
	Message* msg = new Message();
	
	EXPECT_EQ(msg->getMessageType(), UNKNOWN);
	EXPECT_EQ(msg->getRawMessage(), "");
	EXPECT_EQ(msg->getSource(), "");
	EXPECT_EQ(msg->getTarget(), "");
	EXPECT_EQ(msg->getMessage(), "");
	EXPECT_EQ(msg->getSpecial(), "");
	
	delete msg;
}

/**
 * @brief Test if the interpretation of PING messages works
 * 
 * 
 */
TEST(MessageTest, InterpretPING_0) {
	std::string rawMsg = "PING :153123\r\n";
	
	Message* msg = new Message(rawMsg);
	
	EXPECT_EQ(msg->getMessageType(), PING);
	EXPECT_EQ(msg->getRawMessage(), "PING :153123");
	EXPECT_EQ(msg->getSource(), "");
	EXPECT_EQ(msg->getTarget(), "");
	EXPECT_EQ(msg->getMessage(), "153123");
	EXPECT_EQ(msg->getSpecial(), "");
	
	delete msg;
}

/**
 * @brief Test if the interpretation of USER messages works
 * 
 * 
 */
TEST(MessageTest, InterpretUSER_0) {
	std::string rawMsg = "USER testuser 0 * :Real name of the user\r\n";
	
	Message* msg = new Message(rawMsg);
	
	// remove the \r\n
	rawMsg.pop_back();
	rawMsg.pop_back();
	
	EXPECT_EQ(msg->getMessageType(), USER);
	EXPECT_EQ(msg->getRawMessage(), rawMsg);
	EXPECT_EQ(msg->getSource(), "testuser");
	EXPECT_EQ(msg->getTarget(), "");
	EXPECT_EQ(msg->getMessage(), "Real name of the user");
	EXPECT_EQ(msg->getSpecial(), "0 *");
	
	delete msg;
}

/**
 * @brief Test if the interpretation of PRIVMSG messages works
 * 
 * 
 */
TEST(MessageTest, InterpretPRIVMSG_0) {
	std::string rawMsg = ":crasbe!crasbe@MEOW-10DD5EA6.dip0.t-ipconnect.de PRIVMSG #test :Test message\r\n";
	
	Message* msg = new Message(rawMsg);
	
	// remove the \r\n
	rawMsg.pop_back();
	rawMsg.pop_back();
	
	EXPECT_EQ(msg->getMessageType(), PRIVMSG);
	EXPECT_EQ(msg->getRawMessage(), rawMsg);
	EXPECT_EQ(msg->getSource(), "crasbe");
	EXPECT_EQ(msg->getTarget(), "#test");
	EXPECT_EQ(msg->getMessage(), "Test message");
	EXPECT_EQ(msg->getSpecial(), "crasbe@MEOW-10DD5EA6.dip0.t-ipconnect.de");
	
	delete msg;
}

/**
 * @brief Test if the interpretation of KICK messages works
 * 
 * 
 */
TEST(MessageTest, InterpretKICK_0) {
	
	
	
}







