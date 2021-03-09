//////////////////////////////////////////////////////////////////////
// 
// Filename    : WarInfo.cpp 
// Written By  : 
// Description : 
// 
//////////////////////////////////////////////////////////////////////

// include files
#include "RaceWarInfo.h"

//////////////////////////////////////////////////////////////////////
// 입력스트림(버퍼)으로부터 데이타를 읽어서 패킷을 초기화한다.
//////////////////////////////////////////////////////////////////////
void RaceWarInfo::read ( SocketInputStream & iStream ) 
{
	__BEGIN_TRY

	WarInfo::read( iStream );
	m_CastleIDs.read( iStream );

	__END_CATCH
}

		    
//////////////////////////////////////////////////////////////////////
// 출력스트림(버퍼)으로 패킷의 바이너리 이미지를 보낸다.
//////////////////////////////////////////////////////////////////////
void RaceWarInfo::write ( SocketOutputStream & oStream ) const 
{
	__BEGIN_TRY

	WarInfo::write( oStream );
	m_CastleIDs.write( oStream );

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////
// get debug string
//////////////////////////////////////////////////////////////////////
string RaceWarInfo::toString () const
{
	StringStream msg;

	msg << "RaceWarInfo("
		<< ",RemainTime:" << (int)m_RemainTime
		<< ",Guilds:" << m_CastleIDs.toString()
		<< ")";

	return msg.toString();
}

