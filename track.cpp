#include "track.h"

// Track class implementation.

//Private

QString Track::getTrackMainSpeedToQString()
{
	return QString::number(trackMainSpeed);
}

QString Track::getTrackMainLengthToQString()
{
	return QString::number(trackMainLength);
}

QString Track::getTrackSecondarySpeedToQString()
{
	return QString::number(trackSecondarySpeed);
}

QString Track::getTrackSecondaryLengthToQString()
{
	return QString::number(trackSecondaryLength);
}

//Protected

void Track::setDefaultSecondarySpeedLength()
{
	trackSecondarySpeed = 200;
	trackSecondaryLength = 100;
}

//Public

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

QString Track::mainSpeedLengthToQString()
{
	QString trackMainSpeedLengthQString = getTrackMainSpeedToQString();
	trackMainSpeedLengthQString.append(",");
	trackMainSpeedLengthQString.append(getTrackMainLengthToQString());
	return trackMainSpeedLengthQString;
}

QString Track::secondarySpeedLengthToQString()
{
	QString trackSecondarySpeedLengthQString = getTrackSecondarySpeedToQString();
	trackSecondarySpeedLengthQString.append(",");
	trackSecondarySpeedLengthQString.append(getTrackSecondaryLengthToQString());
	return trackSecondarySpeedLengthQString;
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
	trackQString.append(locationToQString());
	trackQString.append(",");
	trackQString.append(mainSpeedLengthToQString());
	return trackQString;
}

QString Track::toQStringForSave()
{
    QString trackQString = locationToQString();
	trackQString.append(",");
    trackQString.append(mainSpeedLengthToQString());
	return trackQString;
}


//StraightTrack class implementation.


QString StraightTrack::getPlatform1ToQString()
{
    return QString::number(platform1);
}

QString StraightTrack::getPlatform2ToQString()
{
    return QString::number(platform2);
}

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

bool StraightTrack::hasPlatform() const
{
	return (platform1 || platform2);
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

QString StraightTrack::platformsToQString()
{
    QString platformsQString = getPlatform1ToQString();
    platformsQString.append(",");
    platformsQString.append(getPlatform2ToQString());
    return platformsQString;
}

bool StraightTrack::hasLevelCrossing() const
{
	return levelCrossing;
}

void StraightTrack::addLevelCrossing()
{
	levelCrossing = true;
}

void StraightTrack::removeLevelCrossing()
{
	levelCrossing = false;
}

QString StraightTrack::levelCrossingToQString()
{
	return QString::number(levelCrossing);
}

QString StraightTrack::straightTypeToQString()
{
	QString straightTypeQString;
	switch (straightType)
	{
	case StraightType::STRAIGHTH:
        straightTypeQString = "SH";
		break;
	case StraightType::STRAIGHTV:
        straightTypeQString = "SV";
		break;
	case StraightType::STRAIGHTLEFTUP:
        straightTypeQString = "SLU";
		break;
	case StraightType::STRAIGHTRIGHTUP:
        straightTypeQString = "SRU";
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
	straightTrackQString.append(locationToQString());
	straightTrackQString.append(",");
	straightTrackQString.append(mainSpeedLengthToQString());
	straightTrackQString.append(",");
    straightTrackQString.append(platformsToQString());
	straightTrackQString.append(",");
	straightTrackQString.append(levelCrossingToQString());
	return straightTrackQString;
}

QString StraightTrack::toQStringForSave()
{
	QString straightTrackQString = straightTypeToQString();
	straightTrackQString.append(",");
	straightTrackQString.append(locationToQString());
	straightTrackQString.append(",");
	straightTrackQString.append(mainSpeedLengthToQString());
	straightTrackQString.append(",");
    straightTrackQString.append(platformsToQString());
	straightTrackQString.append(",");
	straightTrackQString.append(levelCrossingToQString());
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
        directedTypeQString = "DL";
		break;
	case DirectedType::DIRECTEDRIGHT:
        directedTypeQString = "DR";
		break;
	case DirectedType::DIRECTEDUP:
        directedTypeQString = "DU";
		break;
	case DirectedType::DIRECTEDDOWN:
        directedTypeQString = "DD";
		break;
	case DirectedType::DIRECTEDLEFTUP:
        directedTypeQString = "DLU";
		break;
	case DirectedType::DIRECTEDRIGHTUP:
        directedTypeQString = "DRU";
		break;
	case DirectedType::DIRECTEDLEFTDOWN:
        directedTypeQString = "DLD";
		break;
	case DirectedType::DIRECTEDRIGHTDOWN:
        directedTypeQString = "DRD";
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
	directedTrackQString.append(locationToQString());
	directedTrackQString.append(",");
	directedTrackQString.append(mainSpeedLengthToQString());
	directedTrackQString.append(",");
    directedTrackQString.append(platformsToQString());
	return directedTrackQString;
}

QString DirectedTrack::toQStringForSave()
{
	QString directedTrackQString = directedTypeToQString();
	directedTrackQString.append(",");
	directedTrackQString.append(locationToQString());
	directedTrackQString.append(",");
	directedTrackQString.append(mainSpeedLengthToQString());
	directedTrackQString.append(",");
    directedTrackQString.append(platformsToQString());
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
        curvedTypeQString = "C1";
		break;
	case CurvedType::CURVE2:
        curvedTypeQString = "C2";
		break;
	case CurvedType::CURVE3:
        curvedTypeQString = "C3";
		break;
	case CurvedType::CURVE4:
        curvedTypeQString = "C4";
		break;
	case CurvedType::CURVE5:
        curvedTypeQString = "C5";
		break;
	case CurvedType::CURVE6:
        curvedTypeQString = "C6";
		break;
	case CurvedType::CURVE7:
        curvedTypeQString = "C7";
		break;
	case CurvedType::CURVE8:
        curvedTypeQString = "C8";
		break;
	case CurvedType::TIGHTCURVE1:
        curvedTypeQString = "TC1";
		break;
	case CurvedType::TIGHTCURVE2:
        curvedTypeQString = "TC2";
		break;
	case CurvedType::TIGHTCURVE3:
        curvedTypeQString = "TC3";
		break;
	case CurvedType::TIGHTCURVE4:
        curvedTypeQString = "TC4";
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
	curvedTrackQString.append(locationToQString());
	curvedTrackQString.append(",");
	curvedTrackQString.append(mainSpeedLengthToQString());
	return curvedTrackQString;
}

QString CurvedTrack::toQStringForSave()
{
	QString curvedTrackQString = curvedTypeToQString();
	curvedTrackQString.append(",");
	curvedTrackQString.append(locationToQString());
	curvedTrackQString.append(",");
	curvedTrackQString.append(mainSpeedLengthToQString());
	return curvedTrackQString;
}


//LinkedTrack class implementation.


LinkedTrack::LinkedTrack(LinkedType newLinkedType, int newLocationX, int newLocationY)
{
	linkedType = newLinkedType;
	locationX = newLocationX;
	locationY = newLocationY;
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

bool LinkedTrack::isLinked() const
{
	if (otherLinkTrack == nullptr)
	{
		return false;
	}
	return true;
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
        linkedTypeQString = "LL";
		break;
	case LinkedType::LINKRIGHT:
        linkedTypeQString = "LR";
		break;
	case LinkedType::LINKUP:
        linkedTypeQString = "LU";
		break;
	case LinkedType::LINKDOWN:
        linkedTypeQString = "LD";
		break;
	case LinkedType::LINKLEFTDOWN:
        linkedTypeQString = "LLD";
		break;
	case LinkedType::LINKLEFTUP:
        linkedTypeQString = "LLU";
		break;
	case LinkedType::LINKRIGHTDOWN:
        linkedTypeQString = "LRD";
		break;
	case LinkedType::LINKRIGHTUP:
        linkedTypeQString = "LRU";
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
	linkedTrackQString.append(locationToQString());
	linkedTrackQString.append(",");
	linkedTrackQString.append(mainSpeedLengthToQString());
	if (isLinked())
	{
		linkedTrackQString.append(",");
		linkedTrackQString.append("1");
		linkedTrackQString.append(",");
		linkedTrackQString.append(otherLinkedTrackToQString());

	}
	else
	{
		linkedTrackQString.append(",");
		linkedTrackQString.append("0");
	}
	return linkedTrackQString;
}

QString LinkedTrack::otherLinkedTrackToQString()
{
	QString linkedTrackQString = "LinkedTrack";

	linkedTrackQString.append(",");
	linkedTrackQString.append(otherLinkTrack->linkedTypeToQString());
	linkedTrackQString.append(",");
	linkedTrackQString.append(otherLinkTrack->locationToQString());
	linkedTrackQString.append(",");
	linkedTrackQString.append(mainSpeedLengthToQString());
	return linkedTrackQString;
}

QString LinkedTrack::toQStringForSave()
{
	QString linkedTrackQString =linkedTypeToQString();
	linkedTrackQString.append(",");
	linkedTrackQString.append(locationToQString());
	linkedTrackQString.append(",");
	linkedTrackQString.append(mainSpeedLengthToQString());
	if (isLinked())
	{
		linkedTrackQString.append(",");
		linkedTrackQString.append("1");
		linkedTrackQString.append(",");
		linkedTrackQString.append(otherLinkedTrackToQStringForSave());

	}
	else
	{
		linkedTrackQString.append(",");
		linkedTrackQString.append("0");
	}
	return linkedTrackQString;
}

QString LinkedTrack::otherLinkedTrackToQStringForSave()
{
	QString linkedTrackQString = otherLinkTrack->linkedTypeToQString();
	linkedTrackQString.append(",");
	linkedTrackQString.append(otherLinkTrack->locationToQString());
	linkedTrackQString.append(",");
	linkedTrackQString.append(QString::number(otherLinkTrack->getTrackMainSpeed()));
	linkedTrackQString.append(",");
	linkedTrackQString.append(QString::number(otherLinkTrack->getTrackMainLength()));
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
        exitTypeQString = "EL";
		break;
	case ExitType::EXITRIGHT:
        exitTypeQString = "ER";
		break;
	case ExitType::EXITUP:
        exitTypeQString = "EU";
		break;
	case ExitType::EXITDOWN:
        exitTypeQString = "ED";
		break;
	case ExitType::EXITLEFTDOWN:
        exitTypeQString = "ELD";
		break;
	case ExitType::EXITLEFTUP:
        exitTypeQString = "ELU";
		break;
	case ExitType::EXITRIGHTDOWN:
        exitTypeQString = "ERD";
		break;
	case ExitType::EXITRIGHTUP:
        exitTypeQString = "ERU";
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
	exitTrackQString.append(locationToQString());
	exitTrackQString.append(",");
	exitTrackQString.append(mainSpeedLengthToQString());
	return exitTrackQString;
}

QString ExitTrack::toQStringForSave()
{
	QString exitTrackQString = exitTypeToQString();
	exitTrackQString.append(",");
	exitTrackQString.append(locationToQString());
	exitTrackQString.append(",");
	exitTrackQString.append(mainSpeedLengthToQString());
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
        bufferTypeQString = "BL";
		break;
	case BufferType::BUFFERRIGHT:
        bufferTypeQString = "BR";
		break;
	case BufferType::BUFFERUP:
        bufferTypeQString = "BU";
		break;
	case BufferType::BUFFERDOWN:
        bufferTypeQString = "BD";
		break;
	case BufferType::BUFFERLEFTDOWN:
        bufferTypeQString = "BLD";
		break;
	case BufferType::BUFFERLEFTUP:
        bufferTypeQString = "BLU";
		break;
	case BufferType::BUFFERRIGHTDOWN:
        bufferTypeQString = "BRD";
		break;
	case BufferType::BUFFERRIGHTUP:
        bufferTypeQString = "BRU";
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
	bufferTrackQString.append(locationToQString());
	bufferTrackQString.append(",");
	bufferTrackQString.append(mainSpeedLengthToQString());
    bufferTrackQString.append(",");
    bufferTrackQString.append(platformsToQString());
	return bufferTrackQString;
}

QString BufferTrack::toQStringForSave()
{
	QString bufferTrackQString = bufferTypeToQString();
	bufferTrackQString.append(",");
	bufferTrackQString.append(locationToQString());
	bufferTrackQString.append(",");
	bufferTrackQString.append(mainSpeedLengthToQString());
    bufferTrackQString.append(",");
    bufferTrackQString.append(platformsToQString());
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

QString SignalTrack::aspectToQString()
{
	return QString::number(aspect);
}

QString SignalTrack::signalTypeToQString()
{
	QString signalTypeQString;
	switch (signalType)
	{
	case SignalType::SIGNALLEFT:
        signalTypeQString = "SIGL";
		break;
	case SignalType::SIGNALRIGHT:
        signalTypeQString = "SIGR";
		break;
	case SignalType::SIGNALUP:
        signalTypeQString = "SIGU";
		break;
	case SignalType::SIGNALDOWN:
        signalTypeQString = "SIGD";
		break;
	case SignalType::SIGNALLEFTDOWN:
        signalTypeQString = "SIGLD";
		break;
	case SignalType::SIGNALLEFTUP:
        signalTypeQString = "SIGLU";
		break;
	case SignalType::SIGNALRIGHTDOWN:
        signalTypeQString = "SIGRD";
		break;
	case SignalType::SIGNALRIGHTUP:
        signalTypeQString = "SIGRU";
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
	signalTrackQString.append(aspectToQString());
	signalTrackQString.append(",");
	signalTrackQString.append(locationToQString());
	signalTrackQString.append(",");
	signalTrackQString.append(mainSpeedLengthToQString());
	signalTrackQString.append(",");
    signalTrackQString.append(platformsToQString());
	return signalTrackQString;
}

QString SignalTrack::toQStringForSave()
{
	QString signalTrackQString = signalTypeToQString();;
	signalTrackQString.append(",");
	signalTrackQString.append(aspectToQString());
	signalTrackQString.append(",");
	signalTrackQString.append(locationToQString());
	signalTrackQString.append(",");
	signalTrackQString.append(mainSpeedLengthToQString());
	signalTrackQString.append(",");
    signalTrackQString.append(platformsToQString());


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
        bridgeUnderpassTypeQString = "BR1";
		break;
	case BridgeUnderpassType::BRIDGE2:
        bridgeUnderpassTypeQString = "BR2";
		break;
	case BridgeUnderpassType::UNDERPASS1:
        bridgeUnderpassTypeQString = "UP1";
		break;
	case BridgeUnderpassType::UNDERPASS2:
        bridgeUnderpassTypeQString = "UP2";
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
	bridgeUnderpassTrackQString.append(locationToQString());
	bridgeUnderpassTrackQString.append(",");
	bridgeUnderpassTrackQString.append(mainSpeedLengthToQString());
	bridgeUnderpassTrackQString.append(",");
    bridgeUnderpassTrackQString.append(platformsToQString());

	return bridgeUnderpassTrackQString;
}

QString BridgeUnderpassTrack::toQStringForSave()
{
	QString bridgeUnderpassTrackQString = bridgeUnderpassTypeToQString();
	bridgeUnderpassTrackQString.append(",");
	bridgeUnderpassTrackQString.append(locationToQString());
	bridgeUnderpassTrackQString.append(",");
	bridgeUnderpassTrackQString.append(mainSpeedLengthToQString());
	bridgeUnderpassTrackQString.append(",");
    bridgeUnderpassTrackQString.append(platformsToQString());
	return bridgeUnderpassTrackQString;
}


//SwitchTrack class implementation.


SwitchTrack::SwitchTrack(SwitchType newSwitchType, int newLocationX, int newLocationY)
{
	switchType = newSwitchType;
	locationX = newLocationX;
	locationY = newLocationY;
	setDefaultSecondarySpeedLength();
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
        switchTypeQString = "SW1";
		break;
	case SwitchType::SWITCH2:
        switchTypeQString = "SW2";
		break;
	case SwitchType::SWITCH3:
        switchTypeQString = "SW3";
		break;
	case SwitchType::SWITCH4:
        switchTypeQString = "SW4";
		break;
	case SwitchType::SWITCH5:
        switchTypeQString = "SW5";
		break;
	case SwitchType::SWITCH6:
        switchTypeQString = "SW6";
		break;
	case SwitchType::SWITCH7:
        switchTypeQString = "SW7";
		break;
	case SwitchType::SWITCH8:
        switchTypeQString = "SW8";
		break;
	case SwitchType::SWITCH9:
        switchTypeQString = "SW9";
		break;
	case SwitchType::SWITCH10:
        switchTypeQString = "SW10";
		break;
	case SwitchType::SWITCH11:
        switchTypeQString = "SW11";
		break;
	case SwitchType::SWITCH12:
        switchTypeQString = "SW12";
		break;
	case SwitchType::SWITCH13:
        switchTypeQString = "SW13";
		break;
	case SwitchType::SWITCH14:
        switchTypeQString = "SW14";
		break;
	case SwitchType::SWITCH15:
        switchTypeQString = "SW15";
		break;
	case SwitchType::SWITCH16:
        switchTypeQString = "SW16";
		break;
	case SwitchType::SWITCHTIGHT1:
        switchTypeQString = "SWT1";
		break;
	case SwitchType::SWITCHTIGHT2:
        switchTypeQString = "SWT2";
		break;
	case SwitchType::SWITCHTIGHT3:
        switchTypeQString = "SWT3";
		break;
	case SwitchType::SWITCHTIGHT4:
        switchTypeQString = "SWT4";
		break;
	case SwitchType::SWITCHTIGHT5:
        switchTypeQString = "SWT5";
		break;
	case SwitchType::SWITCHTIGHT6:
        switchTypeQString = "SWT6";
		break;
	case SwitchType::SWITCHTIGHT7:
        switchTypeQString = "SWT7";
		break;
	case SwitchType::SWITCHTIGHT8:
        switchTypeQString = "SWT8";
		break;
	case SwitchType::SWITCHSPLIT1:
        switchTypeQString = "SWS1";
		break;
	case SwitchType::SWITCHSPLIT2:
        switchTypeQString = "SWS2";
		break;
	case SwitchType::SWITCHSPLIT3:
        switchTypeQString = "SWS3";
		break;
	case SwitchType::SWITCHSPLIT4:
        switchTypeQString = "SWS4";
		break;
	case SwitchType::SWITCHSPLIT5:
        switchTypeQString = "SWS5";
		break;
	case SwitchType::SWITCHSPLIT6:
        switchTypeQString = "SWS6";
		break;
	case SwitchType::SWITCHSPLIT7:
        switchTypeQString = "SWS7";
		break;
	case SwitchType::SWITCHSPLIT8:
        switchTypeQString = "SWS8";
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
	switchTrackQString.append(locationToQString());
	switchTrackQString.append(",");
	switchTrackQString.append(mainSpeedLengthToQString());
	switchTrackQString.append(",");
	switchTrackQString.append(secondarySpeedLengthToQString());
    switchTrackQString.append(",");
    switchTrackQString.append(platformsToQString());
	return switchTrackQString;
}

QString SwitchTrack::toQStringForSave()
{
	QString switchTrackQString = switchTypeToQString();
	switchTrackQString.append(",");
	switchTrackQString.append(locationToQString());
	switchTrackQString.append(",");
	switchTrackQString.append(mainSpeedLengthToQString());
	switchTrackQString.append(",");
	switchTrackQString.append(secondarySpeedLengthToQString());
    switchTrackQString.append(",");
    switchTrackQString.append(platformsToQString());
	return switchTrackQString;
}


//CrossoverTrack class implementation.


CrossoverTrack::CrossoverTrack(CrossoverType newCrossoverType, int newLocationX, int newLocationY)
{
	crossoverType = newCrossoverType;
	locationX = newLocationX;
	locationY = newLocationY;
	setDefaultSecondarySpeedLength();
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
        crossoverTypeQString = "CR1";
		break;
	case CrossoverType::CROSSOVER2:
        crossoverTypeQString = "CR2";
		break;
	case CrossoverType::CROSSOVER3:
        crossoverTypeQString = "CR3";
		break;
	case CrossoverType::CROSSOVER4:
        crossoverTypeQString = "CR4";
		break;
	case CrossoverType::CROSSOVER5:
        crossoverTypeQString = "CR5";
		break;
	case CrossoverType::CROSSOVER6:
        crossoverTypeQString = "CR6";
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
	crossoverTrackQString.append(locationToQString());
	crossoverTrackQString.append(",");
	crossoverTrackQString.append(mainSpeedLengthToQString());
	crossoverTrackQString.append(",");
    crossoverTrackQString.append(secondarySpeedLengthToQString());
	return crossoverTrackQString;
}

QString CrossoverTrack::toQStringForSave()
{
	QString crossoverTrackQString = crossoverTypeToQString();
	crossoverTrackQString.append(",");
	crossoverTrackQString.append(locationToQString());
	crossoverTrackQString.append(",");
	crossoverTrackQString.append(mainSpeedLengthToQString());
	crossoverTrackQString.append(",");
	crossoverTrackQString.append(secondarySpeedLengthToQString());
	return crossoverTrackQString;
}


//FlyoverTrack class implementation.


FlyoverTrack::FlyoverTrack(FlyoverType newFlyoverType, int newLocationX, int newLocationY)
{
	flyoverType = newFlyoverType;
	locationX = newLocationX;
	locationY = newLocationY;
	setDefaultSecondarySpeedLength();
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
        flyoverTypeQString = "F1";
		break;
	case FlyoverType::FLYOVER2:
        flyoverTypeQString = "F2";
		break;
	case FlyoverType::FLYOVER3:
        flyoverTypeQString = "F3";
		break;
	case FlyoverType::FLYOVER4:
        flyoverTypeQString = "F4";
		break;
	case FlyoverType::FLYOVER5:
        flyoverTypeQString = "F5";
		break;
	case FlyoverType::FLYOVER6:
        flyoverTypeQString = "F6";
		break;
	case FlyoverType::FLYOVER7:
        flyoverTypeQString = "F7";
		break;
	case FlyoverType::FLYOVER8:
        flyoverTypeQString = "F8";
		break;
	case FlyoverType::FLYOVER9:
        flyoverTypeQString = "F9";
		break;
	case FlyoverType::FLYOVER10:
        flyoverTypeQString = "F10";
		break;
	case FlyoverType::FLYOVER11:
        flyoverTypeQString = "F11";
		break;
	case FlyoverType::FLYOVER12:
        flyoverTypeQString = "F12";
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
	flyoverTrackQString.append(locationToQString());
	flyoverTrackQString.append(",");
	flyoverTrackQString.append(mainSpeedLengthToQString());
	flyoverTrackQString.append(",");
	flyoverTrackQString.append(secondarySpeedLengthToQString());
	return flyoverTrackQString;
}

QString FlyoverTrack::toQStringForSave()
{
	QString flyoverTrackQString = flyoverTypeToQString();
	flyoverTrackQString.append(",");
	flyoverTrackQString.append(locationToQString());
	flyoverTrackQString.append(",");
	flyoverTrackQString.append(mainSpeedLengthToQString());
	flyoverTrackQString.append(",");
	flyoverTrackQString.append(secondarySpeedLengthToQString());
	return flyoverTrackQString;
}
