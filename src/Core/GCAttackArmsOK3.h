//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCAttackArmsOK3.h 
// Written By  : elca@ewestsoft.com
// Description : 기술 사용자는 볼 수 있고, 피해자는 볼 수 없는 사람에게 보내는 패킷
// 
//////////////////////////////////////////////////////////////////////

#ifndef __GC_ATTACK_ARMS_OK_3_H__
#define __GC_ATTACK_ARMS_OK_3_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class GCAttackArmsOK3;
//
// 게임서버에서 클라이언트로 자신의 기술이 성공을 알려주기 위한 클래스
//
//////////////////////////////////////////////////////////////////////

class GCAttackArmsOK3 : public Packet {

public :
	
	// constructor
	GCAttackArmsOK3() ;
	
	// destructor
	~GCAttackArmsOK3() ;

	
public :
	
	
    // 입력스트림(버퍼)으로부터 데이타를 읽어서 패킷을 초기화한다.
    void read(SocketInputStream & iStream) ;
		    
    // 출력스트림(버퍼)으로 패킷의 바이너리 이미지를 보낸다.
    void write(SocketOutputStream & oStream) const ;

	// execute packet's handler
	void execute(Player* pPlayer) ;

	// get packet id
	PacketID_t getPacketID() const  { return PACKET_GC_ATTACK_ARMS_OK_3; }
	
	// get packet's body size
	// 최적화시, 미리 계산된 정수를 사용한다.
//	PacketSize_t getPacketSize() const  { return szObjectID + szObjectID + szbool; }
	PacketSize_t getPacketSize() const  { return szSkillType + szObjectID + szCoord*2; }

	// get packet's name
	string getPacketName() const  { return "GCAttackArmsOK3"; }
	
	// get packet's debug string
	string toString() const ;

	SkillType_t getSkillType() const { return m_SkillType; }
	void setSkillType(SkillType_t skillType ) { m_SkillType = skillType; }
	// get / set ObjectID
	ObjectID_t getObjectID() const  { return m_ObjectID; }
	void setObjectID(ObjectID_t ObjectID)  { m_ObjectID = ObjectID; }

	// get / set ObjectID
//	ObjectID_t getTargetObjectID() const  { return m_TargetObjectID; }
//	void setTargetObjectID(ObjectID_t TargetObjectID)  { m_TargetObjectID = TargetObjectID; }
	Coord_t getTargetX() const  { return m_X;}
	Coord_t getTargetY() const  { return m_Y;}
	void setTargetXY(Coord_t X, Coord_t Y)  { m_X = X; m_Y = Y;}

	// get / set success
//	bool getSkillSuccess() const  { return m_bSuccess;}
//	void setSkillSuccess(bool bSuccess)  { m_bSuccess = bSuccess;}

private :
	
	SkillType_t m_SkillType;
	// ObjectID
	ObjectID_t m_ObjectID;
	Coord_t m_X, m_Y;

	// TargetObjectID
//	ObjectID_t m_TargetObjectID;

	// bool
//	bool m_bSuccess;

};


//////////////////////////////////////////////////////////////////////
//
// class GCAttackArmsOK3Factory;
//
// Factory for GCAttackArmsOK3
//
//////////////////////////////////////////////////////////////////////

class GCAttackArmsOK3Factory : public PacketFactory {

public :
	
	// constructor
	GCAttackArmsOK3Factory()  {}
	
	// destructor
	virtual ~GCAttackArmsOK3Factory()  {}

	
public :
	
	// create packet
	Packet* createPacket()  { return new GCAttackArmsOK3(); }

	// get packet name
	string getPacketName() const  { return "GCAttackArmsOK3"; }
	
	// get packet id
	PacketID_t getPacketID() const  { return Packet::PACKET_GC_ATTACK_ARMS_OK_3; }

	// get Packet Max Size
	PacketSize_t getPacketMaxSize() const  { return szSkillType + szObjectID + szCoord*2; }

};


//////////////////////////////////////////////////////////////////////
//
// class GCAttackArmsOK3Handler;
//
//////////////////////////////////////////////////////////////////////

class GCAttackArmsOK3Handler {

public :

	// execute packet's handler
	static void execute(GCAttackArmsOK3* pGCAttackArmsOK3, Player* pPlayer) ;

};

#endif
