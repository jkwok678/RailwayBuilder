#include "track.h"

// Track class implementation.


Track::Track()
{

};

int Track::getTrackMainSpeed() const
{
	return trackMainSpeed;
}

void Track::setTrackMainSpeed(int speed)
{
	trackMainSpeed = speed;
}

int Track::getTrackMainLength() const
{
	return trackMainLength;
}

void Track::setTrackMainLength(int length)
{
	trackMainLength = length;
}

int Track::getTrackSecondarySpeed() const
{
	return trackSecondarySpeed;
}

void Track::setTrackSecondarySpeed(int speed)
{
	trackSecondarySpeed = speed;
}

int Track::getTrackSecondaryLength() const
{
	return trackSecondaryLength;
}

void Track::setTrackSecondaryLength(int length)
{
	trackSecondaryLength = length;
}

bool Track::getLinkAt(int link)
{
	return links[link];
}

bool Track::getFound() const
{
	return found;
}

void Track::setFound(bool newFound)
{
	found = newFound;
}

QString Track::toQString()
{
	QString trackQString = "Track";
	trackQString.append(",");
	trackQString.append(QString::number(locationX));
	trackQString.append(",");
	trackQString.append(QString::number(locationY));
	trackQString.append(",");
	trackQString.append(QString::number(trackMainSpeed));
	trackQString.append(",");
	trackQString.append(QString::number(trackMainLength));
	return trackQString;
}

QString Track::toQStringForSave()
{
	QString trackQString = "";
	trackQString.append(QString::number(locationX));
	trackQString.append(",");
	trackQString.append(QString::number(locationY));
	trackQString.append(",");
	trackQString.append(QString::number(trackMainSpeed));
	trackQString.append(",");
	trackQString.append(QString::number(trackMainLength));
	return trackQString;
}


//StraightTrack class implementation.


StraightTrack::StraightTrack()
{

};

StraightTrack::StraightTrack(StraightType newStraightType, int newLocationX, int newLocationY)
{
	straightType = newStraightType;
	locationX = newLocationX;
	locationY = newLocationY;
	switch (straightType)
	{
		case StraightType::STRAIGHTH:
		{
			links[3] = true;
			links[5] = true;
			break;
		}
		case StraightType::STRAIGHTV:
		{
			links[1] = true;
			links[7] = true;
			break;
		}
		case StraightType::STRAIGHTLEFTUP:
		{
			links[0] = true;
			links[8] = true;
			break;
		}
		case StraightType::STRAIGHTRIGHTUP:
		{
			links[2] = true;
			links[6] = true;
			break;
		}
	}

}

StraightType StraightTrack::getStraightType() const
{
	return straightType;
}

void StraightTrack::setStraightType(const StraightType &newStraightType)
{
	straightType = newStraightType;
}

bool StraightTrack::getPlatformAny() const
{
	return platformAny;
}

void StraightTrack::setPlatformAny(bool platform)
{
	platformAny = platform;
}

bool StraightTrack::getPlatform1() const
{
	return platform1;
}

void StraightTrack::setPlatform1(bool newPlatform)
{
	platform1 = newPlatform;
}

bool StraightTrack::getPlatform2() const
{
	return platform2;
}

void StraightTrack::setPlatform2(bool newPlatform)
{
	platform2 = newPlatform;
}

bool StraightTrack::hasLevelCrossing() const
{
	return levelCrossing;
}

void StraightTrack::addLevelCrossing()
{
	levelCrossing = true;
}

QString StraightTrack::straightTypeToQString()
{
	QString straightTypeQString;
	switch (straightType)
	{
	case StraightType::STRAIGHTH:
		straightTypeQString = "straight_h";
		break;
	case StraightType::STRAIGHTV:
		straightTypeQString = "straight_v";
		break;
	case StraightType::STRAIGHTLEFTUP:
		straightTypeQString = "straight_left_up";
		break;
	case StraightType::STRAIGHTRIGHTUP:
		straightTypeQString = "straight_right_up";
		break;
	}
	return straightTypeQString;
}

QString StraightTrack::toQString()
{
	QString straightTrackQString = "StraightTrack";
	straightTrackQString.append(",");
	straightTrackQString.append(straightTypeToQString());
	straightTrackQString.append(",");
	straightTrackQString.append(QString::number(locationX));
	straightTrackQString.append(",");
	straightTrackQString.append(QString::number(locationY));
	straightTrackQString.append(",");
	straightTrackQString.append(QString::number(trackMainSpeed));
	straightTrackQString.append(",");
	straightTrackQString.append(QString::number(trackMainLength));
	straightTrackQString.append(",");
	straightTrackQString.append(QVariant(platform1).toString());
	straightTrackQString.append(",");
	straightTrackQString.append(QVariant(platform2).toString());
	straightTrackQString.append(",");
	straightTrackQString.append(QVariant(levelCrossing).toString());
	return straightTrackQString;
}

QString StraightTrack::toQStringForSave()
{
	QString straightTrackQString = "";
	straightTrackQString.append(straightTypeToQString());
	straightTrackQString.append(",");
	straightTrackQString.append(QString::number(locationX));
	straightTrackQString.append(",");
	straightTrackQString.append(QString::number(locationY));
	straightTrackQString.append(",");
	straightTrackQString.append(QString::number(trackMainSpeed));
	straightTrackQString.append(",");
	straightTrackQString.append(QString::number(trackMainLength));
	straightTrackQString.append(",");
	straightTrackQString.append(QVariant(platform1).toString());
	straightTrackQString.append(",");
	straightTrackQString.append(QVariant(platform2).toString());
	straightTrackQString.append(",");
	straightTrackQString.append(QVariant(levelCrossing).toString());
	return straightTrackQString;
}


// DirectedTrack class implementation.


DirectedTrack::DirectedTrack(DirectedType newDirectType, int newLocationX, int newLocationY)
{
	directedType = newDirectType;
	locationX = newLocationX;
	locationY = newLocationY;
	switch(directedType)
	{
		case DirectedType::DIRECTEDLEFT:
		case DirectedType::DIRECTEDRIGHT:
		{
			links[3] = true;
			links[5] = true;
			break;
		}
		case DirectedType::DIRECTEDUP:
		case DirectedType::DIRECTEDDOWN:
		{
			links[1] = true;
			links[7] = true;
			break;
		}
		case DirectedType::DIRECTEDLEFTUP:
		case DirectedType::DIRECTEDRIGHTDOWN:
		{
			links[0] = true;
			links[8] = true;
			break;
		}
		case DirectedType::DIRECTEDRIGHTUP:
		case DirectedType::DIRECTEDLEFTDOWN:
		{
			links[2] = true;
			links[6] = true;
			break;
		}

	}

}

DirectedType DirectedTrack::getDirectType() const
{
	return directedType;
}

void DirectedTrack::setDirectedType(const DirectedType &newDirectedType)
{
	directedType = newDirectedType;
}

QString DirectedTrack::directedTypeToQString()
{
	QString directedTypeQString;
	switch (directedType)
	{
	case DirectedType::DIRECTEDLEFT:
		directedTypeQString = "directed_left";
		break;
	case DirectedType::DIRECTEDRIGHT:
		directedTypeQString = "directed_right";
		break;
	case DirectedType::DIRECTEDUP:
		directedTypeQString = "directed_up";
		break;
	case DirectedType::DIRECTEDDOWN:
		directedTypeQString = "directed_down";
		break;
	case DirectedType::DIRECTEDLEFTUP:
		directedTypeQString = "directed_left_up";
		break;
	case DirectedType::DIRECTEDRIGHTUP:
		directedTypeQString = "directed_right_up";
		break;
	case DirectedType::DIRECTEDLEFTDOWN:
		directedTypeQString = "directed_left_down";
		break;
	case DirectedType::DIRECTEDRIGHTDOWN:
		directedTypeQString = "directed_right_down";
		break;
	}
	return directedTypeQString;
}

QString DirectedTrack::toQString()
{
	QString directedTrackQString = "DirectedTrack";
	directedTrackQString.append(",");
	directedTrackQString.append(directedTypeToQString());
	directedTrackQString.append(",");
	directedTrackQString.append(QString::number(locationX));
	directedTrackQString.append(",");
	directedTrackQString.append(QString::number(locationY));
	directedTrackQString.append(",");
	directedTrackQString.append(QString::number(trackMainSpeed));
	directedTrackQString.append(",");
	directedTrackQString.append(QString::number(trackMainLength));
	directedTrackQString.append(",");
	directedTrackQString.append(QVariant(platform1).toString());
	directedTrackQString.append(",");
	directedTrackQString.append(QVariant(platform2).toString());
	return directedTrackQString;
}


//CurvedTrack class implementation.


CurvedTrack::CurvedTrack(CurvedType newCurvedType, int newLocationX, int newLocationY)
{
	curvedType = newCurvedType;
	locationX = newLocationX;
	locationY = newLocationY;
	switch (curvedType)
	{
		case CurvedType::TIGHTCURVE1:
		{
			links[5] = true;
			links[7] = true;
			break;
		}
		case CurvedType::TIGHTCURVE2:
		{
			links[3] = true;
			links[7] = true;
			break;
		}
		case CurvedType::TIGHTCURVE3:
		{
			links[1] = true;
			links[5] = true;
			break;
		}
		case CurvedType::TIGHTCURVE4:
		{
			links[1] = true;
			links[3] = true;
			break;
		}
		case CurvedType::CURVE1:
		{
			links[5] = true;
			links[6] = true;
			break;
		}
		case CurvedType::CURVE2:
		{
			links[3] = true;
			links[8] = true;
			break;
		}
		case CurvedType::CURVE3:
		{
			links[0] = true;
			links[5] = true;
			break;
		}
		case CurvedType::CURVE4:
		{
			links[2] = true;
			links[3] = true;
			break;
		}
		case CurvedType::CURVE5:
		{
			links[1] = true;
			links[8] = true;
			break;
		}
		case CurvedType::CURVE6:
		{
			links[1] = true;
			links[6] = true;
			break;
		}
		case CurvedType::CURVE7:
		{
			links[2] = true;
			links[7] = true;
			break;
		}
		case CurvedType::CURVE8:
		{
			links[0] = true;
			links[7] = true;
			break;
		}
	}

}

CurvedType CurvedTrack::getCurvedType() const
{
	return curvedType;
}

void CurvedTrack::setCurvedType(const CurvedType &newCurvedType)
{
	curvedType = newCurvedType;
}

QString CurvedTrack::curvedTypeToQString()
{
	QString curvedTypeQString;
	switch (curvedType)
	{
	case CurvedType::CURVE1:
		curvedTypeQString = "curve_1";
		break;
	case CurvedType::CURVE2:
		curvedTypeQString = "curve_2";
		break;
	case CurvedType::CURVE3:
		curvedTypeQString = "curve_3";
		break;
	case CurvedType::CURVE4:
		curvedTypeQString = "curve_4";
		break;
	case CurvedType::CURVE5:
		curvedTypeQString = "curve_5";
		break;
	case CurvedType::CURVE6:
		curvedTypeQString = "curve_6";
		break;
	case CurvedType::CURVE7:
		curvedTypeQString = "curve_7";
		break;
	case CurvedType::CURVE8:
		curvedTypeQString = "curve_8";
		break;
	case CurvedType::TIGHTCURVE1:
		curvedTypeQString = "tight_curve_1";
		break;
	case CurvedType::TIGHTCURVE2:
		curvedTypeQString = "tight_curve_2";
		break;
	case CurvedType::TIGHTCURVE3:
		curvedTypeQString = "tight_curve_3";
		break;
	case CurvedType::TIGHTCURVE4:
		curvedTypeQString = "tight_curve_4";
		break;
	}
	return curvedTypeQString;
}

QString CurvedTrack::toQString()
{
	QString curvedTrackQString = "CurvedTrack";
	curvedTrackQString.append(",");
	curvedTrackQString.append(curvedTypeToQString());
	curvedTrackQString.append(",");
	curvedTrackQString.append(QString::number(locationX));
	curvedTrackQString.append(",");
	curvedTrackQString.append(QString::number(locationY));
	curvedTrackQString.append(",");
	curvedTrackQString.append(QString::number(trackMainSpeed));
	curvedTrackQString.append(",");
	curvedTrackQString.append(QString::number(trackMainLength));
	return curvedTrackQString;
}


//LinkedTrack class implementation.


LinkedTrack::LinkedTrack(LinkedType newLinkedType, int newLocationX, int newLocationY)
{
	linkedType = newLinkedType;
	locationX = newLocationX;
	locationY = newLocationY;
	linked = false;
	switch(linkedType)
	{
		case LinkedType::LINKLEFT:
		{
			links[5] = true;
			break;
		}
		case LinkedType::LINKRIGHT:
		{
			links[3] = true;
			break;
		}
		case LinkedType::LINKUP:
		{
			links[7] = true;
			break;
		}
		case LinkedType::LINKDOWN:
		{
			links[1] = true;
			break;
		}
		case LinkedType::LINKLEFTUP:
		{
			links[8] = true;
			break;
		}
		case LinkedType::LINKRIGHTDOWN:
		{
			links[0] = true;
			break;
		}
		case LinkedType::LINKLEFTDOWN:
		{
			links[2] = true;
			break;
		}
		case LinkedType::LINKRIGHTUP:
		{
			links[6] = true;
			break;
		}
	}
}

LinkedType LinkedTrack::getLinkedType() const
{
	return linkedType;
}

void LinkedTrack::setLinkedType(const LinkedType &newLinkedType)
{
	linkedType = newLinkedType;
}

bool LinkedTrack::getLinked() const
{
	return linked;
}

void LinkedTrack::setLinked(bool newLinked)
{
	linked = newLinked;
}

std::shared_ptr<LinkedTrack> LinkedTrack::getOtherLinkedTrack()
{
	return otherLinkTrack;
}

void LinkedTrack::setOtherLinkedTrack(std::shared_ptr<LinkedTrack> &newLinkedTrack)
{
	otherLinkTrack = newLinkedTrack;
}

void LinkedTrack::removeOtherLinkedTrack()
{
	otherLinkTrack = nullptr;
}

QString LinkedTrack::linkedTypeToQString()
{
	QString linkedTypeQString;
	switch (linkedType)
	{
	case LinkedType::LINKLEFT:
		linkedTypeQString = "link_left";
		break;
	case LinkedType::LINKRIGHT:
		linkedTypeQString = "link_right";
		break;
	case LinkedType::LINKUP:
		linkedTypeQString = "link_up";
		break;
	case LinkedType::LINKDOWN:
		linkedTypeQString = "link_down";
		break;
	case LinkedType::LINKLEFTDOWN:
		linkedTypeQString = "link_left_down";
		break;
	case LinkedType::LINKLEFTUP:
		linkedTypeQString = "link_left_up";
		break;
	case LinkedType::LINKRIGHTDOWN:
		linkedTypeQString = "link_right_down";
		break;
	case LinkedType::LINKRIGHTUP:
		linkedTypeQString = "link_right_up";
		break;
	}
	return linkedTypeQString;
}

QString LinkedTrack::toQString()
{
	QString linkedTrackQString = "LinkedTrack";
	linkedTrackQString.append(",");
	linkedTrackQString.append(linkedTypeToQString());
	linkedTrackQString.append(",");
	linkedTrackQString.append(QString::number(locationX));
	linkedTrackQString.append(",");
	linkedTrackQString.append(QString::number(locationY));
	linkedTrackQString.append(",");
	linkedTrackQString.append(QString::number(trackMainSpeed));
	linkedTrackQString.append(",");
	linkedTrackQString.append(QString::number(trackMainLength));
	if (linked && otherLinkTrack != nullptr)
	{
		linkedTrackQString.append(",");
		linkedTrackQString.append("linked");
		linkedTrackQString.append(",");
		linkedTrackQString.append(otherLinkedTrackToQString());

	}
	else
	{
		linkedTrackQString.append(",");
		linkedTrackQString.append("nolink");
	}
	return linkedTrackQString;
}

QString LinkedTrack::otherLinkedTrackToQString()
{
	QString linkedTrackQString = "LinkedTrack";
	linkedTrackQString.append(",");
	linkedTrackQString.append(linkedTypeToQString());
	linkedTrackQString.append(",");
	linkedTrackQString.append(QString::number(locationX));
	linkedTrackQString.append(",");
	linkedTrackQString.append(QString::number(locationY));
	linkedTrackQString.append(",");
	linkedTrackQString.append(QString::number(trackMainSpeed));
	linkedTrackQString.append(",");
	linkedTrackQString.append(QString::number(trackMainLength));
	return linkedTrackQString;
}


//ExitTrack class implementation.


ExitTrack::ExitTrack(ExitType newExitType, int newLocationX, int newLocationY)
{
	exitType = newExitType;
	locationX = newLocationX;
	locationY = newLocationY;
	switch (exitType)
	{
		case ExitType::EXITLEFT:
		{
			links[5] = true;
			break;
		}
		case ExitType::EXITRIGHT:
		{
			links[3] = true;
			break;
		}
		case ExitType::EXITUP:
		{
			links[7] = true;
			break;
		}
		case ExitType::EXITDOWN:
		{
			links[1] = true;
			break;
		}
		case ExitType::EXITLEFTUP:
		{
			links[8] = true;
			break;
		}
		case ExitType::EXITRIGHTUP:
		{
			links[6] = true;
			break;
		}
		case ExitType::EXITLEFTDOWN:
		{
			links[2] = true;
			break;
		}
		case ExitType::EXITRIGHTDOWN:
		{
			links[0] = true;
			break;
		}
	}

}

ExitType ExitTrack::getExitType() const
{
	return exitType;
}

void ExitTrack::setExitType(const ExitType &newExitType)
{
	exitType = newExitType;
}

QString ExitTrack::exitTypeToQString()
{
	QString exitTypeQString;
	switch (exitType)
	{
	case ExitType::EXITLEFT:
		exitTypeQString = "exit_left";
		break;
	case ExitType::EXITRIGHT:
		exitTypeQString = "exit_right";
		break;
	case ExitType::EXITUP:
		exitTypeQString = "exit_up";
		break;
	case ExitType::EXITDOWN:
		exitTypeQString = "exit_down";
		break;
	case ExitType::EXITLEFTDOWN:
		exitTypeQString = "exit_left_down";
		break;
	case ExitType::EXITLEFTUP:
		exitTypeQString = "exit_left_up";
		break;
	case ExitType::EXITRIGHTDOWN:
		exitTypeQString = "exit_right_down";
		break;
	case ExitType::EXITRIGHTUP:
		exitTypeQString = "exit_right_up";
		break;
	}
	return exitTypeQString;
}

QString ExitTrack::toQString()
{
	QString exitTrackQString = "ExitTrack";
	exitTrackQString.append(",");
	exitTrackQString.append(exitTypeToQString());
	exitTrackQString.append(",");
	exitTrackQString.append(QString::number(locationX));
	exitTrackQString.append(",");
	exitTrackQString.append(QString::number(locationY));
	exitTrackQString.append(",");
	exitTrackQString.append(QString::number(trackMainSpeed));
	exitTrackQString.append(",");
	exitTrackQString.append(QString::number(trackMainLength));
	return exitTrackQString;
}


//BufferTrack class implementation.


BufferTrack::BufferTrack(BufferType newBufferType, int newLocationX, int newLocationY)
{
	bufferType = newBufferType;
	locationX = newLocationX;
	locationY = newLocationY;
	switch (bufferType)
	{
		case BufferType::BUFFERLEFT:
		{
			links[5] = true;
			break;
		}
		case BufferType::BUFFERRIGHT:
		{
			links[3] = true;
			break;
		}
		case BufferType::BUFFERUP:
		{
			links[7] = true;
			break;
		}
		case BufferType::BUFFERDOWN:
		{
			links[1] = true;
			break;
		}
		case BufferType::BUFFERLEFTUP:
		{
			links[8] = true;
			break;
		}
		case BufferType::BUFFERRIGHTUP:
		{
			links[6] = true;
			break;
		}
		case BufferType::BUFFERLEFTDOWN:
		{
			links[2] = true;
			break;
		}
		case BufferType::BUFFERRIGHTDOWN:
		{
			links[0] = true;
			break;
		}
	}

}

BufferType BufferTrack::getBufferType() const
{
	return bufferType;
}

void BufferTrack::setBufferType(const BufferType &newBufferType)
{
	bufferType = newBufferType;
}

QString BufferTrack::bufferTypeToQString()
{
	QString bufferTypeQString;
	switch (bufferType)
	{
	case BufferType::BUFFERLEFT:
		bufferTypeQString = "buffer_left";
		break;
	case BufferType::BUFFERRIGHT:
		bufferTypeQString = "buffer_right";
		break;
	case BufferType::BUFFERUP:
		bufferTypeQString = "buffer_up";
		break;
	case BufferType::BUFFERDOWN:
		bufferTypeQString = "buffer_down";
		break;
	case BufferType::BUFFERLEFTDOWN:
		bufferTypeQString = "buffer_left_down";
		break;
	case BufferType::BUFFERLEFTUP:
		bufferTypeQString = "buffer_left_up";
		break;
	case BufferType::BUFFERRIGHTDOWN:
		bufferTypeQString = "buffer_right_down";
		break;
	case BufferType::BUFFERRIGHTUP:
		bufferTypeQString = "buffer_right_up";
		break;
	}
	return bufferTypeQString;
}

QString BufferTrack::toQString()
{
	QString bufferTrackQString = "BufferTrack";
	bufferTrackQString.append(",");
	bufferTrackQString.append(bufferTypeToQString());
	bufferTrackQString.append(",");
	bufferTrackQString.append(QString::number(locationX));
	bufferTrackQString.append(",");
	bufferTrackQString.append(QString::number(locationY));
	bufferTrackQString.append(",");
	bufferTrackQString.append(QString::number(trackMainSpeed));
	bufferTrackQString.append(",");
	bufferTrackQString.append(QString::number(trackMainLength));
	return bufferTrackQString;
}


//SignalTrack class implementation.


SignalTrack::SignalTrack(SignalType newSignalType, int newAspect, int newLocationX, int newLocationY)
{
	signalType = newSignalType;
	aspect = newAspect;
	locationX = newLocationX;
	locationY = newLocationY;
	switch (signalType)
	{
		case SignalType::SIGNALLEFT:
		case SignalType::SIGNALRIGHT:
		{
			links[3] = true;
			links[5] = true;
			break;
		}
		case SignalType::SIGNALUP:
		case SignalType::SIGNALDOWN:
		{
			links[1] = true;
			links[7] = true;
			break;
		}
		case SignalType::SIGNALLEFTUP:
		case SignalType::SIGNALRIGHTDOWN:
		{
			links[0] = true;
			links[8] = true;
			break;
		}
		case SignalType::SIGNALRIGHTUP:
		case SignalType::SIGNALLEFTDOWN:
		{
			links[2] = true;
			links[6] = true;
			break;
		}
	}

}

SignalType SignalTrack::getSignalType() const
{
	return signalType;
}

void SignalTrack::setSignalType(const SignalType &newSignalType)
{
	signalType = newSignalType;
}

int SignalTrack::getAspect() const
{
	return aspect;
}

void SignalTrack::setAspect(int newAspect)
{
	aspect = newAspect;
}

QString SignalTrack::signalTypeToQString()
{
	QString signalTypeQString;
	switch (signalType)
	{
	case SignalType::SIGNALLEFT:
		signalTypeQString = "signal_left";
		break;
	case SignalType::SIGNALRIGHT:
		signalTypeQString = "signal_right";
		break;
	case SignalType::SIGNALUP:
		signalTypeQString = "signal_up";
		break;
	case SignalType::SIGNALDOWN:
		signalTypeQString = "signal_down";
		break;
	case SignalType::SIGNALLEFTDOWN:
		signalTypeQString = "signal_left_down";
		break;
	case SignalType::SIGNALLEFTUP:
		signalTypeQString = "signal_left_up";
		break;
	case SignalType::SIGNALRIGHTDOWN:
		signalTypeQString = "signal_right_down";
		break;
	case SignalType::SIGNALRIGHTUP:
		signalTypeQString = "signal_right_up";
		break;
	}
	return signalTypeQString;
}

QString SignalTrack::toQString()
{
	QString signalTrackQString = "SignalTrack";
	signalTrackQString.append(",");
	signalTrackQString.append(signalTypeToQString());
	signalTrackQString.append(",");
	signalTrackQString.append(QString::number(locationX));
	signalTrackQString.append(",");
	signalTrackQString.append(QString::number(locationY));
	signalTrackQString.append(",");
	signalTrackQString.append(QString::number(trackMainSpeed));
	signalTrackQString.append(",");
	signalTrackQString.append(QString::number(trackMainLength));
	signalTrackQString.append(",");
	signalTrackQString.append(QString::number(aspect));
	return signalTrackQString;
}

//BridgeUnderpassTrack class implementation.


BridgeUnderpassTrack::BridgeUnderpassTrack(BridgeUnderpassType newBridgeUnderpassType, int newLocationX, int newLocationY)
{
	bridgeUnderpassType = newBridgeUnderpassType;
	locationX = newLocationX;
	locationY = newLocationY;
	switch (bridgeUnderpassType)
	{
		case BridgeUnderpassType::BRIDGE1:
		case BridgeUnderpassType::UNDERPASS1:
		{
			links[3] = true;
			links[5] = true;
			break;
		}
		case BridgeUnderpassType::BRIDGE2:
		case BridgeUnderpassType::UNDERPASS2:
		{
			links[1] = true;
			links[7] = true;
			break;
		}
	}
}

BridgeUnderpassType BridgeUnderpassTrack::getBridgeUnderpassType() const
{
	return bridgeUnderpassType;
}

void BridgeUnderpassTrack::setBridgeUnderpassType(const BridgeUnderpassType &newBridgeUnderpassType)
{
	bridgeUnderpassType = newBridgeUnderpassType;
}

QString BridgeUnderpassTrack::bridgeUnderpassTypeToQString()
{
	QString bridgeUnderpassTypeQString;
	switch (bridgeUnderpassType)
	{
	case BridgeUnderpassType::BRIDGE1:
		bridgeUnderpassTypeQString = "bridge_1";
		break;
	case BridgeUnderpassType::BRIDGE2:
		bridgeUnderpassTypeQString = "bridge_2";
		break;
	case BridgeUnderpassType::UNDERPASS1:
		bridgeUnderpassTypeQString = "underpass_1";
		break;
	case BridgeUnderpassType::UNDERPASS2:
		bridgeUnderpassTypeQString = "underpass_2";
		break;
	}
	return bridgeUnderpassTypeQString;
}

QString BridgeUnderpassTrack::toQString()
{
	QString bridgeUnderpassTrackQString = "BridgeUnderpassTrack";
	bridgeUnderpassTrackQString.append(",");
	bridgeUnderpassTrackQString.append(bridgeUnderpassTypeToQString());
	bridgeUnderpassTrackQString.append(",");
	bridgeUnderpassTrackQString.append(QString::number(locationX));
	bridgeUnderpassTrackQString.append(",");
	bridgeUnderpassTrackQString.append(QString::number(locationY));
	bridgeUnderpassTrackQString.append(",");
	bridgeUnderpassTrackQString.append(QString::number(trackMainSpeed));
	bridgeUnderpassTrackQString.append(",");
	bridgeUnderpassTrackQString.append(QString::number(trackMainLength));
	return bridgeUnderpassTrackQString;
}


//SwitchTrack class implementation.


SwitchTrack::SwitchTrack(SwitchType newSwitchType, int newLocationX, int newLocationY)
{
	switchType = newSwitchType;
	locationX = newLocationX;
	locationY = newLocationY;
	trackSecondaryLength = 100;
	trackSecondarySpeed = 200;
	switch (switchType)
	{
		case SwitchType::SWITCHTIGHT1:
		case SwitchType::SWITCHTIGHT2:
		{
			links[1] = true;
			links[3] = true;
			links[5] = true;
			break;
		}
		case SwitchType::SWITCHTIGHT3:
		case SwitchType::SWITCHTIGHT4:
		{
			links[3] = true;
			links[5] = true;
			links[7] = true;
			break;
		}
		case SwitchType::SWITCHTIGHT5:
		case SwitchType::SWITCHTIGHT7:
		{
			links[1] = true;
			links[3] = true;
			links[7] = true;
			break;
		}
		case SwitchType::SWITCHTIGHT6:
		case SwitchType::SWITCHTIGHT8:
		{
			links[1] = true;
			links[5] = true;
			links[7] = true;
			break;
		}
		case SwitchType::SWITCHSPLIT1:
		{
			//Left diverging is main, right diverging is secondary.
			links[2] = true;
			links[3] = true;
			links[8] = true;
			break;
		}
		case SwitchType::SWITCHSPLIT2:
		{
			//Left diverging is main, Right diverging is secondary.
			links[0] = true;
			links[5] = true;
			links[6] = true;
			break;
		}
		case SwitchType::SWITCHSPLIT3:
		{
			//Left diverging is main, right diverging is secondary.
			links[2] = true;
			links[3] = true;
			links[7] = true;
			break;
		}
		case SwitchType::SWITCHSPLIT4:
		{
			//Left diverging is main, right diverging is secondary.
			links[1] = true;
			links[5] = true;
			links[6] = true;
			break;
		}
		case SwitchType::SWITCHSPLIT5:
		{
			//Left diverging is main, right diverging is secondary.
			links[1] = true;
			links[3] = true;
			links[8] = true;
			break;
		}
		case SwitchType::SWITCHSPLIT6:
		{
			//Left diverging is main, right diverging is secondary.
			links[0] = true;
			links[5] = true;
			links[7] = true;
			break;
		}
		case SwitchType::SWITCHSPLIT7:
		{
			//Left diverging is main, right diverging is secondary.
			links[0] = true;
			links[2] = true;
			links[7] = true;
			break;
		}
		case SwitchType::SWITCHSPLIT8:
		{
			//Left diverging is main, right diverging is secondary.
			links[1] = true;
			links[6] = true;
			links[8] = true;
			break;
		}
		case SwitchType::SWITCH1:
		{
			links[2] = true;
			links[3] = true;
			links[5] = true;
			break;
		}
		case SwitchType::SWITCH2:
		{
			links[0] = true;
			links[3] = true;
			links[5] = true;
			break;
		}
		case SwitchType::SWITCH3:
		{
			links[3] = true;
			links[5] = true;
			links[8] = true;
			break;
		}
		case SwitchType::SWITCH4:
		{
			links[3] = true;
			links[5] = true;
			links[6] = true;
			break;
		}
		case SwitchType::SWITCH5:
		{
			links[0] = true;
			links[1] = true;
			links[7] = true;
			break;
		}
		case SwitchType::SWITCH6:
		{
			links[1] = true;
			links[2] = true;
			links[7] = true;
			break;
		}
		case SwitchType::SWITCH7:
		{
			links[1] = true;
			links[6] = true;
			links[7] = true;
			break;
		}
		case SwitchType::SWITCH8:
		{
			links[1] = true;
			links[7] = true;
			links[8] = true;
			break;
		}
		case SwitchType::SWITCH9:
		{
			links[0] = true;
			links[1] = true;
			links[8] = true;
			break;
		}
		case SwitchType::SWITCH10:
		{
			links[1] = true;
			links[2] = true;
			links[6] = true;
			break;
		}
		case SwitchType::SWITCH11:
		{
			links[2] = true;
			links[6] = true;
			links[7] = true;
			break;
		}
		case SwitchType::SWITCH12:
		{
			links[0] = true;
			links[7] = true;
			links[8] = true;
			break;
		}
		case SwitchType::SWITCH13:
		{
			links[0] = true;
			links[3] = true;
			links[8] = true;
			break;
		}
		case SwitchType::SWITCH14:
		{
			links[2] = true;
			links[5] = true;
			links[6] = true;
			break;
		}
		case SwitchType::SWITCH15:
		{
			links[2] = true;
			links[3] = true;
			links[6] = true;
			break;
		}
		case SwitchType::SWITCH16:
		{
			links[0] = true;
			links[5] = true;
			links[8] = true;
			break;
		}
	}
}

SwitchType SwitchTrack::getSwitchType() const
{
	return switchType;
}

void SwitchTrack::setSwitchType(const SwitchType &newSwitchType)
{
	switchType = newSwitchType;
}

QString SwitchTrack::switchTypeToQString()
{
	QString switchTypeQString;
	switch (switchType)
	{
	case SwitchType::SWITCH1:
		switchTypeQString = "switch_1";
		break;
	case SwitchType::SWITCH2:
		switchTypeQString = "switch_2";
		break;
	case SwitchType::SWITCH3:
		switchTypeQString = "switch_3";
		break;
	case SwitchType::SWITCH4:
		switchTypeQString = "switch_4";
		break;
	case SwitchType::SWITCH5:
		switchTypeQString = "switch_5";
		break;
	case SwitchType::SWITCH6:
		switchTypeQString = "switch_6";
		break;
	case SwitchType::SWITCH7:
		switchTypeQString = "switch_7";
		break;
	case SwitchType::SWITCH8:
		switchTypeQString = "switch_8";
		break;
	case SwitchType::SWITCH9:
		switchTypeQString = "switch_9";
		break;
	case SwitchType::SWITCH10:
		switchTypeQString = "switch_10";
		break;
	case SwitchType::SWITCH11:
		switchTypeQString = "switch_11";
		break;
	case SwitchType::SWITCH12:
		switchTypeQString = "switch_12";
		break;
	case SwitchType::SWITCH13:
		switchTypeQString = "switch_13";
		break;
	case SwitchType::SWITCH14:
		switchTypeQString = "switch_14";
		break;
	case SwitchType::SWITCH15:
		switchTypeQString = "switch_15";
		break;
	case SwitchType::SWITCH16:
		switchTypeQString = "switch_16";
		break;
	case SwitchType::SWITCHTIGHT1:
		switchTypeQString = "switch_tight_1";
		break;
	case SwitchType::SWITCHTIGHT2:
		switchTypeQString = "switch_tight_2";
		break;
	case SwitchType::SWITCHTIGHT3:
		switchTypeQString = "switch_tight_3";
		break;
	case SwitchType::SWITCHTIGHT4:
		switchTypeQString = "switch_tight_4";
		break;
	case SwitchType::SWITCHTIGHT5:
		switchTypeQString = "switch_tight_5";
		break;
	case SwitchType::SWITCHTIGHT6:
		switchTypeQString = "switch_tight_6";
		break;
	case SwitchType::SWITCHTIGHT7:
		switchTypeQString = "switch_tight_7";
		break;
	case SwitchType::SWITCHTIGHT8:
		switchTypeQString = "switch_tight_8";
		break;
	case SwitchType::SWITCHSPLIT1:
		switchTypeQString = "switch_switch_1";
		break;
	case SwitchType::SWITCHSPLIT2:
		switchTypeQString = "switch_switch_2";
		break;
	case SwitchType::SWITCHSPLIT3:
		switchTypeQString = "switch_switch_3";
		break;
	case SwitchType::SWITCHSPLIT4:
		switchTypeQString = "switch_switch_4";
		break;
	case SwitchType::SWITCHSPLIT5:
		switchTypeQString = "switch_switch_5";
		break;
	case SwitchType::SWITCHSPLIT6:
		switchTypeQString = "switch_switch_6";
		break;
	case SwitchType::SWITCHSPLIT7:
		switchTypeQString = "switch_switch_7";
		break;
	case SwitchType::SWITCHSPLIT8:
		switchTypeQString = "switch_switch_8";
		break;
	}
	return switchTypeQString;
}

QString SwitchTrack::toQString()
{
	QString switchTrackQString = "SwitchTrack";
	switchTrackQString.append(",");
	switchTrackQString.append(switchTypeToQString());
	switchTrackQString.append(",");
	switchTrackQString.append(QString::number(locationX));
	switchTrackQString.append(",");
	switchTrackQString.append(QString::number(locationY));
	switchTrackQString.append(",");
	switchTrackQString.append(QString::number(trackMainSpeed));
	switchTrackQString.append(",");
	switchTrackQString.append(QString::number(trackMainLength));
	return switchTrackQString;
}


//CrossoverTrack class implementation.


CrossoverTrack::CrossoverTrack(CrossoverType newCrossoverType, int newLocationX, int newLocationY)
{
	crossoverType = newCrossoverType;
	locationX = newLocationX;
	locationY = newLocationY;
	trackSecondaryLength = 100;
	trackSecondaryLength = 200;
	switch (crossoverType)
	{
		case CrossoverType::CROSSOVER1:
		{
			//Horizontal is main, vertical is secondary
			links[1] = true;
			links[3] = true;
			links[5] = true;
			links[7] = true;
			break;
		}
		case CrossoverType::CROSSOVER2:
		{
			//Top left to Bottom right is main, other is secondary
			links[0] = true;
			links[2] = true;
			links[6] = true;
			links[8] = true;
			break;
		}
		case CrossoverType::CROSSOVER3:
		{
			//Vertical is main, other is secondary
			links[0] = true;
			links[1] = true;
			links[7] = true;
			links[8] = true;
			break;
		}
		case CrossoverType::CROSSOVER4:
		{
			//Vertical is main, other is secondary
			links[1] = true;
			links[2] = true;
			links[6] = true;
			links[7] = true;
			break;
		}
		case CrossoverType::CROSSOVER5:
		{
			//Horizontal is main, other is secondary
			links[0] = true;
			links[3] = true;
			links[5] = true;
			links[8] = true;
			break;
		}
		case CrossoverType::CROSSOVER6:
		{
			//Horizontal is main, other is secondary
			links[2] = true;
			links[3] = true;
			links[5] = true;
			links[6] = true;
			break;
		}
	}

}

CrossoverType CrossoverTrack::getCrossoverType() const
{
	return crossoverType;
}

void CrossoverTrack::setCrossoverType(const CrossoverType &newCrossoverType)
{
	crossoverType = newCrossoverType;
}

QString CrossoverTrack::crossoverTypeToQString()
{
	QString crossoverTypeQString;
	switch (crossoverType)
	{
	case CrossoverType::CROSSOVER1:
		crossoverTypeQString = "crossover_1";
		break;
	case CrossoverType::CROSSOVER2:
		crossoverTypeQString = "crossover_2";
		break;
	case CrossoverType::CROSSOVER3:
		crossoverTypeQString = "crossover_3";
		break;
	case CrossoverType::CROSSOVER4:
		crossoverTypeQString = "crossover_4";
		break;
	case CrossoverType::CROSSOVER5:
		crossoverTypeQString = "crossover_5";
		break;
	case CrossoverType::CROSSOVER6:
		crossoverTypeQString = "crossover_6";
		break;
	}
	return crossoverTypeQString;
}

QString CrossoverTrack::toQString()
{
	QString crossoverTrackQString = "CrossoverTrack";
	crossoverTrackQString.append(",");
	crossoverTrackQString.append(crossoverTypeToQString());
	crossoverTrackQString.append(",");
	crossoverTrackQString.append(QString::number(locationX));
	crossoverTrackQString.append(",");
	crossoverTrackQString.append(QString::number(locationY));
	crossoverTrackQString.append(",");
	crossoverTrackQString.append(QString::number(trackMainSpeed));
	crossoverTrackQString.append(",");
	crossoverTrackQString.append(QString::number(trackMainLength));
	return crossoverTrackQString;
}


//FlyoverTrack class implementation.


FlyoverTrack::FlyoverTrack(FlyoverType newFlyoverType, int newLocationX, int newLocationY)
{
	flyoverType = newFlyoverType;
	locationX = newLocationX;
	locationY = newLocationY;
	trackSecondaryLength = 100;
	trackSecondaryLength = 200;
	//Bottom track is secondary
	switch (flyoverType)
	{
		case FlyoverType::FLYOVER1:
		case FlyoverType::FLYOVER2:
		{
			//For Flyover 1, vertical is the Top Track and the main track.
			//For Flyover 2, horizontal is the Top Track and the main track.
			links[1] = true;
			links[3] = true;
			links[5] = true;
			links[7] = true;
			break;
		}
		case FlyoverType::FLYOVER3:
		case FlyoverType::FLYOVER4:
		{
			//For Flyover 3, top left to bottom right is the Top Track and the main track.
			//For Flyover 4, top right to bottom left is the Top Track and the main track.
			links[0] = true;
			links[2] = true;
			links[6] = true;
			links[8] = true;
			break;
		}
		case FlyoverType::FLYOVER5:
		case FlyoverType::FLYOVER7:
		{
			//For Flyover 5, Vertical is the Top Track and the main track.
			//For Flyover 7, top left to bottom right is the Top Track and the main track.
			links[0] = true;
			links[1] = true;
			links[7] = true;
			links[8] = true;
			break;
		}
		case FlyoverType::FLYOVER6:
		case FlyoverType::FLYOVER8:
		{
			//For Flyover 6, Vertical is the Top Track and the main track.
			//For Flyover 8, top right to bottom left is the Top Track and the main track.
			links[1] = true;
			links[2] = true;
			links[6] = true;
			links[7] = true;
			break;
		}
		case FlyoverType::FLYOVER9:
		case FlyoverType::FLYOVER11:
		{
			//For Flyover 9, Horizontal is the Top Track and the main track.
			//For Flyover 11, top left to bottom right is the Top Track and the main track.
			links[0] = true;
			links[3] = true;
			links[5] = true;
			links[8] = true;
			break;
		}
		case FlyoverType::FLYOVER10:
		case FlyoverType::FLYOVER12:
		{
			//For Flyover 10, Horizontal is the Top Track and the main track.
			//For Flyover 12, top right to bottom left Top Track and the main track.
			links[2] = true;
			links[3] = true;
			links[5] = true;
			links[6] = true;
			break;
		}
	}

}

FlyoverType FlyoverTrack::getFlyoverType() const
{
	return flyoverType;
}

void FlyoverTrack::setFlyoverType(const FlyoverType &newFlyoverType)
{
	flyoverType = newFlyoverType;
}

QString FlyoverTrack::flyoverTypeToQString()
{
	QString flyoverTypeQString;
	switch (flyoverType)
	{
	case FlyoverType::FLYOVER1:
		flyoverTypeQString = "flyover_1";
		break;
	case FlyoverType::FLYOVER2:
		flyoverTypeQString = "flyover_2";
		break;
	case FlyoverType::FLYOVER3:
		flyoverTypeQString = "flyover_3";
		break;
	case FlyoverType::FLYOVER4:
		flyoverTypeQString = "flyover_4";
		break;
	case FlyoverType::FLYOVER5:
		flyoverTypeQString = "flyover_5";
		break;
	case FlyoverType::FLYOVER6:
		flyoverTypeQString = "flyover_6";
		break;
	case FlyoverType::FLYOVER7:
		flyoverTypeQString = "flyover_7";
		break;
	case FlyoverType::FLYOVER8:
		flyoverTypeQString = "flyover_8";
		break;
	case FlyoverType::FLYOVER9:
		flyoverTypeQString = "flyover_9";
		break;
	case FlyoverType::FLYOVER10:
		flyoverTypeQString = "flyover_10";
		break;
	case FlyoverType::FLYOVER11:
		flyoverTypeQString = "flyover_11";
		break;
	case FlyoverType::FLYOVER12:
		flyoverTypeQString = "flyover_12";
		break;
	}
	return flyoverTypeQString;
}

QString FlyoverTrack::toQString()
{
	QString flyoverTrackQString = "FlyoverTrack";
	flyoverTrackQString.append(",");
	flyoverTrackQString.append(flyoverTypeToQString());
	flyoverTrackQString.append(",");
	flyoverTrackQString.append(QString::number(locationX));
	flyoverTrackQString.append(",");
	flyoverTrackQString.append(QString::number(locationY));
	flyoverTrackQString.append(",");
	flyoverTrackQString.append(QString::number(trackMainSpeed));
	flyoverTrackQString.append(",");
	flyoverTrackQString.append(QString::number(trackMainLength));
	return flyoverTrackQString;
}
