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


//StraightTrack class implementation.


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
		case StraightType::STRIAGHTRIGHTUP:
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


// DirectedTrack class implementation.


DirectedTrack::DirectedTrack(DirectedType newDirectType, int newLocationX, int newLocationY)
{
	directedType = newDirectType;
	locationX = newLocationX;
	locationY = newLocationY;
	switch(directedType)
	{
		case DirectedType::DIRECTLEFT:
		case DirectedType::DIRECTRIGHT:
		{
			links[3] = true;
			links[5] = true;
			break;
		}
		case DirectedType::DIRECTUP:
		case DirectedType::DIRECTDOWN:
		{
			links[1] = true;
			links[7] = true;
			break;
		}
		case DirectedType::DIRECTLEFTUP:
		case DirectedType::DIRECTRIGHTDOWN:
		{
			links[0] = true;
			links[8] = true;
			break;
		}
		case DirectedType::DIRECTRIGHTUP:
		case DirectedType::DIRECTLEFTDOWN:
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

std::shared_ptr<LinkedTrack> LinkedTrack::getOtherLinkTrack()
{
	return otherLinkTrack;
}

void LinkedTrack::setOtherLinkTrack(std::shared_ptr<LinkedTrack> &newLinkedTrack)
{
	otherLinkTrack = newLinkedTrack;
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
