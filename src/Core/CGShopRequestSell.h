////////////////////////////////////////////////////////////////////////////////
// Filename    : CGShopRequestSell.h 
// Written By  : 김성민
// Description : 
// 플레이어에게 자신이 가지고 있는 아이템을 상점 NPC에게
// 팔기를 요청할 때 쓰이는 패킷이다.
////////////////////////////////////////////////////////////////////////////////

#ifndef __CG_SHOP_REQUEST_SELL_H__
#define __CG_SHOP_REQUEST_SELL_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"

////////////////////////////////////////////////////////////////////////////////
// CGShopRequestSell operation code
////////////////////////////////////////////////////////////////////////////////
enum
{
	SHOP_REQUEST_SELL_NORMAL = 0,
	SHOP_REQUEST_SELL_ALL_SKULL,
	SHOP_REQUEST_SWAP_ADVANCEMENT_ITEM,

	SHOP_REQUEST_SELL_MAX
};

////////////////////////////////////////////////////////////////////////////////
//
// class CGShopRequestSell;
//
////////////////////////////////////////////////////////////////////////////////

class CGShopRequestSell : public Packet 
{
public:
	CGShopRequestSell() { m_ObjectID = 0; m_ItemObjectID = 0; m_OpCode = SHOP_REQUEST_SELL_NORMAL; }
    virtual ~CGShopRequestSell() {};


public:
	void read(SocketInputStream & iStream) ;
	void write(SocketOutputStream & oStream) const ;
	void execute(Player* pPlayer) ;
	PacketID_t getPacketID() const  { return PACKET_CG_SHOP_REQUEST_SELL; }
	PacketSize_t getPacketSize() const  { return szObjectID+szObjectID+szBYTE; }
	string getPacketName() const  { return "CGShopRequestSell"; }
	string toString() const ;
	
public:
	ObjectID_t getObjectID()  { return m_ObjectID; }
	void setObjectID(ObjectID_t ObjectID)  { m_ObjectID = ObjectID; }

	ObjectID_t getItemObjectID()  { return m_ItemObjectID;}
	void setItemObjectID(ObjectID_t oid) { m_ItemObjectID = oid;}

	BYTE getOpCode(void) const { return m_OpCode; }
	void setOpCode(BYTE code) { m_OpCode = code; }

private:
	ObjectID_t m_ObjectID;     // NPC ID
	ObjectID_t m_ItemObjectID; // Item Object ID
	BYTE       m_OpCode;       // operation code

};


////////////////////////////////////////////////////////////////////////////////
//
// class CGShopRequestSellFactory;
//
////////////////////////////////////////////////////////////////////////////////

class CGShopRequestSellFactory : public PacketFactory 
{
public:
	Packet* createPacket()  { return new CGShopRequestSell(); }
	string getPacketName() const  { return "CGShopRequestSell"; }
	PacketID_t getPacketID() const  { return Packet::PACKET_CG_SHOP_REQUEST_SELL; }
	PacketSize_t getPacketMaxSize() const  { return szObjectID+szObjectID+szBYTE; }

};


////////////////////////////////////////////////////////////////////////////////
//
// class CGShopRequestSellHandler;
//
////////////////////////////////////////////////////////////////////////////////

class CGShopRequestSellHandler 
{
public:
	static void execute(CGShopRequestSell* pPacket, Player* player) ;

	static void executeNormal(CGShopRequestSell* pPacket, Player* player) ;
	static void executeMotorcycle(CGShopRequestSell* pPacket, Player* player) ;
	static void executeOpAllSkull(CGShopRequestSell* pPacket, Player* player) ;
	static void executeOpSwapAdvancementItem(CGShopRequestSell* pPacket, Player* player) ;

	static void sendFailPacket(CGShopRequestSell* pPacket, Player* player) ;
};

#endif
