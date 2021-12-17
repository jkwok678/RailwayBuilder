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
}

QString ExitTrack::toQString()
{
	QString exitTrackQString = "LinkedTrack";
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
