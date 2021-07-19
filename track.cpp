#include "track.h"

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

bool Track::getPlatformAny() const
{
	return platformAny;
}

void Track::setPlatformAny(bool platform)
{
	platformAny = platform;
}

bool Track::getPlatform1() const
{
	return platform1;
}

void Track::setPlatform1(bool newPlatform)
{
	platform1 = newPlatform;
}

bool Track::getPlatform2() const
{
	return platform2;
}

void Track::setPlatform2(bool newPlatform)
{
	platform2 = newPlatform;
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
